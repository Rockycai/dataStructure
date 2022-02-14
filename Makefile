all: main.c main.h header.h list/list.h LinkList/LinkList.h
	gcc -g -Wall -o main main.c list/*.c LinkList/*.c
clean:
	@echo "cleanning project"
	-rm main
	@echo "clean completed"

.PHONY: clean
