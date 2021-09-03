#include <iostream>
#include "Block.h"
#include "BlockChain.h"
#include "TransactionData.h"
int main()
{
	Blockchain Privmessage;
	TransactionData msg1;
	time_t msg1Time;
	msg1.amount = "hello";
	msg1.receiveKey = "quin";
	msg1.sendKey = "Navid";
	msg1.timestamp = time(&msg1Time);
	Privmessage.addBlock(msg1);

	cout << "Is chain valid?" << endl;
	cout << Privmessage.isChainValid() << endl;
	return 0;
}
