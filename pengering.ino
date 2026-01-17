const int trig = 5;
const int echo = 6;
const int fan = 4;
const int buzzer = 7;

void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(fan, HIGH);      // Relay OFF (Active LOW)
  digitalWrite(buzzer, HIGH);   // 🔇 Buzzer OFF (ACTIVE LOW)

  Serial.println("Sistem Pengering Tangan + Buzzer Siap");
}

void loop() {
  long duration;
  int distance;

  // Trigger ultrasonic
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH, 30000);

  if (duration == 0) {
    distance = 999;
  } else {
    distance = duration * 0.034 / 2;
  }

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 20) {
    // Tangan terdeteksi
    digitalWrite(fan, LOW);       // Kipas ON
    digitalWrite(buzzer, LOW);    // 🔊 Buzzer ON
    Serial.println("Tangan terdeteksi → Kipas & Buzzer ON");
  } else {
    // Tidak ada tangan
    digitalWrite(fan, HIGH);      // Kipas OFF
    digitalWrite(buzzer, HIGH);   // 🔇 Buzzer OFF
    Serial.println("Tidak ada tangan → OFF");
  }

  delay(100);
}