set -x
pushd ./test/docker
export COMPOSE_PROJECT_NAME=jenkinscomplianceengine
docker-compose -f docker-compose-mysql.yaml up -d
popd

sleep 60
pushd build
cmake .. && make
export CORE_MYSQL_ADDRESS=127.0.0.1:33006
export MYSQL_ROOT_PASSWORD=123456
./main -l ../logs/compliance_engine.log -c ../config/ComplianceEngine.yaml > ../logs/test.log 2>&1 &
popd 

pushd request_processor/test/grpcServer/build
cmake .. && make
./test_register_server > ../logs/test.log 2>&1 &
popd

sleep 30
pushd ./test/integration_test
./data_access.sh
popd

pushd ./test_client
mkdir build
cd build
cmake .. && make
./registration_client 1 1 1 127.0.0.1:50051
./regulator_client 1 1 1 1 127.0.0.1:50051

docker-compose -f docker-compose-mysql.yaml down --volumes --remove-orphans
lsof -i:50051 | awk '{print$2}' | sed '1d' | xargs kill -9
