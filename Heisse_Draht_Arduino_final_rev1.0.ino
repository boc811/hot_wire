


/*******************************************************

  Der Heiße Draht, Björn Callsen Februar 2016, Rev 1.1 (Mit Grenzen)

********************************************************/

#include <LiquidCrystal.h>

int startBit = 0; //wenn das Startbit auf 1 und der Eingang "2" = 0, startet die Zeitaufnahme
int beep = 1;
unsigned long zeit, gesamtZeit = 0, fehler = 0, fehlerzeit = 3000;


// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  analogWrite(11, 0);
  lcd.setCursor(0, 0);
  lcd.print("Der heisse Draht");
  lcd.setCursor(0, 1);
  lcd.print("und los geht's!");
}

void loop() {

  //---------------------------------
  // Display Text Voreinstellungen
  //---------------------------------

  if (digitalRead(2) == 0)
  { zeit = millis();
    lcd.setCursor(0, 0);
    lcd.print("Zeit  :         ");
    lcd.setCursor(0, 1);
    lcd.print("Fehler:         ");
    fehler = 0;
    startBit = 1;
    beep = 1;
    analogWrite(11, 0);
  }

  //---------------------------------
  // Aufnahme der Zeit
  //---------------------------------

  if (digitalRead(2) == 1 and startBit == 1) {
    gesamtZeit = ((millis() - zeit) + fehlerzeit * fehler);
    lcd.setCursor(8, 0);
    lcd.print(gesamtZeit / 1000);
    lcd.setCursor(8, 1);
    lcd.print(fehler);
  };


  //---------------------------------
  // Fehler zählen Schleife
  //---------------------------------

  if (digitalRead(12)  == 0 and beep == 1)
  { digitalWrite(13, 1);
    analogWrite(11, 255);
    delay (500);
    digitalWrite(13, 0);
    analogWrite(11, 0);
    fehler++;
  };

  //---------------------------------
  // Anzeige Spielstand nachdem 2 Station erreicht wurde
  //---------------------------------

  if (digitalRead(3) == 0)
  { lcd.setCursor(0, 0);
    lcd.print("Zeit:     ");
    lcd.setCursor(6, 0);
    lcd.print(gesamtZeit / 1000);
     lcd.setCursor(10, 0);
    lcd.print("F: ");
    lcd.print(fehler);
    lcd.setCursor(13, 0);
 
  //---------------------------------
  // Grenzen festlegen
  //---------------------------------
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     
     if (gesamtZeit <= 10000)
     {lcd.print("Supersuperhero");};
     if (gesamtZeit <= 15000 and gesamtZeit > 10000)
     {lcd.print("Superman");};
     if (gesamtZeit <= 20000 and gesamtZeit > 15000)
     {lcd.print("Spiderman");};
      if (gesamtZeit <= 25000 and gesamtZeit > 20000)
     {lcd.print("Batman");};
     if (gesamtZeit <= 30000 and gesamtZeit > 25000)
     {lcd.print("Hulk");};
    if (gesamtZeit <= 35000 and gesamtZeit > 30000)
     {lcd.print("Iron Man");};
     if (gesamtZeit <= 40000 and gesamtZeit > 35000)
     {lcd.print("Inspector Gadget");};
      if (gesamtZeit <= 45000 and gesamtZeit > 40000)
     {lcd.print("Maulwurf");};
     if (gesamtZeit <= 50000 and gesamtZeit > 45000)
     {lcd.print("komischer Vogel");};
       if (gesamtZeit <= 55000 and gesamtZeit > 50000)
     {lcd.print("Nasenpups");};
    if (gesamtZeit <= 60000 and gesamtZeit > 55000)
     {lcd.print("Tolpatsch");};
     if (gesamtZeit <= 65000 and gesamtZeit > 60000)
     {lcd.print("Biene Maya");};
      if (gesamtZeit <= 70000 and gesamtZeit > 65000)
     {lcd.print("Niete");};
     if (gesamtZeit <= 75000 and gesamtZeit > 70000)
     {lcd.print("Lusche");};
     if (gesamtZeit <= 80000 and gesamtZeit > 75000)
     {lcd.print("Looser");};
       if (gesamtZeit > 80000)
     {lcd.print("Superlooser");};
      startBit = 0;


    if (beep == 1) {
      for (int i = 1; i <= 8; i++) {
        digitalWrite(13, 1);
        delay (50);
        digitalWrite(13, 0);
        delay (50);
      }
    }
    for (int helligkeit = 255; helligkeit >= 0; helligkeit --) {
      analogWrite(11, helligkeit);
      delay(1);
    }
    beep = 0;
  };
}


