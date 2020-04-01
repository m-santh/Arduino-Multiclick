//  Switch Function
void SWITCH() {

  static const int STATE_IDLE           = 0;
  static const int STATE_SINGLE_CLICK   = 1;
  static const int STATE_DOUBLE_CLICK   = 2;
  static const int STATE_LONG_CLICK     = 3;

  int click = 0;

  //  Switch_01
  click = button1.checkPress();
  if (click == STATE_SINGLE_CLICK) {
    switch (SW_COUNTER_01) {
      case 0:
        SW_COUNTER_01++;
        Switch_1_ON();
        break;
      case 1:
        SW_COUNTER_01 = 0;
        Switch_1_OFF();
        break;
    }
  }

  //  Switch_02
  click = button2.checkPress();
  if (click == STATE_SINGLE_CLICK) {
    switch (SW_COUNTER_02) {
      case 0:
        SW_COUNTER_02++;
        Switch_2_ON();
        break;
      case 1:
        SW_COUNTER_02 = 0;
        Switch_2_OFF();
        break;
    }
  }

  //  Switch_03
  click = button3.checkPress();
  if (click == STATE_SINGLE_CLICK) {
    switch (SW_COUNTER_03) {
      case 0:
        SW_COUNTER_03++;
        Switch_3_ON();
        break;
      case 1:
        SW_COUNTER_03 = 0;
        Switch_3_OFF();
        break;
    }
  }

  //  Switch_04 (Push Counter and Dimmer)
  click = button4.checkPress();
  if (click == STATE_LONG_CLICK) {
        FAN_COUNTER = 0;
        SPEED_OFF();
  }
  else if (click == STATE_DOUBLE_CLICK) {
        FAN_COUNTER = 4;
        SPEED_Four();
  }
  else if (click == STATE_SINGLE_CLICK) {
    switch (FAN_COUNTER) {
      case 0:
        FAN_COUNTER++;
        SPEED_One();
        break;
      case 1:
        FAN_COUNTER++;
        SPEED_Two();
        break;
      case 2:
        FAN_COUNTER++;
        SPEED_Three();
        break;
      case 3:
        FAN_COUNTER++;
        SPEED_Four();
        break;
      case 4:
        FAN_COUNTER = 0;
        SPEED_OFF();
        break;
    }
  }

}
