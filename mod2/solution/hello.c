#include <stdio.h>
/* system libraries should come before user libraries */
#include "hello.h"

static const char hello_world_str[] = "Hello, World!\n";

void hello(void) { printf("%s", hello_world_str); }
