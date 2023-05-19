#!/bin/bash

set -eux -o pipefail

pushd "$(dirname $0)"
# set up mysql
export COMPOSE_PROJECT_NAME=jenkinscomplianceengine
docker-compose -f ./test/docker/docker-compose-mysql.yaml up -d
sleep 100

# write necessary date to mysql
./test/data_access.sh

# set up compliance-engine container
docker-compose -f ./test/docker/docker-compose-main.yaml up -d

# set off mysql and compliance-engine container
docker-compose -f ./test/docker/docker-compose-mysql.yaml down --volumes --remove-orphans
docker-compose -f ./test/docker/docker-compose-main.yaml down --volumes --remove-orphans

popd