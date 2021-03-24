#include "hello.h"
#include <stdio.h>

static char hello_world_str[] = "Hello, World!\n";

void hello(void) {
    printf("%s", hello_world_str);
}