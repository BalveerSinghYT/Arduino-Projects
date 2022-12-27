#define IR_SENSOR_PIN A0
#define PUMP_PIN 9
#define LED_PIN 13

int irSensorValue = 0;
bool pumpActivated = false;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT); 
  pinMode(LED_PIN, OUTPUT); 
}

void loop() {
  irSensorValue = analogRead(IR_SENSOR_PIN); // Read the value from the IR sensor
  if (irSensorValue > 400) { // If the IR sensor value is above a certain threshold, activate the pump
    digitalWrite(PUMP_PIN, HIGH); // Turn on the pump
    digitalWrite(LED_PIN, HIGH);
    pumpActivated = true;
  }
  else { // If the IR sensor value is not above the threshold, turn off the pump and LED lights
    digitalWrite(PUMP_PIN, LOW); // Turn off the pump
    digitalWrite(LED_PIN, LOW); 
    pumpActivated = false;
  }
  delay(100); 
}
