#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
#include "TransactionData.h"
class Block {
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();

public:
    //constructor
    Block(int idx, TransactionData D, size_t prevHash);

    //get origional hash
    size_t getHash();

    //get previous hash
    size_t getPreviousHash();

    //transaction data
    TransactionData data;

    //validate Hash
    bool isHashValid();
};