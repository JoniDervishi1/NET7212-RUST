CC := gcc
CFLAGS := -Wall -fprofile-arcs -ftest-coverage
CPPFLAGS := $(shell pkg-config --cflags check)
LDLIBS := $(shell pkg-config --libs check)

.PHONY: all test coverage clean

all: check_money_tiny

check_money_tiny: check_money_tiny.o money.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

check_money_tiny.o: check_money_tiny.c money.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

money.o: money.c money.h
	$(CC) $(CFLAGS) -c $< -o $@

test: check_money_tiny
	./check_money_tiny

coverage: test
	gcov money.c

clean:
	rm -f check_money_tiny *.o *.gcno *.gcda *.gcov