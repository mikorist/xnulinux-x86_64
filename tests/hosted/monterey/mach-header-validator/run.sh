#!/bin/sh
# SPDX-License-Identifier: MIT
set -eu
cd "$(dirname "$0")"
build=$(mktemp -d)
trap 'rm -rf "$build"' EXIT HUP INT TERM
"${CC:-gcc}" -std=c11 -Wall -Wextra -Werror -O2 -fsanitize=undefined -fno-sanitize-recover=all probe.c -o "$build/probe"
"$build/probe"
