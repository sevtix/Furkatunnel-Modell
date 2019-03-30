#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stromabschnitte = Adafruit_NeoPixel(195, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stromabschnitte2 = Adafruit_NeoPixel(195, 8, NEO_GRB + NEO_KHZ800); // 34:22:
Adafruit_NeoPixel rettungsstollen = Adafruit_NeoPixel(26, 10, NEO_GRB + NEO_KHZ800); // 34:22:

Adafruit_NeoPixel blockstellen = Adafruit_NeoPixel(195, 4, NEO_GRB + NEO_KHZ800);

float MULTIPLIER = 0.0f;
float BLINKLICHT = 1.0f;

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

byte blinklicht_status = 0;
bool blinklicht_unlock = true;
long blinklicht_timestamp = 0L;

bool lichtsignal_1_unlock = true;
bool lichtsignal_2_unlock = true;
bool lichtsignal_3_unlock = true;
bool lichtsignal_4_unlock = true;
bool lichtsignal_5_unlock = true;
bool lichtsignal_6_unlock = true;
bool lichtsignal_7_unlock = true;
bool lichtsignal_8_unlock = true;

byte lichtsignal_1_status = true;
byte lichtsignal_2_status = true;
byte lichtsignal_3_status = true;
byte lichtsignal_4_status = true;
byte lichtsignal_5_status = true;
byte lichtsignal_6_status = true;
byte lichtsignal_7_status = true;
byte lichtsignal_8_status = true;

// STROMABSCHNITTE
bool stromabschnitt_unlock_button_1 = true;
bool stromabschnitt_unlock_button_2 = true;
bool stromabschnitt_unlock_button_3 = true;

bool stromabschnitt_unlock_button_4 = true;
bool stromabschnitt_unlock_button_5 = true;

byte stromabschnitt_1 = 1;
byte stromabschnitt_2 = 1;
byte stromabschnitt_3 = 1;

byte stromabschnitt_4 = 1;
byte stromabschnitt_5 = 1;
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
bool blockstellen_unlock_button_5 = true;
bool blockstellen_unlock_button_6 = true;

byte blockstelle_1 = 1;
byte blockstelle_2 = 1;
byte blockstelle_3 = 1;
byte blockstelle_4 = 1;
byte blockstelle_5 = 1;
byte blockstelle_6 = 1;
// - BLOCKSTELLEN

bool rettungsstollen_umschalt_unlock = true;
byte rettungsstollen_umschalt_status = 0;

bool rettungsstollen_toggle_unlock = true;
byte rettungsstollen_toggle_status = 0;

byte tor_state = 0;
// 39:41:

void setup() {
  pixels1.begin();
  blockstellen.begin();
  stromabschnitte.begin();
  stromabschnitte2.begin();
  rettungsstollen.begin();
  Serial.begin(9600);
}


