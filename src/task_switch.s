.syntax undefined
.cpu cortex-m3
.thumb

.global task_switch

task_switch:
    // Save context of the current task
    mrs r0, psp
    stmb ro!, {r4-r11}
    str r0, [r1]

    // Load the context of the next task
    ldr r0, [r2]
    ldmia r0!, {r4-r11}
    msr psp, r0
    bx lr