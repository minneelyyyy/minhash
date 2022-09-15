#include <minhash.h>

unsigned int hash(const char *buf, int size) {
	unsigned int hash = 5381;
	int i;

	for (i = 0; i < size; i++) {
		hash = ((hash << 5) + hash) + buf[i];
	}

	return hash;
}
