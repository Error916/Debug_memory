CFLAGS=-Wall -Wextra -std=c11 -pedantic -O3
LIBS=
SRC=mem_test.c f_mem_debug.c

mem_test: $(SRC)
	$(CC) $(CFLAGS) -o mem_test $(SRC) $(LIBS)
