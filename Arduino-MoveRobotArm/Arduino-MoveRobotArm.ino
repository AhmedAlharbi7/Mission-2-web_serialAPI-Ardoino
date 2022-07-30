#include <Servo.h>

Servo shoulder, base, gripper, wrist, elbow;

double baseAngle = 90, shoulderAngle = 90, elbowAngle = 90, wristAngle = 90;




void setup() {
  //Sets the data rate in bits per second (baud) for serial data transmission.
  //For USB baudrate is fixed on 115200 bps
  Serial.begin(115200);

  base.attach(8);
  shoulder.attach(9);
  gripper.attach(10);
  wrist.attach(11);
  elbow.attach(12);



  //defualt postion
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  base.write(baseAngle);
  shoulder.write(shoulderAngle);
  elbow.write(elbowAngle);
  wrist.write(wristAngle);
}



String getValue(String Info, char separator, int position) {
  int CounterFound = 0;
  int strIndexArray[] = { 0, -1 };
  int maxIndex = Info.length() - 1;

  for (int i = 0; i <= maxIndex && CounterFound <= position; i++) {

    if (Info.charAt(i) == separator || i == maxIndex) {
      CounterFound++;
      strIndexArray[0] = strIndexArray[1] + 1;
      strIndexArray[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  if (CounterFound > position) {
    return Info.substring(strIndexArray[0], strIndexArray[1]);
  } else {
    return "";
  }
}

void loop() {

  String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }

  String command = getValue(computerText, ' ', 0);
  command.toLowerCase();

  if (command == "right"|| command == "رايت") {
    base.write(baseAngle -= 25);
  }
  if (command == "left"|| command == "لفت") {
    base.write(baseAngle += 25);
  }

  if (command == "top"|| command == "توب") {
    shoulder.write(shoulderAngle -= 25);
  }

  if (command == "bottom"|| command == "بوتوم") {
    shoulder.write(shoulderAngle += 25);
  }
  Serial.println(command);
  Serial.println("It's Working");
  delay(500);
}