//Sensor wires
//Brown/Green = Tray 1
//Brown/Orange = Tray 2
//Blue/Green = Tray 3
//Blue/Orange = Tray 4



//Planter 1
// has Swiss Chard
int tray1LowMoisture = 300;
int tray1SensorValue = 0;
int tray1Sensor = 0; // Port A0
int tray1SensorPwr = 7; // Digital 7
int tray1Pump = 13;

//Tray 2
// has Kale
// Likes Moisture
int tray2LowMoisture = 300;
int tray2SensorValue = 0;
int tray2Sensor = 1; //Port A1
int tray2SensorPwr = 6; // Digital 6
int tray2Pump = 12;

//Tray 3
// Oregano, Pansy, Cilantro
// Likes to dry out
int tray3LowMoisture = 400;
int tray3SensorValue = 0;
int tray3Sensor = 2; //Port A2
int tray3SensorPwr = 5; // Digital 5
int tray3Pump = 11;

//Tray 4
// Empty
// 
int tray4LowMoisture = 100;
int tray4SensorValue = 0;
int tray4Sensor = 3; //Port A2
int tray4SensorPwr = 4; // Digital 5
int tray4Pump = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,OUTPUT);  
  pinMode(6,OUTPUT);  
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Power On");

  // Tray 1
  delay(1000);
  Serial.println("Starting Tray1");
  digitalWrite(tray1SensorPwr, HIGH);
  delay(1000);
  tray1SensorValue = ReadSens(tray1Sensor);
  Serial.print("Tray 1 is ");
  Serial.println(tray1SensorValue);
  delay(1000);
  digitalWrite(tray1SensorPwr, LOW);
/*
  if(tray1SensorValue < tray1LowMoisture){
  Serial.println("Turning on pump for tray 1.");
    digitalWrite(tray1Pump,HIGH);
    delay(10000);
    digitalWrite(tray1Pump,LOW);
  }
*/
  Serial.println("Tray 1 Complete.");

  // Tray 2
  delay(1000);
  Serial.println("Starting Tray 2");
  digitalWrite(tray2SensorPwr, HIGH);
  delay(1000);
//  tray2SensorValue = analogRead(tray2Sensor);
  tray2SensorValue = ReadSens(tray2Sensor);
  Serial.print("Tray 2 is ");
  Serial.println(tray2SensorValue);
  delay(1000);
  digitalWrite(tray2SensorPwr, LOW);
/*
  if(tray2SensorValue < tray2LowMoisture){
  Serial.println("Turning on pump for tray 2.");
    digitalWrite(tray2Pump,HIGH);
    delay(10000);
    digitalWrite(tray2Pump,LOW);
  }
*/
   Serial.println("Tray 2 Complete.");




  delay(1000);
  Serial.println("Starting Tray3");
  digitalWrite(tray3SensorPwr, HIGH);
  delay(1000);
//  tray3SensorValue = analogRead(tray3Sensor);
  tray3SensorValue = ReadSens(tray3Sensor);
  Serial.print("Tray 3 is ");
  Serial.println(tray3SensorValue);
  delay(1000);
  digitalWrite(tray3SensorPwr, LOW);

  /*if(tray3SensorValue < tray3LowMoisture){
  Serial.println("Turning on pump for tray 3.");
    digitalWrite(tray3Pump,HIGH);
    delay(20000);
    digitalWrite(tray3Pump,LOW);
  }*/

  Serial.println("Tray 3 Complete.");
 /* if(sensorValue1 < 100){
    digitalWrite(12,HIGH);
    delay(10000);
    digitalWrite(12,LOW);
  }
  */

  
  
  
  // Tray 4
  delay(1000);
  Serial.println("Starting Tray4");
  digitalWrite(tray4SensorPwr, HIGH);
  delay(1000);
  tray4SensorValue = ReadSens(tray4Sensor);
  Serial.print("Tray 4 is ");
  Serial.println(tray4SensorValue);
  delay(1000);
  digitalWrite(tray4SensorPwr, LOW);
/*
  if(tray1SensorValue < tray1LowMoisture){
  Serial.println("Turning on pump for tray 1.");
    digitalWrite(tray1Pump,HIGH);
    delay(10000);
    digitalWrite(tray1Pump,LOW);
  }
*/
  Serial.println("Tray 4 Complete.");

  
  
  
  
  
  
  Serial.println("sleep for 10 minutes");
 delay(3600000);

}


int ReadSens( int arg1){
  int i;
  int sval = 0;

  for (i = 0; i < 5; i++){
    sval = sval + analogRead(arg1); 
    delay(100);
  }

  sval = sval / 5;    // average
  //sval = sval / 4;    // scale to 8 bits (0 - 255)
  //sval = 255 - sval;  // invert output
  return sval;
}

/*
*/

/*
 * Need to build a function to determine if the tray should be watered based on the moisture needs set in variables.
 * 
 * 
 * 
 * 
 */
