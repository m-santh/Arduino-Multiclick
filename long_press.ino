/* Long press button */


class MultiButton {

  private:
    static const int DEBOUNCE_DELAY    =  50; // ms
    static const int DOUBLECLICK_DELAY = 250; // ms
    static const int LONGCLICK_DELAY   = 350; // ms

    static const int STATE_IDLE           = 0;
    static const int STATE_SINGLE_CLICK   = 1;
    static const int STATE_DOUBLE_CLICK   = 2;
    static const int STATE_LONG_CLICK     = 3;


    unsigned int _lastTransition;
    int _state;
    bool _singleClick;
    bool _longPress;
    bool _doubleClick;
    int _pin;


  public:

    /**
     * MultiButton constructor.
     */
    MultiButton(int pin) : _lastTransition(millis()), _state(LOW), _singleClick(false), _longPress(false), _doubleClick(false), _pin(pin) {
    };

    /**
     * Decode hardware button state into clean clicks (single, double, long).
     * The state of isClick() etc is valid until the next call to update().
     *
     * Periodically call update() with the current (raw, non-debounced)
     * state of a (hardware) button.
     * Suggestion is to put it in e.g. loop(), but make sure to call it at
     * least every ~20ms.
     *
     * @param pressed {bool} Whether raw button is currently pressed
     */
    int checkPress() {
      bool previousPressed = (_state == HIGH);
      bool pressed = (PCF_01.digitalRead(_pin) == HIGH);
      int currentClick = STATE_IDLE;

      unsigned int now = millis();
      int diff = now - _lastTransition;

      // Pressed state change
      if(pressed && !previousPressed) {
        _lastTransition = now;
        _state = HIGH;
        _singleClick = true;
        currentClick = STATE_SINGLE_CLICK;

        if(_doubleClick && diff <= DOUBLECLICK_DELAY) {
          _longPress = false;
        }
        else {
          _longPress = true;
          _doubleClick = false;
        }
      }

      // Release state change
      if(!pressed && previousPressed) {

        // Check if long press
        if(_doubleClick) {
          currentClick = STATE_DOUBLE_CLICK;
          _doubleClick = false;
        }
        else if(_longPress && diff > LONGCLICK_DELAY) {
          currentClick = STATE_LONG_CLICK;
          _doubleClick = false;
        }
        else {
          _doubleClick = true;
        }
        _state = LOW;
        _singleClick = false;
        _longPress = false;
      }

      return currentClick;
    }

};
