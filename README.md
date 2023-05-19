# 1. TxSpec - A Programable InterchainNFT Protocol

With ICS-721，now NFTs can be easily transferred between different ICS-721 compatible blockchain. Nevertheless, a challenge remains: we are unable to transfer the programming logic of the NFT.

Suppose a critical in-game item exists, such as an NFT-based 'Extra Life Coin' similar to the one in 'Ready Player One'. This item can be used across various game platforms on different appchains but only once. However, discarding it after use is not desirable.

In such a case, we want to transfer the NFT and its programming logic, as the latter is set up for a one-time use only.

With TxSpec, we can easily accomplish this task.

# 2. Architecture of TxSpec
![TxSpec](https://github.com/1654574171/irishub/blob/main/picture/txspec-whole.png)
## 2.1 TxSpec Module
TxSpec Module is an application module developed on irisnet, built with the Cosmos SDK, which  can be utilized for interchain NFT transactions as well as general transactions. Its functionality includes  establishing transaction rules, registering TxSpec, and persisting the rules and TxSpec node information on the blockchain. Additionally, it performs appropriate actions based on the calculated rule results from TxSpec.

## 2.2 Rule Language
Rule Language is a human-readable domain-specific language used to write interchainNFT programming logic.

## 2.3 TxSpec Relayer
TxSpec Relayer is a component developed based on the Cosmos Relayer that enables the subscribing and relaying of transaction events/messages. It listens to transaction events on Irisnet that have transaction rules established, notifies TxSpec to perform rule calculation on the transactions, and relays the off-chain calculation results back to the chain.

## 2.4 TxSpec Engine
The TxSpec Engine is an off-chain rule language interpreter that leverages SGX technology to securely process sensitive data. It utilizes the graph's services to query on-chain data and the relevant transaction rule language file.

# 3. Basic Process of TxSpec

In order to make use of Txspec, we must first propose four types of proposals to the chain. These four types of proposals are implemented using the TxSpec module.
1. Relation-proposal
The purpose of the relation-proposal is to indicate the connection between the module and binding.
2. Binding-proposal
The binding-proposal serves the purpose of establishing a link between event and rule files.
3. Rule-proposal
The rule-proposal is utilized to upload the rule language file that consists of the necessary programming logic for interchainNFT.
4. TxSpec-proposal
TxSpec-proposal is used to registe the txspec service to the chain.

![proposal](https://github.com/1654574171/irishub/blob/main/picture/proposal.png)

After that, once the event of an interchainNFT transaction has been accepted by the TxSpec Relayer, the TxSpec Engine will be automatically called  to handle it. The TxSpec engine produces a result based on the logic defined in the rule language file. The TxSpec Relayer is responsible for uploading the result to the chain and storing it in the state of the TxSpec Module.

![transaction](https://github.com/1654574171/irishub/blob/main/picture/basic-procedure.png)

# 4. A simple case
[demo vedio](https://www.youtube.com/video/bvVBg1DeVsQ/edit)
