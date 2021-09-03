#include "TransactionData.h"
#include "Block.h"

Block::Block(int idx, TransactionData D, size_t prevHash) {
	index = idx;
	data = D;
	previousHash = prevHash;
	blockHash = generateHash();
}
size_t Block::getHash() {
	return blockHash;
}
size_t Block::getPreviousHash() {
	return previousHash;
}
size_t Block::generateHash() {
	hash<string> hash1;
	hash<size_t> hash2;
	hash<size_t> finalHash;
	string toHash = /*to_string*/(data.amount) + data.receiveKey + data.sendKey + to_string(data.timestamp);
	return finalHash(hash1(toHash) + hash2(previousHash));
}
bool Block::isHashValid() {
	return generateHash() == blockHash;
}
