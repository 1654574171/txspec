#current=`date "+%Y-%m-%d %H:%M:%S"`
#timeStamp=`date -d "$current" +%s` 
#startTimeStamp=$((timeStamp*1000+`date "+%N"`/1000000))
#echo $startTimeStamp

#for i in $(seq 1 1)
#do
grpcurl -plaintext -d '{"nonce":"1","ch_id":"mychannel","end_point":"peer1.regulator.com:50051"}' 127.0.0.1:50051 request_proto.Registration.GetRegisterInfo;
#done

#timeStamp=`date -d "$current" +%s`
#finishTimeStamp=$((timeStamp*1000+`date "+%N"`/1000000))
#echo $finishTimeStamp
