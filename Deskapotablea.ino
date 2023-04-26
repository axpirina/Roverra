#include <Traktorinoa.h>
#include <Servo.h>

Traktorinoa niretraktorinoa;
Servo nireSerboa; // Serbo objetua sortzen du

void setup()
{
  Serial.begin(9600);
nireSerboa.attach(9); // Serboa  Arduinoko 6. Pin-era
nireSerboa.write(90);
}

void loop() {

  if (Serial.available() > 0) {
    char data = Serial.read(); // bluetooth modulutik datorren datua irakurri
    switch (data)
    {
      case 'a': niretraktorinoa.aurrera(); break; 
      case 'b': niretraktorinoa.atzera(); break; 
      case 'c': niretraktorinoa.ezkerrera(); break; 
      case 'd': niretraktorinoa.eskuinera(); break; 
      case 'i': nireSerboa.write(90); break;
      case 'e': nireSerboa.write(180); break;
      case 'p': niretraktorinoa.geratu(); break;  
      default : break;
    }
  }
  delay(50);
 }
