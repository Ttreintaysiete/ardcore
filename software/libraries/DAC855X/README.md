# DAC855X
Library for DAC855X digital to analogic converters by Texas Instruments on Arduino

The library was assembled based on the data sheets of Texas Instruments DAC8550, DAC8551, DAC8552, DAC8554 and DAC8555 chips. However, it was tested only on DAC8552, as seen in the example.

For any explanation see Texas Instrument DAC information at

http://www.ti.com/lit/ds/symlink/dac8550.pdf

http://www.ti.com/lit/ds/symlink/dac8551.pdf

http://www.ti.com/lit/ds/symlink/dac8552.pdf

http://www.ti.com/lit/ds/symlink/dac8554.pdf

http://www.ti.com/lit/ds/symlink/dac8555.pdf


The arduino communication with the chip happens via SPI, selecting the appropriate pins for each type of board through the command setPins(DIN, SCLK, SYNC). In Arduino Uno, the pins correspond to:

DIN = MOSI ==> pin 11

SCLK = SCK ==> pin 13

SYNC = SS ==> pin 10

The command is, therefore, setPins(11, 13, 10).

To initiate the transmission, SPI communication must be enabled via the initializeDAC855X() command.

Next, you define the chip type, the channel where the DAC will be obtained and the DAC value (between 0 and 65535), with the setChipChanValue(Chip, Channel, Value of DAC) command.

For the Chip, there are three options:

0 ==> DAC8550 and DAC8551 ==> They have only one channel, so the value for Channel must also be zero.

1 ==> DAC8552 ==> It has two channels. In this way, the value for channel A becomes 0 and for channel B, 1.

2 ==> DAC8554 and DAC8555 ==> They have 4 channels. A (zero), B (1), C (2) and D (3).

In the example, there are a program to generate a sawtooth wave on channel A and a sine wave on channel B, at the same time, using the DAC8552.

The library does not have power down functionality present on these devices.
