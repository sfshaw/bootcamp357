
HDRS=hello.h
OBJS=main.o hello.o

.PHONY: run
run: main
	./main

main: $(OBJS)
	gcc -o $@ $^

%.o: %.c $(HDRS)
	gcc -c $< -o $@