// Simple Blink Sketch 
#define LED_PIN 13 
 
void setup() { 
    pinMode(LED_PIN, OUTPUT); 
} 
 
void loop() { 
    digitalWrite(LED_PIN, HIGH); // Turn LED on 
    delay(1000); 
    digitalWrite(LED_PIN, LOW); // Turn LED off 
    delay(1000); 
}