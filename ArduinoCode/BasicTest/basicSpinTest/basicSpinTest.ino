//Defining pins for the motor driver circuit
#define PWM_PIN 3
#define H1 10
#define H2 11
#define H3 12
#define M1U 4
#define M1D 5
#define M2U 6
#define M2D 7
#define M3U 8
#define M3D 9

void setup() {
  //Setting up pins
  pinMode(H1,INPUT);
  pinMode(H2,INPUT);
  pinMode(H3,INPUT);
  pinMode(PWM_PIN,OUTPUT);
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
  analogWrite(PWM_PIN,0);
}

void loop() {
  //Code for spinnig the chaft slowly
  analogWrite(PWM_PIN,255);
  digitalWrite(M1U,HIGH);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,LOW);
}
