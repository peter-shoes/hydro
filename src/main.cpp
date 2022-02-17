#include <Arduino.h>
#include <headers.hpp>

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  // run_mot(pump1);
}

void loop() {
  // check_pump(pump1);
  // check_pump(pump2);
  // check_pump(pump3);
  // delay(60000);
  Serial.print("\nSec: ");
  Serial.print(dt.secondstime(), DEC);
  Serial.print("\nHrs: ");
  Serial.print(dt.hour(), DEC);
  delay(1000);
}

void check_pump(Pump pmp) {
  // if current_time-pmp.last_dose_time >= pmp.hrs_btwn_dose OR pmp.last_dose_time == -1
    run_mot(pmp);
    // pmp.last_dose_time = current_time
}

void run_mot(Pump pmp) {
  pmp.mot->setSpeed(pmp.runspeed);
  pmp.mot->run(FORWARD);
  delay(pmp.runtime * 1000);
  pmp.mot->fullOff();
    
}