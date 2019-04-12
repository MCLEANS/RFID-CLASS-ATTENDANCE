/* Pin layout should be as follows:
   Signal     Pin              Pin               Pin
              Arduino Uno      Arduino Mega      MFRC522 board
   ------------------------------------------------------------
   Reset      9                5                 RST
   SPI SS     10               53                SDA
   SPI MOSI   11               51                MOSI
   SPI MISO   12               50                MISO
   SPI SCK    13               52                SCK

   The reader can be found on eBay for around 5 dollars. Search for "mf-rc522" on ebay.com.
*/

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "SoftwareSerial.h"



#define SS_PIN 10
#define RST_PIN 5

#define sendLed1 1
#define sendLed2 2

#define BUZZER 4
#define REDLED 3
#define GREENLED 6
#define YELLOWLED 7


String studentName = "";
String classList = "";
int studentsPresent = 0;
int totalStudents = 4;
//char num[] = "";

SoftwareSerial sms(5, 8);
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() {
  //Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();            // Init SPI bus
  lcd.begin();
  //----------------------------------
  sms.begin(9600);
  sms.print("AT+CMGF=1\r\n");
  delay(1000);
  //-----------------------------
  // Turn on the blacklight and print a message.
  lcd.backlight();
  mfrc522.PCD_Init(); // Init MFRC522 card
  Serial.println("Scan PICC to see UID and type...");
  lcd.print("ATTENDANCE");
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");

  //-----------PINMODE------------------------------------
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(sendLed1, OUTPUT);
  pinMode(sendLed2, OUTPUT);

  //---------------------------------------------------
  delay(3000);
  lcd.clear();
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print("STDNTS PRSNT:");
  lcd.setCursor(14, 0);
  lcd.print(studentsPresent);
  lcd.setCursor(0, 1);
  lcd.print("STDNTS ABSNT:");
  lcd.setCursor(14, 1);
  lcd.print(totalStudents - studentsPresent);


  // Look for new cards

  digitalWrite(YELLOWLED, HIGH);
  if (!mfrc522.PICC_IsNewCardPresent()) {

    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {

    return;
  }

  if (mfrc522.uid.uidByte[0] == 0x86 &&
      mfrc522.uid.uidByte[1] == 0xBE &&
      mfrc522.uid.uidByte[2] == 0x3E &&
      mfrc522.uid.uidByte[3] == 0x1F) {

        
    
    digitalWrite(YELLOWLED, LOW);
    
    studentName = "VIVIAN MORRIS";
    if(classList.indexOf(studentName)>=0){
      digitalWrite(REDLED, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("EXISTS");
      statusInvalid();
    }
    else{
      digitalWrite(GREENLED, HIGH);
          studentsPresent++;
    classList += studentsPresent;
    classList += "->";
    classList += studentName;
    classList += ",";
    Serial.print("Class List=>");
    Serial.println(classList);
    Serial.println(studentName);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(studentName);
    statusOk();
      
    }

    
    digitalWrite(REDLED, LOW);
    digitalWrite(GREENLED, LOW);
  }
  else if (mfrc522.uid.uidByte[0] == 0x26 &&
           mfrc522.uid.uidByte[1] == 0x87 &&
           mfrc522.uid.uidByte[2] == 0x78 &&
           mfrc522.uid.uidByte[3] == 0xF1) {
    
    digitalWrite(YELLOWLED, LOW);
    
    studentName = "ANITA JONES";
        if(classList.indexOf(studentName)>=0){
          digitalWrite(REDLED, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("EXISTS");
      statusInvalid();
    }
    else{
      digitalWrite(GREENLED, HIGH);
          studentsPresent++;
    classList += studentsPresent;
    classList += "->";
    classList += studentName;
    classList += ",";
    Serial.print("Class List=>");
    Serial.println(classList);
    Serial.println(studentName);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(studentName);
      statusOk();
    }
    
digitalWrite(REDLED, LOW);
    digitalWrite(GREENLED, LOW);
  }

  else if (mfrc522.uid.uidByte[0] == 0x5B &&
           mfrc522.uid.uidByte[1] == 0x1F &&
           mfrc522.uid.uidByte[2] == 0xFA &&
           mfrc522.uid.uidByte[3] == 0x9B) {
    
    digitalWrite(YELLOWLED, LOW);
   
    studentName = "SHEILA AMANDA";
       if(classList.indexOf(studentName)>=0){
        digitalWrite(REDLED, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("EXISTS");
      delay(1000);
      statusInvalid();
    }
    else{
      digitalWrite(GREENLED, HIGH);
          studentsPresent++;
    classList += studentsPresent;
    classList += "->";
    classList += studentName;
    classList += ",";
    Serial.print("Class List=>");
    Serial.println(classList);
    Serial.println(studentName);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(studentName);
     statusOk(); 
    }
    

  digitalWrite(REDLED, LOW);
    digitalWrite(GREENLED, LOW);
  }
  else if (mfrc522.uid.uidByte[0] == 0x5B &&
           mfrc522.uid.uidByte[1] == 0xE5 &&
           mfrc522.uid.uidByte[2] == 0xF8 &&
           mfrc522.uid.uidByte[3] == 0xD5) {
    
    digitalWrite(YELLOWLED, LOW);
    
    studentName = "JASON SMITH";
       if(classList.indexOf(studentName)>=0){
        digitalWrite(REDLED, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("EXISTS");
      statusInvalid();
    }
    else{
      digitalWrite(GREENLED, HIGH);
          studentsPresent++;
    classList += studentsPresent;
    classList += "->";
    classList += studentName;
    classList += ",";
    Serial.print("Class List=>");
    Serial.println(classList);
    Serial.println(studentName);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(studentName);
      statusOk();
    }
    

    digitalWrite(REDLED, LOW);
    digitalWrite(GREENLED, LOW);
  }
  else if (mfrc522.uid.uidByte[0] == 0x54 &&
           mfrc522.uid.uidByte[1] == 0x95 &&
           mfrc522.uid.uidByte[2] == 0x54 &&
           mfrc522.uid.uidByte[3] == 0xD3) {
    //-----------------------SMS-------
    digitalWrite(sendLed1,HIGH);
    digitalWrite(sendLed2,LOW);
    delay(200);
    digitalWrite(sendLed1,LOW);
    digitalWrite(sendLed2,HIGH);
    delay(200);
        digitalWrite(sendLed1,LOW);
    digitalWrite(sendLed2,LOW);
    
    Serial.print("Sending sms==>> ");
    Serial.println(classList);
    statusOk();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SUBMITTING LIST");
    sms.println("AT+CMGS=\"+2547********\""); // RECEIVER: change the phone number here with international code
    delay(500);
    sms.println("CLASSLIST");
    sms.print(classList);


    sms.write( 0x1a );
    digitalWrite(sendLed1,HIGH);
    digitalWrite(sendLed2,HIGH);
    delay(2000);
    //-------------------------------
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LIST SENT");
    delay(2000);

        digitalWrite(sendLed1,LOW);
    digitalWrite(sendLed2,LOW);

    //-------------------------------

  }
  else {
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(REDLED, HIGH);
    studentName = "NON STUDENT";
    Serial.println(studentName);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(studentName);
    statusInvalid();
    digitalWrite(REDLED, LOW);

  }

  if (studentsPresent > 4) studentsPresent = 4;
  delay(100);

  lcd.clear();
}
void statusOk() {
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
}
void statusInvalid() {
  digitalWrite(BUZZER, HIGH);
  delay(500);
  digitalWrite(BUZZER, LOW);

}
