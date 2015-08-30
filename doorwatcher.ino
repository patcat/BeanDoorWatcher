int minXVal = 0;
int maxXVal = 0;
int minYVal = 0;
int maxYVal = 0;
int minZVal = 0;
int maxZVal = 0;
int movement = 15;
bool ready = false;

void setup() {
  Serial.begin();
}

void loop() {
  AccelerationReading acceleration = Bean.getAcceleration();
  
  if (!ready) {
    for (int i = 0; i < 100; i++) {
        if (acceleration.xAxis > maxXVal) {
           maxXVal = acceleration.xAxis;
        } else if (acceleration.xAxis < minXVal) {
           minXVal =  acceleration.xAxis;
        }
        
        if (acceleration.yAxis > maxYVal) {
           maxYVal = acceleration.yAxis;
        } else if (acceleration.yAxis < minYVal) {
           minYVal =  acceleration.yAxis;
        }
        
        if (acceleration.zAxis > maxZVal) {
           maxZVal = acceleration.zAxis;
        } else if (acceleration.zAxis < minZVal) {
           minZVal =  acceleration.zAxis;
        }
        
        delay(10);
      }
      
      ready = true;
  } else {
    if (acceleration.zAxis < minZVal - movement) {
      String stringToPrint = "CLOSED";
      Serial.println(stringToPrint);
    } else if (acceleration.zAxis > maxZVal + movement) {
      String stringToPrint = "OPEN";
      Serial.println(stringToPrint);
    }
  }
  
  Bean.sleep(1000);
}