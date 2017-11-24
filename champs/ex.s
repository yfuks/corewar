.name "zork"
.comment "just a basic living prog"
		
	sti r1, %:field1, %1
	ld %0, r10
	add r7, r5, r4
	ldi 3,%4,r1
field1:			live %0
	zjmp %:field1
	