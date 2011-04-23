.global led_entry

.section .boot, "ax"

led_entry: /* bisogna inserire lo stack, lo metto ad 1 KByte (indirizzo 0x00000400) */

        mov r0, pc
        sub r0, #12
        mov sp, r0
        
        /* azzeramento dei valori contenuti nella sezione BSS */
        
        mov r0, #0
        ldr r1, =__bss_start
        ldr r2, =__bss_end
0:      cmp r1, r2
        bge 1f
        str r0, [r1]
        add r1, #4
        /* dopo aver azzerato la sezione bss avvio il programma dal main */
1:      bl led_main
        b 1b