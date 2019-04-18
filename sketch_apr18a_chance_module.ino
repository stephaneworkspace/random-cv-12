// change the pwm dury cycle as needed (0-255)
// https://github.com/amokan/arduino-cv/blob/master/arduinoCV/arduinoCV.ino
int pwm = 0;
int timer = 20;

long portPotChance = A0;
long portPotChoice = A1;
long portJackIn = A2;
long valeurPotChance;
long valeurPotChoice;
long valeurJackIn = A3;
float valeurJackInFloat = A3;

int OUTPUTJACK = 3; // Pin 3
int analogWriteValue; // Use this variable to write 0-5V to the jackOut
int oldAnalaogWriteValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // int POT = A0 en haut
  // pinMode(POT, INPUT) facultatif
  pinMode(OUTPUTJACK, OUTPUT);
  // set freq to 61.5 khz
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20); 
}

void loop() { 
  // put your main code here, to run repeatedly:
  valeurPotChance = analogRead(portPotChance);
  valeurPotChoice = analogRead(portPotChoice);
/*
  // loop the duty cycle from 0-255.
  for(int i = 0; i <= 255; i++) {
    pwm = i;
    OCR2A = pwm;
    delay(1);
  }*/
  
  valeurJackIn = analogRead(portJackIn);
  valeurJackInFloat = valeurJackIn * (4.97 / 1023.0);
  // float voltage = sensorValue * (4.97 / 1023.0);

  // Pot chance dans CV (inutile)
  // analogWriteValue = (255./1023.) * valeurPotChance;
  // analogWrite(OUTPUTJACK, analogWriteValue);

  // JackIn -> JackOut
  // analogWriteValue = valeurJackIn * (4.97 / 1023.0);
  // analogWriteValue = (255./1023.) * valeurJackIn;
   //valeurJackIn = random(125);
   
  valeurJackIn = random(63);
  analogWriteValue = map(valeurJackIn, 0, 1023, 0, 1023);

  analogWrite(OUTPUTJACK, analogWriteValue);
  // Serial.println(analogWriteValue);
/*
  Serial.println("\n\nChance:");
  Serial.println(valeurPotChance);
  Serial.println("\nChoicee:");
  Serial.println(valeurPotChoice);  
  Serial.println();*/
  delay(1);
}
