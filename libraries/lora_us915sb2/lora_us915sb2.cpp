#include "Arduino.h"
#include "lora_us915sb2.h"

LORA_US915SB2::LORA_US915SB2(String devaddr, String nwkskey, String appskey, String appeui, int pwridx){
  Serial.begin(57600);
  Serial1.begin(57600);
  _devaddr = devaddr;
  _nwkskey = nwkskey;
  _appskey = appskey;
  _appeui = appeui;
  _pwridx = pwridx;
}

void LORA_US915SB2::readRNresponse(){
  while(Serial1.available()){
    Serial.write(Serial1.read());
  }
}

void LORA_US915SB2::sendDataHex(String data){
  Serial1.print("mac tx uncnf 1 ");
  Serial1.println(data);
  Serial.print("Send \"");
  Serial.print(data);
  Serial.print("\": ");
  delay(10000);
  readRNresponse();
}

void LORA_US915SB2::joinABP(){
  Serial1.println("mac join abp");
  delay(200);
  Serial.print("Joining network (ABP): ");
  readRNresponse();
}

void LORA_US915SB2::configRN() {
  delay(2000);
  for(int i = 0; i<72; i++){
    Serial1.print("mac set ch status ");
    Serial1.print(i);
    Serial1.println(" off");
    delay(20);
    Serial.print("Channel ");
    Serial.print(i);
    Serial.print(" off: ");
    readRNresponse();
  }
  
  for(int i=8; i<16; i++){
  Serial1.print("mac set ch status ");
  Serial1.print(i);
  Serial1.println( " on");
  delay(20);
  Serial.print("Channel ");
  Serial.print(i);
  Serial.print(" on: ");
  readRNresponse();
  Serial1.print("mac set ch drrange ");
  Serial1.print(i);
  Serial1.println(" 0 3");
  delay(20);
  Serial.print("Channel ");
  Serial.print(i);
  Serial.print(" set 0-3 DR: ");
  readRNresponse();
  }
  delay(20);
  Serial1.println("mac set ch status 65 on");
  delay(20);
  Serial.print("Channel 65 on: ");
  readRNresponse();
  
  Serial1.println("mac set dr 3");
  delay(20);
  Serial.print("Set DR to 3: ");
  readRNresponse();
  
  Serial1.println("mac set adr 1");
  delay(20);
  Serial.print("Disable ADR: ");
  readRNresponse();
  
  Serial1.print("mac set pwridx ");
  Serial1.println(_pwridx);
  delay(20);
  Serial.print("Set TX power to ");
  Serial.print(_pwridx);
  Serial.print(": ");
  readRNresponse();
  
  Serial1.print("mac set devaddr ");
  Serial1.println(_devaddr);
  delay(20);
  Serial.print("Set device address to ");
  Serial.print(_devaddr);
  Serial.print(": ");
  readRNresponse();

  Serial1.print("mac set nwkskey ");
  Serial1.println(_nwkskey);
  delay(20);
  Serial.print("Set network session key to ");
  Serial.print(_nwkskey);
  Serial.print(": ");
  readRNresponse();
  
  Serial1.print("mac set appskey ");
  Serial1.println(_appskey);
  delay(20);
  Serial.print("Set application session key to ");
  Serial.print(_appskey);
  Serial.print(": ");
  readRNresponse();
  
  Serial1.print("mac set appeui ");
  Serial1.println(_appeui);
  delay(20);
  Serial.print("Set application EUI to ");
  Serial.print(_appeui);
  Serial.print(": ");
  readRNresponse();
  
  Serial1.println("mac save");
  Serial.print("Save config to memory: ");
  delay(1000);
  readRNresponse();
}