/*
 * trafficLight.c
 *
 * Created: 03-11-2022 22:33:02
 * Authors : Anders, Daniel & Oliver
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h>
#include <stdbool.h>  // Add boolean data type

// Globals
#define GREENTIME 10  // How many seconds can the light stay green?
#define pedDelay 2  // How much earlier do the pedestrian lights turn off, than the car lights?
#define carDelay GREENTIME * 0.1  // How long are all traffic lights red, when changing from one side to another?

bool currentlyNorthbound = false;  // Is the traffic currently northbound?

char trafficLights[2][4] = {
  // Red, Yellow, Green, Pedestrian
	{0b00001000, 0b00010000, 0b00100000, 0b01000000},  // Port D, E/W
	{0b00000001, 0b00000010, 0b00000100, 0b00001000}  // Port B, N/S
};


void setTrafficLight(bool northbound, bool toGreen){
	// TODO: Implement (#2)
}


void setPedLight(bool northbound, bool toGreen){
  // Sets the pedestrian light to green, if toGreen is true, and red if toGreen is false
  // Uses the eastbound pedestrian light if northbound is false, and northbound if northbound is true
  if (northbound){
    if (toGreen){
      PORTB |= trafficLights[1][3];
    }
    else{
      PORTB &= ~trafficLights[1][3];
    }
  }
  else{
    if (toGreen){
      PORTD |= trafficLights[0][3];
    }
    else{
      PORTD &= ~trafficLights[0][3];
    }
  }
}


void setTrafficDir(bool northbound){
	// TODO: Implement (#4)
}


int main(void)
{
	DDRB = 0xFF;
	DDRD = 0b11111011;
	// TODO: Implement (#5)
	while (1){
		setPedLight(true, true);
		_delay_ms(500);
		setPedLight(true, false);
		_delay_ms(500);
	}
}

