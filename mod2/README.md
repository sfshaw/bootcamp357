# Module 2: Hello, World

In this module we will get bogged down in BS while completing the classic introductory program. The purpose of this module is not to teach the program, but to expand on all the other pieces inside and outside of it. We'll zoom through the first iteration of the program, touching on what we learned in module 1 about Makefiles, compilers, and executables.

## Hello, World

`main.c`

```c
#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("Hello, World!\n");
    return 0;
}
```

`Makefile`

```makefile
.PHONY: run
run: main
    ./main

main: main.c
    gcc -o $@ $^
```

Let's run it all!

    $ make
    gcc -o main main.c
    ./main
    Hello, World!
    $

Hopefully nothing surprising here. If it worked on the first try, you've won a pony. I lied. There's no pony, just more code. The `#define` will be covered in module 3. For now, we are just using it to "import" `printf()`. The only other thing that might be weird is the data type of `argv`. In Python, `sys.argv` is a `list` of `str`s. `argv` in C serves the same purpose. In this case, it is an array of character pointers, essentially a list of strings. I wonder where Python got the idea. Anyway, sometimes it might be possible to treat `argv` as a `char**`, depending on the C standard in use. You can also think about it as a `char[][]`. Strings and pointers will be covered in modules 3 and 5 respectively.

## Do it again, but over-engineered

Let's now expand that example out to cover a bunch more C topics. There's a lot more going on in this second program.

`main.c`

```c
#include "hello.h"

int main(int argc, char* argv[]) {
    hello();
    return 0;
}
```

Instead of the standard IO library, I am including my header and calling the `hello()` function from it.

`hello.h`

```c
#ifndef __HELLO_H__
#define __HELLO_H__

extern void hello(void);

#endif /* __HELLO_H__ */
```

This one looks a bit funkier. `#ifndef`, `#define`, and `#endif` are preprocessor directives. The Preprocessor will be covered in module 3. The specific use of preprocessor directives are a guard pattern that prevents multiple instances of `hello.h` from being compiled at once.

The function signature, declares the existence of the `hello()` function. The body of the function is not here (the `extern` keyword, while not strictly necessary, explicitly states this). It's like taking a selfie.

`hello.c`

```c
#include <stdio.h>
/* system libraries should come before user libraries */
#include "hello.h"

static const char hello_world_str[] = "Hello, World!\n";

void hello(void) {
    printf("%s", hello_world_str);
}
```

Now we get to define the body of `hello()`. We need `stdio.h`, as well as `hello.h`. Our string is `const` since it is a string literal (i.e., a hard-coded string). Our string is also declared `static` so it is only in this "translation unit" (file during compilation). Don't worry about that for now. We are now formatting the string when we print it. Guess where Python got its string formatting specifiers.

`Makefile`

```makefile
HDRS=hello.h
OBJS=main.o hello.o

.PHONY: run
run: main
    ./main

main: $(OBJS)
    gcc -o $@ $^

%.o: %.c $(HDRS)
    gcc -c $< -o $@
```

The `Makefile` is only a slight upgrade from module 1. The main change is that if our header changes, our other files that rely on it will be recompiled.

I swear I ran this and it worked.

    $ make
    gcc -c main.c -o main.o
    gcc -c hello.c -o hello.o
    gcc -o main main.o hello.o
    ./main
    Hello, World!

Boom. With this framework you can grow your C programs to be a bit larger without too much trouble.

In the [next module](../mod3/README.md) we'll discuses the preprocessor in more detail.
