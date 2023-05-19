#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

#include <common/json_lib/json11.hpp>
#include "basic_server/database.h"
#include "system_schema.h"
#include "ProofRequest.pb.h"

// for transfer subgraph
// In test context, there are two users only 0x1, 0x2
class Transfer {
   public:
    std::string hash;
    std::string contract_address;

    std::string sender;
    std::string receiver;

    uint64_t value;
    uint64_t timestamp;

    bool operator<(const Transfer& t1) const {
        if (this->timestamp < t1.timestamp) {
            return true;
        }
        return false;
    }
};


class MockDatabase : public MockSystemDatabase {

public:
    void insertTransferItem(Transfer* transfer) {
        transfer_hash_index.insert({transfer->hash, transfer});
        transfer_contract_address_index.insert(
            {transfer->contract_address, transfer});
        trnasfer_sender_index.insert({transfer->sender, transfer});
        transfer_receiver_index.insert({transfer->receiver, transfer});
        transfers.insert(*transfer);
    }

    Transfer* GetTransferByHash(std::string& hash) {
        return transfer_hash_index[hash];
    }

    Transfer* GetTransferByContractAddress(std::string& contract_address) {
        return transfer_contract_address_index[contract_address];
    }

    Transfer* GetTransferBySender(std::string& sender) {
        return trnasfer_sender_index[sender];
    }

    Transfer* GetTransferByReceiver(std::string& receiver) {
        return transfer_receiver_index[receiver];
    }

    // transfers index by hash, contract_address, sender and receiver
    std::map<std::string, Transfer*> transfer_hash_index;
    std::map<std::string, Transfer*> transfer_contract_address_index;
    std::map<std::string, Transfer*> trnasfer_sender_index;
    std::map<std::string, Transfer*> transfer_receiver_index;

    // transfer container ordered by timestamp
    std::set<Transfer> transfers;
    // std::string subgraph_name_;
};

