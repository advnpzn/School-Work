# x86 Assembly program to find minimum among given numbers in a contiguous memory.

    .section .data

data_items:
    .long 44, 11, 56, 74, 2, 86, 32, 0


    .section .text


    .global _start

_start:

    movl $0, %edi
    movl data_items(, %edi, 4), %eax
    movl %eax, %ebx

start_loop:

    cmpl $0, %eax
    je exit_loop
    incl %edi
    movl data_items(, %edi, 4), %eax
    cmp %ebx, %eax
    jge start_loop

    movl %eax, %ebx
    jmp start_loop

exit_loop:

    movl $1, %eax
    int $0x80
