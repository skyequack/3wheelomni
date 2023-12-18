#include <math.h>


  int d1 = 2;
  int p1 = 3;
  int d2 = 4;
  int p2 = 5;
  int d3 = 6;
  int p3 = 7;

  // front motor M1 : [dir:2, pwm:3]
  // left  motor M2 : [dir:4, pwm:5]
  // right motor M3 : [dir:6, pwm:7]

void setup() {

  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {

  int netAngle;
  int velocity;

  if (Serial.available() > 0) {

    netAngle = Serial.parseInt();
    velocity = Serial.parseInt();

    Serial.print("Net Angle: ");
    Serial.print(netAngle);
    Serial.print(", Velocity: ");
    Serial.println(velocity);

    omni3wheel(netAngle, velocity);
  }
}

void omni3wheel(int angle, int speed) {

  // Convert angle to radians

  float radianAngle = angle * PI / 180.0;

  // Calculate individual motor speeds based on omnibot control equations

  int m1 = speed * cos(radianAngle - PI/3);
  int m2 = speed * cos(radianAngle + PI/3);
  int m3 = speed * cos(radianAngle + 2*PI/3);

  // Set motor speeds

  analogWrite(p1,abs(m1));
  analogWrite(p2,abs(m2));
  analogWrite(p3,abs(m3));

  // Set motor directions based on input angle
  if (m1 >= 0) 
  digitalWrite(d1,HIGH);
  else digitalWrite(d1,LOW);

  if (m2 >= 0) 
  digitalWrite(d2,HIGH);
  else digitalWrite(d2,LOW);

  if (m1 >= 0) 
  digitalWrite(d3,HIGH);
  else digitalWrite(d3,LOW);
}
