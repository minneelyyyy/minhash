# minhash

### This is a hashmap implemented for use in C.

# Installation

1. clone the repository `git clone https://github.com/minneelyyyy/minhash.git; cd minhash`
2. build for release `./release.sh`<br>
for debug, use `make all`
4. install `make install PREFIX=/path/to/install/to`

# Usage
To use this library, you must include `minhash.h`, then you can create a new hashmap with `min_hashmap_new()`.

```c
#include <stdio.h>
#include <string.h>
#include <minhash.h>

int main(void) {
    int x;

    struct min_hashmap* map = min_hashmap_new(16);

    min_hashmap_add(map, HM_key_string("Hello"), HM_int(2022));

    x = (int) min_hashmap_get(map, HM_key_string("Hello"));

    printf("%s = %d\n", "Hello", x);

    min_hashmap_delete(map);

    return 0;
}
```
