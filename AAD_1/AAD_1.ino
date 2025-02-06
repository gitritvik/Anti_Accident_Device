#include <AFMotor.h>  // Indcluding libraray for the moter driver

const int trigPin = A0;  //defining A0 to read anolog data from us sensor
const int echoPin = A2;  //defining A1 to read anolog data from us sensor
const int buzzer = 7;  // defined pin for buzzer
const int ledPin = 9;  //defined pin for led

long duration;      //defined variable for store duration
int distance;      //defined variable to store distance

AF_DCMotor motor1(1, MOTOR12_1KHZ);  //defining moter 1 of arduino shield
AF_DCMotor motor2(2, MOTOR12_1KHZ);  //defining moter 2 of arduino shield
AF_DCMotor motor3(3, MOTOR12_1KHZ);  //defining moter 3 of arduino shield
AF_DCMotor motor4(4, MOTOR12_1KHZ);  //defining moter 4 of arduino shield

 

void setup() 

{  
  
  pinMode(trigPin, OUTPUT);  // defining trigpin as output
  pinMode(echoPin, INPUT);   // defining echopin as input
  pinMode(buzzer, OUTPUT);   // defining buzzer as output
  pinMode(ledPin, OUTPUT);  // defining ledpin as output

  Serial.begin(9600);
  
  motor1.setSpeed(200); 
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  
 
}

void loop() 
{
 /*producing pulse using ultrasonic sensor   */
 
digitalWrite(trigPin, LOW);   
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

/* reading time between sending to recieving the pulse */
duration = pulseIn(echoPin, HIGH);

/* calculating distance using formula*/

distance= duration*0.034/2;

/* printing distance in seriel monitor */

Serial.print("Distance: ");
Serial.println(distance);


if(distance> 50)
{
/*command to run vehicle forward*/
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

/* defining speed at a sepecific distance*/

  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);

 
  
}

else if (distance<= 50 and distance >=40)
{
  
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  motor1.setSpeed(90);
  motor2.setSpeed(90);
  motor3.setSpeed(90);
  motor4.setSpeed(90);

 
}

else if (distance< 40 and distance >=30)
{

/* command to turn led on before collision*/

  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin,LOW);
  delay(100);
/* 
 command to sound the alarm 
 */
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);


  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  motor1.setSpeed(40);
  motor2.setSpeed(40);
  motor3.setSpeed(40);
  motor4.setSpeed(40);

  
  
}
else
{  
/* command to turn led on before collision*/
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin,LOW);
  delay(50);
  
/* 
 command to sound the alarm 
 */

  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(50);

//Programme to stop moter

  motor1.run(RELEASE);  
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

}
