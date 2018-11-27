#include "KeyNew.h"
#include "hid_keys.h"

int upPin = 0;
int upState = 0;
int previousUpState = HIGH;
int downPin = 0;
int downState = 0;
int rightPin = 0;
int rightState = 0;
int previousRightState = HIGH;
int leftPin = 0;
int leftState = 0;
int previousLeftState = HIGH;;
int jumpPin = 4;
int jumpState = 0;
int jumpCount = 0;
int hitPin = 3;
int hitState = 0;
int hitCount = 0;
int escPin = 7;
int escState = 0;
int escCount = 0;

int switchPin = 2;
int switchState = 0;
int switchCount = 0;

int itemPin = 5;
int itemState = 0;
int itemCount = 0;
const byte JOY_X = 0;
const byte JOY_Y = 1;
const int y_STEADY_LOW = 510;
const int y_STEADY_HIGH = 540;
const int x_STEADY_LOW = 500;
const int x_STEADY_HIGH = 520;
const int LEFT_DOWN = 5;
const int RIGHT_UP = 1020;
int x_Position = 0;
int pre_x_Position = 0;
int y_Position = 0;
int pre_y_Position = 0;

void setup() {
  Keyboard.init();
  /*pinMode(upPin, INPUT);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);*/
  pinMode(jumpPin, INPUT_PULLUP);
  digitalWrite(jumpPin,HIGH);
  pinMode(hitPin, INPUT_PULLUP);
  //digitalWrite(hitPin, HIGH);
  pinMode(escPin, INPUT);
  digitalWrite(escPin,HIGH);
  pinMode(itemPin, INPUT);
  digitalWrite(itemPin, HIGH);
  
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin,HIGH);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  x_Position = analogRead(JOY_X);
  y_Position = analogRead(JOY_Y);
  jumpCount ++;
  escCount ++;
  itemCount ++;
  hitCount ++;
  switchCount ++;
  //Serial.println (x_Position);

  if ((pre_x_Position < x_STEADY_HIGH) && (pre_x_Position > x_STEADY_LOW) && (x_Position > x_STEADY_HIGH) && (x_Position < RIGHT_UP) ){
    Keyboard.sendKeyStroke(KEY_D, 0);
    delay(200);
  }
  else if ((pre_x_Position < x_STEADY_HIGH) && (pre_x_Position > x_STEADY_LOW) && (x_Position > LEFT_DOWN) && (x_Position < x_STEADY_LOW) ){
    Keyboard.sendKeyStroke(KEY_A, 0);
    delay(200);
  }
  pre_x_Position = x_Position;
  
  if (x_Position > RIGHT_UP){
    Keyboard.sendKeyStrokeUnReleased(KEY_B);
  }
  else if (x_Position > x_STEADY_HIGH){
    Keyboard.sendKeyReleased(KEY_B,0);
    Keyboard.sendKeyStrokeUnReleased(KEY_D);
  }
  if (x_Position < LEFT_DOWN){
    Keyboard.sendKeyStrokeUnReleased(KEY_C);
  }
  else if (x_Position < x_STEADY_LOW){
    Keyboard.sendKeyReleased(KEY_C,0);
    Keyboard.sendKeyStrokeUnReleased(KEY_A);
  }
  else if ((x_Position > x_STEADY_LOW) && (x_Position < x_STEADY_HIGH)){
    Keyboard.sendKeyReleased(KEY_D,0);
    Keyboard.sendKeyReleased(KEY_B,0);
  
    Keyboard.sendKeyReleased(KEY_A,0);
    Keyboard.sendKeyReleased(KEY_C,0);
  }
  
///////////////////////////


