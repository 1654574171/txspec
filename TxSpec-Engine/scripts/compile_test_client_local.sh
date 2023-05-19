#!/bin/bash

set -eux -o pipefail

cd "$(dirname $0)" "/../test_client"

mkdir build
cd build
cmake .. && make