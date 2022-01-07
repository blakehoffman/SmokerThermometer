#define SCREEN_WIDTH = 128
#define SCREEN_HEIGHT = 64;
#define OLED_RESET = -1;
#define SCREEN_ADDRESS = 0x3C;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void clear_display() {
    display.clear_display();
}

int setup_display() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        return 0;
    }

    print_to_display("Welcome");
    delay(2000);

    return 1;
}

void print_to_display(char* string) {
    display.println(string);
}
