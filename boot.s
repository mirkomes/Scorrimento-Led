.section .text.romboot
.global _led_entry_rom
_led_entry_rom:
	
	ldr	r0, =_sdata
	ldr	r1, =_edata
	ldr	r2, =_erom
	/* stack is before data */
	mov	r3, r0
	sub	r3, #4
	mov	sp, r3
	
	/* copy from r2 to r0, until r1. We know it's aligned at 16b */
10:
	cmp	r0, r1
	bge	_led_entry
	/*copia le celle di memoria puntante da r2 che parte dall'indirizzo _erom e le salva
	nella sezione puntata da r0 che parte da _sdata fino a quando la zonda .data non viene saturata*/
	ldmia	r2!, {r4, r5, r6, r7}
	stmia	r0!, {r4, r5, r6, r7}
	b	10b


.section .text.secondboot
_led_entry:
	ldr	r1, =__bss_start
	ldr	r2, =__bss_end
	mov	r0, #0
0:
	cmp	r1, r2
	bge	1f
	str	r0, [r1]
	add	r1, #4
	b	0b

1:

	mov	r0, #0
	bl led_main
2:	b 2b

