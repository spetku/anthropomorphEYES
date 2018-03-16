// *******************************************
// [!] THIS PROGRAM TESTS THE EYE SEGMENTS [!]
// *******************************************

// d13, d3, d5, d7, d9, d11, d12, d2, d4, d6, d8, d10
int LED [] = {13, 3, 5, 7, 9, 11, 12, 2, 4, 6, 8, 10};

void setup() {

  for ( int i = 0; i < 12; i++) {
    pinMode(LED[i], OUTPUT);
  }
  for ( int i = 0; i < 12; i++) {
    digitalWrite(LED[i], HIGH);
  }
}

void loop() {

  for ( int i = 0; i < 12; i++) {
    digitalWrite(LED[i], LOW);
    delay(1000);
    digitalWrite(LED[i], HIGH);
    delay(300);
  }
}
