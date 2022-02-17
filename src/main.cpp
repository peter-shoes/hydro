#include <Arduino.h>
#include <headers.hpp>

int col_time = 0;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  // run_mot(pump1);
}

void loop() {
  check_pump(pump1);
  check_pump(pump2);
  check_pump(pump3);
  
  dt_chk = dt_chk + TimeSpan(0,0,0,col_time+1);
  delay(1000);
  col_time = 0;

}

void check_pump(Pump pmp) {
  if ((dt_chk == dt_init) || ((dt_chk - pmp.last_dose_time).seconds() >= pmp.hrs_btwn_dose*3600)){
    run_mot(pmp);
  }
  // Serial.println((dt_chk - pmp.last_dose_time).seconds());
}

void run_mot(Pump pmp) {
  pmp.mot->setSpeed(pmp.runspeed);
  pmp.mot->run(FORWARD);
  delay(pmp.runtime * 1000);
  pmp.mot->fullOff();
  col_time += pmp.runtime;
  pmp.last_dose_time = dt_chk;
}