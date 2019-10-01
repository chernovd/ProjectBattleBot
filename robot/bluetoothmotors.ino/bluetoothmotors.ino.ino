#define RxD A0 // Get receiving pin
#define TxD A1 // Get transmitting pin
#include <SoftwareSerial.h>
#define m_BL 2 // BACK LEFT   - digital
#define m_FL 3 // FRONT LEFT  - analog
#define m_BR 4 // BACK RIGHT  - digital
#define m_FR 9 // FRONT RIGHT - analog

SoftwareSerial serial = SoftwareSerial(RxD,TxD); // Setting up software serial

void setup() {
    serial.begin(38400); // Starting software serial
    Serial.begin(9600);
    Serial.println("Initialized");
     // set up motors
  pinMode(m_BL, OUTPUT);
  pinMode(m_FL, OUTPUT);
  pinMode(m_BR, OUTPUT);
  pinMode(m_FR, OUTPUT);
}

void loop() {
  String motors = "";
    while (serial.available() > 0) {
      motors.concat((char)serial.read());
    }
    if(motors != ""){
    if (motors == "1"){
      digitalWrite(m_FL, HIGH);
      digitalWrite(m_FR, HIGH);
      Serial.write("Motor starting");
    } else{
      digitalWrite(m_FL, LOW);
      digitalWrite(m_FR, LOW);
       Serial.write("Motor ending ");
    }
    Serial.print(motors);
    }
    delay(20);
}
