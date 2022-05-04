#define I1 5  // Control pin 1 for motor 1
#define I2 6  // Control pin 2 for motor 1

void setup() {

  //set the pin mode for the motor to be an output
   pinMode(I1, OUTPUT);
   pinMode(I2, OUTPUT);
    
   Serial.begin(9600);
}

 

void loop() {

// read the value from the sensor

 int sensorValue1 = analogRead(A3);
 int sensorValue2 = analogRead(A2);

// Convert the analog value into voltage 

  int volt1=sensorValue1;
  int volt2=sensorValue2;

  
  if ((volt1 > (volt2+40)) && (volt1 > 550)){
      
    analogWrite(I1, 0);
    analogWrite(I2, 120);
    
  }
  if (((volt2+20) > volt1)  && (volt2 > 550)){
   
    analogWrite(I1, 120);
    analogWrite(I2, 0);
    
  }
 
//  if ( ((volt1-volt2) > 600) || ((volt2-volt1) > 600) ) {
//    analogWrite(I1, 0);
//    analogWrite(I2, 0);
//  }

  //print voltages

  Serial.print("sensorValue1: ");
  Serial.print(volt1);
  Serial.print(" sensorValue2: ");
  Serial.println(volt2);

  delay (100);
  
  analogWrite(I1, 0);
  analogWrite(I2, 0);

}
