#include <stdio.h>
#include "configuration.h";
#include "ADC/ADC.h";
#include "Calculations/Calculations.h";

Adafruit_SSD1306 display(OLEDConfiguration::screenWidth, OLEDConfiguration::screenHeight, &Wire, -1);
ADC foodProbe(FoodProbeConfiguration::pinNumber);
ADC grateProbe(GrateProbeConfiguration::pinNumber);

int main()
{
    bool setupOLEDIsSuccessful = setupOLED();
    const long interval = 5000;
    unsigned long previousMillis = 0;
    unsigned long currentMillis = 0;

    while (true)
    {
        currentMillis = millis();

        if (currentMillis - previousMillis >= interval)
        {
            previousMillis = currentMillis;

            float foodProbeTemp = readTemp(foodProbe);
            float grateProbe = readTemp(grateProbe);

            Serial.print("Food probe temp: ", foodProbeTemp);
            Serial.print("Food probe temp: ", grateProbe);
        }
    }
}

float readTemp(ADC probe)
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

bool setupOLED()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLEDConfiguration::screenAddress))
    {
        return false;
    }

    display.print_ln("Welcome");
    return true;
}