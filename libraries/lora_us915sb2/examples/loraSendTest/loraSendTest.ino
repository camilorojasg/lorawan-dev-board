//Library and sketch by HomeNode.co
//US915 subband 2

#include "lora_us915sb2.h"

LORA_US915SB2 loraModule(
              "065105dc", //Device Address
              "3ca2e28da70d10b46db6a00c398a8f52", //Network Session Key
              "5da350da1fdf755d2b5be7cb531f5709", //App. Session Key
              "0000000000000001", //App. EUI
              10 //Power index from 5 to 10
);

void setup() {
}

void loop() {
  loraModule.configRN(); //Run once, then you can comment this line out, if there is no changes in activation data.
  delay(1000);
  
  loraModule.joinABP();
  delay(1000);
  
  while(1){
    loraModule.sendDataHex("0123456789ABCDEF"); //Send HEX string
  }
}
