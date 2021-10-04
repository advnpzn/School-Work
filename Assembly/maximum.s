 # x86 Assembly program to find the maximum number among a group of numbers.
 # %edi - For storing the index
 # %eax - For storing the current element/data
 # %ebx - For storing the largest number

    .section .data

data_items:
    .long 22,56,47,54,11,89,77,82,0     # .long corresponds to 4 bytes. So each number is reserved 4 bytes of memory.


    .section .text    


    .globl _start

_start:

    movl $0, %edi                       # initialising index = 0 in %edi register
    movl data_items(,%edi,4), %eax      # storing the first element in the %eax register
    movl %eax, %ebx                     # The first element is going to the largest anyways in the start.. So, storing the largest element in the %ebx register

start_loop:                             

    cmpl $0, %eax                       # Finding the largest element stops when the %eax register encounters data 0 in data_items.
    je exit_loop                        # if 0 is present in %eax, then goto jump to exit_loop.
    incl %edi                           # else, increase the index (%edi) by 1
    movl data_items(,%edi,4), %eax      # store the next data in the data_items in %eax
    cmpl %ebx, %eax                     # compare the largest number in %ebx with the current number in #eax
    jle start_loop                      # if the number in %eax is smaller or equal to the one in %ebx, will jump to the start_loop

    movl %eax, %ebx                     # else, if the number in %eax > %ebx , then the number in %eax is stored in %ebx 
    jmp start_loop                      # jump to start_loop and repeat the process, until the data in %eax is not 0

exit_loop:

    movl $1, %eax                       # mov linux syscall exit() i.e $1 to %eax register
    int $0x80                           # interrupt linux kernel to execute the syscall in %eax
                                        # the maximum number is stored in the %ebx register, view it by typing echo $? in the shell.


