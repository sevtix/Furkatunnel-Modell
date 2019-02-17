#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel lichtsignale = Adafruit_NeoPixel(13, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(250, 5, NEO_GRB + NEO_KHZ800);

unsigned long timestamp_lichtsignale = 0L;
unsigned long timestamp_stromabschnitte = 25L;
unsigned long timestamp_blockabschnitte = 50L;

// LICHTSIGNALE
byte lichtsignal_button_inputs[] = {24, 26, 28, 30, 36, 38, 27, 25, 29, 37, 35, 41, 39};
bool lichtsignal_unlock_array[] = {false, true, true, true, true, true, true, true, true, true, true, true, true};
bool lichtsignal_status_array[] = {false, false, false, false, false, false, false, false, false, false, false, false, false};

// STROMABSCHNITTE
byte stromabschnitt_button_inputs[] = {32, 40};
bool stromabschnitt_unlock_array[] = {true, true};
byte stromabschnitt_status_array[] = {0, 0};
int stromabschnitt_value_array[] = {0, 31, 32, 62};

// BLOCKABSCHNITTE
byte blockabschnitt_button_inputs[] = {34, 23, 31, 33};
bool blockabschnitt_unlock_array[] = {true, true, true, true};
byte blockabschnitt_status_array[] = {0, 0, 0, 0};
int blockabschnitt_value_array[] = {63, 93, 94, 125, 126, 157, 158, 194};



void setupInputs() {
  for (int i = 0; i <= sizeof(lichtsignal_button_inputs); i++) {
    pinMode(lichtsignal_button_inputs[i], INPUT);
  }

  for (int i = 0; i <= sizeof(stromabschnitt_button_inputs); i++) {
    pinMode(stromabschnitt_button_inputs[i], INPUT);
  }

  for (int i = 0; i <= sizeof(blockabschnitt_button_inputs); i++) {
    pinMode(blockabschnitt_button_inputs[i], INPUT);
  }
}

void setup() {
  Serial.begin(9600);
  lichtsignale.begin();
  pixels.begin();
  setupInputs();
}


void loop() {

  if (timestamp_lichtsignale <= millis()) {
    readLichtsignalInputs();
    timestamp_lichtsignale = millis() + 50L;
  }

  if (timestamp_stromabschnitte <= millis()) {
    readStromabschnittInputs();
    timestamp_stromabschnitte = millis() + 50L;
  }

  if (timestamp_blockabschnitte <= millis()) {
    readBlockabschnittInputs();
    timestamp_blockabschnitte = millis() + 50L;
  }

  updateLichtsignale();
  updateStromabschnitte();
  updateBlockabschnitte();
  lichtsignale.show();
  pixels.show();
}


void setLichtsignal(int index, bool status) {
  if (status) {
    lichtsignale.setPixelColor(index, 0, 255, 0);
  }
  if (!status) {
    lichtsignale.setPixelColor(index, 255, 0, 0);
  }
}

void setStromabschnitt(int index, byte mode) {
  switch (mode) {
    case 0:
      for (int i = stromabschnitt_value_array[index]; i <= stromabschnitt_value_array[index + 2]; i ++) {
        pixels.setPixelColor(i, 127, 127, 127);
      }
      break;

    case 1:
      for (int i = stromabschnitt_value_array[index]; i <= stromabschnitt_value_array[index + 2]; i ++) {
        pixels.setPixelColor(i, 255, 255, 0);
      }
      break;

    case 2:
      for (int i = stromabschnitt_value_array[index]; i <= stromabschnitt_value_array[index + 2]; i ++) {
        pixels.setPixelColor(i, 255, 90, 0);
      }
      break;
  }
}

