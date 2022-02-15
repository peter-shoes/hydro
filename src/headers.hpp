#include <Servo.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <SPI.h>

// DEFINE AFMS
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// PUMP DEFS
typedef struct Pump {
    Adafruit_DCMotor *mot;
    int runspeed;
    int runtime;
    int hrs_btwn_dose;
    int last_dose_time;
} Pump;

Pump pump1 = {AFMS.getMotor(1), 150, 10, 24, -1};
Pump pump2 = {AFMS.getMotor(2), 150, 10, 4, -1};
Pump pump3 = {AFMS.getMotor(3), 150, 10, 2, -1};

// TIME DEFS

// FUNC DEFS
void check_pump(Pump pmp);
void run_mot(Pump pmp);
