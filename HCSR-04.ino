/**********************************************************************************
 *  TITLE: Measure distance using ESP8266 and HCSR-04 ultrasonic sensor
 *  Click on the following links to learn more. 
 *  YouTube Video: https://www.youtube.com/channel/UCscQZ6FyFrx3dKgsPSPOVGQ
 *  by IoT withme
 *  Github link :
 *  https://github.com/IoTWM
 **********************************************************************************/

const int trigP = 5;  //D1 Or GPIO-5 of nodemcu
const int echoP = 4;  //D2 Or GPIO-4 of nodemcu

long duration;
int distance;

void setup() {
pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
pinMode(echoP, INPUT);   // Sets the echoPin as an Input
Serial.begin(9600);      // Open serial channel at 9600 baud rate
}

void loop() {

digitalWrite(trigP, LOW);   // Makes trigPin low
delayMicroseconds(2);       // 2 micro second delay 

digitalWrite(trigP, HIGH);  // tigPin high
delayMicroseconds(10);      // trigPin high for 10 micro seconds
digitalWrite(trigP, LOW);   // trigPin low

duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
distance= duration*0.034/2;        //Calculating actual/real distance

Serial.print("Distance = ");        //Output distance on arduino serial monitor 
Serial.println(distance);
delay(5000);                        //Pause for 5 seconds and start measuring distance again
}
