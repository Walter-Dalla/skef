
CFLAGS = -Wall -Wextra -std=c11

install:
	gcc core/*.c -o skef $(CFLAGS)