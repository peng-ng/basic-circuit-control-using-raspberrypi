# basic-circuit-control-using-raspberrypi
This is my first repository for learning C++ and python programming to control basic electronic devices using a Raspberry Pi 4

OS: Raspbian Buster

$systemctl is-active pigpiod
The pigpio C utility library is by default installed with the OS. Before executing the C++ compiled programs, we can run the command above to check whether the daemon is active or running; if it is not active or running, the command will return the result of "failed". To run or activate the daemon, we can run either command as follows - $sudo systemctl start pigpiod, or $sudo pigpiod.
