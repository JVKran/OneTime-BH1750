/* OneTime-BH1750 Library
   Jochem van Kranenburg - jochemvk.duckdns.org - 9 March 2020
*/

#include "BH1750.h"

#ifdef BH1750_ATTINY
BH1750::BH1750(USI_TWI & bus, const uint8_t address):
	bus(bus),
	address(address)
{}
#else
BH1750::BH1750(TwoWire & bus, const uint8_t address):
	bus(bus),
	address(address)
{}
#endif

void BH1750::begin(){
	bus.begin();
}

uint16_t BH1750::getLightIntensity(){
	bus.beginTransmission(address);
	bus.write((uint8_t)opCodes::ONE_TIME_LOW_RES);
	bus.endTransmission();

	delay((uint8_t)measurementDurations::LOW_RES_MEAS_TIME);

	bus.requestFrom(address, (uint8_t)2);
	uint16_t intensity = bus.read() << 8;
	intensity |= bus.read();

	return intensity;
}