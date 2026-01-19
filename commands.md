list docker processes: docker ps -a
start linux emulation: docker start -ai <container-id-or-name>

assemble asm into object file:
nasm -f elf64 -o main.o main.asm

link to executable
ld test.o -o test
