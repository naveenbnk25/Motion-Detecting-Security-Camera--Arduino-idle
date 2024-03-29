#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "hkeEAYA3CwbWVATDM9CTUeWtz6LMzIUL";  // Replace with your Blynk Auth Token
char ssid[] = "naveen";
char pass[] = "";

const int pirPin = D1;  // PIR sensor connected to D1

BlynkTimer timer;

void setup() {
  Serial.begin(19200);
  Blynk.begin(auth, ssid, pass);
  pinMode(pirPin, INPUT);

  timer.setInterval(1000L, checkMotion);
}

void loop() {
  Blynk.run();
  timer.run();
}

void checkMotion() {
  int motionValue = digitalRead(pirPin);

  // Print the motion value to the Serial Plotter
  Serial.println(motionValue);

  if (motionValue == HIGH) {
    Serial.println("Motion detected!");
    Blynk.virtualWrite(V0, "Motion detected!");  // Send motion status to Blynk (assuming you have a Value Display widget on V0)
  }
}
