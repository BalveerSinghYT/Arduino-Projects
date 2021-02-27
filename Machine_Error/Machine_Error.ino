int red = 2;
int yellow = 3;
int green = 4;


void setup() {
  // put your setup code here, to run once:
pinMode(red, INPUT);
pinMode(yellow, INPUT);
pinMode(green, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(red)==HIGH)
{
  Serial.println("Problem in Machine"); 
}
else if(digitalRead(yellow)==HIGH)
{
  Serial.println("Repairing Stage"); 
}
else if(digitalRead(green)==HIGH)
{
  Serial.println("Repaired"); 
}
else
{
  Serial.println("Machine is fine"); 
}
}
