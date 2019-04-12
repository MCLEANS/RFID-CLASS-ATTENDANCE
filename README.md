# RFID BASED CLASS ATTENDANCE SYSTEM

### COMPONENTS
	RFID RC522 
	RFID TAGS
	ARDUINO UNO
	LEDs
	GSM SIM 800L
	16X2 LCD DISPLAY

### PIN CONFIGURATION

	 Signal     Pin              Pin               Pin
              Arduino Uno      Arduino Mega      MFRC522 board
   
      Reset      9                5                 RST
      SPI SS     10               53                SDA
      SPI MOSI   11               51                MOSI
      SPI MISO   12               50                MISO
      SPI SCK    13               52                SCK
   	
      N/B : The RFID module operates on 3.3V



   	ARDUINO 		GSM
   	GND				GND
   	VCC				VCC
   	RX				TX
   	TX 				RX

   	ARDUINO 		LCD
   	GND 			GND
   	VCC 			VCC
   	A4				SDA
   	A5				SCL


### OPERATION

Each student is issued with an RFID tag whose unique ID is entered into the system and matched with the students details.
The teacher also has a master RFID tag that compiles the classlist and sends it to the teacher via SMS through the GSM module.

When a student enters the class at the begining of the lesson they tap their card onto the RFID reader where they are marked as present as their details are shown on the LCD screen.Once all the students have checked in and are settled in class the lecturer then taps he's/her tag, at this point the checkin period is closed for the students and the generated classlist is sent to the lecturer and the respective Head of Department via SMS.