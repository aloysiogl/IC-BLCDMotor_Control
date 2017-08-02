//Defining pins for the motor driver circuit
#define PWM_PIN 3
#define H1 20
#define H2 19
#define H3 18
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

  //Initializing serial communications for debug
  Serial.begin(9600);

  //Initial speed (can be changed and the defout is 0)
  analogWrite(3,0);
}

const int delayTime = 1000;

void loop() {
  //This loop prints the commutation table
  Serial.println("AB");
  digitalWrite(M1U,HIGH);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,HIGH);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,LOW);
  printAll();
  delay(delayTime);
  Serial.println("AC");
  digitalWrite(M1U,HIGH);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,HIGH);
  printAll();
  delay(delayTime);
  Serial.println("BC");
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,HIGH);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,HIGH);
  printAll();
  delay(delayTime);
  Serial.println("CA");
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,HIGH);
  digitalWrite(M2U,HIGH);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,LOW);
  printAll();
  delay(delayTime);
  Serial.println("BA");
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,HIGH);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,HIGH);
  digitalWrite(M3D,LOW);
  printAll();
  delay(delayTime);
  Serial.println("CB");
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,HIGH);
  digitalWrite(M3U,HIGH);
  digitalWrite(M3D,LOW);
  printAll();
  delay(delayTime);
}

//Function for debugging hall sensors
void printAll(){
 Serial.print(digitalRead(10));
 Serial.print("//");
 Serial.print(digitalRead(11));
 Serial.print("//");
 Serial.println(digitalRead(12));
}

//Commutation sequence (AB AC BC BA CA CB)
/*
  digitalWrite(M1U,HIGH);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,HIGH);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,LOW);
  delay(delayTime);
  digitalWrite(M1U,HIGH);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,HIGH);
  delay(delayTime);
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,HIGH);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,HIGH);
  delay(delayTime);
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,HIGH);
  digitalWrite(M2U,HIGH);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,LOW);
  digitalWrite(M3D,LOW);
  delay(delayTime);
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,HIGH);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,LOW);
  digitalWrite(M3U,HIGH);
  digitalWrite(M3D,LOW);
  delay(delayTime);
  digitalWrite(M1U,LOW);
  digitalWrite(M1D,LOW);
  digitalWrite(M2U,LOW);
  digitalWrite(M2D,HIGH);
  digitalWrite(M3U,HIGH);
  digitalWrite(M3D,LOW);
  delay(delayTime);
*/
