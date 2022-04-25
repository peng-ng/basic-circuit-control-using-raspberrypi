# basic-circuit-control-using-raspberrypi
This is my first repository containing hello codes that can program a Raspberry Pi to control basic electronic circuits  

**pb_control_led.cpp**  

This C++ source code can be compiled and run to turn on/off an LED in response to a push button switch connected to a GPIO input pin, using callback functions that are automatically invoked when the state of the input pin changes  

To compile the .cpp file, run the command as follows -  

$g++ -o pb_control_led pb_control_led.cpp -lpigpiod_if2 -lrt  

Before running the executable file, check whether the pigpio daemon is active or running as follows -  

$systemctl is-active pigpiod  

If the daemon is not active, the command returns the result of "failed". To run or start the daemon, use either command as follows -  

$sudo systemctl start pigpiod or $sudo pigpiod  

To run the executable file in the background, run the shell command as follows -  

$./pb_control_led &  

Schematic diagram of the wiring circuit is shown as follows -  
![](https://github.com/peng-ng/basic-circuit-control-using-raspberrypi/blob/main/manual_button_led.png)

Upper figure shows the wiring diagram to read the open/close status of a push button switch using digital input pin number GPIO 27 with a pull-up resistor  

Lower figure shows the other half of the wiring diagram to turn on and off an LED using output pin number GPIO 26 with a current-limiting resistor in series
