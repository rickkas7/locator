#ifndef __LOCATOR_H
#define __LOCATOR_H


typedef void (*LocatorSubscriptionCallback)(float lat, float lon, float accuracy);

class Locator {
public:
	Locator();
	virtual ~Locator();

	Locator &withLocateOnce();
	Locator &withLocatePeriodic(unsigned long secondsPeriodic);

	Locator &withEventName(const char *name);
	Locator &withPublicEvent();

	Locator &withSubscribe(LocatorSubscriptionCallback callback, bool onlyThisDevice = true);

	Locator &withWiFiConsiderIp(bool value);

	void loop();

	const char *scan();

	void publishLocation();

protected:
	void subscriptionHandler(const char *event, const char *data);

#if Wiring_WiFi
	const char *wifiScan();
#endif

#if Wiring_Cellular
	const char *cellularScan();
#endif

	static const int CONNECT_WAIT_STATE = 0;
	static const int CONNECTED_WAIT_STATE = 2;
	static const int CONNECTED_STATE = 3;
	static const int IDLE_STATE = 4;

	static const int LOCATOR_MODE_MANUAL = 0;
	static const int LOCATOR_MODE_ONCE = 1;
	static const int LOCATOR_MODE_PERIODIC = 2;

	int locatorMode;
	unsigned long periodMs;
	String eventName;
	bool publicEvent;
	unsigned long stateTime;
	int state;
	LocatorSubscriptionCallback callback;
	unsigned long waitAfterConnect;
	bool wifiConsiderIp;
};

#endif
