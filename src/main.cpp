#include <Arduino.h>
#include <headers.hpp>

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  // run_mot(pump1);
}

void loop() {
  check_pump(pump1);
  check_pump(pump2);
  check_pump(pump3);
  dt_chk = dt_chk + TimeSpan(0,0,0,1);
  delay(1000);
}

void check_pump(Pump pmp) {
  if ((pmp.last_dose_time == dt_init) || ((dt_chk - pmp.last_dose_time).seconds() >= pmp.hrs_btwn_dose*3600)){
    run_mot(pmp);
    pmp.last_dose_time = dt_chk;
  }
}

void run_mot(Pump pmp) {
  pmp.mot->setSpeed(pmp.runspeed);
  pmp.mot->run(FORWARD);
  delay(pmp.runtime * 1000);
  pmp.mot->fullOff();
  dt_chk = dt_chk + TimeSpan(0,0,0,pmp.runtime);
}