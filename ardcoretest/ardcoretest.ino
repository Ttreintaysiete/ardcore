int pot_pin[] = {0, 1, 2, 3};

int led_pin[] = {4, 5, 6, 7};

int last_read_val[] = {0, 0, 0, 0};

int last_read_time[] = {0, 0, 0, 0};

int last_led_state[] = {LOW, LOW, LOW, LOW};

void setup() {
  // declare the ledPin as an OUTPUT:
  for (int i = 0; i < 4; i++) {
    pinMode(led_pin[i], OUTPUT);
  }
  
}

void loop() {

  int current_millis = millis();

  for (int i = 0; i < 4; i++) {
    
    int tmp = analogRead(pot_pin[i]);

    if(tmp < current_millis - last_read_time[i]){

      last_read_time[i] = current_millis;

      last_led_state[i] = !last_led_state[i];

      digitalWrite(led_pin[i], last_led_state[i]);
      
    }
    
  }

}
