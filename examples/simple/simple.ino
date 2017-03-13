#include "Particle.h"
#include "locator.h"

SerialLogHandler logHandler;
Locator locator;

SYSTEM_THREAD(ENABLED);


void setup() {
	Serial.begin(9600);
	locator.withLocatePeriodic(120);
}


void loop() {
	locator.loop();
}

