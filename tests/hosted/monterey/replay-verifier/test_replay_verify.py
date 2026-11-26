# SPDX-License-Identifier: MIT
import hashlib
import pathlib
import tempfile
import unittest
from replay_verify import verify_sources, verify_log, load_json

class ReplayVerification(unittest.TestCase):
    def test_sources(self):
        with tempfile.TemporaryDirectory() as d:
            p=pathlib.Path(d)
            (p/'a.c').write_text('int x;\n')
            h=hashlib.sha256((p/'a.c').read_bytes()).hexdigest()
            self.assertEqual(verify_sources(p,{'a.c':h}),1)
            for manifest in ({},{'../a.c':h},{'missing.c':h},{'a.c':'0'*64},{'a.c':'bad'},{'.':h},{'x/y':h}):
                with self.subTest(manifest=manifest),self.assertRaises(ValueError):
                    verify_sources(p,manifest)
            (p/'link.c').symlink_to(p/'a.c')
            with self.assertRaises(ValueError):
                verify_sources(p,{'link.c':h})
    def test_log(self):
        expected={'XNUL_SAMPLE_PASS count=2':2,'XNUL_REFERENCE_GUEST_DONE':1}
        log='[  0.123] XNUL_SAMPLE_PASS count=2\r\nXNUL_SAMPLE_PASS count=2 extra=1\nXNUL_REFERENCE_GUEST_DONE\n'
        self.assertEqual(verify_log(log,expected),2)
        for bad in (log.replace('count=2 extra','count=20 extra'),log.replace('XNUL_SAMPLE_PASS','notXNUL_SAMPLE_PASS'),log+'XNUL_SAMPLE_PASS count=2\n',log+'XNUL_REFERENCE_GUEST_DONE\n',log+'Kernel panic\n',log+'XNUL_SAMPLE_FAIL\n',log.replace('XNUL_REFERENCE_GUEST_DONE','')):
            with self.subTest(log=bad),self.assertRaises(ValueError):
                verify_log(bad,expected)
        for bad in ({},{'XNUL_SAMPLE_PASS count=2':2},{'XNUL_REFERENCE_GUEST_DONE':True},{'XNUL_REFERENCE_GUEST_DONE':0}):
            with self.subTest(expected=bad),self.assertRaises(ValueError):
                verify_log(log,bad)
    def test_duplicate_json(self):
        with tempfile.TemporaryDirectory() as d:
            p=pathlib.Path(d)/'manifest.json'
            p.write_text('{"a":1,"a":2}')
            with self.assertRaises(ValueError):
                load_json(p)

if __name__=='__main__':
    unittest.main()
