/*
   Robot Motor Setup
          Front
  Left  A        B    Right
        C        D
           Back
  Forward = A+ B+ C+ D+
  Backward = A- B- C- D-
  Left = B+ D+ A- C-
  Right = A+ C+ B- D-
*/

//Change to true if auto mode is desired
bool isAuto = true;

//Sonic Sensor Variables
const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 8; // Echo Pin of Ultrasonic Sensor

//Motor A Variables
const int enA = 6;
const int in1 = 5;
const int in2 = 4;
int speedA = 200;

//Motor B Variables
const int in3 = 3;
const int in4 = 2;
const int enB = 1;
int speedB = 200;

void setup() {
  Serial.begin(9600); // Starting Serial Terminal

  pinMode(enA, OUTPUT);//Sets up pin for motor
  pinMode(enB, OUTPUT);//Sets up pin for motor
  pinMode(in1, OUTPUT);//Sets up pin for motor
  pinMode(in2, OUTPUT);//Sets up pin for motor
  pinMode(in3, OUTPUT);//Sets up pin for motor
  pinMode(in4, OUTPUT);//Sets up pin for motor
}

void loop() {
  long duration, inches, cm; //Sonic Sensor (ss) Distance Variables
  pinMode(pingPin, OUTPUT); //ss setup
  digitalWrite(pingPin, LOW); //ss setup
  delayMicroseconds(2); //Waits 2 ms
  digitalWrite(pingPin, HIGH); //Sonic Sensor sends out a ping (It sends a sound wave out)
  delayMicroseconds(10); //Waits 10 ms
  digitalWrite(pingPin, LOW); //Sonic Sensor stops sending
  pinMode(echoPin, INPUT); //SS setup for reading the distance
  duration = pulseIn(echoPin, HIGH); //Sonic Senor has its information stored in a variable 'duration'
  //This is the link to the tutorial I used when learning the ultrasonic senor. The sensor sends out a sound wave that then we record how long it takes to return. https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
  inches = duration / 74 / 2; //Calculations for the Data from the ss to be converted to Inches
  cm = duration / 29 / 2; //Calculations for the Data from the ss to be converted to Centimeters

  if (inches <= 4)  {
    //Turn on B+
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    //Turn on A-
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("TURN");
  }
  else if (inches <= 6 && inches > 4) {
    //Turn on A-
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    //Turn on B-
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("BACK");
  }
  else if (inches <= 20 && inches > 6) {
    //Turn on A+
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    //Turn on B+
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("GO");
  }
  else if (inches > 20)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  delay(100); //Waits 100 ms
}

/*
  Forward = A+ B+
  Backward = A- B-
  Left = B+ A-
  Right = A+ B- */

  //Turn on A+
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speedA);
  //Turn on B+
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speedB);

  //Turn on A-
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //Turn on B-
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  //Turn Stop Motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  //Turn on B+
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //Turn on A-
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  //Turn on A+
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //Turn on B-
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
