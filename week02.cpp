// C++

#define TRIG 12 // TRIG 핀
#define ECHO 11 // ECHO 핀

int Led_r = 7;
int Led_g = 9;

void setup() {
  Serial.begin(9600); // 숫자는 속도, 보통 9600~112500
  pinMode(Led_r, OUTPUT); // 아두이노 기준 IN/OUT
  pinMode(Led_g, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  long duration, distance;

  // 초음파 센서 사용
  digitalWrite(TRIG, LOW); // HIGH일 수도 있으니 LOW로 바꾸고 시작
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 17 / 1000;
  Serial.println(duration);
  Serial.println("\nDistance : ");
  Serial.println(distance);
  Serial.println(" Cm");

  // Led r, g 순서대로 켜졌다 꺼지게 
  digitalWrite(Led_r, HIGH);
  delay(1000); // 1000 millisecond동안 기다림
  digitalWrite(Led_r, LOW);
  delay(1000);

  digitalWrite(Led_g, HIGH);
  delay(1000);
  digitalWrite(Led_g, LOW);
  delay(1000);
}
