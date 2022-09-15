# minhash

### This is a hashmap implemented for use in C.

# Installation

1. clone the repository `git clone https://github.com/minneelyyyy/minhash.git; cd minhash`
2. build for release `./release.sh`<br>
for debug, use `make all`
4. install `make install PREFIX=/path/to/install/to`

# Usage
To use this library, you must include `minhash.h`, then you can create a new hashmap with `min_hashmap_new()`.

Every key and value can have its own type, macros exist to create a key `HM_key_{type}`
and a value `HM_{type}`. This is a fully polymorphic map.

Some limitations exist because of this, you cannot store an entire structure or string in a key,
you can only store a pointer to one that already exists. Strings can be a key, since the hash-map
does not store the entire string, just the hash.

```c
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
```
