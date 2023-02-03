CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g3 -O0
IFLAGS = -Iinc/
LFLAGS = -lm

.PHONY: all clean re open

IMG  = image.ppm
TGT  = main
SRCS = main.c vec3.c ray.c sphere.c hitable.c camera.c
OBJS = $(SRCS:.c=.o)

all: $(TGT)

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(TGT)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(IFLAGS) $(LFLAGS)

clean:
	@rm -f $(OBJS) $(TGT) $(IMG)

re: clean $(TGT)

open: $(TGT)
	./$(TGT) > $(IMG)
	xdg-open $(IMG)
