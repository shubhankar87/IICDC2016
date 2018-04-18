#include <SPI.h>
#include <AIR430BoostFCC.h>

// -----------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */

#define ADDRESS_LOCAL    0x01
char c[4];
int i[4],k,j;
/**
 *  sPacket - packet format.
 */
struct sPacket
{
  uint8_t from;           // Local node address that message originated from
  uint8_t message[59];    // Local node message [MAX. 59 bytes]
};

// -----------------------------------------------------------------------------
/**
 *  Global data
 */

struct sPacket rxPacket;

// -----------------------------------------------------------------------------
// Main example
char* rxd;
void setup()
{
  // The radio library uses the SPI library internally, this call initializes
  // SPI/CSn and GDO0 lines. Also setup initial address, channel, and TX power.
  Radio.begin(ADDRESS_LOCAL, CHANNEL_1, POWER_MAX);

  rxPacket.from = 0;
  memset(rxPacket.message, 0, sizeof(rxPacket.message));

  // Setup serial for debug printing.
  Serial.begin(9600);
  pinMode(P2_2,OUTPUT);
  pinMode(P2_3,OUTPUT);
  pinMode(P2_4,OUTPUT);
  pinMode(P2_5,OUTPUT);

  /**
   *  Setup LED for example demonstration purposes.
   *
   *  Note: Set radio first to ensure that GDO2 line isn't being driven by the 
   *  MCU as it is an output from the radio.
  
   */
 
  pinMode(RED_LED, OUTPUT);       // Use red LED to display message reception
  digitalWrite(RED_LED, LOW);
}

void loop()
{  // Turn on the receiver and listen for incoming data. Timeout after 1 seconds.
  // The receiverOn() method returns the number of bytes copied to rxData.
  if (Radio.receiverOn((unsigned char*)&rxPacket, sizeof(rxPacket), 1000) > 0)
  {
    digitalWrite(RED_LED, HIGH);
   Serial.print("FROM: ");
    Serial.print(rxPacket.from);

    Serial.print(" MSG: ");
    Serial.println((char*)rxPacket.message);
   digitalWrite(RED_LED, LOW);
rxd=(char*)rxPacket.message;
c[0] = *(rxd);
c[1] = *(rxd+1);
c[2] = *(rxd+2);
c[3] = *(rxd+3);

i[0]=c[0]-'0';
i[1]=c[1]-'0';
i[2]=c[2]-'0';
i[3]=c[3]-'0';
k=i[0]+i[1]+i[2]+i[3];
Serial.print(k);
if(k<2)
     {  if(rxPacket.from==2)
                {digitalWrite(P2_2,HIGH);
                delay(100);
                }
        else{digitalWrite(P2_3,HIGH);
             delay(100);
             }
     }
else
      {   if(rxPacket.from==2)
                {digitalWrite(P2_2,LOW);
                delay(100);
               }
          else{digitalWrite(P2_3,LOW);
              delay(100);
              }

      }

delay(1000);}}
