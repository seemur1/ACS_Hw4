# makefile for perimeter.asm
task: main.c rnd.c complex_number.c polar.c fraction.c number.c container.c cast.o
	gcc -g -o task main.c rnd.c complex_number.c polar.c fraction.c number.c container.c cast.o -no-pie -lm
cast.o: cast.asm
	nasm -f elf64 -g -F dwarf cast.asm -l cast.lst