cc = gcc

main : main.c
	$(cc) -o exec main.c -Wall -std=c99 -pedantic
