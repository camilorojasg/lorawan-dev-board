#ifndef LORA_US915SB2_H
#define LORA_US915SB2_H

#include "Arduino.h"

class LORA_US915SB2{
public:
	LORA_US915SB2(String devaddr, String nwkskey, String appskey, String appeui, int pwridx);
	void joinABP();
	void configRN();
	void sendDataHex(String data);

private:
	String _devaddr;
	String _nwkskey;
	String _appskey;
	String _appeui;
	int _pwridx;
	void readRNresponse();
};

#endif