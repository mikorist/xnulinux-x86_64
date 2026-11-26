# Replay verifier
MIT-licensed standalone flat source-manifest and serial-marker verification. Synthetic unit tests cover missing, changed, duplicate and invalid inputs, symlinks, marker boundaries, unexpected counts and guest errors. No kernel source is required by these tests; they validate evidence handling, not a boot or any kernel feature.

Run from the repository root:

```sh
cd tests/hosted/monterey/replay-verifier
python3 -B -m unittest -v test_replay_verify.py
```

See the [MIT license](../../../../LICENSES/MIT.txt). The full private candidate is not included.
