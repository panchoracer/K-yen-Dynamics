int uv = A0;
int val_uv=0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  val_uv = analogRead(uv);
  Serial.println(val_uv);
}
