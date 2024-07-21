const int buzzer = 13;
const int inPins[] = {8, 9, 10, 11, 12};
const float toneFrequencies[] = {261.6, 293.7, 329.6, 349.2, 392};

void setup() {
  // defined buzzer pin as output
  pinMode(buzzer, OUTPUT);

  // defined all the input pins for buttons
  for(int i=0;i<sizeof(inPins)/sizeof(int);i++){
    pinMode(i, INPUT);
  }
}

void loop() {
  for(int i=0;i<5;i++){
    int val = digitalRead(inPins[i]);
    if(val == HIGH){
        tone(buzzer, toneFrequencies[i]);
        delay(1000);
    }
    noTone(buzzer);
  }
}
