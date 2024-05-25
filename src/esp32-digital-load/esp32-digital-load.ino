#include <Arduino.h>

// Pin definitions
#define POT_PIN 3
#define PWM_PIN 2
#define RED_LED_PIN 9
#define GREEN_LED_PIN 8

// PWM parameters
const long pwmFrequency = 50000; // 50 kHz to achieve a 20us period
const uint8_t pwmResolution = 8; // 8-bit resolution for PWM
const uint8_t maxPwmValue = 255; // Maximum value for 8-bit resolution PWM

// ADC and Voltage settings
const float referenceVoltage = 3.3; // ADC reference voltage in volts
const int adcMaxValue = 4095; // Maximum ADC value for 12-bit resolution
const float minimumVoltage = 0.1; // Minimum voltage threshold to start PWM

void setup() {
  // Initialize Serial for debug output
  Serial.begin(9600);

  // Set up LED pins
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Initialize PWM on pin
  ledcSetup(0, pwmFrequency, pwmResolution);
  ledcAttachPin(PWM_PIN, 0);

  // Check initial position of the potentiometer
  float initialVoltage = (analogRead(POT_PIN) * referenceVoltage) / adcMaxValue;
  if (initialVoltage > minimumVoltage) {
    digitalWrite(RED_LED_PIN, HIGH); // Turn on red LED
    digitalWrite(GREEN_LED_PIN, LOW); // Make sure green LED is off
    while ((analogRead(POT_PIN) * referenceVoltage / adcMaxValue) > minimumVoltage) {
      // Wait for the user to adjust the potentiometer to minimum
      delay(100); // Delay to avoid excessive reading
      Serial.println("Adjust potentiometer to minimum to start.");
      Serial.println((analogRead(POT_PIN) * referenceVoltage / adcMaxValue));

    }
  }
  // Potentiometer is at minimum value, proceed with normal operation
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
}

void loop() {
  // Read the potentiometer value and convert to voltage
  float potVoltage = (analogRead(POT_PIN) * referenceVoltage) / adcMaxValue;

  // Calculate the PWM duty cycle (0 - 50% of maximum PWM value) 
  int pwmDutyCycle = map(potVoltage * 1000, 0, referenceVoltage * 1000, 0, 128);

  // Set the PWM duty cycle
  ledcWrite(0, pwmDutyCycle);
 digitalWrite(GREEN_LED_PIN, HIGH);
  // Debug output to Serial Monitor
  Serial.print("Duty Cycle: ");
  Serial.print((float)pwmDutyCycle / maxPwmValue * 100);
  Serial.println("%");
  Serial.print("Potentiometer Voltage: ");
  Serial.print(potVoltage);
  Serial.println(" V");
}
