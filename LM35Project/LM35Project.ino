void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);           // set up Serial library at 9600 bps

}
/*
temperatur in celsius  = ADC_raw x 0.48875
*/
void loop() {
  // put your main code here, to run repeatedly:
 int ADC_raw = analogRead(A0);
 //Serial.println(ADC_raw,HEX);
 double temperature = ADC_raw * 0.48875;
 Serial.print("temperature:");
 Serial.println(temperature);
 delay(500);
}
