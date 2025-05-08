#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 50
#define MIN_PULSE 0 // 0.5ms (common servo min)
#define MAX_PULSE 500 // 2.5ms (common servo max)

#define SERVO1_CHANNEL 0 // Base Motor (Servo 1)
#define SERVO2_CHANNEL 1 // Linear Actuator (Servo 2)
#define SERVO3_CHANNEL 2 // Link 3 (Servo 3)
#define SERVO4_CHANNEL 3 // Link 4 (Servo 4)
#define GRIPPER_CHANNEL 4 // Gripper

void setup() {
Serial.begin(9600);
pwm.begin();
pwm.setPWMFreq(SERVO_FREQ);
// Initial positions
pwm.setPWM(SERVO1_CHANNEL, 0, MIN_PULSE);
pwm.setPWM(SERVO2_CHANNEL, 0, MIN_PULSE);
pwm.setPWM(SERVO3_CHANNEL, 0, MIN_PULSE);
pwm.setPWM(SERVO4_CHANNEL, 0, MIN_PULSE);
pwm.setPWM(GRIPPER_CHANNEL, 0, MIN_PULSE);
Serial.println("Arduino initialized");
}