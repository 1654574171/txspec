#!/bin/bash
set -e

echo "=== build mock local peer grpc serve ==="
pushd request_processor/test/grpcServer/build
cmake .. && make
./test_register_server > ../logs/test.log 2>&1 &
popd

echo "=== launch compliance serve ==="
pushd build
./main >log.txt 2>&1 &
popd

echo "=== integration test ==="
pushd test_client
mkdir build
cd build
cmake .. && make
./registration_client 1 1 1 127.0.0.1:50051
./regulator_client 1 1 1 127.0.0.1:50051 
# sleep 5
# lsof -i:50051 | awk '{print$2}' | sed '1d' | xargs kill -9

# echo "=== integration test completed ==="