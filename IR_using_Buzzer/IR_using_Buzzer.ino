int IR = 4;
int BZ = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  pinMode(BZ, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int status = digitalRead(IR);
  if(status == LOW)
  {
    Serial.println("HIGH");
    digitalWrite(BZ, HIGH);
    }
  else if (status == HIGH)
  {
    Serial.println("LOW");    
    digitalWrite(BZ, LOW);
   }
}
