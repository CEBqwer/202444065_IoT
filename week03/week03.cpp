// 미세먼지 센서로 미세먼지 양 측정
// 미세먼지 센서는 미세먼지 양을 전압으로 표현해줌

int Vo = A0;
int V_LED = 2;

float Vo_value = 0;
float Voltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(V_LED, OUTPUT);
  pinMode(Vo, INPUT);
}

void loop() {
  // DataSheet 설명대로 작동
  digitalWrite(V_LED, LOW); // LOW일 때 LED on
  delayMicroseconds(280); // 0.28s wait
  Vo_value = analogRead(Vo);
  delayMicroseconds(40); // 0.04s wait (샘플링 후 LED 끌 수 있을 때까지 대기)
  digitalWrite(V_LED, HIGH); // LED off
  delayMicroseconds(9680); // LED off 상태에서 9.68s 대기

  Voltage = Vo_value * 5.0 / 1023.0;
  dustDensity = (Voltage - 0.5) / 0.005;

  // 측정값을 dust = 14.37 ... 와 같은 형태로 출력 (key = value)
  Serial.print("dust = ");
  Serial.println(dustDensity);

  delay(1000);
}
