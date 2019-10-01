#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define m_BL 2 // BACK LEFT   - digital
#define m_FL 3 // FRONT LEFT  - analog
#define m_BR 4 // BACK RIGHT  - digital
#define m_FR 9 // FRONT RIGHT - analog

#define u_echo 12 // Ultrasonic echo
#define u_trigger 13 // Ultrasonic trigger

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int display;

void setup() {  // put your setup code here, to run once:

  // set up motors
  pinMode(m_BL, OUTPUT);
  pinMode(m_FL, OUTPUT);
  pinMode(m_BR, OUTPUT);
  pinMode(m_FR, OUTPUT);

  // set up ultrasonic
  pinMode(u_echo, INPUT);
  pinMode(u_trigger, OUTPUT);

  // set up lcd
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  display = 0;
}



void loop() {
  int obstacle = UltraSonic(); // get obstacle distance
  if(obstacle < 20) {
    stop(); // stop
    turn(true, true); // turn (left, 90°)
  } else {
    go(100); // go with the speed 100
  }
  
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("dist: ");
  lcd.print(obstacle);
  delay(200);
}

int UltraSonic() { // get distance in cm (kinda)
  long duration;
  int distance;
  digitalWrite(u_trigger, LOW); 
  delayMicroseconds(2);
  digitalWrite(u_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(u_trigger, LOW);
  duration = pulseIn(u_echo, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}

void go(int speed) {
  analogWrite(m_FL, speed);
  analogWrite(m_FR, speed);
  analogWrite(m_BL, 0);
  analogWrite(m_BR, 0);
}

void turn(bool left, bool large) { // large = 90°    small = 45°
  int wait = 200;
  if(large)
    wait = 400;
  if(left) {
    analogWrite(m_FL, 0);
    analogWrite(m_FR, 100);
    analogWrite(m_BL, 200);
    analogWrite(m_BR, 0);
    delay(wait);
    analogWrite(m_FL, 0);
    analogWrite(m_FR, 0);
    analogWrite(m_BL, 0);
    analogWrite(m_BR, 0);
  } else {
    analogWrite(m_FL, 100);
    analogWrite(m_FR, 0);
    analogWrite(m_BL, 0);
    analogWrite(m_BR, 200);
    delay(wait);
    analogWrite(m_FL, 0);
    analogWrite(m_FR, 0);
    analogWrite(m_BL, 0);
    analogWrite(m_BR, 0);
  }
}

void stop() {
  digitalWrite(m_FL, LOW);
  digitalWrite(m_FR, LOW);
  digitalWrite(m_BL, LOW);
  digitalWrite(m_BR, LOW);
}
