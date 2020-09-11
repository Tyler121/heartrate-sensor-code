int led_pin = 13;
int sensor_pin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;

void setup() {
  pinMode(led_pin, OUTPUT);
}


void loop() {
  static double old_value=0;
  static double old_change=0;
  
  int raw_value = analogRead(sensor_pin);
  
  double value = alpha * old_value + (1 - alpha) * raw_value;
  change = value - old_value;
  
  digitalWrite(led_pin,(change<0.0&&old_change>0.0));
  
  old_value=value;
  old_change=change;
  delay(period);
}
