# Module 5: Firearm safety (Pointers, GDB, Valgrind, and Godbolt)

## Danger

The danger in C's memory model is formally known as memory (un)safety. It means you can do all kinds of sketchy things that can end in tears. Many of these sketchy things involve "undefined behavior", which is basically a place where the compiler got to do whatever weird stuff it wanted because ISO couldn't agree on what it should actually do.

A lot of times these memory unsafety errors can lead to security vulnerabilities. As reported in [a post](https://alexgaynor.net/2019/aug/12/introduction-to-memory-unsafety-for-vps-of-engineering/) by Alex Gaynor, ~60-70% of high severity security vulnerabilities are the result of memory unsafety across Apple, Google, and Microsoft. Some of these are zero days exploited to compromise the safety of dissidents, activists, and journalists. It kind of looks like its impossible to write _safe C at scale_ (nor can you say it five times fast).

So why are they making us use this? Its basically the same reason we were taught assembly. C can be considered high level assembly language.

## Pointers

Generally, memory unsafety in C involves the misuse of pointers. This actually includes array indexing as well because:

    p[i]

is the same as:

    i[p]

is the same as:

    *(p + i)

No one can actually tell if `p` has `i` elements. What is the 10th element of an array of length 5? It's "get pwned noob". :(

In the best case, though, is that if your program accesses an index that is out of bounds is that your program dies due to a SIGSEGV (kill SIGnal SEGmentation Violation). This is a **good** thing! You know that there is a bug somewhere (hopefully close by)!

_But why are SIGSEGVs good?_
They (usually) generate a core dump\*, which is the state of the program's memory at the time it was killed.
You can use them to help debug at which point the program failed (`gdb ./main pid.core` (note that `pid` will be replaced by some string that usually contains the process ID your program was running as))

Since C does not do array bounds checking, what would normally generate an "array index out-of-bounds" exception in, say, Java or Python may just result in your variable containing unexpected garbage (which may result in a "heisen-bug" (where your code may seem to "randomly" work), which is one of the worst types of bugs, second only to typos).

\* **_Note:_** On the UNIX servers, core dumps may not be generated. This is (likely) intentional to preserve disk space.

## GDB

GDB is an indispensable tool. It is the premier debugger for C.

`main.c`

```c
int main() {
    int i = 1;
    i -= ;
    return i;
}
```

Shell

    $ gcc -g -o main main.c
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

- `b main`: (short for `break main`)s et a break point at the main function
- `r` (short for `run`) run the program
- `s` (short for `step`) step
- `print i` print out the value of i
- `q` quit

VSCode can also wrap GDB nicely for ease of use.

## Valgrind

Valgrind is a tool for checking whether a program does any sketchy memory operations.
Professors usually introduce Valgrind as a tool for debugging for memory leaks, however.
If you're having trouble figuring out what's wrong with your program, run Valgrind. If your program works fine, you should still run Valgrind. It runs like GDB but without interactivity. Valgrind intercepts many things that your program might do, such as allocate or deallocate memory. It can tell you when you screwed up.

    valgrind ./main --leak-check=full --track-origins=yes --show-leak-kinds=all

## Godbolt Compiler Explorer

[The Godbolt Compiler Explorer](https://godbolt.org/) gives you a variety of compilers and their output very quickly. You give it a snippet of (in any number of languages) and chose one or more compilers and it shows you the assembly output. Its great for comparing different optimization flags or tiny changes to code. Try it out!

## Conclusion

Ya done now. Head over to the [conclusion](../conclusion/README.md) for some emotional closure.
