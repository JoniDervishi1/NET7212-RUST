C_BINARIES = bracket-parser #linkedlist #uppercase 
CXX_BINARIES = #fibonacci
BINARIES = $(C_BINARIES) $(CXX_BINARIES)

CC = clang
CXX = clang++

CALLFLAGS = -g -O0 -Wall -Wextra 
CFLAGS = $(CALLFLAGS) -std=gnu99 -fsanitize=address,undefined #needs to be in the cflags for c compiler 	
CXXFLAGS = $(CALLFLAGS) -std=c++17
LDFLAGS = -fsanitize=address,undefined

all: $(BINARIES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(C_BINARIES): %:%.o
	$(CC) $^ $(LDFLAGS) -o $@
$(CXX_BINARIES): %:%.o
	$(CXX) $^ $(LDFLAGS) -o $@

distclean: clean
clean:
	rm -f *.o $(BINARIES)