void loop() {

  if (MULTIPLIER < 1 && MULTIPLIER_TIMESTAMP <= millis()) {
    MULTIPLIER = MULTIPLIER + 0.01;
    MULTIPLIER_TIMESTAMP = millis() + 15;
  }

  // toggle(byte pin, bool& unlock, byte& toggle, byte range0, byte range1, bool useTimestamp, long& timestamp)

  long timestamp_null = 0;

  // block: 24:26:36:33:25:27:

  toggle(24, blockstellen_unlock_button_1, blockstelle_1, 0, 1, false, timestamp_null);
  toggle(26, blockstellen_unlock_button_2, blockstelle_2, 0, 1, false, timestamp_null);
  toggle(36, blockstellen_unlock_button_3, blockstelle_3, 0, 1, false, timestamp_null);
  toggle(33, blockstellen_unlock_button_4, blockstelle_4, 0, 1, false, timestamp_null);
  toggle(47, blockstellen_unlock_button_5, blockstelle_5, 0, 1, false, timestamp_null);
  toggle(23, blockstellen_unlock_button_6, blockstelle_6, 0, 1, false, timestamp_null);

  toggle(27, lichtsignal_1_unlock, lichtsignal_1_status, 0, 1, false, timestamp_null);
  toggle(25, lichtsignal_2_unlock, lichtsignal_2_status, 0, 1, false, timestamp_null);
  toggle(29, lichtsignal_3_unlock, lichtsignal_3_status, 0, 1, false, timestamp_null);
  toggle(37, lichtsignal_4_unlock, lichtsignal_4_status, 0, 1, false, timestamp_null);
  toggle(38, lichtsignal_5_unlock, lichtsignal_5_status, 0, 1, false, timestamp_null);
  toggle(32, lichtsignal_6_unlock, lichtsignal_6_status, 0, 1, false, timestamp_null);
  toggle(28, lichtsignal_7_unlock, lichtsignal_7_status, 0, 1, false, timestamp_null);
  toggle(30, lichtsignal_8_unlock, lichtsignal_8_status, 0, 1, false, timestamp_null);
  toggleBlinklicht(35, blinklicht_unlock, blinklicht_status, 0, 1, false, timestamp_null);

  toggle(40, stromabschnitt_unlock_button_1, stromabschnitt_1, 0, 2, false, timestamp_null);
  toggle(31, stromabschnitt_unlock_button_2, stromabschnitt_2, 0, 2, false, timestamp_null);
  toggle(45, stromabschnitt_unlock_button_3, stromabschnitt_3, 0, 2, false, timestamp_null);

  toggle(34, stromabschnitt_unlock_button_4, stromabschnitt_4, 0, 2, false, timestamp_null);
  toggle(22, stromabschnitt_unlock_button_5, stromabschnitt_5, 0, 2, false, timestamp_null);

  setBlockstelle(0, 30, blockstelle_1);
  setBlockstelle(31, 61, blockstelle_2);
  setBlockstelle(62, 92, blockstelle_3);
  setBlockstelle(93, 123, blockstelle_4);
  setBlockstelle(124 , 154, blockstelle_5);
  setBlockstelle(155, 185, blockstelle_6);


  // strom: 40:31:45:
  // 0-7, 8-38, 39-133

  setStromabschnitt(0, 7, stromabschnitt_1);
  setStromabschnitt(8, 38, stromabschnitt_2);
  setStromabschnitt(39, 133, stromabschnitt_3);

  setStromabschnitt2(0, 30, stromabschnitt_4);
  setStromabschnitt2(31, 124, stromabschnitt_5);

  setLichtsignal(0, lichtsignal_1_status);
  setLichtsignal(1, lichtsignal_2_status);
  setLichtsignal(2, lichtsignal_3_status);
  setLichtsignal(3, lichtsignal_4_status);
  setLichtsignal(5, lichtsignal_5_status);
  // 2
  // 3
  // 2
  setLichtsignal(13, lichtsignal_6_status);
  setLichtsignal(14, lichtsignal_7_status);
  setLichtsignal(15, lichtsignal_8_status);

  setBlinklicht(4, blinklicht_status);
  BlinklichtFader(blinklicht_timestamp);

  /*
    39:41
  */

  toggle(39, rettungsstollen_toggle_unlock, rettungsstollen_toggle_status, 0, 1, false, timestamp_null);
  toggle(41, rettungsstollen_umschalt_unlock, rettungsstollen_umschalt_status, 0, 1, false, timestamp_null);
  setRettungsstollen(rettungsstollen_toggle_status, rettungsstollen_umschalt_status);

  readTorInput(42,44, tor_state);
  setTor(tor_state);
  // 0-4: weiss
  // 8-21: blau
  // 25-25: weiss

  blockstellen.show();
  stromabschnitte.show();
  stromabschnitte2.show();
  rettungsstollen.show();
  pixels1.show();
}

void setTor(byte mode) {
  if (mode == 0) {
    setColorFromToPixels1(6, 7,    253, 0, 0);
    setColorFromToPixels1(8, 10,   0, 253, 0);
    setColorFromToPixels1(11, 12,  253, 0, 0);
  }
  if (mode == 1) {
    setColorFromToPixels1(6, 7,    0, 253, 0);
    setColorFromToPixels1(8, 10,   253, 0, 0);
    setColorFromToPixels1(11, 12,  0, 253, 0);
  }
}

void setRettungsstollen(byte state, byte umschalt) {
  if (umschalt == 0) {
    setColorFromToRettungsstollen(5, 7, 253, 0, 0);
    setColorFromToRettungsstollen(22, 24, 0, 253, 0);
    // 5-7
    // 22-24
  }

  if (umschalt == 1) {
    setColorFromToRettungsstollen(5, 7, 0, 253, 0);
    setColorFromToRettungsstollen(22, 24, 253, 0, 0);
    // 5-7
    // 22-24
  }

  if (state == 0) {
    // 0-4: weiss
    // 8-21: blau
    // 25-25: weiss
    setColorFromToRettungsstollen(0, 4, 0, 0, 0);
    setColorFromToRettungsstollen(8, 21, 0, 0, 0);
    setColorFromToRettungsstollen(25, 25, 0, 0, 0);
  }

  if (state == 1) {
    // 0-4: weiss
    // 8-21: blau
    // 25-25: weiss
    setColorFromToRettungsstollen(0, 4, 200, 200, 200);
    setColorFromToRettungsstollen(8, 21, 0, 0, 253);
    setColorFromToRettungsstollen(25, 25, 200, 200, 200);
  }
}

