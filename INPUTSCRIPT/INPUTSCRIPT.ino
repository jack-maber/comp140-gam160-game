int xPinL = A1;
int yPinL = A0;
int yPinR = A3:
int xPinR = A2;
int buttonPinL = 2;
int buttonPinR = 1;

int xPositionL = 0;
int yPositionL = 0;
int buttonStateL = 0;

void setup() {
  
  Serial.begin(9600); 
  
  pinMode(xPinL, INPUT);
  pinMode(yPinL, INPUT);
 }

void loop() {
  xPositionL = analogRead(xPinL);
  yPositionL = analogRead(yPinL);
  buttonStateL = digitalRead(buttonPinL);
  xPositionR = analogRead(xPinR);
  yPositionR = analogRead(yPinR);
  
  Serial.print("X: ");
  Serial.print(xPositionL);
  Serial.print(" | Y: ");
  Serial.print(yPositionL);
  Serial.print(" | Button: ");
  Serial.println(buttonStateL);

  delay(100); // add some delay between reads
}
