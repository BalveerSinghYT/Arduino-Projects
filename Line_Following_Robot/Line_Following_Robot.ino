int IRR = 8;
int IRL = 9;

int IN1 = 2;   // RIGHT
int IN2 = 3;   // RIGHT
int IN3 = 4;   // LEFT
int IN4 = 7;   // LEFT

void setup() {
  // put your setup code here, to run once:
pinMode(IRR ,INPUT);
pinMode(IRL ,INPUT);
pinMode(IN1 ,OUTPUT);
pinMode(IN2 ,OUTPUT);
pinMode(IN3 ,OUTPUT);
pinMode(IN4 ,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statusl, statusr ;
  statusl = digitalRead(IRR);
  statusr = digitalRead(IRL);

  Serial.print(statusl);
  Serial.println(statusr);

if (statusl == HIGH && statusr == HIGH) // FORWARD
   {
   digitalWrite(IN1, HIGH);  
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
   Serial.println("HIGH");
   }
else if (statusr == LOW && statusl == HIGH) // LEFT
{
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW); 
}
else if (statusr == HIGH && statusl == LOW)  // RIGHT
{
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH); 
}
else  if(statusl == LOW && statusr == LOW) // Reverse
   {
   digitalWrite(IN1, LOW);  
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   }
   }
