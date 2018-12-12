/*
LED dice for ATmega328P

Copyright (C) 2018 Thomas Kummer
licensed under the GNU General Public License v3.0


*/

int PinLedGr1 = 13;       //Pins for the LED Groups
int PinLedGr2 = 11; 
int PinLedGr3 = 10;
int PinLedGr4 = 12;
int PinButton = 9;        //Pin for Button
int buttonState;
char ran;                 //Random number for dice
int time;                 //Delay time
int i;                    //dice ’rolling’ counter

void setup() {
  Serial.begin(9600);
  pinMode (PinLedGr1, OUTPUT);
  pinMode (PinLedGr2, OUTPUT);
  pinMode (PinLedGr3, OUTPUT);
  pinMode (PinLedGr4, OUTPUT);
  pinMode (PinButton, INPUT);
  randomSeed(analogRead(0));
}

void dice () {
  time = 20;                //timer for rolling effect
  i=0;                      //counter for rolling effect to zero
    while (i<10) {          //start rolling loop 
      if(i==9) time=5000;   //until it flipped 9 times, 5 sec final delay
      time=time+40;         //makes the 'rolling' slower
      i++;                  //increase the counter
      ran = random(1, 7);   //generate number between 1 and 6
      switch(ran) {         //switsh on LED groups to appear like a phycical dice. Knowledge how a dice looks is expected 
        case 1: digitalWrite (PinLedGr4, HIGH); //led group on
                delay (time);                   
                led_off();  //function to turn of leds
                break;
        case 2: digitalWrite (PinLedGr1, HIGH);
                delay (time);
                led_off();
                break;
        case 3: digitalWrite (PinLedGr3, HIGH);
                digitalWrite (PinLedGr4, HIGH);
                delay (time);
                led_off();
                break;
        case 4: digitalWrite (PinLedGr1, HIGH);
                digitalWrite (PinLedGr3, HIGH);
                delay (time);
                led_off();
                break;
        case 5: digitalWrite (PinLedGr1, HIGH);
                digitalWrite (PinLedGr3, HIGH);
                digitalWrite (PinLedGr4, HIGH);
                delay (time);
                led_off();
                break;
        case 6: digitalWrite (PinLedGr1, HIGH);
                digitalWrite (PinLedGr2, HIGH);
                digitalWrite (PinLedGr3, HIGH);
                delay (time);
                led_off();
                break;
      }
    }
}

void led_off() {            //function to turn of leds
  digitalWrite (PinLedGr1, LOW);
  digitalWrite (PinLedGr2, LOW);
  digitalWrite (PinLedGr3, LOW);
  digitalWrite (PinLedGr4, LOW);
}

void loop() {               //the allways running loop
buttonState = digitalRead(PinButton);
  if (buttonState == HIGH) dice();  //run function 'dice' when button is pressed

  
}
