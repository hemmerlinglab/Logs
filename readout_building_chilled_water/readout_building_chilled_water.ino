//#include <Time.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}


void loop() {

  //read the input on analog pin 0:
  int V_temp = analogRead(A0);
  int V_flow = analogRead(A1);
  int V_pressure = analogRead(A2);
  int V_hornet_pressure = analogRead(A3);

  //Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  // Conversion could be wrong: 0.13 V corresponds to 1.3 lpm and 1.95 V correspond to 25.3 grad

  float flow = V_flow * (5.0 / 1023.0); // * 14.0/5.0 + 1.0;  
  float temp = V_temp * (5.0 / 1023.0); // * 120.0/5.0 * 0.5;  
  float pressure =  V_pressure * (5.0 / 1023.0)/ 1.15;
  float hornet_pressure =  V_hornet_pressure * (5.0 / 1023.0) * 3.3212;
  
  //print out the value you need:
  //Serial.print(hour());

  Serial.print("temp,");
  Serial.print(temp);
  Serial.print(",flow,");
  Serial.print(flow);
  Serial.print(",pressure,");
  Serial.print(pressure);
  Serial.print(",hornet_pressure,");
  Serial.println(hornet_pressure);

  delay(1000);
}
