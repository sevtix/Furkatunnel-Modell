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

byte pattern_index = 1;
byte animation_delay = 10;
long animation_timestamp = 0L;

// NOTLICHT PART 1

bool notlicht_1_part1_unlock = true;
int notlicht_1_part1_counter = 0;
int notlicht_1_part1_delay_ms = 250;
int notlicht_1_part1_read_delay = 2;
bool notlicht_1_part1_countermode = false;
long notlicht_1_part1_timestamp = 0L;
long notlicht_1_part1_timestamp_read = 0L;

bool notlicht_1_part2_unlock = true;
int notlicht_1_part2_counter = 0;
int notlicht_1_part2_delay_ms = 250;
int notlicht_1_part2_read_delay = 2;
bool notlicht_1_part2_countermode = false;
long notlicht_1_part2_timestamp = 0L;
long notlicht_1_part2_timestamp_read = 0L;

// LAUFLICHT

bool lauflicht_1_part1_unlock = true;
int lauflicht_1_part1_counter = 0;
int lauflicht_1_part1_delay_ms = 250;
int lauflicht_1_part1_read_delay = 2;
bool lauflicht_1_part1_countermode = false;
long lauflicht_1_part1_timestamp = 0L;
long lauflicht_1_part1_timestamp_read = 0L;

bool lauflicht_1_part2_unlock = true;
int lauflicht_1_part2_counter = 0;
int lauflicht_1_part2_delay_ms = 250;
int lauflicht_1_part2_read_delay = 2;
bool lauflicht_1_part2_countermode = false;
long lauflicht_1_part2_timestamp = 0L;
long lauflicht_1_part2_timestamp_read = 0L;

byte abschnitt_state_1 = 0;
byte abschnitt_state_2 = 0;
byte abschnitt_state_3 = 0;
byte abschnitt_state_4 = 0;
byte abschnitt_state_5 = 0;
byte abschnitt_state_6 = 0;
byte abschnitt_state_7 = 0;
byte abschnitt_state_8 = 0;

bool reverse = true;

void setup() {
  Serial.begin(9600);
  strip.begin();
}

void extendTimespan(byte b) {
  switch (b) {
    case 1:
      notlicht_1_part1_timestamp = millis() + notlicht_1_part1_delay_ms;
      break;
    case 2:
      notlicht_1_part2_timestamp = millis() + notlicht_1_part2_delay_ms;
      break;
    case 3:
      lauflicht_1_part1_timestamp = millis() + lauflicht_1_part1_delay_ms;
      break;
    case 4:
      lauflicht_1_part2_timestamp = millis() + lauflicht_1_part2_delay_ms;
      break;

  }

}

