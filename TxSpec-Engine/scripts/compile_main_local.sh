
#!/bin/bash

set -eux -o pipefail

BUILD_DIR=

cd "$(dirname $0)" "/.."

mkdir build
cd build
cmake .. && make