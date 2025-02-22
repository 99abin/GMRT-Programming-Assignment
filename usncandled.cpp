#include <NewPing.h> // Include the NewPing library for ultrasonic distance measurement
#include <Servo.h>   // Include the Servo library for controlling servo motors

const int ledPins[] = {13, 12, 11}; // Array for LED pins (M, B, H)
Servo mesin; // Create a Servo object to control the servo motor
NewPing sensor(4, 2, 400); // Create a NewPing object with trigger pin 4, echo pin 2, and max distance of 400 cm

void setup() {
  mesin.attach(8); // Attach the servo motor to pin 8
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT); // Set each LED pin as an output
  }
}

void loop() {
  int jarak = sensor.ping_cm(); // Measure the distance in centimeters using the ultrasonic sensor
  int ledState = -1; // Variable to determine which LED to light up
  int servoPosition = 0; // Variable to store the servo position

  // Determine which LED to light up and the servo position based on the distance
  if (jarak % 2 == 0 && jarak % 3 != 0 && jarak % 7 != 0) {
    ledState = 0; // Light up the first LED
    servoPosition = 20; // Set servo position to 20 degrees
  } else if (jarak % 3 == 0 && jarak % 2 != 0 && jarak % 7 != 0) {
    ledState = 1; // Light up the second LED
    servoPosition = 30; // Set servo position to 30 degrees
  } else if (jarak % 7 == 0 && jarak % 3 != 0 && jarak % 2 != 0) {
    ledState = 2; // Light up the third LED
    servoPosition = 70; // Set servo position to 70 degrees
  } else if (jarak % 2 == 0 && jarak % 3 == 0 && jarak % 7 != 0) {
    ledState = 0; // Light up the first LED
    digitalWrite(ledPins[1], HIGH); // Light up the second LED
    servoPosition = 50; // Set servo position to 50 degrees
  }

  // Turn off all LEDs if none of the conditions are met
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], (i == ledState) ? HIGH : LOW); // Light up the selected LED
  }

  mesin.write(servoPosition); // Set the servo position
  delay(500); // Wait for 500 milliseconds before the next loop iteration
}
