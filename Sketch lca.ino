#define TriggerPin 10
#define EchoPin 9
#define TriggerPinb 12
#define EchoPinb 11
#define relaypin 13
int distance;
int distance2;
int counter=0;
void setup() {
for(int i=2;i<=8;i++){
pinMode(i,OUTPUT);}
pinMode(TriggerPin, OUTPUT);
pinMode(EchoPin, INPUT);
pinMode(TriggerPinb, OUTPUT);
pinMode(EchoPinb, INPUT);
pinMode(relaypin,OUTPUT);
digitalWrite(relaypin, LOW);
Serial.begin(9600);
}
void loop() { 
 distance =trigger_sensor_1();
 distance2 = trigger_sensor_2();
while(distance<15){
  distance2=trigger_sensor_2();
  distance=trigger_sensor_1();
  if (distance2<15){
    counter=counter+1;
    Serial.println(counter);
    delay(1500);
    break;
  }}
while(distance2<15){
  distance2=trigger_sensor_2();
  distance=trigger_sensor_1();
  if (distance<15){
    counter=counter-1;
    Serial.println(counter);
    delay(1500);
    break;
  }}
 if(counter<1){
  counter=0;
 digitalWrite(relaypin,LOW);}
 else{
 digitalWrite(relaypin,HIGH);}
 switch(counter){
 case 0:
 zero();
 break;
 case 1:
 one();
 break;
case 2:
two();
break;
case 3:
three();
break;
case 4:
four();
break;
case 5:
five();
break;
case 6:
six();
break;
case 7:
seven();
break;
case 8:
eight();
break;
case 9:
nine();
break;
default:
e();}
}
void zero() {
  digitalWrite(2,HIGH);digitalWrite(3,LOW);digitalWrite(4,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);delay(50);}
void one(){
  digitalWrite(2,HIGH);digitalWrite(3,HIGH);digitalWrite(4,HIGH);digitalWrite(5,HIGH);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,HIGH);delay(50);}
void two(){
  digitalWrite(2,LOW);digitalWrite(3,HIGH);digitalWrite(4,LOW);digitalWrite(5,LOW);digitalWrite(6,HIGH);digitalWrite(7,LOW);digitalWrite(8,LOW);delay(50);}
 void three() {
  digitalWrite(2,LOW);digitalWrite(3,HIGH);digitalWrite(4,HIGH);digitalWrite(5,LOW);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);delay(50);}
void four() {
  digitalWrite(2,LOW);digitalWrite(3,LOW);digitalWrite(4,HIGH);digitalWrite(5,HIGH);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,HIGH);delay(50);}
void five() {
  digitalWrite(2,LOW);digitalWrite(3,LOW);digitalWrite(4,HIGH);digitalWrite(5,LOW);digitalWrite(6,LOW);digitalWrite(7,HIGH);digitalWrite(8,LOW);delay(50);}
void six() {
  digitalWrite(2,LOW);digitalWrite(3,LOW);digitalWrite(4,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW);digitalWrite(7,HIGH);digitalWrite(8,LOW);delay(50);}
void seven() {
  digitalWrite(2,HIGH);digitalWrite(3,HIGH);digitalWrite(4,HIGH);digitalWrite(5,HIGH);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);delay(50);}
void eight() {
  digitalWrite(2,LOW);digitalWrite(3,LOW);digitalWrite(4,LOW);digitalWrite(5,LOW);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);delay(50);  }
void nine() {
  digitalWrite(2,LOW);digitalWrite(3,LOW);digitalWrite(4,HIGH);digitalWrite(5,LOW);digitalWrite(6,LOW);digitalWrite(7,LOW);digitalWrite(8,LOW);delay(50);}
void e() {
digitalWrite(2,LOW);digitalWrite(3,LOW);digitalWrite(4,LOW);digitalWrite(5,LOW);digitalWrite(6,HIGH);digitalWrite(7,HIGH);digitalWrite(8,LOW);delay(50);}
int trigger_sensor_2(){
  int distance2;
  unsigned long duration2;
  digitalWrite(TriggerPinb, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPinb, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPinb, LOW);
  duration2 = pulseIn(EchoPinb, HIGH);
  distance2 = duration2 * 0.034 / 2;
  digitalWrite(EchoPinb, LOW);
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");
 return distance2;}
int trigger_sensor_1(){
    int distance;
    unsigned long duration;
 digitalWrite(TriggerPin, LOW);
 delayMicroseconds(2);
 digitalWrite(TriggerPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(TriggerPin, LOW);
 duration = pulseIn(EchoPin, HIGH);
 distance = duration * 0.034 / 2;
 digitalWrite(EchoPin, LOW);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 return distance;}
