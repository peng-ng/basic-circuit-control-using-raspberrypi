# basic-circuit-control-using-raspberrypi
This is my first repository containing C++ and python hello codes to control basic electronic devices using a Raspberry Pi 4  

Pre-requisites: basic knowledge of a programming language such as C/C++ or python, electrical circuits, and linux shell commands

OS: Raspbian Buster

$systemctl is-active pigpiod  

Before executing the C++ compiled programs, I run the command above to check whether the pigpio daemon is active or running; if it is not active or running, the command will return the result of "failed". To run or start the daemon, either command can be used as follows -  

$sudo systemctl start pigpiod or $sudo pigpiod

![](https://www.raspberrypi.com/documentation/computers/images/GPIO-Pinout-Diagram-2.png)