void loop() {

  byte notlicht_1_part1 = digitalRead(22);
  byte notlicht_1_part2 = digitalRead(28);

  byte lauflicht_1_part1 = digitalRead(26);
  byte lauflicht_1_part2 = digitalRead(24);

  if (animation_timestamp < millis()) {
    animation_timestamp = millis() + animation_delay;

    switch (reverse) {
      case true:
        if (pattern_index > 1) {
          pattern_index--;
          return;
        }
        if (pattern_index == 1) {
          pattern_index = 6;
          return;
        }
        break;

      case false:
        if (pattern_index < 6) {
          pattern_index++;
          return;
        }
        if (pattern_index == 6) {
          pattern_index = 1;
          return;
        }
        break;
    }


  }

  setAbschnitt(0, 32, abschnitt_state_1);
  setAbschnitt(32, 62, abschnitt_state_2);
  setAbschnitt(62, 156, abschnitt_state_3);
  setAbschnitt(156, 184, abschnitt_state_4);
  setAbschnitt(184, 213, abschnitt_state_5);
  setAbschnitt(213, 307, abschnitt_state_6);
  setAbschnitt(307, 340, abschnitt_state_7);
  setAbschnitt(340, 367, abschnitt_state_8);

  strip.show();
  // INPUTS

  // NOTLICHT PART 1 ------------------------------------------------------------------------------------

  if (notlicht_1_part1_timestamp_read < millis())  {
    if (notlicht_1_part1 == 0 && !notlicht_1_part1_unlock) {
      notlicht_1_part1_unlock = true;
    }

    if (notlicht_1_part1 == 1 && notlicht_1_part1_unlock) {
      notlicht_1_part1_unlock = false;

      switch (notlicht_1_part1_countermode) {
        case true:
          notlicht_1_part1_counter++;
          extendTimespan(1);
          return;
          break;

        case false:
          notlicht_1_part1_counter++;
          extendTimespan(1);
          notlicht_1_part1_countermode = true;
          break;
      }
    }
    notlicht_1_part1_timestamp_read = millis() + notlicht_1_part1_read_delay;
  }

  if (notlicht_1_part1_timestamp < millis()) {
    if (notlicht_1_part1_countermode) {

      Serial.print("Notlicht Part 1: ");
      Serial.println(notlicht_1_part1_counter);

      switch (notlicht_1_part1_counter) {
        case 1:
          switch (abschnitt_state_1) {
            case 0:
              abschnitt_state_1 = 1;
              break;
            case 1:
              abschnitt_state_1 = 0;
              break;
          }
          break;

        case 2:
          switch (abschnitt_state_2) {
            case 0:
              abschnitt_state_2 = 1;
              break;
            case 1:
              abschnitt_state_2 = 0;
              break;
          }
          break;

        case 3:
          switch (abschnitt_state_3) {
            case 0:
              abschnitt_state_3 = 1;
              break;
            case 1:
              abschnitt_state_3 = 0;
              break;
          }
          break;

        case 4:
          switch (abschnitt_state_4) {
            case 0:
              abschnitt_state_4 = 1;
              break;
            case 1:
              abschnitt_state_4 = 0;
              break;
          }
          break;
      }

      notlicht_1_part1_countermode = false;
      notlicht_1_part1_counter = 0;
    }
  }

  // NOTLICHT PART 2 ------------------------------------------------------------------------------------

  if (notlicht_1_part2_timestamp_read < millis())  {
    if (notlicht_1_part2 == 0 && !notlicht_1_part2_unlock) {
      notlicht_1_part2_unlock = true;
    }

    if (notlicht_1_part2 == 1 && notlicht_1_part2_unlock) {
      notlicht_1_part2_unlock = false;

      switch (notlicht_1_part2_countermode) {
        case true:
          notlicht_1_part2_counter++;
          extendTimespan(2);
          return;
          break;

        case false:
          notlicht_1_part2_counter++;
          extendTimespan(2);
          notlicht_1_part2_countermode = true;
          break;
      }
    }
    notlicht_1_part2_timestamp_read = millis() + notlicht_1_part2_read_delay;
  }

  if (notlicht_1_part2_timestamp < millis()) {
    if (notlicht_1_part2_countermode) {

      Serial.print("Notlicht Part 2: ");
      Serial.println(notlicht_1_part2_counter);
      switch (notlicht_1_part2_counter) {
        case 1:
          switch (abschnitt_state_5) {
            case 0:
              abschnitt_state_5 = 1;
              break;
            case 1:
              abschnitt_state_5 = 0;
              break;
          }
          break;

        case 2:
          switch (abschnitt_state_6) {
            case 0:
              abschnitt_state_6 = 1;
              break;
            case 1:
              abschnitt_state_6 = 0;
              break;
          }
          break;

        case 3:
          switch (abschnitt_state_7) {
            case 0:
              abschnitt_state_7 = 1;
              break;
            case 1:
              abschnitt_state_7 = 0;
              break;
          }
          break;

        case 4:
          switch (abschnitt_state_8) {
            case 0:
              abschnitt_state_8 = 1;
              break;
            case 1:
              abschnitt_state_8 = 0;
              break;
          }
          break;
      }

      notlicht_1_part2_countermode = false;
      notlicht_1_part2_counter = 0;
    }
  }

  // LAUFLICHT ------------------------------------------------------------------------------------

  if (lauflicht_1_part1_timestamp_read < millis())  {
    if (lauflicht_1_part1 == 0 && !lauflicht_1_part1_unlock) {
      lauflicht_1_part1_unlock = true;
    }

    if (lauflicht_1_part1 == 1 && lauflicht_1_part1_unlock) {
      lauflicht_1_part1_unlock = false;

      switch (lauflicht_1_part1_countermode) {
        case true:
          lauflicht_1_part1_counter++;
          extendTimespan(3);
          return;
          break;

        case false:
          lauflicht_1_part1_counter++;
          extendTimespan(3);
          lauflicht_1_part1_countermode = true;
          break;
      }
    }
    lauflicht_1_part1_timestamp_read = millis() + lauflicht_1_part1_read_delay;
  }

  if (lauflicht_1_part1_timestamp < millis()) {
    if (lauflicht_1_part1_countermode) {

      switch (lauflicht_1_part1_counter) {
        case 1:
          switch (abschnitt_state_1) {
            case 0:
              reverse = true;
              abschnitt_state_1 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_1 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_1 = 0;
              }
              break;
          }
          break;
        case 2:
          switch (abschnitt_state_2) {
            case 0:
              reverse = true;
              abschnitt_state_2 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_2 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_2 = 0;
              }
              break;
          }
          break;
        case 3:
          switch (abschnitt_state_3) {
            case 0:
              reverse = true;
              abschnitt_state_3 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_3 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_3 = 0;
              }
              break;
          }
          break;
        case 4:
          switch (abschnitt_state_4) {
            case 0:
              reverse = true;
              abschnitt_state_4 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_4 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_4 = 0;
              }
              break;
          }
          break;
        case 5:
          switch (abschnitt_state_5) {
            case 0:
              reverse = true;
              abschnitt_state_5 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_5 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_5 = 0;
              }
              break;
          }
          break;
        case 6:
          switch (abschnitt_state_6) {
            case 0:
              reverse = true;
              abschnitt_state_6 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_6 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_6 = 0;
              }
              break;
          }
          break;
        case 7:
          switch (abschnitt_state_7) {
            case 0:
              reverse = true;
              abschnitt_state_7 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_7 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_7 = 0;
              }
              break;
          }
          break;
        case 8:
          switch (abschnitt_state_8) {
            case 0:
              reverse = true;
              abschnitt_state_8 = 2;
              break;
            case 1:
              reverse = true;
              abschnitt_state_8 = 2;
              break;
            case 2:
              if (reverse == false) {
                reverse = true;
              } else {
                abschnitt_state_8 = 0;
              }
              break;
          }
          break;
      }

      lauflicht_1_part1_countermode = false;
      lauflicht_1_part1_counter = 0;
    }
  }

  // LAUFLICHT PART 2 ------------------------------------------------------------------------------------

  if (lauflicht_1_part2_timestamp_read < millis())  {
    if (lauflicht_1_part2 == 0 && !lauflicht_1_part2_unlock) {
      lauflicht_1_part2_unlock = true;
    }

    if (lauflicht_1_part2 == 1 && lauflicht_1_part2_unlock) {
      lauflicht_1_part2_unlock = false;

      switch (lauflicht_1_part2_countermode) {
        case true:
          lauflicht_1_part2_counter++;
          extendTimespan(4);
          return;
          break;

        case false:
          lauflicht_1_part2_counter++;
          extendTimespan(4);
          lauflicht_1_part2_countermode = true;
          break;
      }
    }
    lauflicht_1_part2_timestamp_read = millis() + lauflicht_1_part2_read_delay;
  }

  if (lauflicht_1_part2_timestamp < millis()) {
    if (lauflicht_1_part2_countermode) {

      switch (lauflicht_1_part2_counter) {
        case 1:
          switch (abschnitt_state_1) {
            case 0:
              reverse = false;
              abschnitt_state_1 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_1 = 2;
              break;
            case 2:
              if (reverse == true) {
                reverse = false;
              } else {
                abschnitt_state_1 = 0;
              }
              break;
          }
          break;
        case 2:
          switch (abschnitt_state_2) {
            case 0:
              reverse = false;
              abschnitt_state_2 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_2 = 2;
              break;
            case 2:
              if (reverse == true) {
                reverse = false;
              } else {
                abschnitt_state_2 = 0;
              }
              break;
          }
          break;
        case 3:
          switch (abschnitt_state_3) {
            case 0:
              reverse = false;
              abschnitt_state_3 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_3 = 2;
              break;
            case 2:
              if (reverse == true) {
                reverse = false;
              } else {
                abschnitt_state_3 = 0;
              }
              break;
          }
          break;
        case 4:
          switch (abschnitt_state_4) {
            case 0:
              reverse = false;
              abschnitt_state_4 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_4 = 2;
              break;
            case 2:
              if (reverse == true) {
                reverse = false;
              } else {
                abschnitt_state_4 = 0;
              }
              break;
          }
          break;
        case 5:
          switch (abschnitt_state_5) {
            case 0:
              reverse = false;
              abschnitt_state_5 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_5 = 2;
              break;
            case 2:
              if (reverse == true) {
                reverse = false;
              } else {
                abschnitt_state_5 = 0;
              }
              break;
          }
          break;
        case 6:
          switch (abschnitt_state_6) {
            case 0:
              reverse = false;
              abschnitt_state_6 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_6 = 2;
              break;
            case 2:
              if (reverse == true) {
                reverse = false;
              } else {
                abschnitt_state_6 = 0;
              }
              break;
          }
          break;
        case 7:
          switch (abschnitt_state_7) {
            case 0:
              reverse = false;
              abschnitt_state_7 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_7 = 2;
              break;
            case 2:
              if (reverse == true) {
                reverse = false;
              } else {
                abschnitt_state_7 = 0;
              }
              break;
          }
          break;
        case 8:
          switch (abschnitt_state_8) {
            case 0:
              reverse = false;
              abschnitt_state_8 = 2;
              break;
            case 1:
              reverse = false;
              abschnitt_state_8 = 2;
              break;
            case 2:
              abschnitt_state_8 = 0;
              break;
          }
          break;
      }

      lauflicht_1_part2_countermode = false;
      lauflicht_1_part2_counter = 0;
    }
  }
}

