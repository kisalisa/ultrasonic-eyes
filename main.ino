    
int trigPin = 9;
int echoPin = 10;
int vibPin1 = 7;
int vibPin2 = 8;
int vibPin3 = 11;

//defines which pins the sensor and motors are on
//below are the sensor’s pins, and where they connect on the arduino board
//vcc-5v
//gnd-gnd
//echo-10
//trig-9

void setup() {
  Serial.begin(9600);
//sets the data rate in bits per second, this is the most common setting
  pinMode(vibPin1, OUTPUT);
  pinMode(vibPin2, OUTPUT);
  pinMode(vibPin3, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//the sensor and motor pins are being defined as input/output

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
/*the purpose of the trigPin on the sensor is to send a “ping” that starts 
the sensor’s sequence of emitted pulses, so it must be told to turn on and off, 
to keep searching for objects; trigPin searches in a distance units,
and runs the entire time the board is connected to a power supply*/
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
/*distance = change in time divided by two, 
all divided by pace of sound, which is 29.1 ss(speed of sound) per cm*/

//turns all motors off from last loop
digitalWrite(vibPin1, LOW);
digitalWrite(vibPin2, LOW);
digitalWrite(vibPin3, LOW);

//turns on specific motors
//if dist is greater than or equal to 291.12cm, 1 motor turns on
//about 10 feet
  if ((distance >= 291.12))
  {
    digitalWrite(vibPin1, HIGH);
  }
//if dist is less than 291.12cm and greater than 181.12cm, 2 motors turn on
  else if ((291.12 > distance > 181.12))
  {
    digitalWrite(vibPin2, HIGH);
    digitalWrite(vibPin1, HIGH);
  }
//if dist is less than or equal to 181.12, 3 motors turn on
//about 6 feet
  else if ((distance <= 181.12))
    {
     digitalWrite(vibPin3, HIGH);
     digitalWrite(vibPin2, HIGH);
     digitalWrite(vibPin1, HIGH);
    }
}
  
  
