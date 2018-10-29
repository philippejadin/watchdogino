
// time limit to wake up the dog (ms)
int watchdog_duration = 1000 * 60; // default is 60 seconds


// reset duration (ms) (duration to hold the reset pin high)

int reset_duration = 100;


// watchdog pin number (inout)
int watchdog_pin = 1;

// watchdog reset pin (output)
int reset_pin = 2;


// timer
unsigned long timer = 0;


void setup() {
pinMode(watchdog_pin, INPUT);
pinMode(reset_pin, OUTPUT);

}

void loop() {
  timer = millis();

  // wait for a wake up from the host
  if (digitalRead(watchdog_pin) == HIGH)
  {
    timer = 0;
  }

  // if host takes too long, send a reset and log

  if (timer > watchdog_duration)
  {
    digitalWrite(reset_pin, HIGH);
    delay(reset_duration);
    digitalWrite(reset_pin, LOW);

    // add log (todo)
  }


  // every hour log run time in eeprom
  // find a free space in eeprom
  // save run time



}
