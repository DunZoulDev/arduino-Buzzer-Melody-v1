int speakerPin = 4;
int length = 28; // the number of notes
char notesHBD[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beatsHBD[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tempo = 150;

void playTone(int tone, int duration) {
for (long i = 0; i < duration * 1000L; i += tone * 2) {
   digitalWrite(speakerPin, HIGH);
   delayMicroseconds(tone);
   digitalWrite(speakerPin, LOW);
   delayMicroseconds(tone);
}
}

void playNote(char note, int duration) {
char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           
                 'c', 'd', 'e', 'f', 'g', 'a', 'b',
                 'x', 'y' };

int tones[] = { 1915/200, 1700/200, 1519/200, 1432/200, 1275/200, 1136/200, 1014/200,
                 956/200,  834/200,  765/200,  593/200,  468/200,  346/200,  224/200,
                 655/200 , 715/200 };
int SPEE = 5;

// play the tone corresponding to the note name
for (int i = 0; i < 17; i++) {
   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);
   }
}
}

void setup() {
pinMode(speakerPin, OUTPUT);
}
void loop() {
for (int i = 0; i < length; i++) {

   if (notesHBD[i] == ' ') {
     delay(beatsHBD[i] * tempo); // rest
   } else {
     playNote(notesHBD[i], beatsHBD[i] * tempo);
   }
   delay(tempo);
}
}
