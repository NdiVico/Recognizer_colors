/* Arduino Color Sensing
 *  program to detect colors with Arduino 
 */

#include <Wtv020sd16p.h>

  #define S0 11
  #define S1 10
  #define S2 9
  #define S3 7
  #define sensorOut 8
  #define button 6

  int resetPin = 2;  
  int clockPin = 3;  
  int dataPin = 4;  
  int busyPin = 5;

  int frequency = 0;
  int but = 0;

  Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);

  
void setup() {

  wtv020sd16p.reset();
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(button, INPUT);

  //Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);

  }

void loop() {

  but = digitalRead(button);
  
  if (but == HIGH){
    readColor();
    wtv020sd16p.playVoice(4);

  }

}

void readColor() {

  //Set red photodiodes
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  //Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  //Print frequency
  Serial.println("R = ");
  Serial.println(frequency);
  Serial.println("  ");
  delay(100);

  //Set green photodiodes
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  //Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  //Print frequency
  Serial.println("G = ");
  Serial.println(frequency);
  Serial.println("  ");
  delay(100);

  //Set blue photodiodes
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  //Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  //Print frequency
  Serial.println("B = ");
  Serial.println(frequency);
  Serial.println("  ");
  delay(100);

  if(R<70 & R>40 & G<220 & G>80){
    Serial.print("Rosso");
  }
  if(R<120 & R>90 & G<65 & G>40){
    Serial.print("Verde");
  }
  if(R<50 & R>24 & G<70 & G>30){
    Serial.print("Giallo");
  }
  
}

