# SPDX-License-Identifier: MIT
"""Validate a retained flat source manifest and an isolated guest test log."""
import hashlib
import json
import pathlib
import re

def verify_sources(root, manifest):
    if not isinstance(manifest, dict) or not manifest:
        raise ValueError("empty or invalid source manifest")
    root = pathlib.Path(root)
    for name, digest in manifest.items():
        if not isinstance(name, str) or not re.fullmatch(r"[A-Za-z0-9_][A-Za-z0-9_.-]*", name):
            raise ValueError("invalid flat source name")
        if not isinstance(digest, str) or not re.fullmatch(r"[a-f0-9]{64}", digest):
            raise ValueError("invalid source digest")
        p = root / name
        if p.is_symlink() or not p.is_file():
            raise ValueError("missing or nonregular source: " + name)
        if hashlib.sha256(p.read_bytes()).hexdigest() != digest:
            raise ValueError("source digest mismatch: " + name)
    return len(manifest)

def verify_log(log, expected):
    if not isinstance(expected, dict) or not expected:
        raise ValueError("empty or invalid expected markers")
    lines = [re.sub(r"^\[\s*\d+(?:\.\d+)?\]\s*", "", x).strip() for x in log.splitlines()]
    if any(re.search(r"XNUL_[A-Z0-9_]*FAIL\b|Kernel panic|BUG:|Oops:|WARNING:", x) for x in lines):
        raise ValueError("guest error")
    for marker, count in expected.items():
        if not isinstance(marker, str) or not re.fullmatch(r"XNUL_[A-Z0-9_]+(?: [^\r\n]+)?", marker):
            raise ValueError("invalid marker")
        if type(count) is not int or count <= 0:
            raise ValueError("invalid marker count")
        matches = sum(x == marker or x.startswith(marker + " ") for x in lines)
        if matches != count:
            raise ValueError("marker count mismatch: " + marker)
    if not any(x == "XNUL_REFERENCE_GUEST_DONE" for x in expected):
        raise ValueError("missing completion requirement")
    if lines.count("XNUL_REFERENCE_GUEST_DONE") != 1:
        raise ValueError("missing or duplicate completion")
    return len(expected)

def load_json(path):
    def pairs(items):
        out = {}
        for k, v in items:
            if k in out:
                raise ValueError("duplicate JSON key: " + k)
            out[k] = v
        return out
    return json.loads(pathlib.Path(path).read_text(), object_pairs_hook=pairs)
