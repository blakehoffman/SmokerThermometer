#include <stdio.h>
#include "configuration.h";

Adafruit_SSD1306 display(OLEDConfiguration::screenWidth, OLEDConfiguration::screenHeight, &Wire, -1);

int main()
{
    bool setupOLEDIsSuccessful = SetupOLED();
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