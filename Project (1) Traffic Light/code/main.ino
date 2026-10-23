int Green1 = 5, Yellow1 = 6, Red1 = 7;
int Green2 = 11, Yellow2 = 12, Red2 = 13;
int Green3 = 8, Yellow3 = 9, Red3 = 10;
int Green4 = A0, Yellow4 = A1, Red4 = 4;

int ModeButton = 2;
int ManualButton = 3;
int BlueLed = A2;

volatile bool mode = true;
volatile bool modeChanged = false;
int m = 0;

void setup() {
    pinMode(Green1, OUTPUT); pinMode(Yellow1, OUTPUT); pinMode(Red1, OUTPUT);
    pinMode(Green2, OUTPUT); pinMode(Yellow2, OUTPUT); pinMode(Red2, OUTPUT);
    pinMode(Green3, OUTPUT); pinMode(Yellow3, OUTPUT); pinMode(Red3, OUTPUT);
    pinMode(Green4, OUTPUT); pinMode(Yellow4, OUTPUT); pinMode(Red4, OUTPUT);

    pinMode(ModeButton, INPUT_PULLUP);
    pinMode(ManualButton, INPUT_PULLUP);
    pinMode(BlueLed, OUTPUT);

    attachInterrupt(digitalPinToInterrupt(ModeButton), ch, FALLING);

    allOff();

    digitalWrite(Red1, HIGH);
    digitalWrite(Red2, HIGH);
    digitalWrite(Red3, HIGH);
    digitalWrite(Red4, HIGH);
}

void loop() {
    if (modeChanged) {

     if (m == 0) autoSignal(Green1, Yellow1, Red1);
     else if (m == 1) autoSignal(Green2, Yellow2, Red2);
     else if (m == 2) autoSignal(Green3, Yellow3, Red3);
     else if (m == 3) autoSignal(Green4, Yellow4, Red4);

    } else {

        if (digitalRead(ManualButton) == LOW) {
            changeManual();
        }

        allOff();
  if (m == 0) { digitalWrite(Green1, HIGH); digitalWrite(Red2, HIGH); digitalWrite(Red3, HIGH);
digitalWrite(Red4, HIGH); }
  if (m == 1) { digitalWrite(Green2, HIGH); digitalWrite(Red1, HIGH); digitalWrite(Red3, HIGH);
digitalWrite(Red4, HIGH); }
  if (m == 2) { digitalWrite(Green3, HIGH); digitalWrite(Red1, HIGH); digitalWrite(Red2, HIGH);
digitalWrite(Red4, HIGH); }
  if (m == 3) { digitalWrite(Green4, HIGH); digitalWrite(Red1, HIGH); digitalWrite(Red2, HIGH);
digitalWrite(Red3, HIGH); }
    }
}

void allOff() {
    digitalWrite(Green1, LOW); digitalWrite(Yellow1, LOW); digitalWrite(Red1, LOW);
    digitalWrite(Green2, LOW); digitalWrite(Yellow2, LOW); digitalWrite(Red2, LOW);
    digitalWrite(Green3, LOW); digitalWrite(Yellow3, LOW); digitalWrite(Red3, LOW);
    digitalWrite(Green4, LOW); digitalWrite(Yellow4, LOW); digitalWrite(Red4, LOW);
}

void autoSignal(int g, int y, int r) {
    allOff();

    if (r != Red1) digitalWrite(Red1, HIGH);
    if (r != Red2) digitalWrite(Red2, HIGH);
    if (r != Red3) digitalWrite(Red3, HIGH);
    if (r != Red4) digitalWrite(Red4, HIGH);

    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);

    for (int i = 0; i < 50; i++) {
        delay(100);
        if (modeChanged) return;

    }

    blinkGreen(g);
    digitalWrite(g, LOW);
    digitalWrite(y, HIGH);

    for (int i = 0; i < 20; i++) {
        delay(100);
        if (modeChanged) return;
    }

    digitalWrite(y, LOW);
    digitalWrite(r, HIGH);

    m++;
    if (m > 3) m = 0;
}

void blinkGreen(int led) {
    for (int i = 0; i < 3; i++) {
        digitalWrite(led, LOW);
        delay(200);
        digitalWrite(led, HIGH);
        delay(200);
        if (modeChanged) return;
    }
}

void changeManual() {

 if (m == 0) { blinkGreen(Green1); digitalWrite(Green1, LOW); digitalWrite(Yellow1, HIGH);
delay(2000); digitalWrite(Yellow1, LOW); digitalWrite(Red1, HIGH); }
 if (m == 1) { blinkGreen(Green2); digitalWrite(Green2, LOW); digitalWrite(Yellow2, HIGH);
delay(2000); digitalWrite(Yellow2, LOW); digitalWrite(Red2, HIGH); }
 if (m == 2) { blinkGreen(Green3); digitalWrite(Green3, LOW); digitalWrite(Yellow3, HIGH);
delay(2000); digitalWrite(Yellow3, LOW); digitalWrite(Red3, HIGH); }
 if (m == 3) { blinkGreen(Green4); digitalWrite(Green4, LOW); digitalWrite(Yellow4, HIGH);
delay(2000); digitalWrite(Yellow4, LOW); digitalWrite(Red4, HIGH); }

    m++;

    if (m > 3) m = 0;
    delay(300);
}

void ch() {
    modeChanged = !modeChanged;
    digitalWrite(BlueLed, modeChanged);
    delay(300);
}
