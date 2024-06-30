TARGET = my_rtos_project
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -O2
LDFLAGS = -Tsrc/startup/linker_script.ld

SRCS = src/main.c src/rtos.c src/startup/startup_stm32f103xx.s
OBJS = $(SRCS:.c=.o) $(SRCS:.s=.o)

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET).elf

.PHONY: clean
