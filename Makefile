build $(n).c:
	gcc $(n).c -g -std=c11 -pedantic -lm -fno-builtin -Wall -o $(n)

