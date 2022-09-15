#ifndef __MINHASH_H
#define __MINHASH_H

enum min_type {
	UNKNOWN = 0, CHAR, INT, SHORT, LONG, POINTER
};

struct min_hashmap_item {
	unsigned int hash;
	enum min_type type;
	void* value;
};

struct min_hashmap_linked {
	struct min_hashmap_item item;
	struct min_hashmap_linked* next;
};

struct min_hashmap_linked* min_hashmap_linked_new();
void min_hashmap_linked_delete(struct min_hashmap_linked* ptr);

struct min_hashmap_bucket {
	int heap;
	int count;
	struct min_hashmap_linked* items;
};

struct min_hashmap_bucket* min_hashmap_bucket_new();
void min_hashmap_bucket_delete(struct min_hashmap_bucket* ptr);

struct min_hashmap {
	int capacity;
	struct min_hashmap_bucket* items;
};

struct min_hashmap* min_hashmap_new(int capacity);
void min_hashmap_delete(struct min_hashmap* ptr);

unsigned int hash(const char *buf, int size);

#endif /* __MINHASH_H */
