#include <AccelStepper.h>
AccelStepper stepper(1, 7, 6);///(Type:driver, STEP, DIR)



void setup() {
  pinMode(2,OUTPUT);
  stepper.setMaxSpeed(50);
  stepper.setAcceleration(20);
  stepper.moveTo(200);

  digitalWrite(2,HIGH);

}

void loop() {
  if (stepper.distanceToGo() == 0) {
    stepper.moveTo(-stepper.currentPosition());
    delay(2000);
  }
  stepper.run();

}
