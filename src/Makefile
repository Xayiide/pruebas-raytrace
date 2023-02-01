CC     = g++
CFLAGS = -Wall -Wextra -g3 -O0
IFLAGS = -Iinc/

.PHONY: clean re open

IMG = image.ppm
SRC = main.cpp
TGT = $(SRC:.cpp=)

$(TGT): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(TGT)

re: clean $(TGT)

open: $(TGT)
	./$(TGT) > $(IMG)
	xdg-open $(IMG)
