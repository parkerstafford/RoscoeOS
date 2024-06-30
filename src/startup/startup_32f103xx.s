.syntax unified
.cpu cortex-m3
.fpu softvfp
.thumb

.global _start

// Stack configuration
.equ STACK_TOP, 0x2005000

// Vector table
.section .isr_vector, "a", %progbits
.type vector_table, %object
.size vector_table, .-vector_table

vector_table:
    .word STACK_TOP // Initial stack pointer
    .word reset_handler // Reset handler
    // TODO: Add other interrupt handlers here

.section .text.reset_handler.type
.type reset_handler, %function
reset_handler:
    // Call system initialization  function
    bl system_init
    // Call the main function
    bl main
    // Infinite loop
     b   .


// System initialization
.section .text.system_init
.type system_init, %function
system_init:
    // Initialize data and bss
    ldr r0, =_sbss
    ldr r1, =_ebss
    movs r2, #0
    b 2f

1:  str r2, [r0], #4
2:  cmp r0, r1
    bcc 1b

    ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_sidata
    b 2f
3:  ldr r3, [r2], #4
    str r3, [r0], #4
2:  cmp r0, r1
    bcc 3b
    bx lr

// Provide weak default handlers
.section .text.default_handler
.type default_handler, %function
default_handler:
    b .

.section .text.isr_vector_fill, "a", %progbits
    .rept (256 - 2)
    .word default_handler
    .endr