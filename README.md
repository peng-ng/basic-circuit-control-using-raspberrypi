# basic-circuit-control-using-raspberrypi
This is my first repository containing C++ and python hello codes to control basic electronic devices using a Raspberry Pi 4  

**pb_control_led.cpp**  

This program turns on and off an LED in response to the push button switch connected to a GPIO input pin, using callback functions that are automatically invoked according to the change of state at the input pin  

To compile the .cpp file, run the command as follows -  

$g++ -o pb_control_led pb_control_led.cpp -lpigpiod_if2 -lrt  

Before running the executable file, check whether the pigpio daemon is active or running as follows -  

$systemctl is-active pigpiod  

If it is not active, the command returns the result of "failed". To run or start the daemon, use either command as follows -  

$sudo systemctl start pigpiod or $sudo pigpiod  

To run the executable file in the background, run the next command as follows -  

$./pb_control_led &

![](https://github.com/peng-ng/basic-circuit-control-using-raspberrypi/blob/main/manual_button_led.png)

Upper figure shows the wiring diagram to read the open/close status of a push button switch using digital input pin number GPIO 27 with a pull-up resistor  

Lower figure shows the other half of the wiring diagram to turn on and off an LED using output pin number GPIO 26 with a current-limiting resistor in series
