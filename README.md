# basic-circuit-control-using-raspberrypi
**Introduction**  

This is my first repository containing C/C++ hello codes that I use to program a Raspberry Pi 4 (RPI) to control basic electronic circuits. I am using the Raspbian Buster OS and the built-in GNU C++ compiler. I am also using the built-in PIGPIO library to control the RPI's general-purpose-input-output pins  

**(1) pb_control_led.cpp**  

![](https://github.com/peng-ng/basic-circuit-control-using-raspberrypi/blob/main/manual_button_led.png)

Upper half of the wiring circuit is used to read the input status of a push button switch using pin number GPIO 27 with a pull-up resistor; the pin reads high when the switch is open, and reads low when the switch is close  

Lower half of the wiring circuit is used to turn on and off an LED light using pin number GPIO 26 with a current-limiting resistor in series

The program uses callback functions that are invoked when the input level at GPIO 27 changes (from high to low and from low to high), which in turn will turn on and off the LED light   

To compile the .cpp file, run the command as follows -  

$g++ -o pb_control_led pb_control_led.cpp -lpigpiod_if2 -lrt  

Before running the executable file, check whether the PIGPIO daemon is active or running as follows -  

$systemctl is-active pigpiod  

If the daemon is not active, the command returns the result of "failed". To run or start the daemon, use either command as follows -  

$sudo systemctl start pigpiod or $sudo pigpiod  

To run the executable file in the background, run the shell command as follows -  

$./pb_control_led &  

**(2) voice_control_led.cpp**  

![](https://github.com/peng-ng/basic-circuit-control-using-raspberrypi/blob/main/voice_control_led_1.png)  

The program turns on and off the LED light in response to my voice instructions ("ON", "OFF" and "EXIT") through an Android app running on my smartphone. The Android voice control app is developed using the MIT App Inventor. The voice control Android app is archived into the file called  **VoiceControlBot.aia**, and you can login to your AI account to import and have a look inside  
  
  
![](https://github.com/peng-ng/basic-circuit-control-using-raspberrypi/blob/main/mit_app_inventor_1.png)  

![](https://github.com/peng-ng/basic-circuit-control-using-raspberrypi/blob/main/mit_app_inventor_2.png)  

Both smartphone and RPI have to be paired using bluetooth. I have also enabled the serial port profile on the RPI by editing the bluetooth.service systemd unit file  

The libbluetooth-dev package has to be installed because it has some of the bluetooth header files that are required  

The .cpp file can be compiled as follows  

g++ -o voice_control_led voice_control_led.cpp -lpigpiod_if2 -lrt -lbluetooth
