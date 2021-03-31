# Module 3: The Preprocessor

Red alert: The compiler actually runs another sort-of compiler prior to compiling C source code. This "pre-compiler" is called the preprocessor. It is a very low level form of "meta-programming", programming something to write code. If you recall from module 2, we intermixed preprocessor directives write inside our `.h` and `.c` C files. Most of the preprocessor's operations are pretty much copy and pasting. Lets go over what we used there but in more detail.

## Observability

When you run the compiler, you hope to get the outputted executable or linkable object. In this case, you will never see the immediate result of the preprocessor. We can just have the compiler output the result of the preprocessor with the `-E` flag.

`main.c`

```c
#define HELLOOOO main

int HELLOOOO() {
    return 0;
}
```

Gives us:

    $ gcc main.c -E
    # 1 "main.c"
    # 1 "<built-in>"
    # 1 "<command-line>"
    # 31 "<command-line>"
    # 1 "/usr/include/stdc-predef.h" 1 3 4
    # 32 "<command-line>" 2
    # 1 "main.c"


    int main() {
        return 0;
    }

IDK what all that info is at the start, but you can see that the preprocessor replaced `HELLOOOO` with `main`.

## \#include

`#include` is most common use of the preprocessor. It acts as C's import statement. But C doesn't have namespaces, packages, or modules like other languages. All it has are header files, and "translation units" (source files). Header files provide function signatures to translation units. The function implementations referenced by header files are combined across translation units at link time (at the end of compilation). Module 2's second program was a good example of this.

`main.c`

```c
#include "hello.h"

int main(int argc, char* argv[]) {
    hello();
    return 0;
}
```

`hello.h`

```c
#ifndef __HELLO_H__
#define __HELLO_H__

extern void hello(void);

#endif /* __HELLO_H__ */
```

`hello.c`

```c
#include "hello.h"
#include <stdio.h>

static const char hello_world_str[] = "Hello, World!\n";

void hello(void) {
    printf("%s", hello_world_str);
}
```

`Makefile`

```makefile
OBJS=main.o hello.o

.PHONY: run
run: main
    ./main

main: $(OBJS)
    gcc -o $@ $^

%.o: %.c hello.h
    gcc -c $< -o $@
```

## `#define`

`#define` defines a value for the preprocessor.

```c
#define MY_CONSTANT value

int variable = MY_CONSTANT;
```

The first example showed `#define`s are just copy and paste, so you can paste in function names. That's kind of a whack usage though. Please don't do that. Using it for values is much more reasonable. I don't expect that you will actually need them for much of your own purposes yet.

There is another usage of `#define`, with no value. This is how our header file guards work:

`my_header.h`

```c
#ifndef __MY_HEADER_H__
#define __MY_HEADER_H__

/* Good stuff */

#endif /* __MY_HEADER_H__ */
```

## `#ifndef`

`#ifndef` is a shortcut for an if statement, checking to see if `__MY_HEADER_H__` is not defined. `#if defined()` also exists, and there many more out there. If the identifier is already defined, Body of the if statement, in this case the entire contents of the header, are removed and never make it to the compiler.

The reason this guard pattern is advantageous is that we can then `#include` our header file all over the place and not worry about it being duplicated. For example:

- `a.h` includes `b.h` and `c.h`,
- `b.h` includes `c.h`
- `c.h` has something useful in it such as a `#define` that we want later
- `a.c` includes `a.h` and `b.h`, and uses the `#define` from `c.h`

In this situation, we only want one definition of everything from `c.h` inside `a.c`.

The good news is there is not pop quiz for this module. The bad news is there is homework. Your assignment is to replicate the above situation with actual files and implement the preprocessor guard pattern to produce preprocessed compiler output (using `gcc -E` as explained above) where the contents of `c.h` only end up in `a.c` once.

Try to get this to work on the UNIX servers. I'll see you in [module 4](../intermission/README.md).

JK, you need a break. The intermission is next.
