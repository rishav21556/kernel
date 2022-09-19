final:
	nasm -f elf64 -o new.o new.asm
	gcc -lc new.o -no-pie -o a.out
