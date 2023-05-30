#include <M5Stack.h>
#include <rapidFIRE_SPI.h>

// GPIO
//#define SPI_PIN_CLK 16  // Port.C RXD(Y) --> rapidFIRE Pin.1(CS3 CLK)
//#define SPI_PIN_DATA 17 // Port.C TXD(W) --> rapidFIRE Pin.2(CS2 DATA)
#define SPI_PIN_CLK 22 // Port.A (Y)      --> rapidFIRE Pin.1(CS3 CLK)
#define SPI_PIN_DATA 21 // Port.A (W)      --> rapidFIRE Pin.2(CS2 DATA)
#define SPI_PIN_SS 26   // Port.B          --> rapidFIRE Pin.3(CS1 NSS)

rapidFIRE_SPI rapidfire(SPI_PIN_CLK, SPI_PIN_DATA, SPI_PIN_SS);

void setup()
{
    M5.begin();

    // rapidFIRE SPI mode enabled.
    rapidfire.begin();

    // play buzzer
    for (int i = 0; i < 5; ++i)
    {
        rapidfire.buzzer();
        delay(200);
    }

    // Query firmware version.
    {
        QUERY_FIRMWARE_VERSION ver;
        rapidfire.getFirmwareVersion(&ver);
        Serial.printf("rapidFIRE: Ver %d.%d.%d\n", ver.oled[0], ver.oled[1], ver.oled[2]);
    }
    delay(100);

    // Select E1 (5705MHz) band.
    rapidfire.setBand(rapidFIRE_SPI::BAND::BAND_E);
    delay(100);
    rapidfire.setChannel(1);
    delay(500);

    // Select F1 (5740MHz) band.
    rapidfire.setBand(rapidFIRE_SPI::BAND::BAND_F);
    delay(100);
    rapidfire.setChannel(1);
    delay(500);

    // Select F4 (5800MHz) band.
    rapidfire.setBand(rapidFIRE_SPI::BAND::BAND_F);
    delay(100);
    rapidfire.setChannel(4);
    delay(500);

    // Set OSD to 'User text' mode
    rapidfire.setOSDMode(rapidFIRE_SPI::OSDMODE::USERTEXT);
}

static int count = 0;

void loop()
{
    // Query firmware version.
    {
        QUERY_FIRMWARE_VERSION ver;
        rapidfire.getFirmwareVersion(&ver);
        Serial.printf("rapidFIRE: Ver %d.%d.%d\n", ver.oled[0], ver.oled[1], ver.oled[2]);
    }

    // Query RSSI.
    delay(500);
    {
        QUERY_RSSI rssi;

        RF_RESULT res = rapidfire.getRSSI(&rssi);
        if (res == RF_RESULT_OK)
        {
            Serial.printf("rapidFIRE: RSSI RX1:%d(%d) RX2:%d(%d)\n",
                          rssi.raw_rx1,
                          rssi.scaled_rx1,
                          rssi.raw_rx2,
                          rssi.scaled_rx2);
        }
        else
        {
            Serial.printf("Error: can't query RSSI.(%d)\n", res);
        }
    }
    delay(500);

    // Query Voltage.
    {
        QUERY_VOLTAGE volt;
        RF_RESULT res = rapidfire.getVoltage(&volt);
        if (res == RF_RESULT_OK)
        {
            Serial.printf("rapidFIRE: %fV\n", volt.voltage);
        }
        else
        {
            Serial.printf("Error: can't query voltage.(%d)\n", res);
        }
    }
    delay(100);
    // Set OSD to 'User text' mode
    rapidfire.setOSDMode(rapidFIRE_SPI::OSDMODE::USERTEXT);


    delay(100);
    char temp[256];
    sprintf(temp, "HELLO FPV! %5d", count++ );
    rapidfire.setOSDUserText(temp);

    delay(100);
}
