const int buzzerPin = 21;

// Notes in Hz
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// Melody for "Happy Birthday"
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4,4,2,2,2,1,
  4,4,2,2,2,1,
  4,4,2,2,2,2,2,
  4,4,2,2,2,1
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int melodyLength = sizeof(melody)/sizeof(melody[0]);

  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // Pause between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }

  delay(2000); // Wait 2 seconds before repeating
}