if ((pre_y_Position < y_STEADY_HIGH) && (pre_y_Position > y_STEADY_LOW) && (y_Position > y_STEADY_HIGH)){
    Keyboard.sendKeyStroke(KEY_W, 0);
    delay(500);
    y_Position = 505;
  }
  else if ((pre_y_Position < y_STEADY_HIGH) && (pre_y_Position > y_STEADY_LOW)&& (y_Position < y_STEADY_LOW) ){
    Keyboard.sendKeyStroke(KEY_S, 0);
    delay(500);
    y_Position = 545;
  }
  pre_y_Position = y_Position;
  //Serial.println(x_Position);
  
  if (y_Position > y_STEADY_HIGH + 10){
    Keyboard.sendKeyStrokeUnReleased(KEY_W);
  }
  else if (y_Position < y_STEADY_LOW  - 10){
    Keyboard.sendKeyStrokeUnReleased(KEY_S);
  }
  else if ((y_Position > y_STEADY_LOW) && (y_Position < y_STEADY_HIGH)){
    Keyboard.sendKeyReleased(KEY_W,0);
    Keyboard.sendKeyReleased(KEY_S,0);
  }
  
  /*if ((pre_y_Position < y_Position) && (y_Position >WALK)){
    Keyboard.sendKeyStroke(KEY_A, 0);
    delay(200);
  }
  pre_y_Position = y_Position;
  if (y_Position > RUN){
    Keyboard.sendKeyStrokeUnReleased(KEY_C);
  }
  else if (y_Position > WALK){
    Keyboard.sendKeyReleased(KEY_C,0);
    Keyboard.sendKeyStrokeUnReleased(KEY_A);
  }
  else{
    Keyboard.sendKeyReleased(KEY_C,0);
    Keyboard.sendKeyReleased(KEY_A,0);
  }*/





  
  /*upState = digitalRead(upPin);

  if ((previousUpState != upState) && (upState == LOW)){
    Keyboard.sendKeyStroke(KEY_W, 0);
    delay(400);
  }
  previousUpState = upState;
  if (upState == LOW){
    Keyboard.sendKeyStrokeUnReleased(KEY_W);
  }
  if (upState == HIGH){
    Keyboard.sendKeyReleased(KEY_W,0);
  }
  
  /*leftState = digitalRead(leftPin);
  if ((previousLeftState != leftState) && (leftState == LOW)){
    Keyboard.sendKeyStroke(KEY_A, 0);
    delay(400);
  }
  previousUpState = leftState;
  if (leftState == LOW){
    Keyboard.sendKeyStroke(KEY_A,0);
  }
  ////////////

  leftState = digitalRead(leftPin);
  if (leftState == LOW){
    Keyboard.sendKeyStrokeUnReleased(KEY_A);
  }
  if (leftState == HIGH){
    Keyboard.sendKeyReleased(KEY_A,0);
  }
  

  
  rightState = digitalRead(rightPin);
  if (rightState == LOW){
    Keyboard.sendKeyStrokeUnReleased(22);
  }
  if (rightState == HIGH){
    Keyboard.sendKeyReleased(22,0);
  }

  downState = digitalRead(downPin);
  if (downState == LOW){
    Keyboard.sendKeyStrokeUnReleased(KEY_D);
  }
  if (downState == HIGH){
    Keyboard.sendKeyReleased(KEY_D,0);
  }*/
  /*downState = digitalRead(downPin);
  if (downState == LOW){
    Keyboard.sendKeyStrokeUnReleased(KEY_S);
  }
  if (downState == HIGH){
    Keyboard.sendKeyReleased(KEY_S,0);
  }*/

  escState = digitalRead(escPin);
  if (escState == LOW && escCount > 10){
    Keyboard.sendKeyStroke(KEY_P);
    escCount = 0;
  }
  
  itemState = digitalRead(itemPin);  
  if (itemState == LOW && itemCount > 10){
    Keyboard.sendKeyStroke(KEY_U);
    itemCount = 0;
    delay(200);
  }
  
  jumpState = digitalRead(jumpPin);
  if (jumpState == LOW && jumpCount > 10){
    Keyboard.sendKeyStroke(KEY_J);
    Keyboard.sendKeyStroke(KEY_ESCAPE);
    jumpCount = 0;
  }

  switchState = digitalRead(switchPin);  
  if (switchState == LOW && switchCount > 10){
    //Serial.println(8);
    Keyboard.sendKeyStroke(KEY_I);
    switchCount = 0;
    delay (200);
  }
  
  hitState = digitalRead(hitPin);  
  if (hitState == LOW && hitCount > 10){
    Keyboard.sendKeyStroke(KEY_K);
    Keyboard.sendKeyStroke(KEY_ENTER);
    hitCount = 0;
    delay (200);
  }
 }
