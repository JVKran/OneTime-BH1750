# OneTime-BH1750
There isn't a large amount of small, efficient and easy to use libraries for the BH1750; that's what I found out when I needed one.
That's the main goal of this entire library.

The name of this respository stands for the mode in which the BH1750 is used. In One Time mode the chip sleeps and gets waked up if data is requested. During measurements it peeks up to normal current consumption. However, when not in use, the chip only uses 0.01uA! Great for battery powered ATtiny's ;).

## Advantages of this library
- Ultra low power. In sleep mode the BH1750 only uses 0.01uA!
- Ultra small footprint; this library was made with efficiency and memory usage in mind.
- Easy to use interface and functions. Despite the small size of this library, functions are still very intuitive.
- Automatically change between using Wire and TinyWire.


## Example
There has been given an example that can be obtained from below or from within the Arduino IDE in Examples->Forced-BME280->Test.
```c++
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
```

> This library automatically determines wether to use TinyWireM or Wire. The _begin()_ function of the corresponding bus is called in BH1750::begin(). That doesn't have to be taken care of anymore.

## Functions
#### begin() 
This function starts the Wire or TinyWire bus by calling _begin()_ on the corresponding object.
#### getLightIntensity()
This function can be used to retrieve the light intensity. After returning the intensity, the BH1750 gets back to sleep; this is done automatically. This function takes approximately 24ms to execute due to the measurement duration of the intensity.


## Installation
#### Download
Press the green _clone or download_ button in the upper-right and download as _.ZIP_. Then go to the Arduino IDE and go to _Sketch_>Use Library->Add .ZIP Library_ and select the just downloaded zip file.

#### Library Manager
Open up the Library Manager in the Arduino IDE and search for *OneTime-BH1750*. Select the desired version; higher means more features ;).