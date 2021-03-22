# Module 1: Environment Setup (Make, compilers, and executables)

In this frist module we will cover setting up the development environment.

## Evironment

The main focus of CPE 357 is programming in the Unix environment. Unix is the ancient spiritual predecessor to Linux. Today, we call Linux and BSD-like (of which MacOS can be considered) operating systems "Unix-like". Some of the likeness is due to shared deisgn choices and the rest is "POSIX" compliance. POSIX is an old operating system standard that many OS's follow to varying degrees. When looking at manual pages, you might see a section like:

    CONFORMING TO
       POSIX.1-2001, POSIX.1-2008, C89, C99.
indicating that the thing you're looking at is compliant with some POSIX standards (as well as some C standards in this case)

Further reading: [Google "POSIX"](https://www.google.com/search?q=POSIX)

### OS

Since CPE 357 is all about Unix, you should do all of your work on a Unix-like operating system. More specifically, all of your work will be graded on the CS deparment's Unix servers. Even if you do all your development in your own Ubuntu or MacOS environment, your program might fall on its face when run on the Unix servers. The Unix servers are probably also using an out of date compiler compared to your local machine. I do think there is value in developing local and then testing your code on the servers. Your local machine might perform more consistently that the servers that are simultaneously being used by hundreds of students. Connectiveity issues are also a problem. The latency, even in `ssh` and `vim`, can be infurriating. We'll discuss choices of IDE's in a following section. Suffice it to say, you must always ensure your program runs on the Unix servers where it will be graded.

### Terminal

The terminal is text based interface is used to interact with a computer. A program called a "shell" is used to make this easier. When using a terminal, it is generally assumed that someone is using a shell program such as `bash`(Very common), `ash`(let's pretend the A is for ancient), `zsh`(often the MacOS default), etc.. If I want to access another computer, such as a Unix server on campus, I can use a program called `ssh` to open a remote terminal/shell on that machine.

MIT offers [a resource](https://missing.csail.mit.edu/) for learning all about this, courtesy of Rick.

### IDE

You've probably been using PyCharm and IntelliJ as your integrated development environment (IDE) for 202 and 203. Your professor might encourage you to use Vim, a terminal based editor, for 357.

#### Vim

Vim is entirely useful to learn. At the bear minimum you should learn how to:

1. Open a file with Vim
2. Edit a file in Vim
3. Save and exit Vim

To open a file in Vim:

    $ vim my_file.c

Vim will open in "a mode that is not insert mode", meaning we can move around a bit but it is really expecting "commands" in its prompt. Pressing "i" will put it into "insert-mode" so we can actually move around with the arrow keys and type to insert characters. To get out of insert-mode, hit the escape key. Now you should be back in "probably command mode". To __quit Vim__, type a colon followed by q for quit. Vim might warn you that you will lose your changes. To save your files, use the ":w" command. Save and quit can be chained together as ":wq". If you don't want to save your changes, you can add an exclaimation mark to q to force it, ":q!" I hope you can tell that I don't use Vim often. Knowing how to escape Vim is really just a foundational skill. This has been a terrible explanation of Vim; you should now go look up some Vim tutorials.

If you otherwise prefer a GUI IDE (because you weren't born in the 80's), these specific tasks are mostly just useful in a pinch. I love using VSCode but I can still use Vim to edit files inside a terminal. Vim can be configured in all kinds of ways with lots of settings and plugins.

#### Microsoft's Visual Studio Code

It's what's hot right now. Its not clunky like Visual Studio or IntelliJ. It is an electron based application, so it is literally another instance of Chrome running (Electron simultaneous exemplifies everything wrong with web technologies and peak performance of web technologies). It's portability is great. VSCode has plugins for everything under the sun. [Microsofts's C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) is super good enough. In addition to that, you will need the [Remote - WSL extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl) in order to develope in Linux while on Windows (If you are afflicted by such malware).

I would recommend setting VSCode to autosave files very quickly, such as after 500 ms or on loss/change of focus.

### Git

_Git_ is a "version control system" (VCS) used throughtout the software industry for tracking changes to code by teams of software engineers. Git was originally developed by Linus Torvalds, the creator of the Linux kernel. Git allows people in separate locations to make independant changes to code and then merge them into one version. It effectively achieves the collaboration of Google Docs (but not in real time) for source code. It has innumerable other features that make it indispensable to software engineers. _Github_ is a company that provides instances of Git as a free and commercial service. It is very common to use Github at Cal Poly as many premium features are provided to teachers and students for free. Other companies provide services similar to Github, including _Gitlab_ and _Atlassian's Bitbucket_. The interfaces provided by each company are different but under the hood, each is still Git or at least an API compatible with Git.

Learning to use Git effectively is one of the most important skills you can take away from your education Cal Poly. Becoming comfortable in Git will be invaluable to you at Cal Poly and beyond. You will likely be using it on day one at any software engineering job or internship.

Git was originally developed to be used entirely from the command line. This is the canonical interface. It is extremely daunting at first and probably doesn’t make sense if you aren’t already comfortable with the terminal. The reality of the terminal is that the only reason it is hard for beginners is because it forces you to formally learn to use it through the command line. This differs from a graphical user interface (GUI) where many of us have developed an intuition to poke around and quickly discover features.

You should endevour to use Git for everything that you code. In our simple use case here, GitHub will mostly just be acting as a backup of our code. Just like professors will encourage you to use Vim, they might encourage you to use the command line interface of Git. This can be great for you but I don't think its strictly neccessary for the desired learning outcomes. For this boot camp you should make use of Git either through the terminal or through a GUI client such as GitHub Desktop, VSCode, IntelliJ/CLion, etc..

This document is already inside Git _repository_ that I initialized with the command below. Git uses a directory, `.git` to store information about a repository.

To make a directory a Git repository:

    $ git init
    Initialized empty Git repository in /home/sfshaw/git/bootcamp357/.git/

I keep all of my repositories in the git directory, this one is a directory called `bootcamp357`. At the end of each module, I'll show the steps I took to 'commit' to the repository.

## Make and Makefiles

Make is an awesome tool for scripting. It is basically the solution to repeatedly pressing the up arrow to find a command you need to run again. Just put a shell command under a "recipe" inside your `Makefile`. (Note that the following examples use spaces instead of tabs. I'm doing this for this document. Usually Make will shit itself if you give it spaces. Theres probably a workaround out there.)

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

I have `m` aliased to `make` in my shell (search for "bash aliases"), I just run:

    $ m f
    omg --this shell_command.is | so -long

Save your arrow keys for... actually they aren't that useful.

The `.PHONY: faster` tells make that the target, `faster` is not a file that it should look for. This gets us to the actual magic of Make:

Make expects recipe targets to be files and if it sees that a file is already "up-to-date", it does not run the recipe. Let's 'make' use of this. >:) I now present, a useful Makefile.

    OBJS=main.o other_stuff.o 
    
    main: $(OBJS)
        gcc $^ -o $@

    %.o: %.c
        gcc -c $< -o $@

You: "woah woah woah wtf is all this. I don't want to learn another programming language."

Everything here is simple enough that I can explain it whithout full understanding it. Lets go one piece at a time:

- First a variable assignment:
  - `OBJS`
    - a variable name
  - `=`
    - an assignment (There are a bunch of types of assignment and Make is weird)
  - `main.o other_stuff.o`
    - the names of the two object files that will be intermediate file that we build. More on these in the compilers section.
- Next a recipe:
  - `main`
    - The target of the recipe, the name of our desired executable
  - `: $(OBJS)`
    - Everything after the ":" on the first line of a recipe is a "dependancy", generally the list of files that the target depends on.
      - `$( )`
        - Access a variable
      - `OBJS`
        - The name of the variable we defined earlier
  - `gcc`
    - Everything after the first line of a recipe is a just shell command. You can even tell Make that you want to use the Python shell. `gcc` is our compiler and linker.
  - `$^`
    - Using a variable built into the recipe, this one meaning "all of the dependnacies"
  - `-o`
    - Where and what should gcc output.
  - `$@`
    - Another variable built into recipes, this one meaning "the target"
- And finally another recipe
  - `%.o`
    - The recipe target, pattern matching anything that ends in ".o"
  - `: %.c`
    - The dependancy for the recipe, picking the matching ".c" file
  - `gcc`
    - Invoking the compiler
  - `-c`
    - The flag telling GCC: "Only compile and assemble these inputs into objects, not executables" (see `gcc --help`)
  - `$<`
    - Built in variable meaning "the first depenancy"
  - `-o`
    - Flag telling the compiler to output the following output
  - `$@`
    - Builtin variable referencing the target of the recipe

So what actually gets run? If we just run `make` without specificying a recipe to target, the first one in the Makefile will be run. In this case, the default recipe is `main`. But that recipe depends on two other files, `main.o` and `other_stuff.o`, which can both be made with the other recipe. Make will do it all for us:

    $ make
    gcc -c main.c -o main.o
    gcc -c other_stuff.c -o other_stuff.o
    gcc main.o other_stuff.o -o main

Why we wanted to do this will hopefully become more evident in the next section on the compiler itself. Suffice it to say, Make gives us a bunch more programability surrounding the compiler.

## Compilers

The last section of Makefiles talked actually working with the compiler. This section will expand on that and be a bit more general. let the hand waving commence:

Compilers take in source code and output executables. Boom, we're done here. jk. Our weapons of choice are the GNU Compoiler Collection (GCC) and CLang (A C frontend for the LLVM compiler framework). They both break the problem of translating source code to an executable into much smaller pieces of work. Roughly:

1. Translate the code into something that is easier for the compiler to work with (maybe an "AST" or intermediate representation)
2. Do some transforms and optimizations of the code to make it less shitty. (I want to talk about compiler and optimization flags at least two more times)
3. Assemble the "stuff" into assembly "machine" code
4. Link all the pieces of machine code into an executable

__WORK IN PROGRESS__

## Excutables

File extensions, such as `file.whatever`, `meme.png`, or `malware.exe`, are kind of made up bullshit (Thanks Bill). "Real" files tell you what they are by a header, the first few bytes of data inside the file. In the case of the executable files we build for 357, the file type is what is known as ELF (Executable and Linkable Format). The file extension is unecessary. Sometimes you will see a .elf file in contexts where more fancy linking is happening such as for an embedded target.

## handin

handin is a stupid simple program that runs on the unix servers. It is probably how you will submit files for class. I hate it very much and don't want to talk about it. I'm pretty sure I've already written multiple rants about it. Professors should have students submit code through Git instead. nuff said.

- handin is written and used in the unix utility style
- You can't take anything back once it is submitted
  1. You submit a file to the professor/grader
  2. You delete that file in your directory
  3. That file still exists in the professor/grader's directory
  4. That file could prevent your final submission from building or running correctly (Boom you have a zero for that assignemnt).
  5. You would have to ask the professor/grader to delete the file on their end.

## Conclusion

Phew, that was a lot of stuff before we even get to write any code... maybe next time in [module 2](../mod2/README.md)

