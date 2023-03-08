#define BLYNK_TEMPLATE_ID "TMPLBH7YiPhG"
#define BLYNK_DEVICE_NAME "HandSanitizer"
#define BLYNK_AUTH_TOKEN "EZqTNUklBS8xeOI9feQmVr_-PH43K5e5"
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Kitarp";
char pass[] = "pratikdangi";

#include <Servo.h>
const int trigPin =D6;
const int echoPin =D7;
Servo servo;
int sound = 250;
void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(D2);
  servo.write(0);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
  Blynk.run();
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Blynk.virtualWrite(V0, duration);
  Blynk.virtualWrite(V1, distance);

  if (distance < 10) {
    Serial.println("the distance is less than 5");
    servo.write(90);
    delay(2000);

    servo.write(0);
 

}
if (distance > 60 || distance <= 0){
  Serial.println("The distance is more than 60");
}
else {
  Serial.print(distance);
  Serial.println(" cm");
}
delay(500);
}