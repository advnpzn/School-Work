# x86 Assembly program to multiply two numbers.

    .section .data
data_items:
    .long 15,3

    .section .text

    .global _start

_start:
    movl $0, %edi
    movl data_items(, %edi, 4), %eax
    incl %edi
    imul data_items(, %edi, 4), %eax
    movl %eax, %ebx
    movl $1, %eax
    int $0x80
    
