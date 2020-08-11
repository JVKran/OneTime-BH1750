/* OneTime-BH1750 Library
   Jochem van Kranenburg - jochemvk.duckdns.org - 9 March 2020
*/

#ifndef __BH1750_H
#define __BH1750_H

#if defined(__AVR_ATtiny25__) | defined(__AVR_ATtiny45__) | defined(__AVR_ATtiny85__) | defined(__AVR_AT90Tiny26__) | defined(__AVR_ATtiny26__)
	#define BH1750_ATTINY
#endif

#include <Arduino.h>

#ifdef BH1750_ATTINY
#include <TinyWireM.h>
#else
#include <Wire.h>
#endif 


class BH1750 {
	private:
		#ifdef BH1750_ATTINY
		USI_TWI & bus;
		#else
		TwoWire & bus;	
		#endif
		uint8_t address;

		enum class opCodes {
			PWR_DOWN = 0x00,
			PWR_UP = 0x01,
			ONE_TIME_LOW_RES = 0x23
		};

		enum class measurementDurations {
			LOW_RES_MEAS_TIME = 24
		};

	public:
		#ifdef BH1750_ATTINY
		BH1750(USI_TWI & bus = TinyWireM, const uint8_t address = 0x23);
		#else
		BH1750(TwoWire & bus = Wire, const uint8_t address = 0x23);
		#endif

		void begin();

		uint16_t getLightIntensity();
};

#endif //__BH1750_HPP