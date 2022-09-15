CC?=cc
AR?=ar
CFLAGS?=-g
ARFLAGS=-crs
INCLUDE=-I./include
PREFIX?=/usr

object-files := src/hashmap.o \
				src/hash.o

include-files := include/minhash.h

.PHONY: all tests clean install uninstall

all: libminhash.so libminhash.a

libminhash.so: $(object-files)
	$(CC) $(CFLAGS) -shared -fpie -o $@ $^

libminhash.a: $(object-files)
	$(AR) $(ARFLAGS) $@ $^

tests: libminhash.a
	$(CC) $(CFLAGS) $(INCLUDE) -o tests/constructor tests/constructor.c $^

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -rf $(object-files) libminhash.so libminhash.a
	rm -rf test/constructor

install:
	mv libminhash.so $(PREFIX)/lib/libminhash.so
	mv libminhash.a $(PREFIX)/lib/libminhash.a
	cp $(include-files) $(PREFIX)/include/

uninstall:
	rm -f $(PREFIX)/lib/libminhash.so
	rm -f $(PREFIX)/lib/libminhash.a
	rm -f $(PREFIX)/$(include-files)