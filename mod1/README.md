# Module 1: Environment Setup (Make, compilers, and executables)

In this first module we will cover setting up the development environment.

## Environment

The main focus of CPE 357 is programming in the Unix environment. Unix is the ancient spiritual predecessor to Linux. Today, we call Linux and BSD-like (of which MacOS can be considered) operating systems "Unix-like". Some of the likeness is due to shared design choices and the rest is "POSIX" compliance. POSIX is an old operating system standard that many OS's follow to varying degrees. When looking at manual pages, you might see a section like:

```man
CONFORMING TO
    POSIX.1-2001, POSIX.1-2008, C89, C99.
```

indicating that the thing you're looking at is compliant with some POSIX standards (as well as some C standards in this case)

Further reading: [Google "POSIX"](https://www.google.com/search?q=POSIX)

### OS

Since CPE 357 is all about Unix, you should do all of your work on a Unix-like operating system. More specifically, all of your work will be graded on the CS department's Unix servers. Even if you do all your development in your own Ubuntu or MacOS environment, your program might fall on its face when run on the Unix servers (every computer is different!). The Unix servers are probably also using an out of date compiler compared to your local machine. I do think there is value in developing local and then testing your code on the servers. Your local machine might perform more consistently that the servers that are simultaneously being used by hundreds of students. Connectivity issues are also a problem. The latency, even in `ssh` and `vim`, can be infuriating. We'll discuss choices of IDEs in a following section. Suffice it to say, you must always ensure your program runs on the Unix servers where it will be graded.

### Terminal

The terminal is text based interface is used to interact with a computer. A program called a "shell" is used to make this easier. When using a terminal, it is generally assumed that someone is using a shell program such as `bash`(Very common), `ash`(let's pretend the A is for ancient), `zsh`(often the MacOS default), etc.. If I want to access another computer, such as a Unix server on campus, I can use a program called `ssh` to open a remote terminal/shell on that machine.

<!-- TODO: Move this link to the main README.md because its a better version of this entire course -->

MIT offers [a resource](https://missing.csail.mit.edu/) for learning all about this, courtesy of Rick.

### IDE

You've probably been using PyCharm and IntelliJ as your integrated development environment (IDE) for 202 and 203. Your professor might encourage you to use Vim, a terminal based editor, for 357.

#### Vim

Vim is "Vi Improved". Vi is another older text editor. If someone is writing about both, they might write "Vi(m)". Vim is entirely useful to learn. At the bare minimum you should learn how to:

1. Open a file with Vim
2. Edit a file in Vim
3. Save and exit Vim

To open a file in Vim:

```shell
    $ vim my_file.c
    ...
```

Vim will open in "a mode that is not insert mode", meaning we can move around a bit but it is really expecting "commands" in its prompt. Pressing "i" will put it into "insert-mode" so we can actually move around with the arrow keys and type to insert characters. To get out of insert-mode, hit the escape key. Now you should be back in "probably command mode". To **quit Vim**, type a colon followed by q for quit. Vim might warn you that you will lose your changes. To save your files, use the ":w" command. Save and quit can be chained together as ":wq". If you don't want to save your changes, you can add an exclamation mark to q to force it, ":q!" I hope you can tell that I don't use Vim often. Knowing how to escape Vim is really just a foundational skill. This has been a terrible explanation of Vim; you should now go look up some Vim tutorials.

[Here is a cheat sheet on Vi(m) keybindings](https://vim.rtorr.com/)

If you otherwise prefer a GUI IDE (because you weren't born in the 80's), these specific tasks are mostly just useful in a pinch. I love using VSCode but I can still use Vim to edit files inside a terminal. Vim can be configured in all kinds of ways with lots of settings and plugins. To change Vim settings, the vim settings file located at ~/.vimrc is where the settings are sourced from. If it does not exist already, just create it with Vim! Here are some of my favorite Vim settings:

```vim
set mouse=a " enables mouse usage
set number " turns line numbers on
set autoindent " autoindents
set expandtab " expands tabs you put in into spaces
set tabstop=4 " sets the character width of a tab character
set shiftwidth=4 " sets the autoindent amounts
```

#### Microsoft's Visual Studio Code

It's what's hot right now. Its not clunky like Visual Studio or IntelliJ. It is an electron based application, so it is literally another instance of Chrome running (Electron simultaneous exemplifies everything wrong with web technologies and peak performance of web technologies). It's portability is great. VSCode has plugins for everything under the sun. [Microsoft's C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) is super good enough. In addition to that, you will need the [Remote - WSL extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl) in order to develop in Linux while on Windows (If you are afflicted by such malware).

I would recommend setting VSCode to autosave files very quickly, such as after 500 ms or on loss/change of focus.

### Git

_Git_ is a "version control system" (VCS) used throughout the software industry for tracking changes to code by teams of software engineers. Git was originally developed by Linus Torvalds, the creator of the Linux kernel. Git allows people in separate locations to make independent changes to code and then merge them into one version. It effectively achieves the collaboration of Google Docs (but not in real time) for source code. It has innumerable other features that make it indispensable to software engineers. _GitHub_ is a company that provides instances of Git as a free and commercial service. It is very common to use GitHub at Cal Poly as many premium features are provided to teachers and students for free. Other companies provide services similar to GitHub, including _GitLab_ and _Atlassian's Bitbucket_. The interfaces provided by each company are different but under the hood, each is still Git or at least an API compatible with Git.

Learning to use Git effectively is one of the most important skills you can take away from your education Cal Poly. Becoming comfortable in Git will be invaluable to you at Cal Poly and beyond. You will likely be using it on day one at any software engineering job or internship.

Git was originally developed to be used entirely from the command line. This is the canonical interface. It is extremely daunting at first and probably doesn’t make sense if you aren’t already comfortable with the terminal. The reality of the terminal is that the only reason it is hard for beginners is because it forces you to formally learn to use it through the command line. This differs from a graphical user interface (GUI) where many of us have developed an intuition to poke around and quickly discover features.

You should endeavor to use Git for everything that you code. In our simple use case here, GitHub will mostly just be acting as a backup of our code. Just like professors will encourage you to use Vim, they might encourage you to use the command line interface of Git. This can be great for you but I don't think its strictly necessary for the desired learning outcomes. For this boot camp you should make use of Git either through the terminal or through a GUI client such as GitHub Desktop, VSCode, IntelliJ/CLion, etc..

This document is already inside Git _repository_ that I initialized with the command below. Git uses a directory, `.git` to store information about a repository.

To make a directory a Git repository:

```shell
    $ git init
    Initialized empty Git repository in /home/sfshaw/git/bootcamp357/.git/
```

#### Links to Git Resources

Since the commands never got added, here is a link to a presentation to get you started (or at least enough to be armed and dangerous):

- Meta-link: [https://cplug.org/2020-getting-good-at-git/](https://cplug.org/2020-getting-good-at-git/)
- Perma-links:

  - Part 1 (Presentation): [https://youtu.be/H18s69KdGGg](https://youtu.be/H18s69KdGGg)
  - Part 2 (Demo): [https://youtu.be/T4Xd3k1G5oU](https://youtu.be/T4Xd3k1G5oU)

- Links referenced the video:

  - [https://git-scm.com/book](https://git-scm.com/book)
  - [https://try.github.io/](https://try.github.io/)
  - [https://guides.github.com/](https://guides.github.com/)
  - [https://git-school.github.io/visualizing-git/](https://git-school.github.io/visualizing-git/)

#### Git Workflow Graph

In general, your workflow will look something like this (if you don't need to do complex commit managing/rolling back work).
There are definitely better graphs out there with more complex git flows, this is one is pretty simple.

```graph
    +----------------+                                                  +--------------------------------------+
    | on branch main | ----- `git checkout -b new_project_branch` ----> | on branch new_project_branch (clean) |
    +----------------+                                                  +--------------------------------------+
                                                                            |                      /|\
                            +--- `git checkout main` <--- (yes) ----- done with project?            |
                            |                                               |                       |
                            V                                               |                       |
    +---------------------------------------------------+               (not yet)                   |
    | on branch main                                    |                   |                       |
    |   (does not have changes from new_project_branch) |                   |                       |
    +---------------------------------------------------+              do some work                 |
            |                                                         run some tests                |
    `git merge [--no-ff] new_project_branch`                     get your code to a good state      |
        (pulls in changes on new_project_branch)                            |                       |
            |                                                               |                       |
            V                                           +--------------------------------------+    |
    +-----------------------------------------+         | on branch new_project_branch (dirty) |    |
    | on branch main                          |         +--------------------------------------+    |
    |   (has changes from new_project_branch) |                             |                       |
    +-----------------------------------------+                 `git add <changed file(s)>`         |
                                                                            |                       |
                                                                            V                       |
                                                                +-------------------------+         |
                                                                | changes ready to commit |         |
                                                                +-------------------------+         |
                                                                            |                       |
                                                            `git commit [-m "commit message"]`      |
                                                                            |                       |
                                                                            +-----------------------+
```

How to read the graph:

- Each "box" contains a "state" (what status your git repository is in (view this with `git status`)
- `dirty` refers to a state where there are "untracked changes" (i.e., you have made changes that Git has not yet written into its history)
- `clean` refers to a state where there are no untracked changes
- The `git` commands to move between states are in backticks (for example, `` `git help` ``)
- Anything inside square brackets (`[ ]`) means it is an optional command line argument
- Anything inside angled brackets (`< >`) means it is a **mandatory** command line argument

## Make and Makefiles

Make is an awesome tool for scripting. It is basically the solution to repeatedly pressing the up arrow to find a command you need to run again. Just put a shell command under a "recipe" inside your `Makefile`. (Note that the following examples use spaces instead of tabs. I'm doing this for this document. Make will shit itself if you give it spaces -- it was written to expect tabs.)

```Makefile
    faster:
        omg --this shell_command.is | so -long

Then you can run it like this:

    $ make faster
    omg --this shell_command.is | so -long

Or if you're lazy and bad at typing like me:

    .PHONY: faster
    f: faster
    faster:
        omg --this shell_command.is | so -long
```

I have `m` aliased to `make` in my shell (search for "[bash aliases](https://www.google.com/search?q=bash+aliases)"), I just run:

```shell
    $ m f
    omg --this shell_command.is | so -long
```

Save your arrow keys for... actually they aren't that useful.

The `.PHONY: faster` tells make that the target, `faster` is not a file that it should look for. This gets us to the actual magic of Make:

Make expects recipe targets to be files and if it sees that a file is already "up-to-date", it does not run the recipe. Let's 'make' use of this. >:) I now present, a useful Makefile.

```Makefile
    OBJS=main.o other_stuff.o

    main: $(OBJS)
        gcc $^ -o $@

    %.o: %.c
        gcc -c $< -o $@
```

You: "woah woah woah wtf is all this. I don't want to learn another programming language."
Just be glad I'm not teaching you CMake. \*gags\* Everything here is simple enough that I can explain it without full understanding it. Lets go one piece at a time:

- First a variable assignment: `OBJS=main.o other_stuff.o`
  - `OBJS`: a variable name
  - `=`: an assignment (There are a bunch of types of assignment and Make is weird)
  - `main.o other_stuff.o`: the names of the two object files that will be intermediate file that we build. More on these in the compilers section.
- Next a recipe: `main: $(OBJS)`
  - `main`: The target of the recipe, the name of our desired executable
  - `: $(OBJS)`: Everything after the ":" on the first line of a recipe is a "dependency", generally the list of files that the target depends on.
    - `$( )`: Access a variable
    - `OBJS`: The name of the variable we defined earlier
  - A shell command the recipe wants to execute: `gcc $^ -o $@`
    - `gcc`: Calling our compiler and linker.
    - `$^`: Using a variable built into the recipe, this one meaning "all of the dependencies"
    - `-o`: Where and what should gcc output.
    - `$@`: Another variable built into recipes, this one meaning "the target"
- And finally another recipe: `%.o: %.c`
  - `%.o`: The recipe target, pattern matching anything that ends in ".o"
  - `: %.c`: The dependency for the recipe, picking the matching ".c" file
  - Executing the command: `gcc -c $< -o $@`
    - `gcc`: Invoking the compiler
    - `-c`: The flag telling GCC: "Only compile and assemble these inputs into objects, not executables" (see `gcc --help`)
    - `$<`: Built in variable meaning "the first dependency"
    - `-o`: Flag telling the compiler to output the following output
    - `$@`: Builtin variable referencing the target of the recipe

So what actually gets run? If we just run `make` without specifying a recipe to target, the first one in the Makefile will be run. In this case, the default recipe is `main`. But that recipe depends on two other files, `main.o` and `other_stuff.o`, which can both be made with the other recipe. Make will do it all for us:

```shell
    $ make
    gcc -c main.c -o main.o
    gcc -c other_stuff.c -o other_stuff.o
    gcc main.o other_stuff.o -o main
```

Why we wanted to do this will hopefully become more evident in the next section on the compiler itself. Essentially, Make gives us a bunch more automation surrounding the compiler.

## Compilers

The last section of Makefiles talked actually working with the compiler. This section will expand on that and be a bit more general. let the hand waving commence:

Compilers take in source code and output executables. Boom, we're done here. jk. Our weapons of choice are the GNU Compiler Collection (GCC) and CLang (A C frontend for the LLVM compiler framework). They both break the problem of translating source code to an executable into much smaller pieces of work. Roughly:

1. Translate the code into something that is easier for the compiler to work with (maybe an "AST" or intermediate representation)
2. Do some transforms and optimizations of the code to make it less shitty. (I want to talk about compiler and optimization flags at least two more times)
3. Assemble the "stuff" into assembly "machine" code
4. Link all the pieces of machine code into an executable

### 1. Reading in source code

This is the part where the compiler screams at you for missing a semicolon (I hope your IDE caught that first). Exactly what things is complains about will depend on the C standard it is using (Remember those ISO nerds?). You can specify the standard with the flag: `-std=...`. Your professor might make you use something ancient like `-std=c89`. `-std=gnu11` is pretty dank. There are a few other flags for this such as `-ansi`, which is ancient scripture.

I would highly recommend using additional warning flags. It might seem counter intuitive to purposefully ask the compiler to give you more errors, but it can really help point out when you've screwed up. Here's my personal stash (straight from a `Makefile`), you should look up what they do:

`WARNINGS=-pedantic -Wall -Wextra -Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Werror=format-security`

### 2. Transforms and Optimizations

The compiler does all kinds of fancy things to make the trash code that you gave it better. You can specify how hard you want it to try with optimization flags (in order of increase try-hard):

- `-O0`: Try zero, no optimizations
- `-Os`: Try for size, optimize the code to be as small as possible
- `-O1`: level 1, some optimizations, nothing crazy
- `-Og`: debug optimizations, you want some optimizations, but you need the compiler to not screw up the embedded debug info that is put in the output for the `-g` flag. Explained further in [Module 5](../mod5/README.md)
- `-O2`: level 2, most optimizations, potentially crazy optimizations
- `-O3`: level 3: sweaty try-hard, all optimizations, quite possibly crazy

For introductory programs, these don't matter at all. You'll want them later for the SPEED. Or if you've written such bad code that the compiler only notices your screw up in super try-hard `-O3` mode.

### 3. Assembling

Remember all the assembly code you wrote in 233 or 225? Well, computers do that for us now and they do it faster than you could and they screw up less. It looks like you're out of a job as an assembly programmer (probably not, humans still do that sometimes).

Sometimes the assembly output is a `.s` file, otherwise its a `.o` object. If you'd like to see your assembly code, use the flag `-S` in your compilation step.

### 4. Linking (Its actually called that)

This is what we did in one of the Makefiles. We specified some `.o`'s and asked for an executable binary. The executable is almost certainly of the format ELF, starting with a small header of meta data and configuration and stuff.

### Tidbits and takeaways

- You can switch between multiple compilers get better warning coverage (sometimes one compiler will catch something the other didn't)
- You can switch between multiple optimization flags to get better warning coverage (the reason for this is that many optimizations rely on ignoring "Undefined behavior" aka your bug)
- If you want to feel like a real badass you can clone the source code of the Tiny C Compiler (tcc) and compile the compiler yourself. Its pretty easy if you can find and follow the instructions.
- Learn more in CSC 430!

## Executables

File extensions, such as `file.whatever`, `meme.png`, or `malware.exe`, are kind of made up bullshit (Thanks Bill). "Real" files tell you what they are by a header, the first few bytes of data inside the file. In the case of the executable files we build for 357, the file type is what is known as ELF (Executable and Linkable Format). The file extension is unnecessary. Sometimes you will see a .elf file in contexts where more fancy linking is happening such as for an embedded target.

<!-- Needed here: chmod +x -->
Not all files have the same permissions in the Unix ecosystem, and thus we need to be able to differentiate between the different types. As you begin 357, you'll start writing scripts and other executable files. These require the use of the command `chmod +x <filename>` to be executed. GCC and Clang's output executables already set the output flags on those files, and thus can be executed right out of the compilation process.

## handin

handin is a stupid simple program that runs on the UNIX servers. It is probably how you will submit files for class. I hate it very much and don't want to talk about it. I'm pretty sure I've already written multiple rants about it. Professors should have students submit code through Git instead. 'nuff said.

- handin is written and used in the UNIX utility style
- You can't take anything back once it is submitted

  1. You submit a file to the professor/grader
  2. You delete that file in your directory
  3. That file still exists in the professor/grader's directory
  4. That file could prevent your final submission from building or running correctly (Boom you have a zero for that assignment).
  5. You would have to ask the professor/grader to delete the file on their end.

- That being said, you can "delete" the file by performing the following steps (in this example, suppose the file I want to delete is called `deleteMe.c`):

  1. Delete the file in your working directory (`rm -iv deleteMe.c`)
  2. Make a file of zero length (an empty file) using the command (`touch deleteMe.c`)
  3. Hand in the zero-length file (`handin toUser asgnName deleteMe.c`)
  4. Now, the file is as deleted as you can make it (it should no longer affect compilation)

## Pop Quiz

Go look at your browser history. Did you do more research on all of these topics? If so, you passed the pop quiz. You've just won an inflated ego, well done!

## Conclusion

Phew, that was a lot of stuff before we even get to write any C... maybe next time in [module 2](../mod2/README.md)
