#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial espSerial(2, 3);   // RX=D2, TX=D3 (TX not used)

Servo dustbinServo;

const int trigPin = 7;
const int echoPin = 6;

long duration;
int distance;

void setup() {

  Serial.begin(115200);
  espSerial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  dustbinServo.attach(9);
  dustbinServo.write(90);   // Center position

  Serial.println("Smart Dustbin Ready");
}

void loop() {

  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Object detected
  if (distance > 0 && distance < 30) {

    Serial.println("Object Detected");

    unsigned long start = millis();

    while (millis() - start < 5000) {

      if (espSerial.available()) {

        char c = espSerial.read();

        Serial.print("Received: ");
        Serial.println(c);

        if (c == 'R') {

          Serial.println("Reusable");

          dustbinServo.write(180);
          delay(5000);
          dustbinServo.write(90);
          break;
        }

        if (c == 'N') {

          Serial.println("Non-Reusable");

          dustbinServo.write(0);
          delay(5000);
          dustbinServo.write(90);
          break;
        }
      }
    }
  }

  delay(500);
}