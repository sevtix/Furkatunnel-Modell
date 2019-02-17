void setup() {
  Serial.begin(9600);
}

int pinRange[] = {23, 41};
bool unlock_array[] = {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,};

void loop() {
  for(int i = pinRange[0]; i <= pinRange[1]; i++) {
    if(unlock_array && digitalRead(i)) {
      Serial.print(i);
      Serial.print(":");
      unlock_array[i] = false;
    }

    if(!unlock_array[i] && !digitalRead(i)) {
      unlock_array[i] = true;
    }
  }
  delay(200);
}
