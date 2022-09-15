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
#include <minhash.h>

int main(void) {
    struct min_hashmap* map = min_hashmap_new(16);
    
    /* use the hashmap... */
    
    min_hashmap_delete(map);

    return 0;
}
```
