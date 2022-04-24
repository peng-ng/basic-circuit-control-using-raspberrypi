# basic-circuit-control-using-raspberrypi
This is my first repository containing C++ and python hello codes to control basic electronic devices using a Raspberry Pi 4  

Pre-requisites: basic knowledge of a programming language such as C/C++ or python, electrical circuits, and linux shell commands

OS: Raspbian Buster

$systemctl is-active pigpiod  

Before executing the C++ compiled programs, I run the command above to check whether the pigpio daemon is active or running; if it is not active or running, the command will return the result of "failed". To run or start the daemon, either command can be used as follows -  

$sudo systemctl start pigpiod or $sudo pigpiod

![](https://github.com/peng-ng/basic-circuit-control-using-raspberrypi/blob/main/manual_button_led.png)

Upper figure shows the wiring diagram to read a push button switch using digital input pin number GPIO 27 with pull-up resistor  

Lower figure shows the wiring diagram to control an LED using output pin number GPIO 26 with current limiting resistor in series
