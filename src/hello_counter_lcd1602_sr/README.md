# ESP32-CAM with LCD1602

The ESP32-cam has barely any physically accessible pins, because of the camera and SD card.

We can "extend" the amount of usable pins by using a shift register.

![My example](./esp_lcd1602_real0.jpg)

![My example](./esp_lcd1602_real1.jpg)

There is a Raspberry PI, but it's only acting as 
a power supply for both 5v and 3.3v.

Here's the schematic:

![Schematic](./esp_lcd1602_schematic.jpg)

## Libraries
- https://github.com/davetcc/LiquidCrystalIO
