#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <iostream>
#include <pigpiod_if2.h>

using namespace std;

const int LED = 6; //use GPIO 6 to control the LED light

//function to setup a handshake with the PIGPIO daemon
int PigpioSetup() {
    char *addrStr = nullptr;
    char *portStr = nullptr;
    int pi = pigpio_start(addrStr, portStr);
    set_mode(pi, LED, PI_OUTPUT);
    gpio_write(pi, LED, 0);
    return pi;
}

int main() {
    int pi = PigpioSetup();
    if (pi >= 0)
        cout << "PIGPIOD daemon interface started ok at " << pi << endl;
    else {
        cout << "Failed to connect to PIGPIO daemon \n" << \
        "Try running sudo pigpiod and try again." << endl;
        return 1;
    }
    /*initialse the RFCOMM address structures of the local device (RPI)
    and remote device (android phone)*/
    struct sockaddr_rc local_address = { 0 }, remote_address = { 0 };
    //initialise a buffer to hold the incoming data
    char data[1024] = { 0 };
    //declare variables to hold values of the server and client sockets,
    //and incoming bytes information
    int s, clientsocket, bytes;
    //variable to hold the size of the remote device's address structure
    socklen_t opt = sizeof(remote_address);
    /*server socket is created with the communication domain set to
    AF_BLUETOOTH, communication type set to SOCK_STREAM, & communication
    protocol to BTPPROTO_RFCOMM*/
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    //fill up the RFCOMM address structure of the local device
    local_address.rc_family = AF_BLUETOOTH;
    bdaddr_t bdaddr_any = { };
    local_address.rc_bdaddr = bdaddr_any;
    local_address.rc_channel = (uint8_t) 1;
    /*bind server socket to channel 1 of the first available local
    bluetooth adapter*/
    bind(s, (struct sockaddr *)&local_address, sizeof(local_address));
    //puts server socket into listening mode
    listen(s, 1);
    //create client socket when incoming connection request is accepted
    clientsocket = accept(s, (struct sockaddr *)&remote_address, &opt);
    //convert incoming byte data into a string
    ba2str( &remote_address.rc_bdaddr, data );
    //display MAC address of the connected bluetooth device
    cout << "Connected to " << data << endl;
    memset(data, 0, sizeof(data));
    while (1) {
        //read incoming data
        bytes = read(clientsocket, data, sizeof(data));
        if( bytes > 0 ) {
            cout << "Alphabet: " << data << endl;
	    if(*data=='1')
                gpio_write(pi, LED, 1);
            else if(*data=='0')
	        gpio_write(pi, LED, 0);
	    else if(*data=='E') {
                gpio_write(pi, LED, 0);
                break; }
        }
    }
    //shut down sockets and free the memory allocated to them
    close(clientsocket);
    close(s);
    pigpio_stop(pi);
    return 0;
}
