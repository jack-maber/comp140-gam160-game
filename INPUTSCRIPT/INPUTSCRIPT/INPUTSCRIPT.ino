#define SERIAL_BUFFER_SIZE 256

//ASSIGNS INPUTS TO PINS ON THE BOARD 
int xPinL = A1;
int yPinL = A0;
int yPinR = A3;
int xPinR = A2;
int tSwitch = 9;
int keypad1 = 2;
int keypad2 = 3;
int keypad3 = 4;
int keypad4 = 5;
int fire = 7;


//CREATES VARIABLES FOR THE INPUTS TO USE 
int xPositionL = 0;
int yPositionL = 0;
int xPositionR = 0;
int yPositionR = 0;
int togglestate = 0;
int Button1 = 0;
int Button2 = 0;
int Button3 = 0;
int Button4 = 0;
int firetoggle = 0;

void setup() {
  //GIVES THE INPUT PIN A MODE, SUCH AS IF IT NEEDS AN INLINE RESISITOR, PULLUP IS USED 
  Serial.begin(115200); //Sets Serial Com Rate
  pinMode(xPinL, INPUT);
  pinMode(yPinL, INPUT);
  pinMode(xPinR, INPUT);
  pinMode(yPinR, INPUT);
  pinMode(tSwitch, INPUT_PULLUP);
  pinMode(keypad1, INPUT_PULLUP);
  pinMode(keypad2, INPUT_PULLUP);
  pinMode(keypad3, INPUT_PULLUP);
  pinMode(keypad4, INPUT_PULLUP);
  pinMode(fire, INPUT_PULLUP);
  
 }

void loop() {
  xPositionL = analogRead(xPinL);
  yPositionL = analogRead(yPinL);
  xPositionR = analogRead(xPinR);
  yPositionR = analogRead(yPinR);
  togglestate = digitalRead(tSwitch);
  Button1 = digitalRead(keypad1);
  Button2 = digitalRead(keypad2);
  Button3 = digitalRead(keypad3);
  Button4 = digitalRead(keypad4);
  firetoggle = digitalRead(fire);
  

 //WRITES DATA TO WINDOW USED FOR DEBUGGING
  //Serial.print("X: ");
  //Serial.print(xPositionL);
  //Serial.print(" | Y: ");
  //Serial.print(yPositionL);
  //Serial.print("X: ");
  //Serial.print(xPositionR);
  //Serial.print(" | Y: ");
  //Serial.print(yPositionR);
  //Serial.print(togglestate);
  //Serial.print(Button1);
  //Serial.print(Button2);
  //Serial.print(Button3);
  //Serial.print(Button4);

  //CONVERTS INTS TO STRINGS SO THAT THEY CAN BE PARSED INTO THE ARRAY BY THE C++ CODE
  String xL =  String(analogRead(xPinL));
  String yL =  String(analogRead(yPinL));
  String xR =  String(analogRead(xPinR));
  String yR =  String(analogRead(yPinR));
  String Button1 =  String(digitalRead(keypad1));
  String Button2 =  String(digitalRead(keypad2));
  String Button3 =  String(digitalRead(keypad3));
  String Button4 =  String(digitalRead(keypad4));
  String togglestate =  String (digitalRead(tSwitch));
  String firetoggle = String (digitalRead(fire));

//XL=100,yL=20
 String SendString;
 SendString= xL + 
 ":" + yL +
 ":" + yR +
 ":" + xR +
 ":" + Button1 +
 ":" + Button2 +
 ":" + Button3 +
 ":" + Button4 +
 ":" + togglestate +
 ":" + firetoggle;

 Serial.println(SendString);
 Serial.flush(); 
 
 delay(60); // add some delay between reads
}
