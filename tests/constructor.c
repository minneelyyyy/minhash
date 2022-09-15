
#include <stdio.h>
#include <string.h>
#include <minhash.h>

int main(void) {
    int x;
    int y;
    char c;

    struct min_hashmap* map = min_hashmap_new(16);

    min_hashmap_add(map, HM_key_string("Hello"), HM_int(2022));
    min_hashmap_add(map, HM_key_float(5.5f), HM_char('a'));
    min_hashmap_add(map, HM_key_int(55), HM_int(56));

    x = (int) min_hashmap_get(map, HM_key_string("Hello"));
    y = (int) min_hashmap_get(map, HM_key_int(55));
    c = (char) min_hashmap_get(map, HM_key_float(5.5f));

    printf("%s = %d\n", "Hello", x);
    printf("%d = %d\n", 55, y);
    printf("%f = %c\n", 5.5f, c);

    min_hashmap_delete(map);

    return 0;
}

