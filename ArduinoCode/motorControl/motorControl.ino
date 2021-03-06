//Timer interrupt library
#include "TimerOne.h"

//Defining pins for the motor driver circuit
#define H1 20
#define H2 19
#define H3 18
#define M1U 4
#define M1D 5
#define M2U 7
#define M2D 6
#define M3U 8
#define M3D 9

//Variable for speed
volatile int speed;

//Variable for counting pulses
volatile unsigned long pulses = 0;

//Double desired speed
double desiredSpeed = 100;

//Control variables
volatile unsigned long pulsosAtual = 0;
volatile unsigned long pulsosAnterior= 0;
volatile double UAtual = 0;
volatile double UAnterior = 0;
volatile double erroAtual = desiredSpeed;
volatile double erroAnterior = 0;

//Constants
double Ki = 104.55;
double Kp = 2.8522;

//Delta t
double dt = 0.05;

void setup() {
  //Setting up pins
  pinMode(H1,INPUT);
  pinMode(H2,INPUT);
  pinMode(H3,INPUT);
  pinMode(M1U, OUTPUT);
  pinMode(M1D, OUTPUT);
  pinMode(M2U, OUTPUT);
  pinMode(M2D, OUTPUT);
  pinMode(M3U, OUTPUT);
  pinMode(M3D, OUTPUT);

  //Setting every output pin to low state
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,LOW);

  //Attaching interruptions for the commutation
  attachInterrupt(digitalPinToInterrupt(H1), commute, CHANGE);
  attachInterrupt(digitalPinToInterrupt(H2), commute, CHANGE);
  attachInterrupt(digitalPinToInterrupt(H3), commute, CHANGE);

  //Timer interrupt
  Timer1.initialize(50000);
  Timer1.attachInterrupt(control);

  //Serial communication initialization for debug and message parsing
  Serial.begin(9600);

  //Speed
  speed = 255;
}

void loop() {
  Serial.println(pulses);
}

//Control interrupt
void control(){
  pulsosAnterior = pulsosAtual;
  pulsosAtual = pulses;
  erroAnterior = erroAtual; 
  erroAtual = (pulsosAtual-pulsosAnterior)/dt - desiredSpeed;

  UAtual = UAnterior + Kp*erroAtual + Ki*dt*erroAtual/2+Ki*dt*erroAnterior/2;

  speed = (int)UAtual*6.7/255;
}

//Intterupt function for commutation
void commute(){
  commuteD();
  //Incrementing pulses
  ++pulses;
}

//Function wich finds the next commutation in the commutation table in direct order
void commuteD(){
  //AB
  if (digitalRead(H1) == 0 && digitalRead(H2) == 1 && digitalRead(H3) == 1){
    digitalWrite(M1U,HIGH);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    analogWrite(M2D,speed);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,LOW);
  }
  //AC
  else if (digitalRead(H1) == 0 && digitalRead(H2) == 1 && digitalRead(H3) == 0){
    digitalWrite(M1U,HIGH);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    analogWrite(M3D,speed);
  }
  //BC
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 1 && digitalRead(H3) == 0){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    analogWrite(M3D,speed);
  }
  //BA
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 0){
    digitalWrite(M1U,LOW);
    analogWrite(M1D,speed);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,LOW);
  }
  //CA
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    analogWrite(M1D,speed);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,HIGH);
    digitalWrite(M3D,LOW);
  }
  //CB
  else if (digitalRead(H1) == 0 && digitalRead(H2) == 0 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    analogWrite(M2D,speed);
    digitalWrite(M3U,HIGH);
    digitalWrite(M3D,LOW);
  }
}

//Function wich finds the next commutation in the commutation table in inverse order
void commuteI(){
  //AB
  if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 0){
    digitalWrite(M1U,HIGH);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,HIGH);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,LOW);
  }
  //AC
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 1){
    digitalWrite(M1U,HIGH);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,HIGH);
  }
  //BC
  else if (digitalRead(H1) == 0 && digitalRead(H2) == 0 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,HIGH);
  }
  //BA
  else if (digitalRead(H1) == 0 && digitalRead(H2) == 1 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,HIGH);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,LOW);
  }
  //CA
  else if (digitalRead(H1) == 0 && digitalRead(H2) == 1 && digitalRead(H3) == 0){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,HIGH);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,HIGH);
    digitalWrite(M3D,LOW);
  }
  //CB
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 1 && digitalRead(H3) == 0){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,HIGH);
    digitalWrite(M3U,HIGH);
    digitalWrite(M3D,LOW);
  }
}
