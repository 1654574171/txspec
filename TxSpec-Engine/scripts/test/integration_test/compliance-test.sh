current=`date "+%Y-%m-%d %H:%M:%S"`
timeStamp=`date -d "$current" +%s` 
startTimeStamp=$((timeStamp*1000+`date "+%N"`/1000000))
echo $startTimeStamp

for i in $(seq 1 5)
do

Invoke Transfer

timeStamp=`date -d "$current" +%s`
finishTimeStamp=$((timeStamp*1000+`date "+%N"`/1000000))
echo $finishTimeStamp
