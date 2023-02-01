CC     = g++
CFLAGS = -Wall -Wextra -g3 -O0
IFLAGS = -Iinc/

.PHONY: all clean re open

IMG  = image.ppm
TGT  = main
OBJS = main.o

all: $(TGT)

$(TGT): main.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(IFLAGS)

clean:
	@rm -f $(TGT) $(IMG) $(OBJS)

re: clean $(TGT)

open: $(TGT)
	./$(TGT) > $(IMG)
	xdg-open $(IMG)
