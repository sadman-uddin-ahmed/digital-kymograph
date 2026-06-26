/*
Digital Kymograph Data Acquisition:
    Arduino Uno + ADXL335 accelerometer interface.

Sensor connections:
    A3: X-axis analogue output
    A2: Y-axis analogue output
    A1: Z-axis analogue output
    A4: software-controlled ground
    A5: software-controlled power

Output format:
    X
    Y
    Z

Sampling interval: 100 ms
*/

const int x_axis_pin = A3;
const int y_axis_pin = A2;
const int z_axis_pin = A1;

const int sensor_ground_pin = A4;
const int sensor_power_pin = A5;

const unsigned long sample_interval_ms = 100;

void setup() {
pinMode(sensor_ground_pin, OUTPUT);
pinMode(sensor_power_pin, OUTPUT);
digitalWrite(sensor_ground_pin, LOW);
digitalWrite(sensor_power_pin, HIGH);
Serial.begin(9600);
}
void loop() {
int x_axis_value = analogRead(x_axis_pin);
int y_axis_value = analogRead(y_axis_pin);
int z_axis_value = analogRead(z_axis_pin);
Serial.print(x_axis_value);
Serial.print("\t");
Serial.print(y_axis_value);
Serial.print("\t");
Serial.println(z_axis_value);
delay(sample_interval_ms);
}
