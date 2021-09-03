#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

struct TransactionData {
    string amount;
    string sendKey;
    string receiveKey;
    time_t timestamp;
};