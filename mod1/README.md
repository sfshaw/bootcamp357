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

The terminal is text based interface is used to interact with a computer. A program called a "shell" is used to make this easier. When using a terminal, it is generally assumed that someone is using a shell program such as `bash`(Very common), `ash`(let's pretend the A is for ancient), `zsh`(often the MacOS default), etc.. If I want to access another computer, such as a Unix server on campus, I can use a program called `ssh` to open a remote terminal/shell on that machine

### IDE

You've probably been using PyCharm and IntelliJ as your integrated development environment (IDE) for 202 and 203. Your professor might encourage you to use Vim, a terminal based

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

## Compilers

## Excutables

File extensions, such as `file.whatever`, `meme.png`, or `malware.exe`, are kind of made up bullshit (Thanks Bill). "Real" files tell you what they are by a header, the first few bytes of data inside the file. In the case of the executable files we build for 357, the file type is what is known as ELF (Executable and Linkable Format). The file extension is unecessary. Sometimes you will see a .elf file in contexts where more fancy linking is happening such as for an embedded target.

## Conclusion

Phew, that was a lot of stuff before we even get to write any code... maybe next time in [module 2](../mod2/README.md)

