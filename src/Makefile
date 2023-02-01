CC     = g++
CFLAGS = -Wall -Wextra -g3 -O0
IFLAGS = -Iinc/

.PHONY: all clean re open

IMG  = image.ppm
TGT  = main
OBJS = main.o vec3.o

all: $(TGT)

$(TGT): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(IFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@ $(IFLAGS)

clean:
	@rm -f $(TGT) $(IMG) $(OBJS)

re: clean $(TGT)

open: $(TGT)
	./$(TGT) > $(IMG)
	xdg-open $(IMG)
