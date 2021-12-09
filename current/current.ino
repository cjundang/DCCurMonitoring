// Select sensitivity for appropriate ACS712 version:
//int mVperAmp = 185;           // Sensitivity in mV/A for the 5A version
//int mVperAmp = 100;           // Sensitivity in mV/A for the 20A version
int mVperAmp = 66;              // Sensitivity in mV/A for the 30A version

 
double Voltage = 0;       //
double Amps = 0;          //

void setup(){
Serial.begin(9600);      // Start serial monitor
}

float getVPP(){
  float result;
  int readValue;
  int maxValue = 0;
  int minValue = 1024;

  uint32_t start_time = millis();
  while((millis()-start_time) < 1000){
    readValue = analogRead(A0);
    if (readValue > maxValue){
      maxValue = readValue;
    }
    if (readValue < minValue){
      minValue = readValue;
    }
  }
  result = ((maxValue - minValue) * 5.0)/1024.0;
  return result;
}


void loop(){

  Voltage = getVPP();
  Amps = ((Voltage/2.0) *0.707 * 1000)/mVperAmp;
        

  Serial.print("\t Amps = ");          // Current measured
  Serial.println(Amps,10);              // 

  delay(2500);                         // Wait a bit then do it again

}
