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
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,72,255,0);
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
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30,90,255,0);
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
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,70,255,0);
  int B = frequency;
  //Print frequency
  Serial.println("B = ");
  Serial.println(frequency);
  Serial.println("  ");
  delay(100);

  if(R<=255 & R>=250 & G<=5 & G>=0 & B<=5 & B>=0 ){
    Serial.print("Rosso");
    wtv020sd16p.playVoice(1);
  }
  if(G<=255 & G>=250 & R<=5 & R>=0 & B<=5 & B>=0 ){
    Serial.print("Verde");
    wtv020sd16p.playVoice(2);
  }
  if(R<=255 & R>=250 & G<=255 & G>=250 & B<=5 & B>=0){
    Serial.print("Giallo");
    wtv020sd16p.playVoice(4);
  }
  if(B<=255 & B>=250 & R<=5 & R>=0 & G<=5 & G>=0 ){
    Serial.print("Blu");
    wtv020sd16p.playVoice(3);
  }
  if(G<=80 & G>=70 & R<=155 & R>=145 & B<=5 & B>=0){
    Serial.print("Marrone");
    wtv020sd16p.playVoice(5);
  }
  if(G<=5 & G>=0 & R<=5 & R>=0 & B<=5 & B>=0 ){
    Serial.print("Nero");
    wtv020sd16p.playVoice(6);
  }
  if(G<=255 & G>=250 & R<=255 & R>=250 & B<=255 & B>=250){
    Serial.print("Bianco");
    wtv020sd16p.playVoice(7);
  }
  if(G<=130 & G>=125 & R<=130 & R>=125 & B<=130 & B>=125 ){
    Serial.print("Grigio");
    wtv020sd16p.playVoice(8);
  }
  if(G<=170 & G>=160 & R<=255 & R>=250 & B<=5 & B>=0 ){
    Serial.print("Arancione");
    wtv020sd16p.playVoice(9);
  }
}
