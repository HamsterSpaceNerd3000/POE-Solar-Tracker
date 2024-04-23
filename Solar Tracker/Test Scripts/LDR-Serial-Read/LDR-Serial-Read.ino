#define LDR1pin A0
#define LDR2pin A1
#define LDR3pin A2
#define LDR4pin A3

int LDR1Value = 0;
int LDR2Value = 0;
int LDR3Value = 0;
int LDR4Value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  LDR1Value = analogRead(LDR1pin);
  LDR2Value = analogRead(LDR2pin);
  LDR3Value = analogRead(LDR3pin);
  LDR4Value = analogRead(LDR4pin);

  Serial.println(String(LDR1Value) + ", " + String(LDR2Value) + ", " + String(LDR3Value) + ", " + String(LDR4Value));
  delay(50);
}
