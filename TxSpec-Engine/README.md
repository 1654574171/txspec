# Compliance Engine

## PreRequirements

Want to complie locally? Please follow the instructions in [ComplianceEnginePrerequisites](./docs/ComplianceEnginePrerequisites.md).

## How to Use

### Option1: Natively
```shell
# Prepare to compile and build whole project
mkdir build
cd build
cmake .. && make

# Run with options
./main --log ../logs/compliance_engine.log --config ../config/ComplianceEngine.yaml

```
- Notes. 
    If ./main is killed for no obvious reason in log, try to reduce enclave stack size in .xml config file.

### Option2: Docker
```shell
# replace http(s) proxy with your own address for quick installation
docker build -t compliance-engine --build-arg "http_proxy=http://192.168.177.1:7890" --build-arg "https_proxy=http://192.168.177.1:7890" -f Dockerfile .

# pull mysql image
docker pull mysql

# set up containers
export COMPOSE_PROJECT_NAME=ComplianceEngine
docker-compose -f ./docker-compose.yaml up -d

# set off mysql and compliance-engine container
docker-compose -f ./docker-compose.yaml down --volumes --remove-orphans
```
- Notes. 
    Default mysql port is 3306, and in docker way, we map it to 33006. So compliance-engines's mysql address(CORE_MYSQL_ADDRESS) should be set to 33006 in config file to.
## How to test

## Option1: Local Test Procedure
```shell
# 1. build and run echo http server, which used to 


# 2. Build and Run as showed above
# 3. Go into test_client dir, build and run test_client
cd test/test_client
cd build
cmake .. && make

./regulator_client
./registration_client
```

## Option2: Test Procedure on Server along with Regchain
```shell
# 1. Run local test for compliance-engine first.
# 2. Download regchain-fabric git repo
# 3. Checkout to dev branch
# 4. Copy compliance-engine dir into regchain-fabric
# 5. Run following commands at the path of regchain-fabric to make regulator-peer image:
make regulator-docker-clean;
make regulator-docker;
# 6. Package the image
docker save -o regchain-peer.tar oxhainan/regchain-regulator:latest
# 7. Drag regchain-peer.tar out of virtual machine to your main machine
# 8. Log in server
# 8. Upload regchain-peer.tat to server using scp
root@server: scp xufeiwang@10.100.128.166:/Users/xufeiwang/Desktop/regchain-peer.tar .
# 9. Recover image from package
docker load -i regchain-peer.tar
# 10. Change docker image name
docker tag xxxx(above image id) oxhainan/regchain-peer:latest
# 11. All Done!
```

## Test for Jenkins

[![Build Status](http://39.98.246.137:2280/buildStatus/icon?job=Compliance+Engine%2Fcode_review)](http://39.98.246.137:2280/job/Compliance%20Engine/job/code_review/)


## TODO List
- add config file (.yaml)
    - thread number
- [ErrorType format united](./ErrorCode_VS_Exception.md)
- RunServer char* tmp naming
- RunServer line:224 - 232 comments
- RunServer server down and restart
- mysql server down and restart
- enclave deconstruct and save state
- Function return value :Error Code type (Need to modify EDL file)
- Log System review
- Remove KeyManagement /App /Enclave2 /Enclave3 (Still need them for test in future)
- Local Attestation 6 times or 3 times? Improve: add src_session_info and dest_session_info at the same time
- Where to delete kDataServer? 
- Parallel Threads issue
- Hard-code create tables (hot plug-in)
- [Code style](./RuleEngine_CodeStyle_Checklist.md)
- Dockerfile simplify and engineering
  - openssl1.1.1g make test fail
  - reduce size 
- 12.29
  - cleanup some include path to relative
  - optimize comment
  - optimize variable name, e.g. change  global variable 'config' in Config.cpp to g_config
  - provide method to shut down Grpc Service
