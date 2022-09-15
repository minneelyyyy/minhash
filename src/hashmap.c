#include <minhash.h>
#include <stdlib.h>

struct min_hashmap* min_hashmap_new(int capacity) {
    struct min_hashmap* ptr = malloc(sizeof(struct min_hashmap));
    int i;

    ptr->capacity = capacity;
    ptr->items = malloc(sizeof(struct min_hashmap_bucket) * capacity);

    for (i = 0; i < capacity; i++) {
        min_hashmap_bucket_new(&ptr->items[i]);
    }

    return ptr;
}

void min_hashmap_delete(struct min_hashmap* ptr) {
    int i;

    for (i = 0; i < ptr->capacity; i++) {
        min_hashmap_bucket_delete(&ptr->items[i]);
    }

    free(ptr->items);
    free(ptr);
}

struct min_hashmap_bucket* min_hashmap_bucket_new(
        struct min_hashmap_bucket* prealloc) {
    struct min_hashmap_bucket* ptr = prealloc;

    if (ptr != NULL) {
        ptr->count = 0;
        ptr->heap = 0;
        ptr->items = min_hashmap_linked_new(16);
    } else {
        ptr = malloc(sizeof(struct min_hashmap_bucket));

        ptr->count = 0;
        ptr->heap = 1;
        ptr->items = min_hashmap_linked_new(16);
    }

    return ptr;
}

void min_hashmap_bucket_delete(struct min_hashmap_bucket* ptr) {
    min_hashmap_linked_delete(ptr->items);
    if (ptr->heap) free(ptr);
}

struct min_hashmap_linked* min_hashmap_linked_new(int count) {
    struct min_hashmap_linked* ptr;

    if (count < 1) return NULL;

    if (count == 1) {
        ptr = malloc(sizeof(struct min_hashmap_linked));
        ptr->item.hash = 0;
        ptr->item.type = UNKNOWN;
        ptr->item.value = NULL;

        ptr->next = NULL;

        return ptr;
    }

    ptr = malloc(sizeof(struct min_hashmap_linked));

    ptr->item.hash = 0;
    ptr->item.type = UNKNOWN;
    ptr->item.value = NULL;

    ptr->next = min_hashmap_linked_new(count - 1);

    return ptr;
}

void min_hashmap_linked_delete(struct min_hashmap_linked* ptr) {
    struct min_hashmap_linked* temp;

    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;

        free(temp);
    }
}

struct min_hashmap* min_hashmap_add(struct min_hashmap* map,
                                    enum min_type type, void* key,
                                    int keylen, void* value) {
    unsigned int key_hash = hash(key, keylen);
    unsigned int bucket = key_hash % map->capacity;
    
    struct min_hashmap_linked* item_location = map->items[bucket].items;

    while (item_location->item.type != UNKNOWN) {
        if (item_location == NULL) {
            item_location = min_hashmap_linked_new(16);
        }

        item_location = item_location->next;
    }

    item_location->item.hash = key_hash;
    item_location->item.type = type;
    item_location->item.value = value;

    return map;
}

void* min_hashmap_get(struct min_hashmap* map,
	                  enum min_type type, void* key, int keylen) {
    unsigned int key_hash = hash(key, keylen);
    unsigned int bucket = key_hash % map->capacity;

    struct min_hashmap_linked* item = map->items[bucket].items;

    (void) type;

    while (item->item.hash != key_hash) {
        if (item->next == NULL) {
            return NULL;
        }

        item = item->next;
    }

    return item->item.value;
}