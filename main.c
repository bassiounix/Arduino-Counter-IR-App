#define IR 12

byte seg[7];
byte counter = 0;
bool state = 0;

void writeDigit(int n);
void clearDigit();

void setup() {
  for (int i = 8; i >= 2; i--) {
    seg[8 - i] = i;
    pinMode(i, OUTPUT);
  }
  pinMode(IR, INPUT);
//  Serial.begin(9600);
}

void loop() {
  byte reader = digitalRead(IR);
  if (state == 0) {
    switch (reader) {
      case 1 : 
        state = 1; 
        
        if (counter == 10) counter = 1;
        clearDigit();
        writeDigit(counter);
        counter++;
        break;
      case 0: 
        state = 0;
        break;
    }
  }

  if (reader == LOW) {
    state = 0;
  }
  
}

void writeDigit(int n) {
  for (int i = 0; i < 7; i++) {
    switch (n) {
      case 0:
        if (i != 5) digitalWrite(seg[i], HIGH);
        break;
      case 1:
        if (i == 1 || i == 2) digitalWrite(seg[i], HIGH);
        break;
      case 2:
        if (i != 6 && i != 2) digitalWrite(seg[i], HIGH);
        break;
      case 3:
        if (i != 6 && i != 4) digitalWrite(seg[i], HIGH);
        break;
      case 4:
        if (i != 0 && i != 3 && i != 4) digitalWrite(seg[i], HIGH);
        break;
      case 5:
        if (i != 1 && i != 4) digitalWrite(seg[i], HIGH);
        break;
      case 6:
        if (i != 1) digitalWrite(seg[i], HIGH);
        break;
      case 7:
        if (i == 0 || i == 1 || i == 2) digitalWrite(seg[i], HIGH);
        break;
      case 8:
        digitalWrite(seg[i], HIGH);
        break;
      case 9:
        if (i != 4) digitalWrite(seg[i], HIGH);
        break;
    }
  }
}

void clearDigit() {
  for (int i = 0; i < 7; i++) digitalWrite(seg[i], LOW); 
}
