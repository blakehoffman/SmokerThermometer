#include <stdio.h>
#include "configuration.h";
#include "ADC/ADC.h";

Adafruit_SSD1306 display(OLEDConfiguration::screenWidth, OLEDConfiguration::screenHeight, &Wire, -1);
ADC foodProbe(FoodProbeConfiguration::pinNumber);
ADC grateProbe(GrateProbeConfiguration::pinNumber);

int main()
{
    bool setupOLEDIsSuccessful = SetupOLED();

    while (true)
    {
    }
}

bool setupOLED()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLEDConfiguration::screenAddress))
    {
        return false;
    }

    display.print_ln("Welcome");
    delay(2000);

    return true;
}