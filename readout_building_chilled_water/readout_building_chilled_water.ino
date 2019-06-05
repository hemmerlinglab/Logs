//#include <Time.h>

void setup() {

  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A10,INPUT);
  pinMode(A11,INPUT);
  pinMode(2,INPUT);
  analogReadResolution(12);
  
}


void loop() {
  //Serial.flush();
  //read the input on analog pin 0:
  int V_temp = analogRead(A0);
  delay(5);
  V_temp = analogRead(A0);
  delay(100);
  int V_pressure = analogRead(A2);
  delay(5);
  V_pressure = analogRead(A2);
  long flow1 = pulseIn(2,HIGH,2000000);
  int V_hornet_pressure = analogRead(A3);
  delay(5);
  V_hornet_pressure = analogRead(A3);
  long flow2 = pulseIn(2,HIGH,2000000);
  int V_UCR_in = analogRead(A11);
  delay(5);
  V_UCR_in = analogRead(A11);
  long flow3 = pulseIn(2,HIGH,2000000);
  int V_UCR_out = analogRead(A10);
  delay(5);
  V_UCR_out = analogRead(A10);

  float prd = 2*(max(flow1,max(flow2,flow3)));
  if(prd<0.01){
    prd = 66000.0;
  };

  //Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  // Conversion could be wrong: 0.13 V corresponds to 1.3 lpm and 1.95 V correspond to 25.3 grad
  float res = 4095.0;
  float Vmax = 3.3;
  float flow = prd; // * 14.0/5.0 + 1.0;  
  float temp = V_temp * (Vmax / res); // * 120.0/5.0 * 0.5;  
  float pressure =  V_pressure * (Vmax / res) * 1.25;
  float hornet_pressure =  V_hornet_pressure * (Vmax / res) * 3.3212;
  float V_in = V_UCR_in*(Vmax/res);
  float V_out = V_UCR_out*(Vmax/res);
  
  //print out the value you need:
  //Serial.print(hour());

  String mess = "temp,"+String(temp)+",flow,"+String(flow)+",pressure,"+String(pressure)+",hornet_pressure,"+String(hornet_pressure)+",UCR_in,"+String(V_in)+",UCR_out,"+String(V_out);
  //Serial.print("temp,");
  //Serial.print(temp);
  //Serial.print(",flow,");
  //Serial.print(flow);
  //Serial.print(",pressure,");
  //Serial.print(pressure);
  //Serial.print(",hornet_pressure,");
  //Serial.println(hornet_pressure);
  Serial.println(mess);
  //Serial.flush();
  delay(100);
  }
