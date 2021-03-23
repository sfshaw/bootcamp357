# Module 2: Hello, World

In this module we will get bogged down in BS while completing the classic introductory program. The purpose of this module is not to teach the program, but to expand on all the other pieces inside and outside of it. We'll zoom through the first iteration of the program, touching on what we learned in module 1 about Makefiles, compilers, and executables.

## Hello, World

`main.c`

    #include <stdio.h>

    int main(int argc, char* argv[]) {
        printf("Hello, World!\n");
        return 0;
    }

`Makefile`

    .PHONY: run
    run: main
        ./main

    main: main.c
        gcc -o $@ $^

Let's run it all!

    $ make
    gcc -o main main.c
    ./main
    Hello, World!
    $

Hopefully nothing surprising here. If it worked on the first try, you've won a pony. I lied. Theres no pony, just more code. 

<!-- TODO: Add explanation -->

## Do it again, but over-engineered

`main.c`

    #include "hello.h"

    int main(int argc, char* argv[]) {
        hello();
        return 0;
    }

`hello.h`

    #ifndef __HELLO_H__
    #define __HELLO_H__

    #define HELLO_WORLD_STR ""

    void hello(void);

    #endif

`hello.c`

    #include "hello.h"
    #include <stdio.h>

    static char hello_world_str[] = "Hello, World!\n";

    void hello(void) {
        printf("%s", hello_world_str);
    }

`Makefile`

    HDRS=hello.h
    OBJS=main.o hello.o

    .PHONY: run
    run: main
        ./main

    main: $(OBJS)
        gcc -o $@ $^

    %.o: %.c $(HDRS)
        gcc -c $< -o $@

I swear I ran this an it worked.

    $ make
    gcc -c main.c -o main.o
    gcc -c hello.c -o hello.o
    gcc -o main main.o hello.o
    ./main
    Hello, World!

There's a lot more going on in this second program so lets read it line by line (This is absolutely a legitamate strategy for finding bugs, you'd be surprised).

<!-- TODO: Add explanation -->
