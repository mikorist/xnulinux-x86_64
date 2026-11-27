# Replay verifier
MIT-licensed standalone flat source-manifest and serial-marker verification. Synthetic unit tests cover missing, changed, duplicate and invalid inputs, symlinks, marker boundaries, unexpected counts and guest errors. No kernel source is required by these tests; they validate evidence handling, not a boot or any kernel feature.

Run from the repository root:

```sh
cd tests/hosted/monterey/replay-verifier
python3 -B -m unittest -v test_replay_verify.py
```

See the [MIT license](../../../../LICENSES/MIT.txt). The full private candidate is not included.

New to the project? See [Getting started](../../../../docs/getting-started.md). No guest image is needed to run these unit tests.

CP635 independently confirms the three existing unit test methods with Python 3.13.5 and 3.14.4 on the two development environments, standard library only. [CP635](../../../../research/2026-11/checkpoint-635.md).
