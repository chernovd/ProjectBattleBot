const int switch = 2; // switch input

const int motor1 = 3; // H-bridge leg 1 (pin 2, 1A)

const int motor2= 4; // H-bridge leg 2 (pin 7, 2A)

const int enable = 9; // H-bridge enable pin

void setup() {

// set the switch as an input:

pinMode(switch, INPUT);

pinMode(12,OUTPUT);

pinMode(A0,INPUT);

// set all the LOWother pins you’re using as outputs:

pinMode(motor1, OUTPUT);

pinMode(motor2, OUTPUT);

pinMode(enable, OUTPUT);

// set enable high so that motor can turn on:

digitalWrite(enable, HIGH);

  }

    void loop() 
    {

// if the switch is high, motor will turn on one direction:

  if (analogRead(A0)>0)

  {

  digitalWrite(motor2, LOW);
  
  digitalWrite(motor1, LOW);

  } // set leg 1 of the H-bridge low

  else

  {

  digitalWrite(motor1, HIGH);
  
  digitalWrite(motor2, LOW);

  }

}
