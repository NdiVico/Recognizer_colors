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

  if(R<70 & R>30 & G<220 & G>60 & B<135 & B>100 ){
    Serial.print("Rosso");
    wtv020sd16p.playVoice(1);
  }
   else if(R<120 & R>60 & G<75 & G>30 & B<70 & B>50 ){
    Serial.print("Verde");
    wtv020sd16p.playVoice(2);
  }
  else if(R<50 & R>24 & G<60 & G>30 & B<70 & B>30){
    Serial.print("Giallo");
    wtv020sd16p.playVoice(4);
  }
  else if(R<110 & R>70 & G<90 & G>60 & B<60 & B>35 ){
    Serial.print("Blu");
    wtv020sd16p.playVoice(3);
  }
  else if(R<130 & R>100 & G<150 & G>120 & B<110 & B>80){
    Serial.print("Marrone");
    wtv020sd16p.playVoice(5);
  }
  else if(R<380 & R>200 & G<390 & G>200 & B<290 & B>150 ){
    Serial.print("Nero");
    wtv020sd16p.playVoice(6);
  }
  else if(R<40 & R>20 & G<40 & G>20 & B<30 & B>15 ){
    Serial.print("Bianco");
    wtv020sd16p.playVoice(7);
  }
  else if(R<25 & R>10 & G<20 & G>10 & B<20 & B>10 ){
    Serial.print("Grigio");
    wtv020sd16p.playVoice(8);
  }
  else {
    Serial.print("colore non rilevato");
    wtv020sd16p.playVoice(11);
  }
  
}

