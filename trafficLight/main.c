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


void setTrafficLight(bool northbound, bool toGreen){
	// TODO: Implement (#2)
}


void setPedLight(bool northbound, bool toGreen){
	// TODO: Implement (#3)
}


void setTrafficDir(bool northbound){
	// TODO: Implement (#4)
}


int main(void)
{
	DDRB = 0xFF;
	DDRD = 0b11111011;
	// TODO: Implement (#5)
}

