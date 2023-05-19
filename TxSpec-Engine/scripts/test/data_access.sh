echo "insert data for compliance-engine integration test"
mysql --host=127.0.0.1 --port=33006 --user=root --password=123456 << EOF
CREATE DATABASE IF NOT EXISTS reg_data_access
    DEFAULT CHARACTER SET utf8;
use reg_data_access;

CREATE TABLE IF NOT EXISTS binding (
        _channel_id VARCHAR(100) NOT NULL,
        _chaincode_id VARCHAR(128) NOT NULL,
        _file_content TEXT,
        _block_num BIGINT NOT NULL,
        _tx_index INT NOT NULL,
        _self_version VARCHAR(16),
        _timestamp TIMESTAMP
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS rule (
        _channel_id VARCHAR(100) NOT NULL,
        _rule_file_name VARCHAR(64) NOT NULL,
        _file_content TEXT,
        _block_num BIGINT NOT NULL,
        _tx_index INT NOT NULL,
        _self_version VARCHAR(16),
        _timestamp TIMESTAMP
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO binding VALUES (
 "mychannel",
    "OXTokenContractTest",
    "Contract is DABERC20
Datas{
transfer.from -> Transfer.Sender
transfer.to -> Transfer.Receiver
transfer.value -> Transfer.Value
}
Rules{
function Transfer -> [ERC20@single_transfer_limit]
}",
1,
0,
"0.0.1",
"2020-07-02 00:00:00"
);

INSERT INTO rule VALUES (
 "mychannel",
    "ERC20",
    "regulation erc20
entities {
 entity Transfer {
  Originator
  Sender
  Receiver
  Value is number
 }
 
}
rules {
 rule single_transfer_limit {
  0 < Transfer.Value <= 20,000
 }
}",
 2,
    0,
    "0.0.1",
    "2021-07-02 00:00:01"
);

exit
EOF
echo "insertion completed"
