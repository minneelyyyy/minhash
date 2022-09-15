#include <stdio.h>
#include <string.h>
#include <minhash.h>

int main() {
    int x;

    struct min_hashmap* map = min_hashmap_new(16);

    min_hashmap_add(map, HM_key_string("Hello"), HM_int(2022));

    x = (int) min_hashmap_get(map, HM_key_string("Hello"));

    printf("%s = %d\n", "Hello", x);

    min_hashmap_delete(map);

    return 0;
}
