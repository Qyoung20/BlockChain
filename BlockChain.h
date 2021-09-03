#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
#include "Block.h"
class Blockchain {
private:
    Block createGenesisBlock();

public:
    //public chain
    vector<Block> chain;

    //Constructor
    Blockchain();

    //Public functions
    void addBlock(TransactionData data);
    bool isChainValid();

    //verify that validating block works
    Block getLatestBlock();
};