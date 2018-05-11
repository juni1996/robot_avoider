const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;

const int ENA = 11;
const int ENB = 10;

const int TRIG = 13;
const int ECHO = 12;

int durasi, jarak;

void setup(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  Serial.begin(9600);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  durasi = pulseIn(ECHO, HIGH);
  jarak = ((durasi*0.034)/2);
  
  if(jarak <= 9){
    Serial.println("ada halangan");
    delay(500);
    
 digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);  
    analogWrite(ENA, LOW);
  analogWrite(ENB, LOW);
    delay(500);
    
 digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);  
    analogWrite(ENA, 100);
  analogWrite(ENB, 100);
    delay(500);

    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);  
    analogWrite(ENA, 100);
  analogWrite(ENB, 100);
    delay(500);
  }
  else if(jarak >= 10){   
    Serial.println("aman");
    delay(500);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
      analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  }
}
