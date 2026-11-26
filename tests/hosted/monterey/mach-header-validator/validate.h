/* SPDX-License-Identifier: MIT */
/* Structural gate for a private little-endian Intel MH_EXECUTE snapshot.
 * Does not authenticate an image, validate all load command payloads,
 * authorize executable mapping, or establish native boot compatibility. */
static unsigned mh_u32(const unsigned char *p)
{
 return (unsigned)p[0] | (unsigned)p[1]<<8 |
        (unsigned)p[2]<<16 | (unsigned)p[3]<<24;
}
static unsigned long long mh_u64(const unsigned char *p)
{
 return (unsigned long long)mh_u32(p) |
        (unsigned long long)mh_u32(p+4)<<32;
}
static int mh_range(unsigned long long base,unsigned long long size,
                    unsigned long long limit)
{
 return base<=limit && size<=limit-base;
}
static int validate_mh(const void *snapshot,size_t len,unsigned long long image_size)
{
 const unsigned char *p=snapshot;
 size_t pos=32;
 unsigned count, bytes;
 if (!p || len<32 || mh_u32(p)!=0xfeedfacf ||
     mh_u32(p+4)!=0x01000007 || mh_u32(p+12)!=2) return -EINVAL;
 count=mh_u32(p+16); bytes=mh_u32(p+20);
 if (bytes!=len-32 || len>image_size || count>bytes/8) return -EINVAL;
 for (unsigned i=0;i<count;i++) {
  unsigned cmd,n;
  if (len-pos<8) return -EINVAL;
  cmd=mh_u32(p+pos); n=mh_u32(p+pos+4);
  if (n<8 || n%8 || n>len-pos) return -EINVAL;
  if (cmd==0x19) {
   unsigned ns;
   unsigned long long va,vs,off,fs;
   if (n<72) return -EINVAL;
   va=mh_u64(p+pos+24); vs=mh_u64(p+pos+32);
   off=mh_u64(p+pos+40); fs=mh_u64(p+pos+48);
   ns=mh_u32(p+pos+64);
   if ((n-72)%80 || ns!=(n-72)/80 || fs>vs ||
       !mh_range(va,vs,~0ULL) || !mh_range(off,fs,image_size)) return -EINVAL;
   for (unsigned j=0;j<ns;j++) {
    const unsigned char *s=p+pos+72+80*(size_t)j;
    unsigned long long addr=mh_u64(s+32),size=mh_u64(s+40);
    unsigned type=mh_u32(s+64)&0xff;
    if (memcmp(s+16,p+pos+8,16) || addr<va ||
        !mh_range(addr-va,size,vs)) return -EINVAL;
    /* S_ZEROFILL, S_GB_ZEROFILL, S_THREAD_LOCAL_ZEROFILL have no file bytes. */
    if (size && type!=1 && type!=0xc && type!=0x12) {
     unsigned long long fo=mh_u32(s+48);
     if (fo<off || !mh_range(fo-off,size,fs)) return -EINVAL;
    }
   }
  } else if (cmd==0x1b && n!=24) return -EINVAL;
  pos+=n;
 }
 return pos==len?0:-EINVAL;
}
