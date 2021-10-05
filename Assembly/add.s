# x86 Assembly program to add two numbers.

    .section .data
data_items:
    .long 23,67

    .section .text

    .global _start

_start:
    movl $0, %edi
    movl data_items(, %edi, 4), %eax
    incl %edi
    addl data_items(, %edi, 4), %eax
    movl %eax, %ebx
    movl $1, %eax
    int $0x80
    
