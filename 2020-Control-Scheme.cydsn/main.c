#include "project.h"
#include <stdio.h>

#define EP_IN 1 // Endpoint for reading data from HID
#define EP_OUT 2 // Endpoint for sending data from host to HID

#define BUTTON_SIZE 2 // 2 indices for 2 bytes of button data

static uint8 USB_INPUT[BUTTON_SIZE];
static uint8 USB_OUTPUT[BUTTON_SIZE];
int flash_time = 70;

void startup(void){
    // initalize all arrays
    for(uint8 j = 0; j < BUTTON_SIZE; j++){
        USB_INPUT[j] = 0;
    }    
    for(uint8 k = 0; k < BUTTON_SIZE; k++){
        USB_OUTPUT[k] = 0;
    }  
    
    CyGlobalIntEnable // enable global interrupts 
    USB_Start(0, USB_DWR_VDDD_OPERATION); // start usb port with bus power
    while(!USB_bGetConfiguration()){} // wait to configure the usb port
    
    USB_LoadInEP(EP_IN, (uint8 *)USB_INPUT, sizeof(USB_INPUT)); // Initial load-in of port
    USB_EnableOutEP(EP_OUT);
}

void read_buttons(void){
    USB_INPUT[0] = Status_1_8_Read();
    USB_INPUT[1] = Status_9_11_Read();
}

void write_leds(void){
    LEDs_1_8_Write(USB_INPUT[0]);
    LEDs_9_10_Write(USB_INPUT[1]);
}

void blink_button(void){
    for(int i = 0; i < 10; i++){
        Internal_LED_Write(1);
        CyDelay(flash_time);
        Internal_LED_Write(0);
        CyDelay(flash_time);
    } 
}

int main(void)
{
    startup();
    
    blink_button();
    
    for(;;)
    {
    
    while(!USB_bGetEPAckState(EP_IN)); // Wait for ACK signal before sending data
    
    read_buttons(); // Store button values in an array
    write_leds();
    
     // if usb reading data is empty, write
    if (USB_GetEPState(EP_IN) == USB_IN_BUFFER_EMPTY){
        USB_LoadInEP(EP_IN, (uint8 *)USB_INPUT, sizeof(USB_INPUT)); // check last parameter
    }
    
    }
}
