#
# picoUART example makefile
# edited to support flashing
#

# MCU ?= attiny85
MCU ?= atmega328
F_CPU ?= 8000000
SRC = ../picoUART/src
SOURCES := $(wildcard $(SRC)/*.c $(SRC)/*.cpp)
SKETCH := $(wildcard *.ino)

all: main.hex

clean:
	rm -f *.o *~ *.hex *.elf *.map *.lst

main.elf:
	avr-gcc -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -flto -I$(SRC) main.cpp $(SOURCES) -x c++ $(SKETCH) -o main.elf

# programmer configuration for avrdude programming utility
# for AVRISP programmer on USB
DUDEPORT  = -c avrispv2 -P usb

# for Arduino bootloader
# DUDEPORT  = -c arduino -P /dev/ttyACM0

# set to correct device type; usually an Arduino Uno is 328p
DUDEMCU = m328p

AVRDUDE  = avrdude $(DUDEPORT) -p $(DUDEMCU) -y -u 

flash: main.hex
	$(AVRDUDE) -U flash:w:$^:i

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex $< $@
