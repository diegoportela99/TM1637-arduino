# TM1637-arduino
Timer Method for arduino TM1637

To use, simply change the timecount and run timesetup() in the loop.

example of loop code;
---------

void loop() {
  timecount = 1234;
  timesetup();
  
  delay(15); //delay can be anything to the users discretion
  ...
}

---------

the TM1637 module will display "1234"
