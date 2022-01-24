all: main.c main.h header.h list/list.h
	gcc -g -Wall -o main main.c list/*.c
clean:
	@echo "cleanning project"
	-rm main
	@echo "clean completed"

.PHONY: clean
