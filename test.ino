/**
 *  ----------------------------------------------------------------------------
 *  WirelessTest.ino - test transceiver sketch using AIR430Boost ETSI driver.
 *  Copyright (C) 2012-2013 Anaren Microwave, Inc.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 * 
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 * 
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 *  This example demonstrates usage of the AIR430BoostETSI library which uses
 *  the 430Boost-CC110L AIR Module BoosterPack created by Anaren Microwave, Inc.
 *  and available through the TI eStore, for the European Union.
 *
 *  ----------------------------------------------------------------------------
 *
 *  Note: This file is part of AIR430Boost.
 *
 *  ----------------------------------------------------------------------------
 *
 *  Description
 *  ===========
 *
 *  Each radio will send a message consisting of: 1 byte counter, 5 byte static 
 *  text. The counter will count from 0 to 9 and will rollover. Each radio will 
 *  wait in receive mode for approximately one second. Upon receiving data, or 
 *  timeout of one second, the radio receive function will return. If valid data 
 *  was received, the radio's receiverOn() method will return the number of bytes
 *  that were received. In this example, the data can be monitored on the serial 
 *  port (please refer to printTxData() and printRxData() functions).
 *
 *  ----------------------------------------------------------------------------
 * 
 *  This example assumes that two BoosterPacks will be used to showcase the 
 *  wireless radio communication functionality. This same code should be 
 *  programmed to both LaunchPad development kits.
 *
 *  This BoosterPack relies on the SPI hardware peripheral and two additional 
 *  GPIO lines for SPI chip-select and GDO0 for packet handling. They use pins 18 
 *  and 19 respectively. 
 *
 *  In the default configuration, this BoosterPack is not compatible with an 
 *  external crystal oscillator. This can be changed, if necessary, and would
 *  require reconfiguration of the BoosterPack hardware and changes to the 
 *  AIR430BoostETSI library. Refer to the BoosterPack User's Manual if necessary.
 *
 *  ETSI regulations must be followed when using this library. This example 
 *  limits the wireless duty cycle to 0.1% per ETSI.
 *
 *  For complete information, please refer to the BoosterPack User's Manual 
 *  available at:
 *  https://www.anaren.com/air/cc110l-air-module-boosterpack-embedded-antenna-module-anaren
 *  
 *  To purchase the 430Boost-CC110L AIR module BoosterPack kit, please visit the 
 *  TI eStore at:
 *  https://estore.ti.com/430BOOST-CC110L-CC110L-RF-Module-BoosterPack-P2734.aspx
 */

// The AIR430BoostETSI library uses the SPI library internally. Energia does not
// copy the library to the output folder unless it is referenced here.
// The order of includes is also important due to this fact.
#include <SPI.h>
#include <AIR430BoostETSI.h>

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

// Data to write to radio TX FIFO (60 bytes MAX.)
unsigned char txData[5] = { 0x03, '0', '0', '0', '0'};

float Htime1=0;
float Ltime1=0;
float Ttime1=0;
float frequency1;
float capacitance1;

float Htime2=0;
float Ltime2=0;
float Ttime2=0;
float frequency2;
float capacitance2;

float Htime3=0;
float Ltime3=0;
float Ttime3=0;
float frequency3;
float capacitance3;

float Htime4=0;
float Ltime4=0;
float Ttime4=0;
float frequency4;
float capacitance4;

int j,k,l,m;

void printTxData()
{
  Serial.print("TX (DATA): ");
  Serial.println((char*)txData); 
}


// -----------------------------------------------------------------------------
// Main example

void setup()
{
  
  // The radio library uses the SPI library internally, this call initializes
  // SPI/CSn and GDO0 lines. Also setup initial address, channel, and TX power.
  Radio.begin(0x01, CHANNEL_1, POWER_MAX);

  // Setup serial for debug printing.
  Serial.begin(9600);
  
  /**
   *  Setup LED for example demonstration purposes.
   *
   *  Note: Set radio first to ensure that GDO2 line isn't being driven by the 
   *  MCU as it is an output from the radio.
   */
  // set the LED on
pinMode(P2_0,INPUT);
pinMode(P2_1,INPUT);
pinMode(P2_2,INPUT);
pinMode(P2_3,INPUT);
}

void loop()
{
  // Load the txData into the radio TX FIFO and transmit it to the broadcast
  // address.
  Radio.transmit(ADDRESS_BROADCAST, txData, 5);
 
 for(int i=0;i<5;i++)
  {

  Ltime1+=pulseIn(P2_0,HIGH);
  Htime1+=pulseIn(P2_0,LOW);
  }
  
Ltime1/=5;
Htime1/=5;

Ttime1=Htime1+Ltime1;
frequency1=1000000/Ttime1;

capacitance1=(1044*1000000)/(20800*frequency1);
capacitance1/=0.067;
Serial.print(capacitance1);
Serial.print("pF\n");
delay(500);

if(capacitance1>=425)
{j=1;}

else
{j=0;}

Htime1=0;
Ltime1=0;

 for(int i=0;i<5;i++)
  {

  Ltime2+=pulseIn(P2_1,HIGH);
  Htime2+=pulseIn(P2_1,LOW);
  }
  
Ltime2/=5;
Htime2/=5;

Ttime2=Htime2+Ltime2;
frequency2=1000000/Ttime2;

capacitance2=(1044*1000000)/(20800*frequency2);
capacitance2/=0.067;
Serial.print(capacitance2);
Serial.print("pF\n");
delay(500);

if(capacitance2>=425){k=1;}

else{k=0;}


Htime2=0;
Ltime2=0; 
 
for(int i=0;i<5;i++)
  {

  Ltime3+=pulseIn(P2_2,HIGH);
  Htime3+=pulseIn(P2_2,LOW);
  }
  
Ltime3/=5;
Htime3/=5;

Ttime3=Htime3+Ltime3;
frequency3=1000000/Ttime3;

capacitance3=(1044*1000000)/(20800*frequency3);
capacitance3/=0.067;
Serial.print(capacitance3);
Serial.print("pF\n");
delay(500);

if(capacitance3>=425){l=1;}

else{l=0;}


Htime3=0;
Ltime3=0;


for(int i=0;i<5;i++)
{

  Ltime4+=pulseIn(P2_3,HIGH);
  Htime4+=pulseIn(P2_3,LOW);
}
  
Ltime4/=5;
Htime4/=5;

Ttime4=Htime4+Ltime4;
frequency4=1000000/Ttime4;

capacitance4=(1044*1000000)/(20800*frequency4);
capacitance4/=0.067;
Serial.print(capacitance4);
Serial.print("pF\n");
delay(500);

if(capacitance4>=425){m=1;}

else{m=0;}


Htime4=0;
Ltime4=0;
 
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
  
  printTxData();                    // TX debug information
  
  delay(500);


}


