#include <Servo.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <SPI.h>
#include "RTClib.h"

// DEFINE AFMS
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// TIME DEFS
DateTime dt_init (0, 0, 0, 0, 0, 0);
DateTime dt_chk (0, 0, 0, 0, 0, 0);

// PUMP DEFS
typedef struct Pump {
    Adafruit_DCMotor *mot;
    int runspeed;
    int runtime;
    int hrs_btwn_dose;
    DateTime last_dose_time;
} Pump;

Pump pump1 = {AFMS.getMotor(1), 150, 64, 24, dt_init};
Pump pump2 = {AFMS.getMotor(2), 150, 92, 34, dt_init};
Pump pump3 = {AFMS.getMotor(3), 150, 228, 84, dt_init};



// FUNC DEFS
void check_pump(Pump pmp);
void run_mot(Pump pmp);
