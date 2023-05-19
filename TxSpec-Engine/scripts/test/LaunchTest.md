<!-- protoc -I . --proto_path=/home/liyue/request_processor/protos/ --cpp_out=. /home/liyue/request_processor/protos/Wset.proto 
protoc -I . --proto_path=/home/liyue/request_processor/protos/ --cpp_out=. /home/liyue/request_processor/protos/Compliance.proto 
protoc -I . --proto_path=/home/liyue/request_processor/protos/ --cpp_out=. /home/liyue/request_processor/protos/Regulator.proto 
protoc -I . --proto_path=/home/liyue/request_processor/protos/ --grpc_out=. --plugin=protoc-gen-grpc=/home/liyue/.local/bin/grpc_cpp_plugin /home/liyue/request_processor/protos/Regulator.proto

g++ -std=c++11 -I/usr/local/include -pthread -c Compliance.pb.cc -o Compliance.pb.o
g++ -std=c++11 -I/usr/local/include -pthread -c Regulator.grpc.pb.cc -o Regulator.grpc.pb.o
g++ -std=c++11 -I/usr/local/include -pthread -c Regulator.pb.cc -o Regulator.pb.o
g++ -std=c++11 -I/usr/local/include -pthread -c Wset.pb.cc -o Wset.pb.o

g++ -std=c++11 -I/usr/local/include -pthread -c RegulatorServer.cc -o RegulatorServer.o

g++ Compliance.pb.o Regulator.grpc.pb.o Regulator.pb.o Wset.pb.o RegulatorServer.o -L/usr/local/lib `pkg-config --libs grpc++ grpc` -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -lprotobuf -lpthread -ldl -lssl -o RegulatorServer -->

# How To Launch Simple Using CMD

## Tool

[https://github.com/fullstorydev/grpcurl](https://github.com/fullstorydev/grpcurl)

## GetComplianceProof

```bash
grpcurl -plaintext -d '{"nonce":"1","peer_signature":"1502006504000700000808010101010000000000000000000007000006000000020000000000000AE791776C1D5C169132CA96D56CC2D59E5A46F23E39933DFB3B4962A8608AB53D84F77D254627D906B46F08073D33FF511E74BC318E8E0C37483C5B08899D1B5E9F","tx_info":{"tx_id":"10086","ch_id":"mychannel","cc_id":"OXTokenContractTest","func_name":"transfer","args":["eyJwdWJsaWNrZXkiOiItLS0tLUJFR0lOIFBVQkxJQyBLRVktLS0tLVxuTUZrd0V3WUhLb1pJemowQ0FRWUlLb1pJemowREFRY0RRZ0FFTGpuNFMrUTZEQmdzUXVTbDVRTTZ4THk1akVrK1xuWkZ1V2xqbW9tUzRZeTJQMVFiVkVhRWNwNnoreTZ1ejRpNk5aWWxTNWd5TDkyeEV6d1RXcHlzK2d6UT09XG4tLS0tLUVORCBQVUJMSUMgS0VZLS0tLS1cbiIsIm1lc3NhZ2UiOnsiY29udHJhY3QiOiJPWFRva2VuQ29udHJhY3RUZXN0IiwiZnVuY3Rpb24iOiJUcmFuc2ZlciIsImFyZ3VtZW50cyI6WyI3ZmNjZWFiNzgyMTI0Njk5YjIyZDExYWU0YjU3MzBkNmM5NTA5ZGI2NDk5MWI0M2VjMzIwNDliMzFmYTljMGM3IiwiMjAwMDAiXSwibm9uY2UiOjh9LCJzaWduYXR1cmUiOiJNRVlDSVFEbzh3Nmk1TnhxWnBab1VTRjFJVXRUdDNBR0I1L3dJZ3JxZElOSFF5NzRIZ0loQUlobDM3WmRhTVVmbTAzenBhWW1SeWVuS1pQQ3ozMmwvL1g3TVRQWkQrTnQifQ==","7fcceab782124699b22d11ae4b5730d6c9509db64991b43ec32049b31fa9c0c7","20000"],"wset":{"pb_wset":[]},"version":{"block_number":"10","tx_id":"10086"},"timestamp":1625107567}}' 0.0.0.0:50051 request_proto.Regulator.GetComplianceProof
```

```bash
grpcurl -plaintext -d '{"nonce":"1","peer_signature":"1502006504000700000808010101010000000000000000000007000006000000020000000000000AE791776C1D5C169132CA96D56CC2D59E5A46F23E39933DFB3B4962A8608AB53D84F77D254627D906B46F08073D33FF511E74BC318E8E0C37483C5B08899D1B5E9F","tx_info":{"tx_id":"10087","ch_id":"mychannel","cc_id":"OXTokenContractTest","func_name":"Transfer","args":["eyJwdWJsaWNrZXkiOiItLS0tLUJFR0lOIFBVQkxJQyBLRVktLS0tLVxuTUZrd0V3WUhLb1pJemowQ0FRWUlLb1pJemowREFRY0RRZ0FFTGpuNFMrUTZEQmdzUXVTbDVRTTZ4THk1akVrK1xuWkZ1V2xqbW9tUzRZeTJQMVFiVkVhRWNwNnoreTZ1ejRpNk5aWWxTNWd5TDkyeEV6d1RXcHlzK2d6UT09XG4tLS0tLUVORCBQVUJMSUMgS0VZLS0tLS1cbiIsIm1lc3NhZ2UiOnsiY29udHJhY3QiOiJPWFRva2VuQ29udHJhY3RUZXN0IiwiZnVuY3Rpb24iOiJUcmFuc2ZlciIsImFyZ3VtZW50cyI6WyI3ZmNjZWFiNzgyMTI0Njk5YjIyZDExYWU0YjU3MzBkNmM5NTA5ZGI2NDk5MWI0M2VjMzIwNDliMzFmYTljMGM3IiwiMjAwMDAiXSwibm9uY2UiOjh9LCJzaWduYXR1cmUiOiJNRVlDSVFEbzh3Nmk1TnhxWnBab1VTRjFJVXRUdDNBR0I1L3dJZ3JxZElOSFF5NzRIZ0loQUlobDM3WmRhTVVmbTAzenBhWW1SeWVuS1pQQ3ozMmwvL1g3TVRQWkQrTnQifQ==","7fcceab782124699b22d11ae4b5730d6c9509db64991b43ec32049b31fa9c0c7","21000"],"wset":{"pb_wset":[]},"version":{"block_number":"10","tx_id":"10087"},"timestamp":1625107567}}' 0.0.0.0:50051 request_proto.Regulator.GetComplianceProof
```

## GetRegisterInfo

grpcurl -plaintext 0.0.0.0:50051 request_proto.Registration.GetRegisterInfo