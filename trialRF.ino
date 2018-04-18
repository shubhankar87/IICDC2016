#include <SPI.h>
#include <AIR430BoostFCC.h>

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

// Data to write to radio TX FIFO (60 bytes MAX.)
unsigned char txData[5] = { 0x03, '0', '0', '0', '0'};


int j,k,l,m;

//void printTxData()
//{
//  Serial.print("TX (DATA): ");
//  Serial.println((char*)txData); 
//}


// -----------------------------------------------------------------------------
// Main example

void setup()
{
  
  // The radio library uses the SPI library internally, this call initializes
  // SPI/CSn and GDO0 lines. Also setup initial address, channel, and TX power.
  Radio.begin(0x01, CHANNEL_1, POWER_MAX);

  // Setup serial for debug printing.
  Serial.begin(9600);
  
pinMode(P2_0,INPUT);
pinMode(P2_1,INPUT);
pinMode(P2_2,INPUT);
pinMode(P2_3,INPUT);
}

void loop()
{
  Radio.transmit(ADDRESS_BROADCAST, txData, 5);
 

if(digitalRead(P2_0)==HIGH)
{j=1;}

else
{j=0;}

if(digitalRead(P2_1)==HIGH){k=1;}

else{k=0;}


if(digitalRead(P2_2)==HIGH){l=1;}

else{l=0;}



if(digitalRead(P2_3)==HIGH){m=1;}

else{m=0;}
 
  if(j==1)
 {txData[1]='1';}
 else{
  txData[1]='0';
  }

 if(k==1)
 {txData[2]='1';}
 else{
  txData[2]='0';
  }
  
 if(l==1)
 {txData[3]='1';}
 else{
  txData[3]='0';
  }
  
if(m==1)
 {txData[4]='1';}
 else{
  txData[4]='0';
  }
  
  
  delay(500);
}


