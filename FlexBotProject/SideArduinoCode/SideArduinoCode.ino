#include <GSM.h>
#include <GSM3CircularBuffer.h>
#include <GSM3IO.h>
#include <GSM3MobileAccessProvider.h>
#include <GSM3MobileCellManagement.h>
#include <GSM3MobileClientProvider.h>
#include <GSM3MobileClientService.h>
#include <GSM3MobileDataNetworkProvider.h>
#include <GSM3MobileMockupProvider.h>
#include <GSM3MobileNetworkProvider.h>
#include <GSM3MobileNetworkRegistry.h>
#include <GSM3MobileServerProvider.h>
#include <GSM3MobileServerService.h>
#include <GSM3MobileSMSProvider.h>
#include <GSM3MobileVoiceProvider.h>
#include <GSM3ShieldV1.h>
#include <GSM3ShieldV1AccessProvider.h>
#include <GSM3ShieldV1BandManagement.h>
#include <GSM3ShieldV1BaseProvider.h>
#include <GSM3ShieldV1CellManagement.h>
#include <GSM3ShieldV1ClientProvider.h>
#include <GSM3ShieldV1DataNetworkProvider.h>
#include <GSM3ShieldV1DirectModemProvider.h>
#include <GSM3ShieldV1ModemCore.h>
#include <GSM3ShieldV1ModemVerification.h>
#include <GSM3ShieldV1MultiClientProvider.h>
#include <GSM3ShieldV1MultiServerProvider.h>
#include <GSM3ShieldV1PinManagement.h>
#include <GSM3ShieldV1ScanNetworks.h>
#include <GSM3ShieldV1ServerProvider.h>
#include <GSM3ShieldV1SMSProvider.h>
#include <GSM3ShieldV1VoiceProvider.h>
#include <GSM3SMSService.h>
#include <GSM3SoftSerial.h>
#include <GSM3VoiceCallService.h>

// use abhis circuit, create two pins that take in ground and positive input, and sensitivity from port 2/4, corresponding electrical lines put motor controller and motor, test out!
#include <Servo.h>


// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0; //A0 // Analog input pin that the potentiometer is attached to


int nval = 0;


void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop() {
  // read the analog in value:


 
  int nval = analogRead(analogInPin);
  Serial.println(nval);
  if (nval< 295 or nval > 311) {
    analogWrite(6, nval);
    Serialprintln(2);
    {
  
{