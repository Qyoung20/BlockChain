#include "BlockChain.h"
//BlockChain constructor
Blockchain::Blockchain() {
	Block genesis = createGenesisBlock();
	chain.push_back(genesis);
}
Block Blockchain::createGenesisBlock() {
	//current timestamp
	time_t current;
	TransactionData d;
	d.amount = "None";
	d.receiveKey = "None";
	d.sendKey = "None";
	//pointer to current time
	d.timestamp = time(&current);
	hash<int> hash1;
	Block genesis(0, d, hash1(0));
	return genesis;
}
//get latest 
//return a pointer 
//refence in memory. gives memory address
//use this to manipulate data inside memory adress
Block Blockchain::getLatestBlock() {
	return chain.back();
}
void Blockchain::addBlock(TransactionData d) {
	int index = (int)chain.size() - 1;
	Block newBlock(index, d, getLatestBlock().getHash());
}
bool Blockchain::isChainValid() {
	//iterator that iterates over type block
	vector<Block>::iterator it;
	int chainLength = (int)chain.size();
	//from begining of chain until chain is at the end 
	for (it = chain.begin(); it != chain.end(); ++it) {
		Block currentBlock = *it;
		//block not valid return false
		if (!currentBlock.isHashValid()) {
			return false;
		}
		//if chain has a length greater than 1 check if previous block's hash does not equal the current blocks previous hash.
		//Meaning: currents blocks previous hash !=previous blocks current hash
		if (chainLength > 1) {
			Block previousBlock = *(it - 1);
			if (currentBlock.getPreviousHash() != previousBlock.getHash()) {
				return false;
			}
		}
	}
	return true;
}