void setBlinklicht(byte index, byte status) {
  switch (status) {
    case 0:
      pixels1.setPixelColor(index, 0, 0, 0);
      break;
    case 1:
      pixels1.setPixelColor(index, cor[254] * BLINKLICHT, cor[127] * BLINKLICHT, 0);
      break;
  }
}

void setStromabschnitt(byte from, byte to, byte status) {
  switch (status) {
    case 0:
      setColorFromToStromabschnitt(from, to, 200, 200, 200);
      break;
    case 1:
      setColorFromToStromabschnitt(from, to, 253, 210, 0 );
      break;
    case 2:
      setColorFromToStromabschnitt(from, to, 254, 127, 0);
      break;
  }
}

void setStromabschnitt2(byte from, byte to, byte status) {
  switch (status) {
    case 0:
      setColorFromToStromabschnitt2(from, to, 200, 200, 200);
      break;
    case 1:
      setColorFromToStromabschnitt2(from, to, 254, 210, 0 );
      break;
    case 2:
      setColorFromToStromabschnitt2(from, to, 254, 127, 0);
      break;
  }
}


void setBlockstelle(byte from, byte to, byte status) {
  switch (status) {
    case 0:
      setColorFromToBlockstellen(from, to, 200, 200, 200);
      break;
    case 1:
      setColorFromToBlockstellen(from, to, 254, 0, 0 );
      break;
  }
}


void setColorFromTo(Adafruit_NeoPixel pxl, byte from, byte to, byte r, byte g, byte b) {
  for (int i = from; i <= to; i++) {
    pxl.setPixelColor(i, round(cor[r] * MULTIPLIER), round(cor[g] * MULTIPLIER), round(cor[b] * MULTIPLIER));
  }
}

void setColorFromToPixels1(byte from, byte to, byte r, byte g, byte b) {
  for (int i = from; i <= to; i++) {
    pixels1.setPixelColor(i, round(cor[r] * MULTIPLIER), round(cor[g] * MULTIPLIER), round(cor[b] * MULTIPLIER));
  }
}

void setColorFromToBlockstellen(byte from, byte to, byte r, byte g, byte b) {
  for (int i = from; i <= to; i++) {
    blockstellen.setPixelColor(i, round(cor[r] * MULTIPLIER), round(cor[g] * MULTIPLIER), round(cor[b] * MULTIPLIER));
  }
}

void setColorFromToRettungsstollen(byte from, byte to, byte r, byte g, byte b) {
  for (int i = from; i <= to; i++) {
    rettungsstollen.setPixelColor(i, round(cor[r] * MULTIPLIER), round(cor[g] * MULTIPLIER), round(cor[b] * MULTIPLIER));
  }
}

void setColorFromToStromabschnitt(byte from, byte to, byte r, byte g, byte b) {
  for (int i = from; i <= to; i++) {
    stromabschnitte.setPixelColor(i, round(cor[r] * MULTIPLIER), round(cor[g] * MULTIPLIER), round(cor[b] * MULTIPLIER));
  }
}

void setColorFromToStromabschnitt2(byte from, byte to, byte r, byte g, byte b) {
  for (int i = from; i <= to; i++) {
    stromabschnitte2.setPixelColor(i, round(cor[r] * MULTIPLIER), round(cor[g] * MULTIPLIER), round(cor[b] * MULTIPLIER));
  }
}

void setLichtsignal(int index, byte status) {
  if (status == 0) {
    pixels1.setPixelColor(index, 0, round(250 * MULTIPLIER), 0);
  }
  if (status == 1) {
    pixels1.setPixelColor(index, round(250 * MULTIPLIER), 0, 0);
  }
}

void BlinklichtFader(long& timestamp) {
  if (timestamp <= millis()) {

    timestamp = millis() + 500;

    if (BLINKLICHT == 0) {
      BLINKLICHT = 1;
      return;
    }

    if (BLINKLICHT == 1) {
      BLINKLICHT = 0;
    }
  }
}

void toggle(byte pin, bool& unlock, byte& toggle, byte range0, byte range1, bool useTimestamp, long& timestamp) {

  if (timestamp > millis() && useTimestamp) {
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

void toggleBlinklicht(byte pin, bool& unlock, byte& toggle, byte range0, byte range1, bool useTimestamp, long& timestamp) {

  if (timestamp > millis() && useTimestamp) {
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

    BLINKLICHT = 1;
    blinklicht_timestamp = millis() + 500;

  }
  if (unlock == false && digitalRead(pin) == 0) {
    unlock = true;
  }
}

void readTorInput(byte button1, byte button2, byte& toggle) {
  if (digitalRead(button1)) {
    toggle = true;
    Serial.println("toggled tor to true");
  }

  if (digitalRead(button2)) {
    toggle = false;
    Serial.println("toggled tor to false");
  }
}
