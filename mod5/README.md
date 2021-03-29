# Module 5: Firearm safety (Pointers, GDB, Valgrind, and Godbolt)

## Danger

The danger in C's memory model is formally known as memory unsafety. It means you can do all kinds of sketchy things that can end in tears. Many of these sketchy things involve "undefined behavior", which is basicly a place where the compiler got to do whatever weird stuff it wanted because ISO couldn't agree on what it should actually do. 

Alot of times these memory unsafety errors can lead to security vuleranbilities. As reported in [a post](https://alexgaynor.net/2019/aug/12/introduction-to-memory-unsafety-for-vps-of-engineering/) by Alex Gaynor, ~60-70% of high severity security vulerabilities are the result of memory unsafety across Apple, Google, and Microsoft. Some of these are zero days exploited to compromise the safety of dissidents, activists, and journalists. It kind of looks like its impossible to write _safe C at scale_ (nor can you say it five times fast).

So why are they making us use this? Its basically the same reason we were taught assembly. C can be considered high level assembly language.

## Pointers

Generally, memeory unsafety in C involves the misuse of pointers. This actually includes array indexing as well because:

    p[i]

is the same as:

    *(p + i)

No one can actualy tell if `p` has `i` elements.

## GDB

GDB is an indespencible tool. It is the premier debugger for C.

`main.c`

    int main() {
        int i = 1;
        i -= ;
        return i;
    }

Shell

    gcc -g -o main main.c
    $ gdb ./main
    ...
    > b main
    > r
    > print i
    $1 = _
    > s
    > print i
    $1 = _
    
    ...

    > q

- `b main`: set a break point at the main function
- `r` run the program
- `s` step
- `print i` print out the value of i
- `q` quit

## Valgrind

Valgrind is a tool for checking whether a program does any sketchy memory operations.
If you're having trouble figuring out what's wrong with your program, run Valgrind. If your program works fine, you should still run Valgrind. It runs like GDB but without interactiveity. Valgrind intercepts many things that your program might do, such as allocate or deallocate memory. It can tell you when you screwed up.

    valgrind ./main --leak-check=full

## Godbolt Compiler Explorer

[The Godbolt Compiler Explorer](https://godbolt.org/) gives you a variety of compilers and their output very quickly. You give it a snippet of (in any number of languages) and chose one or more compilers and it shows you the assembly output. Its great for comparing differnt optimization flags or tiny changes to code. Try it out!

## Conclusion

Ya done now. Head over to the [conclusion](../conclusion/README.md) for some emotional closure.
