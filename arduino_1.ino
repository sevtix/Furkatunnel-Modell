#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel lichtsignale = Adafruit_NeoPixel(13, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(194, 5, NEO_GRB + NEO_KHZ800);

float MULTIPLIER = 0.0f;

byte cor[] = {
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

byte GLOBAL_DELAY = 12;

byte MULTIPLIER_TIMESTAMP = 0L;

// LICHTSIGNALE
byte lichtsignal_button_inputs[] = {24, 26, 28, 30, 36, 38, 25, 27, 29, 37, 35, 41, 39};
bool lichtsignal_unlock_array[] = {false, true, true, true, true, true, true, true, true, true, true, true, true};
bool lichtsignal_status_array[] = {false, false, false, false, false, false, false, false, false, false, false, false, false};

// STROMABSCHNITTE
bool stromabschnitt_unlock_button_1 = true;
bool stromabschnitt_unlock_button_2 = true;
byte stromabschnitt_1 = 0;
byte stromabschnitt_2 = 0;
// - STROMABSCHNITTE

long timestamp_lichtsignale = 0L;
long TIMESTAMP_STROMABSCHNITT_1 = 2L;
long TIMESTAMP_STROMABSCHNITT_2 = 4L;

long TIMESTAMP_BLOCKSTELLE_1 = 6L;
long TIMESTAMP_BLOCKSTELLE_2 = 8L;
long TIMESTAMP_BLOCKSTELLE_3 = 10L;
long TIMESTAMP_BLOCKSTELLE_4 = 12L;

// BLOCKSTELLEN
bool blockstellen_unlock_button_1 = true;
bool blockstellen_unlock_button_2 = true;
bool blockstellen_unlock_button_3 = true;
bool blockstellen_unlock_button_4 = true;
byte blockstelle_1 = 0;
byte blockstelle_2 = 0;
byte blockstelle_3 = 0;
byte blockstelle_4 = 0;
// - BLOCKSTELLEN

void setupInputs() {
  for (int i = 0; i <= sizeof(lichtsignal_button_inputs); i++) {
    pinMode(lichtsignal_button_inputs[i], INPUT);
  }

}

void setup() {
  Serial.begin(9600);
  lichtsignale.begin();
  pixels.begin();
  setupInputs();
  updateLichtsignale();
  // toggle(pin, unlock, state, range0, range1);
}


void loop() {
  
  if(MULTIPLIER < 1 && MULTIPLIER_TIMESTAMP <= millis()) {
    MULTIPLIER = MULTIPLIER + 0.005;  
    MULTIPLIER_TIMESTAMP = millis() + 15;
  }
  
  setStromabschnitt(0, 30, stromabschnitt_1);
  setStromabschnitt(31, 62, stromabschnitt_2);
  toggle(32, stromabschnitt_unlock_button_1, stromabschnitt_1, 0, 2, TIMESTAMP_STROMABSCHNITT_1);
  toggle(40, stromabschnitt_unlock_button_2, stromabschnitt_2, 0, 2, TIMESTAMP_STROMABSCHNITT_2);
  
  toggle(34, blockstellen_unlock_button_1, blockstelle_1, 0, 1, TIMESTAMP_BLOCKSTELLE_1);
  toggle(23, blockstellen_unlock_button_2, blockstelle_2, 0, 1, TIMESTAMP_BLOCKSTELLE_2);
  toggle(31, blockstellen_unlock_button_3, blockstelle_3, 0, 1, TIMESTAMP_BLOCKSTELLE_3);
  toggle(33, blockstellen_unlock_button_4, blockstelle_4, 0, 1, TIMESTAMP_BLOCKSTELLE_4);

  setBlockstelle(63, 93, blockstelle_1);
  setBlockstelle(94, 125, blockstelle_2);
  setBlockstelle(126, 157, blockstelle_3);
  setBlockstelle(158, 194, blockstelle_4);

  updateLichtsignale();

  if (timestamp_lichtsignale <= millis()) {
    readLichtsignalInputs();
    timestamp_lichtsignale = millis() + 10L;
    //Serial.print("read lichtsignal inputs @ ");
    //Serial.println(millis());
  }

  lichtsignale.show();
  pixels.show();
}

void setStromabschnitt(byte from, byte to, byte status) {
  switch (status) {
    case 0:
      setColorFromTo(from, to, 200, 200, 200);
      break;
    case 1:
      setColorFromTo(from, to, 254, 229, 0 );
      break;
    case 2:
      setColorFromTo(from, to, 254, 127, 0);
      break;
  }
}


void setBlockstelle(byte from, byte to, byte status) {
  switch (status) {
    case 0:
      setColorFromTo(from, to, 200, 200, 200);
      break;
    case 1:
      setColorFromTo(from, to, 254, 0, 0 );
      break;
  }
}

void setColorFromTo(byte from, byte to, byte r, byte g, byte b) {
  for (int i = from; i <= to; i++) {
    pixels.setPixelColor(i, round(cor[r] * MULTIPLIER), round(cor[g] * MULTIPLIER),round(cor[b] * MULTIPLIER));
  }
}

void setLichtsignal(int index, bool status) {
  if (status) {
    lichtsignale.setPixelColor(index, 0, round(254 * MULTIPLIER), 0);
  }
  if (!status) {
    lichtsignale.setPixelColor(index, round(254 * MULTIPLIER), 0, 0);
  }
}


void updateLichtsignale() {
  for (int i = 0; i < sizeof(lichtsignal_status_array); i++) {
    setLichtsignal(i, lichtsignal_status_array[i]);
  }
}


void readLichtsignalInputs() {
  for (int i = 0; i <= sizeof(lichtsignal_button_inputs); i++) {
    if (lichtsignal_unlock_array[i] && digitalRead(lichtsignal_button_inputs[i])) {
      lichtsignal_status_array[i] = !lichtsignal_status_array[i];
      lichtsignal_unlock_array[i] = false;
    }

    if (!lichtsignal_unlock_array[i] && !digitalRead(lichtsignal_button_inputs[i])) {
      lichtsignal_unlock_array[i] = true;
    }
  }
}

void toggle(byte pin, bool& unlock, byte& toggle, byte range0, byte range1, long& timestamp) {

  if (timestamp > millis()) {
    return;
  }

  if (unlock == true && digitalRead(pin) == 1) {

    timestamp = millis() + GLOBAL_DELAY;
    
    unlock = false;
    toggle++;
    if (toggle > range1) {
      toggle = range0;
    }

    Serial.print("Toggled pin");
    Serial.print(pin);
    Serial.print(" to ");
    Serial.println(toggle);
  }
  if (unlock == false && digitalRead(pin) == 0) {
    unlock = true;
  }
}