void setBlockabschnitt(int index, byte mode) {
  switch (mode) {
    case 0:

      switch (index) {
        case 0:
          for (int i = blockabschnitt_value_array[0]; i <= blockabschnitt_value_array[1]; i ++) {
            pixels.setPixelColor(i, 127, 127, 127);
          }
          break;
        case 1:
          for (int i = blockabschnitt_value_array[2]; i <= blockabschnitt_value_array[3]; i ++) {
            pixels.setPixelColor(i, 127, 127, 127);
          }
          break;
        case 2:
          for (int i = blockabschnitt_value_array[4]; i <= blockabschnitt_value_array[5]; i ++) {
            pixels.setPixelColor(i, 127, 127, 127);
          }
          break;
        case 3:
          for (int i = blockabschnitt_value_array[6]; i <= blockabschnitt_value_array[7]; i ++) {
            pixels.setPixelColor(i, 127, 127, 127);
          }
          break;
      }
      
      break;

    case 1:
      switch (index) {
        case 0:
          for (int i = blockabschnitt_value_array[0]; i <= blockabschnitt_value_array[1]; i ++) {
            pixels.setPixelColor(i, 255, 0, 0);
          }
          break;
        case 1:
          for (int i = blockabschnitt_value_array[2]; i <= blockabschnitt_value_array[3]; i ++) {
            pixels.setPixelColor(i, 255, 0, 0);
          }
          break;
        case 2:
          for(int i = blockabschnitt_value_array[4]; i <= blockabschnitt_value_array[5]; i ++) {
            pixels.setPixelColor(i, 255, 0, 0);
          }
          break;
        case 3:
          for (int i = blockabschnitt_value_array[6]; i <= blockabschnitt_value_array[7]; i ++) {
            pixels.setPixelColor(i, 255, 0, 0);
          }
          break;
      }
      break;
  }
}


void updateLichtsignale() {
  for (int i = 0; i <= sizeof(lichtsignal_status_array); i++) {
    setLichtsignal(i, lichtsignal_status_array[i]);
  }
}

void updateStromabschnitte() {
  for (int i = 0; i < sizeof(stromabschnitt_status_array); i++) {
    setStromabschnitt(i, stromabschnitt_status_array[i]);
  }
}

void updateBlockabschnitte() {
  for (int i = 0; i < sizeof(blockabschnitt_status_array); i++) {
    setBlockabschnitt(i, blockabschnitt_status_array[i]);
  }
}

void toggleStromabschnitt(int index) {
  int get = stromabschnitt_status_array[index];

  if (get == 2) {
    stromabschnitt_status_array[index] = 0;
  } else {
    stromabschnitt_status_array[index] = stromabschnitt_status_array[index] + 1;
  }

}

void toggleBlockabschnitt(int index) {
  int get = blockabschnitt_status_array[index];

  if (get == 1 ) {
    blockabschnitt_status_array[index] = 0;
  } else {
    blockabschnitt_status_array[index] = blockabschnitt_status_array[index] + 1;
  }

}

void readLichtsignalInputs() {

  for (int i = 0; i <= sizeof(lichtsignal_button_inputs); i++) {
    if (lichtsignal_unlock_array[i] && digitalRead(lichtsignal_button_inputs[i])) {
      lichtsignal_status_array[i] = !lichtsignal_status_array[i];
      lichtsignal_unlock_array[i] = false;
      Serial.print("toggled pin");
      Serial.println(lichtsignal_button_inputs[i]);
    }

    if (!lichtsignal_unlock_array[i] && !digitalRead(lichtsignal_button_inputs[i])) {
      lichtsignal_unlock_array[i] = true;
    }
  }

}

void readStromabschnittInputs() {
  for (int i = 0; i <= sizeof(stromabschnitt_button_inputs); i++) {
    if (stromabschnitt_unlock_array[i] && digitalRead(stromabschnitt_button_inputs[i]) == 1) {
      stromabschnitt_unlock_array[i] = false;
      toggleStromabschnitt(i);
      Serial.print("toggled pin");
      Serial.println(stromabschnitt_button_inputs[i]);
    }
    if (stromabschnitt_unlock_array[i] == false && digitalRead(stromabschnitt_button_inputs[i]) == 0) {
      stromabschnitt_unlock_array[i] = true;
    }
  }
}

void readBlockabschnittInputs() {
  for (int i = 0; i <= sizeof(blockabschnitt_button_inputs); i++) {
    if (blockabschnitt_unlock_array[i] && digitalRead(blockabschnitt_button_inputs[i]) == 1) {
      blockabschnitt_unlock_array[i] = false;
      toggleBlockabschnitt(i);
      Serial.print("toggled pin");
      Serial.println(blockabschnitt_button_inputs[i]);
    }
    if (blockabschnitt_unlock_array[i] == false && digitalRead(blockabschnitt_button_inputs[i]) == 0) {
      blockabschnitt_unlock_array[i] = true;
    }
  }
}

