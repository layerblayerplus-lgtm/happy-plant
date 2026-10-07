#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>
Adafruit_7segment led_display = Adafruit_7segment();
Servo servo_11;
void setup()
{  int number1=1;
 
  led_display.begin(0x70); 
  Serial.begin(9600);
  servo_11.attach(11);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
int activenum=1;
  int TIME=0;
int servodelay = 100;
void loop()
 
{ unsigned long pastmillis = millis();
 led_display.writeDisplay();   
   int sensorValue4 = analogRead(A4);
 Serial.println(sensorValue4);
 int num4=0;
 
 if (analogRead(A0)>0 && analogRead(A0)<100 ) {
   analogWrite(3,0); int active=1; } 
 else if (analogRead(A0)>100 && analogRead(A0)<200) { analogWrite(3,0); num4=1;} 
 else if (analogRead(A0)>200 && analogRead(A0)<300) { analogWrite(3,50); num4=2;}
 else if (analogRead(A0)>300 && analogRead(A0)<400) { analogWrite(3,75); num4=3;}
 else if (analogRead(A0)>400 && analogRead(A0)<500) { analogWrite(3,100); num4=4;}\
 else if (analogRead(A0)>500 && analogRead(A0)<600) { analogWrite(3,125); num4=5;}
 else if (analogRead(A0)>600 && analogRead(A0)<700) { analogWrite(3,150); num4=6;}
 else if (analogRead(A0)>700 && analogRead(A0)<800) { analogWrite(3,175); num4=7;}
 else if (analogRead(A0)>800 && analogRead(A0)<900) { analogWrite(3,200); num4=8;}\
 else if (analogRead(A0)>900 && analogRead(A0)<1000) { analogWrite(3,225); num4=9;}
 
 int sensorValue3 = analogRead(A3);
 Serial.println(sensorValue3);
 int num3=0;
 
 if (analogRead(A3)>0 && analogRead(A3)<100 ) {
   analogWrite(9,0); int active=2;} 
 if (analogRead(A3)>100 && analogRead(A3)<200 ) { num3=1;
   analogWrite(9,0);} 
 else if (analogRead(A3)>200 && analogRead(A3)<300) { analogWrite(9,50);  num3=2;}
 else if (analogRead(A3)>300 && analogRead(A3)<400) { analogWrite(9,75); num3=3;}
 else if (analogRead(A3)>400 && analogRead(A3)<500) { analogWrite(9,100); num3=4; }\
 else if (analogRead(A3)>500 && analogRead(A3)<600) { analogWrite(9,125); num3=5;}
 else if (analogRead(A3)>600 && analogRead(A3)<700) { analogWrite(9,150); num3=6;}
 else if (analogRead(A3)>700 && analogRead(A3)<800) { analogWrite(9,175); num3=7;}
 else if (analogRead(A3)>800 && analogRead(A3)<900) { analogWrite(9,200); num3=8;}\
 else if (analogRead(A3)>900 && analogRead(A3)<1000) { analogWrite(9,225); num3=9;}
 
 int sensorValue2 = analogRead(A2);
 Serial.println(sensorValue2);
 int num2=0;
 Serial.println(num2);
 
 if (analogRead(A2)>0 && analogRead(A2)<100 ) {analogWrite(10,0); int active=3;} 
 
 if (analogRead(A2)>100 && analogRead(A2)<200 ) { num2=1; analogWrite(1,0);} 
 else if (analogRead(A2)>200 && analogRead(A2)<300) { analogWrite(10,50); num2 = 2;}
 else if (analogRead(A2)>300 && analogRead(A2)<400) { analogWrite(10,75); num2 = 3;}
 else if (analogRead(A2)>400 && analogRead(A2)<500) { analogWrite(10,100); num2 = 4;}
 else if (analogRead(A2)>500 && analogRead(A2)<600) { analogWrite(10,125); num2 = 5;}
 else if (analogRead(A2)>600 && analogRead(A2)<700) { analogWrite(10,150); num2 = 6;}
 else if (analogRead(A2)>700 && analogRead(A2)<800) { analogWrite(10,175); num2 = 7;}
 else if (analogRead(A2)>800 && analogRead(A2)<900) { analogWrite(10,200); num2 = 8;}
 else if (analogRead(A2)>900 && analogRead(A2)<1024) { analogWrite(10,225); num2 = 9;}
 
  
 int sensorValue1 = analogRead(A1);
  Serial.println(sensorValue1);
int num1=0;
 
 if (analogRead(A1)>0 && analogRead(A1)<100 )       { servodelay = 100; int active=4;} 
 else if (analogRead(A1)>100 && analogRead(A1)<200) {  servodelay = 90; num1=1; } 
 else if (analogRead(A1)>200 && analogRead(A1)<300) {  servodelay = 80;  num1=2;}
 else if (analogRead(A1)>300 && analogRead(A1)<400) {  servodelay = 70;  num1=3;}
 else if (analogRead(A1)>400 && analogRead(A1)<500) {  servodelay = 60;  num1=4;}\
 else if (analogRead(A1)>500 && analogRead(A1)<600) {  servodelay = 50;  num1=5;}
 else if (analogRead(A1)>600 && analogRead(A1)<700) {  servodelay = 40; num1=6;}
 else if (analogRead(A1)>700 && analogRead(A1)<800) {  servodelay = 30; num1=7;}
 else if (analogRead(A1)>800 && analogRead(A1)<900) {  servodelay = 20; num1=8;}\
 else if (analogRead(A1)>900 && analogRead(A1)<1000){  servodelay = 10; num1=9;}
 servo_11.write(0);
 if (servodelay<100)  { if (TIME >= servodelay) { servo_11.write(-40); TIME==0;} }


int tick=0;
unsigned long tIme = millis();
unsigned long time = tIme - pastmillis;
if (time>1 ) {tick=1;} 

if (tick==1) {TIME=TIME+1;} 
 
 activenum=num4; 
  activenum=num3;
  activenum=num2; 
 activenum=num1; 

 
 if (activenum==0)     {led_display.print(0, DEC);} 
else if (activenum==1 && activenum == num4 ) {led_display.print(1, DEC);} 
else if (activenum==2 && activenum == num4 ) {led_display.print(2, DEC);} 
else if (activenum==3 && activenum == num4 ) {led_display.print(3, DEC);} 
else if (activenum==4 && activenum == num4) {led_display.print(4, DEC);} 
else if (activenum==5 && activenum == num4 ) {led_display.print(5, DEC);} 
else if (activenum==6 && activenum == num4 ) {led_display.print(6, DEC);} 
else if (activenum==7 && activenum == num4 ) {led_display.print(7, DEC);} 
else if (activenum==8 && activenum == num4) {led_display.print(8, DEC);} 
else if (activenum==9 && activenum == num4) {led_display.print(9, DEC);} 

else if (activenum==1 && activenum == num3 ) {led_display.print(10, DEC);} 
else if (activenum==2 && activenum == num3 ) {led_display.print(20, DEC);} 
else if (activenum==3 && activenum == num3 ) {led_display.print(30, DEC);} 
else if (activenum==4 && activenum == num3) {led_display.print(40, DEC);} 
else if (activenum==5 && activenum == num3 ) {led_display.print(50, DEC);} 
else if (activenum==6 && activenum == num3 ) {led_display.print(60, DEC);} 
else if (activenum==7 && activenum == num3 ) {led_display.print(70, DEC);} 
else if (activenum==8 && activenum == num3) {led_display.print(80, DEC);} 
else if (activenum==9 && activenum == num3) {led_display.print(90, DEC);} 
 
 
else if (activenum==1 && activenum == num2 ) {led_display.print(100, DEC);} 
else if (activenum==2 && activenum == num2 ) {led_display.print(200, DEC);} 
else if (activenum==3 && activenum == num2 ) {led_display.print(300, DEC);} 
else if (activenum==4 && activenum == num2) {led_display.print(400, DEC);} 
else if (activenum==5 && activenum == num2 ) {led_display.print(500, DEC);} 
else if (activenum==6 && activenum == num2 ) {led_display.print(600, DEC);} 
else if (activenum==7 && activenum == num2 ) {led_display.print(700, DEC);} 
else if (activenum==8 && activenum == num2) {led_display.print(800, DEC);} 
else if (activenum==9 && activenum == num2) {led_display.print(900, DEC);} 
 
  
else if (activenum==1 && activenum == num1 ) {led_display.print(1000, DEC);} 
else if (activenum==2 && activenum == num1 ) {led_display.print(2000, DEC);} 
else if (activenum==3 && activenum == num1 ) {led_display.print(3000, DEC);} 
else if (activenum==4 && activenum == num1) {led_display.print(4000, DEC);} 
else if (activenum==5 && activenum == num1 ) {led_display.print(5000, DEC);} 
else if (activenum==6 && activenum == num1 ) {led_display.print(6000, DEC);} 
else if (activenum==7 && activenum == num1 ) {led_display.print(7000, DEC);} 
else if (activenum==8 && activenum == num1) {led_display.print(8000, DEC);} 
else if (activenum==9 && activenum == num1) {led_display.print(9000, DEC);} 


}
