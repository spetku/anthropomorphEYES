

const int rightEye = 1;  // Set to 0 for left eye,  1 for right eye.

// *************************************
// *IF YOU WANT A TOGGLE BUTTON TO CYCLE
// THROUGH EMOTIONS, ATTACH TO A5 PIN*
// *************************************
const int buttonPin = A5;
int mode = 0;
int buttonState = HIGH;
int lastButtonState = HIGH;
long lastDebounceTime = 0;
long debounceDelay = 50;

const long TIMERCOUNT = 10000;
long timer = TIMERCOUNT;

const int outPin=A4;
//const int inPin=A3;

// TEMP DEBUG
//const int ledPin = 13;      // the number of the LED pin
//int ledState = HIGH;

// ****************************************
// *THIS IS WHERE YOU ADD YOUR EXPRESSIONS*
// ****************************************

// d13, d3, d5, d7, d9, d11, d12, d2, d4, d6, d8, d10
int LED [] = {13, 3, 5, 7, 9, 11, 12, 2, 4, 6, 8, 10};

int blank[] = { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH };

//*SURPRISED*
//suprised L
// 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1
int suprisedL[] = {LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
//suprised R
// 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1
int suprisedR[] = {LOW, LOW, LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

//*LOOK LEFT*
//look left L
// 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1
int lookleftL[] = {LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, LOW, HIGH, HIGH, LOW, HIGH};
//look left R
// 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1
int lookleftR[] = {LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, LOW, HIGH, HIGH, LOW, HIGH};

//*LOOK RIGHT*
//look right L
// 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1
int lookrightL[] = {LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH};
//look right R
// 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1
int lookrightR[] = {LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH};

//*CONFUSED*
//confused L
// 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0
int confusedL[] = {HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW};
//confused R
// 0, 0, 1, 1, 0, 0, 1, 0, 1 ,1 ,0, 1
int confusedR[] = {LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, LOW, HIGH, HIGH, LOW, HIGH};

//*EYE ROLL*
//roll-eyes L
// 0. 0. 1. 1. 1. 0. 1. 1. 0. 1. 1. 0
int rolleyesL[] = {LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW};
//roll-eyes R
// 0. 0. 1. 1. 1. 0. 1. 1. 0. 1. 1. 0
int rolleyesR[] = {LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW};

//*STERN*
//stern L
// 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1
int sternL[] = {LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH};
//stern R
// 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1
int sternR[] = {LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH};
  
//*NERVOUS*
//nervous L
// 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1
int nervousL[] = {HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH};
//nervous R
// 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1
int nervousR[] = {HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH};

//*OVERWHELMED*
//over-whelmed L
// 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0
int overwhelmedL[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, HIGH, LOW};
//over-whelmed R
// 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1
int overwhelmedR[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH};

//*SAD*
//sad L
// 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0
int sadL[] = {HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW};
//sad R
// 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1
int sadR[] = {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH, HIGH};

//*ANGRY*
//angry L
// 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1
int angryL[] = {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH, HIGH};
//angry R
// 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0
int angryR[] = {HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW};

//*DRUNK*
//drunk L
// 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0
int drunkL[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW, LOW, HIGH, LOW};
//drunk R
// 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0
int drunkR[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW, LOW, HIGH, LOW};

//*EMBARRASSED*
//embarrassed L
// 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0
int embarrassedL[] = {HIGH, HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW};
//embarrassed R
// 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0
int embarrassedR[] = {HIGH, HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW};

//*BLINK*
//blink L
// 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0
int blinkL[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW};
//blink R
// 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0
int blinkR[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW};

//*GLEE*
//glee L
// 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1
int gleeL[] = {LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
//glee R
// 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1
int gleeR[] = {LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

//*ANNOIED* 
//annoied L
// 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1
int annoyedL[] = {LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW, HIGH, HIGH, HIGH};
//annoied R
// 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1
int annoyedR[] = {LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW, HIGH, HIGH, HIGH};

//*DEPRESSED*
//depressed L
// 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0
int depressedL[] = {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW};
//depressed R
// 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0
int depressedR[] = {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW};

int *modesL[] = {blank, blank,
                suprisedL, lookleftL, lookrightL, confusedL, 
                rolleyesL, sternL, nervousL, overwhelmedL, 
                sadL, angryL, drunkL, embarrassedL, 
                blinkL, gleeL, annoyedL, depressedL}; 
                
int *modesR[] = {blank, blank,
                suprisedR, lookleftR, lookrightR, confusedR, 
                rolleyesR, sternR, nervousR, overwhelmedR, 
                sadR, angryR, drunkR, embarrassedR, 
                blinkR, gleeR, annoyedR, depressedR}; 

int modeSize = 0;

void setup() {
  modeSize = sizeof(modesL)/sizeof(int*);
  
   pinMode(buttonPin, INPUT_PULLUP);
   
   // TEMP Debug
   //digitalWrite(ledPin, ledState);
   
   // Change to for loop using LED[]
    pinMode(13, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(10, OUTPUT);
 
    emotion(blank);
 
    pinMode(outPin, OUTPUT);
    digitalWrite(outPin, HIGH);
}

void loop() {

// **TESTING BUTTON PRESS COMMITMENT**
// **DOES YOUR BUTTON HAVE COMMITMENT PROBLEMS??**
// **THIS WILL FIGURE THAT OUT... FOR YOU...**

// read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is LOW
      if (buttonState == LOW) {
        // DEBUG
        //ledState = !ledState;
        mode++;
        if ( mode >= modeSize ) {
          mode = 0;
          timer = TIMERCOUNT;
        }
        digitalWrite(outPin, LOW);
        delay(100);
        digitalWrite(outPin, HIGH);
     }
    }
  }

// ********************************************
// *THIS IS WHERE YOU CHAIN YOUR EXPRESSIONS 
// TOGETHER TO DEFINE EMOTIONS AND PERSONALITY*
// ********************************************
  
  if ( !mode ) {
    // animate at mode 0
    timer--;
    if ( timer < 0 ) timer = TIMERCOUNT;
    
    if (!rightEye) {
      switch (timer) {
        case 9999:
          emotion(blinkR);
          break;
         case 9980:
          emotion( lookleftR );
          break;
        case 9000:
          emotion(blinkR);
          break;
        case 8980:
          emotion( lookrightR );
          break;
        case 7000:
          emotion(blinkR);
          break;
        case 6950:
          emotion( lookrightR );
          break;
        case 5000:
          emotion(blinkR);
          break;
        case 4980:
          emotion( lookleftR );
          break;
        case 4000:
          emotion(blinkR);
          break;
        case 3970:
          emotion(annoyedR);
          break;
        case 3300:
          emotion(blinkR);
          break;
        case 3280:
          emotion(annoyedR);
          break;
        case 2030:
          emotion(blinkR);
          break;
        case 1880:
          emotion(annoyedR);
          break;
        case 1830:
          emotion(blinkR);
          break;
        case 1810:
          emotion(annoyedR);
          break;
        case 900:
          emotion(rolleyesR);
          break;
          
        default:
          break;
      }
    } else {
      switch (timer) {
        case 9999:
          emotion(blinkL);
          break;
         case 9980:
          emotion( lookleftL );
          break;
        case 9000:
          emotion(blinkL);
          break;
        case 8980:
          emotion( lookrightL );
          break;
        case 7000:
          emotion(blinkR);
          break;
        case 6950:
          emotion( lookrightR );
          break;
        case 5000:
          emotion(blinkL);
          break;
        case 4980:
          emotion( lookleftL );
          break;
        case 4000:
          emotion(blinkL);
          break;
        case 3970:
          emotion(annoyedL);
          break;
        case 3300:
          emotion(blinkL);
          break;
        case 3280:
          emotion(annoyedL);
          break;
        case 2030:
          emotion(blinkL);
          break;
        case 1880:
          emotion(annoyedL);
          break;
        case 1830:
          emotion(blinkL);
          break;
        case 1810:
          emotion(annoyedL);
          break;
        case 900:
          emotion(rolleyesL);
          break;
          
        default:
          break;
      }
    }
    delay(3);
  } else {
    if(!rightEye){
      emotion( modesL[mode] );
    } else {
      emotion( modesR[mode] );
    }
  }
  
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  
  // TEMP DEBUG
   //digitalWrite(ledPin, ledState);
   
   lastButtonState = reading;
   
}


void emotion ( int* em){
  for(int i=0;i<sizeof(LED)/sizeof(int);i++){
   digitalWrite(LED[i],em[i]); 
  }
}
