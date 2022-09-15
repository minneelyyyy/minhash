#include <minhash.h>

int main() {
    struct min_hashmap* map = min_hashmap_new(16);
    min_hashmap_delete(map);
}
