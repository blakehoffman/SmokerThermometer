#include <stdio.h>
#include "src/configuration.h"
#include "src/AnalogDigitalConversion/AnalogDigitalConversion.h"
#include "src/Calculations/Calculations.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>

Adafruit_SSD1306 display(OLEDConfiguration::screenWidth, OLEDConfiguration::screenHeight, &Wire, -1);
AnalogDigitalConversion foodProbe(FoodProbeConfiguration::pinNumber);
AnalogDigitalConversion grateProbe(GrateProbeConfiguration::pinNumber);

const long interval = 5000;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

void setup() {
    bool setupOLEDIsSuccessful = setupOLED();
    //connectToWifi();
}

void loop() {
    currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        //float foodProbeTemp = readTemp(foodProbe);
        //float grateProbe = readTemp(grateProbe);

        printTemp(20, "Food");
        delay(2500);
        printTemp(250,"Pit");
    }
}

void connectToWifi()
{
    WiFi.begin(WifiConfiguration::wifiName, WifiConfiguration::wifiPassword);
}

float readTemp(AnalogDigitalConversion probe)
{
    float probeVoltage = probe.getVoltage();
    float temperature = Calculations::getTemp(
        ArduinoConfiguration::VoltageSupply,
        probeVoltage,
        ResistorTwoConfiguration::Resistance,
        GeneralProbeConfiguration::steinConstants[0],
        GeneralProbeConfiguration::steinConstants[1],
        GeneralProbeConfiguration::steinConstants[2]);

    return temperature;
}

void printTemp(float temp, String description)
{
    String tempText = String(temp) + " F";
    display.clearDisplay();
    display.setTextSize(4);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(description);
    display.println(tempText);
    display.display();
}

bool setupOLED()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLEDConfiguration::screenAddress))
    {
        return false;
    }

    return true;
}