void setAbschnitt(int from, int to, byte state) {
  switch (state) {
    case 0:
      for (int i = from; i < to; i++) {
        strip.setPixelColor(i, 0, 0, 0);
      }
      // OFF
      break;
    case 1:
      // NOTLICHT
      for (int i = from; i < to; i++) {
        strip.setPixelColor(i, 200, 200, 200);
      }
      break;
    case 2:
      switch (pattern_index) {
        case 1:
          for (int i = from; i < to; i++) {
            if (pattern1[i]) {
              strip.setPixelColor(i, 0, 255, 0);
            } else {
              strip.setPixelColor(i, 0, 0, 0);
            }
          }
          break;
        case 2:
          for (int i = from; i < to; i++) {
            if (pattern2[i]) {
              strip.setPixelColor(i, 0, 255, 0);
            } else {
              strip.setPixelColor(i, 0, 0, 0);
            }
          }
          break;
        case 3:
          for (int i = from; i < to; i++) {
            if (pattern3[i]) {
              strip.setPixelColor(i, 0, 255, 0);
            } else {
              strip.setPixelColor(i, 0, 0, 0);
            }
          }
          break;
        case 4:
          for (int i = from; i < to; i++) {
            if (pattern4[i]) {
              strip.setPixelColor(i, 0, 255, 0);
            } else {
              strip.setPixelColor(i, 0, 0, 0);
            }
          }
          break;
        case 5:
          for (int i = from; i < to; i++) {
            if (pattern5[i]) {
              strip.setPixelColor(i, 0, 255, 0);
            } else {
              strip.setPixelColor(i, 0, 0, 0);
            }
          }
          break;
        case 6:
          for (int i = from; i < to; i++) {
            if (pattern6[i]) {
              strip.setPixelColor(i, 0, 255, 0);
            } else {
              strip.setPixelColor(i, 0, 0, 0);
            }
          }
          break;
      }
      break;
  }
}
