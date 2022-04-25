/*
This program turns on and off an LED in response to the push button switch connected
to a GPIO input pin, using callback functions that are automatically invoked according
to the change of state at the input pin
*/

#include <iostream>
#include <pigpiod_if2.h>

using namespace std;

const int LED = 26; //output pin number GPIO 26
const int BUTTON = 27; //input pin number GPIO 27

int PigpioSetup() {
    char *addrStr = nullptr;
    char *portStr = nullptr;
    int pi = pigpio_start(addrStr, portStr); //handshake with daemon and get pi handle
    return pi;
}

/*callback function that is invoked when push button is pressed
  instructs output pin to transmit a 3.3V signal
  LED turns on light*/
void button_event_pressed(int pi, unsigned int gpio, unsigned int edge, unsigned int foo) {
        gpio_write(pi, LED, 1);
}

/*callback function that is invoked when push button is released
  instructs output pin to transmit a 0V signal
  LED turns off light*/
void button_event_released(int pi, unsigned int gpio, unsigned int edge, unsigned int foo) {
        gpio_write(pi, LED, 0);
}

int main() {
    int pi = PigpioSetup();
    if (pi >= 0)
        cout << "daemon interface started ok at " << pi << endl;
    else {
        cout << "Failed to connect to PIGPIO daemon \n" << \
        "Try running sudo pigpiod and try again." << endl;
        return 1;
    }
    set_mode(pi, LED, PI_OUTPUT); //set GPIO 26 to output mode
    set_mode(pi, BUTTON, PI_INPUT); //set GPIO 27 to input mode
    //set GPIO 27 to use pull-up resistor
    int pi_pud = set_pull_up_down(pi, BUTTON, PI_PUD_UP);
    if ( pi_pud != 0) {
        cerr << pi_pud << endl;
        return 2;
    }
    /*initialise the 2 callbacks and store their IDs
      when pb is pressed, input signal to GPIO 27 changes from high to low
      when pb is released, input signal to GPIO 27 changes from low to high
    */
    int callbackID_1 = callback(pi, BUTTON, FALLING_EDGE, button_event_pressed);
    int callbackID_2 = callback(pi, BUTTON, RISING_EDGE, button_event_released);
    //let the program run for 60s
    time_sleep(60);
    //cancel the 2 callbacks and end the pigpio daemon interface
    callback_cancel(callbackID_1);
    callback_cancel(callbackID_2);
    pigpio_stop(pi);
    return 0;
}

