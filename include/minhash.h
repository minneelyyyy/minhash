#ifndef __MINHASH_H
#define __MINHASH_H

enum min_type {
	UNKNOWN = 0, CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, POINTER
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

static void* float_to_ptr(float f) {
	return (void*) *(unsigned long*) &f;
}

static void* double_to_ptr(double d) {
	return (void*) *(unsigned long*) &d;
}

#define HM_char(c) (void*) c
#define HM_short(s) (void*) s
#define HM_int(i) (void*) i
#define HM_long(l) (void*) l
#define HM_float(f) float_to_ptr(f)
#define HM_double(d) double_to_ptr(d)
#define HM_ptr(p) (void*) p

#define HM_key_char(c) CHAR, HM_char(c), sizeof(void*)
#define HM_key_short(s) SHORT, HM_short(s), sizeof(void*)
#define HM_key_int(i) INT, HM_int(i), sizeof(void*)
#define HM_key_long(l) LONG, HM_long(l), sizeof(void*)
#define HM_key_float(f) FLOAT, HM_float(f), sizeof(void*)
#define HM_key_double(d) DOUBLE, HM_double(d), sizeof(void*)
#define HM_key_ptr(p) POINTER, HM_ptr(p), sizeof(void*)
#define HM_key_string(str) POINTER, (void*) str, strlen(str)

struct min_hashmap* min_hashmap_add(struct min_hashmap* map,
	enum min_type type, void* key, int keylen, void* value);

void* min_hashmap_get(struct min_hashmap* map,
	enum min_type type, void* key, int keylen);

#endif /* __MINHASH_H */
