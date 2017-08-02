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

  //Initial speed (can be changed and the defout is 0)
  analogWrite(3,255);
}

const int delayTime = 1000;

void loop() {
  //Cummutation loop
  commuteD();
}

//Function wich finds the next commutation in the commutation table in direct order
void commuteD(){
  //AB
  if (digitalRead(H1) == 0 && digitalRead(H2) == 1 && digitalRead(H3) == 1){
    digitalWrite(M1U,HIGH);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,HIGH);
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
    digitalWrite(M3D,HIGH);
  }
  //BC
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 1 && digitalRead(H3) == 0){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,HIGH);
  }
  //BA
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 0){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,HIGH);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,LOW);
  }
  //CA
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,HIGH);
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
    digitalWrite(M2D,HIGH);
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

void commute2(){
  //AB
  if (digitalRead(H1) == 0 && digitalRead(H2) == 1 && digitalRead(H3) == 0){
    digitalWrite(M1U,HIGH);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,HIGH);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,LOW);
  }
  //AC
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 1 && digitalRead(H3) == 0){
    digitalWrite(M1U,HIGH);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,HIGH);
  }
  //BC
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 0){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,HIGH);
  }
  //BA
  else if (digitalRead(H1) == 1 && digitalRead(H2) == 0 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,HIGH);
    digitalWrite(M2U,HIGH);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,LOW);
    digitalWrite(M3D,LOW);
  }
  //CA
  else if (digitalRead(H1) == 0 && digitalRead(H2) == 0 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,HIGH);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,LOW);
    digitalWrite(M3U,HIGH);
    digitalWrite(M3D,LOW);
  }
  //CB
  else if (digitalRead(H1) == 0 && digitalRead(H2) == 1 && digitalRead(H3) == 1){
    digitalWrite(M1U,LOW);
    digitalWrite(M1D,LOW);
    digitalWrite(M2U,LOW);
    digitalWrite(M2D,HIGH);
    digitalWrite(M3U,HIGH);
    digitalWrite(M3D,LOW);
  }
}


