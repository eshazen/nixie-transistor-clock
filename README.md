In 2013 I built a clock from a kit purchased here:  https://tube-clock.com/

![Clock](pix/first_run.jpg)

* [Manual](neon_man.pdf)

* set_board - start of a design to set the time using an ESP32
* case - acrylic case design


Some circuit analysis for setting remotely.

Set switches (ref schematic in manual):

SW1 (minutes) - page 8/23 (PDF page 70)
SW2 (Hours) - page 10/23 (PDF page 72)
SW3 (s hold) - page 2/23 (PDF page 64)

### 2026-05-11

Based on Peter's claim that WWVB reception was ok at Deb's place,
purchased a [Canaduino Atomic Clock](https://www.canaduino.ca/downloads/CANADUINO_Atomic_Clock_Receiver_Kit_V4.pdf)
board and 3D printed a little holder for it.  It seems to work OK
powered by 2xAA batteries in the kitchen.  Maybe at night it will work
in a window?

Per suggestion in the datasheet, thinking to connect with a shielded
RJ-45 patch cable.  Re-do `set_board_avr` to accommodate the connector,
and remove the 8MHz crystal and WiFi module.

Should probably add a couple of buttons.

Also, maybe need an additional small PCB for the WWVB board
with jumpers for LED and power (choose between battery and remote power).

### 2026-04-29

Confirm that ESP-01 works using FTDI at 115200 baud.
<br>Problem is that hardware UART on 8MHz AVR is unreliable.
<br>Downloaded https://github.com/nerdralph/picoUART
<br>Tested on "control panel" PCB with FTDI and seems to work

Starting to write some WiFi test code

### 2026-04-23

Reviving the "set board" project.  Thinking of a new design with an
ESP-01 serial WiFi module connected to a small AVR (ATTiny85?).
This could be much lower power or even fire up once only on power-up
to retrieve the time from somewhere.

The main issue may be poor wifi in the kitchen!

ESP-01 doco at:  https://nurdspace.nl/ESP8266
