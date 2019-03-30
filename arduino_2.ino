#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(368, 5, NEO_GRB + NEO_KHZ800);

bool pattern1[] =  {
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,

  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,

  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,

  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,

  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,

  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false, true, true, true, false, false, false,
  true, true, true, false, false, false
};

bool pattern2[] =  {
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,

  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,

  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,

  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,

  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,

  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false, false, true, true, true, false, false,
  false, true, true, true, false, false
};
bool pattern3[] =  {
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false, false, false, true, true, true, false,
  false, false, true, true, true, false
};
bool pattern4[] =  {
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,

  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true, false, false, false, true, true, true,
  false, false, false, true, true, true
};
bool pattern5[] =  {
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,

  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,

  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,

  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,

  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,

  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true, true, false, false, false, true, true,
  true, false, false, false, true, true

};
bool pattern6[] =  {
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true, true, true, false, false, false, true,
  true, true, false, false, false, true
};


byte gamma8[] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
  2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
  10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
  17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
  25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
  37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
  51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
  69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
  90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
  115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
  144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
  177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
  215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
};

byte frame = 1;
int mode = 0;
bool invert = false;

bool notlicht_part1 = false;
bool notlicht_part2 = false;

long trigger_ms = millis();
byte verzoegerung = 10;

void setup() {
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void setCorrectedPixelColor(int index, byte r, byte g, byte b, byte correction[]) {
  strip.setPixelColor(index, correction[r], correction[g], correction[b]);
}

void setCorrectedPattern(bool pattern[]) {
  for (int i = 0; i <= 368; i++) {
    if (pattern[i]) {
      setCorrectedPixelColor(i, 33, 255, 74, gamma8);
    } else {
      strip.setPixelColor(i, 0, 0, 0);
    }
  }
}

void resetLEDS() {
  for (int i = 0; i <= strip.numPixels(); i++ ) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}

void loop() {

  if (millis() > trigger_ms + verzoegerung ) {

    // TRIGGER AUSLÖSEN
    trigger_ms = millis() + verzoegerung;

    if (mode == 0) {
      for (int i = 0; i <= 368; i++) {
        strip.setPixelColor(i, 0, 0, 0);
      }
    }

    if (mode == 1) {
      if (notlicht_part1) {
        for (int i = 0; i <= 183; i++) {
          strip.setPixelColor(i, 127, 127, 127);
        }
      } if (!notlicht_part1) {
        for (int i = 0; i <= 183; i++) {
          strip.setPixelColor(i, 0, 0, 0);
        }
      }

      if (notlicht_part2) {
        for (int i = 184; i <= 367; i++) {
          strip.setPixelColor(i, 127, 127, 127);
        }
      } if (!notlicht_part2) {
        for (int i = 184; i <= 367; i++) {
          strip.setPixelColor(i, 0, 0, 0);
        }
      }
    }

    if (mode == 2) {
      if (!invert) {
        switch (frame) {
          case 1:
            setCorrectedPattern(pattern1);
            frame++;
            break;

          case 2:
            setCorrectedPattern(pattern2);
            frame++;
            break;

          case 3:
            setCorrectedPattern(pattern3);
            frame++;
            break;

          case 4:
            setCorrectedPattern(pattern4);
            frame++;
            break;

          case 5:
            setCorrectedPattern(pattern5);
            frame++;
            break;

          case 6:
            setCorrectedPattern(pattern6);
            frame = 1;
            break;
        }
      }

      if (invert) {
        switch (frame) {
          case 1:
            setCorrectedPattern(pattern6);
            frame++;
            break;

          case 2:
            setCorrectedPattern(pattern5);
            frame++;
            break;

          case 3:
            setCorrectedPattern(pattern4);
            frame++;
            break;

          case 4:
            setCorrectedPattern(pattern3);
            frame++;
            break;

          case 5:
            setCorrectedPattern(pattern2);
            frame++;
            break;

          case 6:
            setCorrectedPattern(pattern1);
            frame = 1;
            break;
        }
      }
    }

    strip.show();
  }


  handleLauflichtInput();
}

bool input_freigegeben_lauflicht_1 = true;
bool input_freigegeben_lauflicht_2 = true;

bool input_freigegeben_notlicht_1 = true;
bool input_freigegeben_notlicht_2 = true;

void handleLauflichtInput() {

  // LAUFLICHT ---------------------------------------------//

  if (digitalRead(28) == 1 && input_freigegeben_lauflicht_1) {
    if (mode == 2) {
      mode = 0;
      digitalWrite(32, LOW);
      digitalWrite(30, LOW);
    } else {
      mode = 2;
      digitalWrite(32, LOW);
      digitalWrite(30, HIGH);
      invert = false;
    }
    input_freigegeben_lauflicht_1 = false;
    Serial.println("Lüfter nach links");

    return;
  }
  if (digitalRead(28) == 0 && !input_freigegeben_lauflicht_1) {
    input_freigegeben_lauflicht_1 = true;
    Serial.println("freigegeben");
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

  if (digitalRead(26) == 1 && input_freigegeben_lauflicht_2) {
    if (mode == 2) {
      mode = 0;
      digitalWrite(30, LOW);
      digitalWrite(32, LOW);
    } else {
      mode = 2;
      invert = true;
      digitalWrite(30, LOW);
      digitalWrite(32, HIGH);
    }
    input_freigegeben_lauflicht_2 = false;
    Serial.println("Lüfter nach rechts");

    return;
  }
  if (digitalRead(26) == 0 && !input_freigegeben_lauflicht_2) {
    input_freigegeben_lauflicht_2 = true;
    Serial.println("freigegeben");
  }

  // NOTLICHT ---------------------------------------------//

  if (digitalRead(24) == 1 && input_freigegeben_notlicht_1 && mode != 2) {
    notlicht_part1 = !notlicht_part1;
    mode = 1;
    input_freigegeben_notlicht_1 = false;
    return;
  }
  if (digitalRead(24) == 0 && !input_freigegeben_notlicht_1) {
    input_freigegeben_notlicht_1 = true;
    Serial.println("freigegeben");
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

  if (digitalRead(22) == 1 && input_freigegeben_notlicht_2 && mode != 2) {
    notlicht_part2 = !notlicht_part2;
    mode = 1;
    input_freigegeben_notlicht_2 = false;

    return;
  }
  if (digitalRead(22) == 0 && !input_freigegeben_notlicht_2) {
    input_freigegeben_notlicht_2 = true;
    Serial.println("freigegeben");
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - //



}
