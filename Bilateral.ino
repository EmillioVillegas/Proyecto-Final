String IncomingByte; //Serial Data
float x[] = {0,0,0};  
float y[] = {0,0,0};
float valor = 0.0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) {
    IncomingByte = Serial.readStringUntil('\n');
    valor = IncomingByte.toFloat();
    x[0] = valor;
    y[0] = 1.91122623*y[1] + -0.91500257*y[2] + 0.00094408*x[0] + 0.00188817*x[1] + 0.00094408*x[2];
    Serial.println(y[0],4);
    delay(10); //10ms
    
    for(int i = 1; i >= 0; i--){
      x[i+1] = x[i]; 
      y[i+1] = y[i];
      
    }
    
  }
}
