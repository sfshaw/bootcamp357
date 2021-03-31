# Module 4: The Memory Model

C's memory model is a key difficulty for learners coming from garbage collected languages including Python and Java.

The Application Binary Interface (ABI) specifies the bare runtime for native programs, including how other functions can be called and how registers are treated during calls. Based on the ABI, the agreed upon standard for memory available to a program is two areas: the stack and the heap. They are managed in different ways.

## The Stack

The stack is the default location for storing things in memory. It may be somewhat limited in size. The stack is a "stack": push and pop operations add and remove elements from it. The elements are called frames and they contain local variables and function call overhead. That stack frame contains all of the variables from the scope of that function, whether it's the `main` function or any other. As a result, the stack grows with the oldest variables at the "bottom" (The actual direction it grows is compiler/ABI detail that shouldn't matter to us). When a function returns, all the space it used is freed and the stack shrinks. Local variables from inside the function call are now gone. The top of the stack is again the caller and all of its locals are still there. In summary, local variables are stored on the stack, the current frame of which corresponds to the current function scope.

## A Problem

What if we want to create an object (or an array of objects), taking up a bunch of memory, in a function and then use it in the caller? We can return it from the function, but that requires the size of the object to be known to the compiler, probably due to the ABI.

Strat #2 them: make space for our object farther down the stack and tell the function where to put the object. This would be passing a pointer to a local variable as an argument in a function call. Then the function has a place to put the object and we have the object after the function is done. But what if we don't know how much space we will need prior to calling the function that creates the object. We don't want to over allocate space on the stack and then waste it. This is where the heap comes in.

## The Heap

The heap is essentially global memory space that can be allocated. It is independent of function calls and such control flow. While local variables are automatically put on the stack, we must explicitly ask for space on the heap. It is not guaranteed to be organized in any particular way. It's only structure is the individual blocks of memory that you can request from it. This is the part where you expect a fancy diagram from me. Instead, you'll have to do your own research. Go ahead, practice.

In GC'ed languages, many objects are stored on the heap and identified by reference (in C, a pointer). But when is that memory no longer in use? When can it be recycled and reused? In a GC'ed language, the runtime might pause your program to see if an object is not longer needed and then free it. Then something else can use that memory. If we want to use the heap in C, we request some size of memory. When we are done with it, we must release the same block of memory. The exact same one. C has no idea that your heap-allocated variable is no longer in scope. Maybe the pointer to that memory is gone (as in you didn't return the created object). That memory is still taken up and your program can never get it back. Technically, when your program ends the OS should take the memory back but that only works for trivial programs. It can't scale to larger programs or programs that run for a long time, aka useful programs. If over time a program uses a little bit more memory and never uses less memory, eventually the computer will run out of memory and crash. How many of you have left Chrome open for a week or more. Google has invested billions on dollars in making sure that you can do that and Chrome doesn't just poop itself after four days. Since correct memory management at Chromes scale has been proven legitimately difficult, you're going to have to actually try to do it right, meaning properly releasing memory you use.

In Python and Java, references are transparent. All objects in Python are references and the only annotation telling us in Java is the `new` keyword. In C, objects are either a chunk of memory on the stack (or heap), or a pointer to a piece of memory on the stack (or heap).

In Python and Java reference objects were allocated and deallocated automatically. This is not the case in C. C requires diligence and discipline to use correctly. There are many mistakes that can be made very easily. We will discuss them in the last module, [module 5](../mod5/README.md)
