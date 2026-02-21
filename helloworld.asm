section .data
    msg db "This is a test", 0xa ; Our message with a newline character (0xa)
    msglen equ $ - msg          ; Length of the message

section .text
    global _start               ; Declare entry point for the linker

_start:
    ; sys_write system call
    mov rax, 1                  ; System call number for sys_write (1)
    mov rdi, 1                  ; File descriptor 1 for stdout
    mov rsi, msg                ; Address of the message to write
    mov rdx, msglen             ; Number of bytes to write
    syscall                     ; Call the kernel to perform the write

    ; sys_exit system call
    mov rax, 60                 ; System call number for sys_exit (60)
    mov rdi, 10                  ; Exit status code 0 (success)
    syscall                     ; Call the kernel to exit the program
