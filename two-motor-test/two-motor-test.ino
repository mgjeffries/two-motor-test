#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper1(AccelStepper::DRIVER, 4, 13); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper stepper2(AccelStepper::DRIVER, 2, 14); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
#define MS1 0
#define MS2 12
#define EN  16

void setup()
{  
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, LOW);
  // Change these to suit your stepper if you want
  stepper1.setMaxSpeed(500);
  stepper1.setAcceleration(100);
  stepper1.moveTo(1000);
  stepper2.setMaxSpeed(500);
  stepper2.setAcceleration(100);
}

void loop()
{
    // If at the end of travel go to the other end
    if (stepper1.distanceToGo() == 0 and stepper1.currentPosition() == stepper2.currentPosition())
      stepper1.moveTo(-stepper1.currentPosition());
    else if (stepper1.distanceToGo() == 0)
      stepper2.moveTo(stepper1.currentPosition());

    stepper1.run();
    stepper2.run();
}
