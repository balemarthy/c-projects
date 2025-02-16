# Makefile for Sugarcane Juice Vending Machine (ATmega2560)
# Author: 

# MCU and Clock Speed
MCU = atmega2560
F_CPU = 16000000UL

# Compiler and Flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra

# AVRDUDE settings (Change as needed for your programmer)
PROGRAMMER = usbasp
AVRDUDE = avrdude
AVRDUDE_FLAGS = -c $(PROGRAMMER) -p m2560

# Source and Object Files
SRC = main.c hardware.c state_machine.c debounce.c
OBJ = $(SRC:.c=.o)

# Output Files
TARGET = vending_machine

# Compilation and Linking
all: $(TARGET).hex

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Flashing to ATmega2560
flash: $(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(TARGET).hex:i

# Clean Build Files
clean:
	rm -f $(OBJ) $(TARGET).elf $(TARGET).hex
