# rapidFIRE_SPI Library
ImmersionRC Rapidfire - SPI Mode Programming

## Description

This library provides SPI control for the IRC rapidFIRE receiver. You can perform functions such as changing the VTX frequency (band and channel) from ESP32, Arduino or etc..., and displaying arbitrary text on the OSD. For more details, please refer to the [official specification document](https://www.immersionrc.com/?download=5995).

## Applications

- VTX Channel Changer
- RSSI Visual Monitor
- LAP or Time Viewer(using UserText OSD)
- Custom Buzzer

![Sample](/docs/images/rapidFIRE_SPI_Sample.jpg) 

## Pin Map

Connect CS1, CS2, CS3, and GND to your microcontroller.

| rapidFIRE | Pin |
| ----------- | --- |
| CS3 ​CLK     | 1 |
| CS2 DATA    | 2 |
| CS1 NSS     | 3 |
| Video       | 4 |
| Audio 6.5M  | 5 |
| Audio 6M    | 6 |
| Gnd         | 7 |
| Gnd         | 8 |
| +5V         | 9 |

Bottom View

![PinAssign](/docs/images/rapidFIRE_SPI_PinAssign.jpg) 

## See also

- rapidFIRE 5.8GHz Goggle Module: [Click Here](https://www.immersionrc.com/fpv-products/rapidfire/)

- rapidFIRE SPI Mode API Documentation: [Click Here](https://www.immersionrc.com/?download=5995)
