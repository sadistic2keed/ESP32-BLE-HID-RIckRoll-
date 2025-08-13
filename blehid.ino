#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Trigger 1
#define BUTTON_2_PIN 17 // Trigger 2  
#define BUTTON_3_PIN 18 // Trigger 3

char kbd[] = "Logitech"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;

// Debounce variables
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  bleKeyboard.begin();
  Serial.println("BLE Keyboard initialized");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    bool state1 = digitalRead(BUTTON_1_PIN);
    bool state2 = digitalRead(BUTTON_2_PIN);
    bool state3 = digitalRead(BUTTON_3_PIN);
    
    // Button 1: Rickroll on Parrot OS
    if (lastState1 == HIGH && state1 == LOW && (millis() - lastDebounceTime1) > debounceDelay) {
      Serial.println("Trigger 1: Rickroll on Parrot OS");
      lastDebounceTime1 = millis();
      
      // Open terminal (Ctrl + Alt + T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(100);
      bleKeyboard.releaseAll();
      delay(1500); // Give terminal time to open
      
      // Launch Firefox with Rickroll URL - type slowly with delays
      String command = "firefox https://www.youtube.com/watch?v=dQw4w9WgXcQ";
      for (int i = 0; i < command.length(); i++) {
        bleKeyboard.write(command.charAt(i));
        delay(20); // Small delay between each character
      }
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(5000); // Wait for Firefox to load
      
      // Set system volume to max (Alt + F3)
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press(KEY_F3);
      delay(100);
      bleKeyboard.releaseAll();
      delay(500);
      
      // Make YouTube player volume max (Up arrow x20)
      for (int i = 0; i < 20; i++) {
        bleKeyboard.press(KEY_UP_ARROW);
        delay(50);
        bleKeyboard.releaseAll();
        delay(50);
      }
      
      // Fullscreen video (press 'f')
      bleKeyboard.press('f');
      delay(100);
      bleKeyboard.releaseAll();
    }
    
    // Button 2: Example function - Open calculator
    if (lastState2 == HIGH && state2 == LOW && (millis() - lastDebounceTime2) > debounceDelay) {
      Serial.println("Trigger 2: Open Calculator");
      lastDebounceTime2 = millis();
      
      // Open run dialog (Alt + F2 on many Linux systems)
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press(KEY_F2);
      delay(100);
      bleKeyboard.releaseAll();
      delay(500);
      
      // Type calculator command
      bleKeyboard.print("gnome-calculator");
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
    }
    
    // Button 3: Example function - Open text editor
    if (lastState3 == HIGH && state3 == LOW && (millis() - lastDebounceTime3) > debounceDelay) {
      Serial.println("Trigger 3: Open Text Editor");
      lastDebounceTime3 = millis();
      
      // Open terminal
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
      
      // Open nano text editor
      bleKeyboard.print("nano");
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
    }
    
    // Update button states
    lastState1 = state1;
    lastState2 = state2;
    lastState3 = state3;
  }
  
  delay(10); // Small delay for stability
}