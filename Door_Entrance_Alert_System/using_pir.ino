// Declare pin constants
const int BUZZER_PIN = 5;
const int LED_PIN = 6;
const int MOTION_PIN = 7;
const int BUTTON_PIN = 12;

// Set initial state of buzzer to off
bool buzzer_on = false;

// Initialize variables for blinking LED
int led_state = LOW;
unsigned long previous_millis = 0; 
const unsigned long BLINK_INTERVAL = 100;  // Interval at which LED blinks

void setup() {
  // Set output pins for buzzer and LED
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Set input pin for button
  pinMode(BUTTON_PIN, INPUT);
  
  // Wait 5 seconds before starting the alarm
  delay(5000);
}

void loop() {
  // Check if motion has been detected
  if (digitalRead(MOTION_PIN)) {
    buzzer_on = true; 
  }

  // If alarm mode is on, blink LED
  if (buzzer_on) {
    unsigned long current_millis = millis();
    if (current_millis - previous_millis > BLINK_INTERVAL) {
      previous_millis = current_millis;   
      if (led_state == LOW) {
        led_state = HIGH;
      } else {
        led_state = LOW;
      }
      // Switch the LED
      digitalWrite(LED_PIN, led_state);
    }
    // Play a tone on the buzzer
    tone(BUZZER_PIN, 1000);
  }

  // If alarm is off
  if (!buzzer_on) {
    // Turn off the tone and the LED
    noTone(BUZZER_PIN);  
    digitalWrite(LED_PIN, LOW);
  }

  // If the button is pressed, turn off the ringing and reset the alarm
  if (digitalRead(BUTTON_PIN)) {
    buzzer_on = false;
  }
}
