/* OneTime-BH1750 Library
   Jochem van Kranenburg - jochemvk.duckdns.org - 11 August 2020
*/

#include <BH1750.h>

// Create an instance of a BH1750. The parameters I2C bus and I2C address are optional. For example:
// - BH1750 lightSensor = BH1750(Wire, 0x23);
// - BH1750 lightSensor = BH1750(TinyWireM, 0x5C);
BH1750 lightSensor = BH1750();

void setup(){
	Serial.begin(9600);
	lightSensor.begin();
}

void loop(){
	Serial.println(lightSensor.getLightIntensity());
	delay(1000);
}