.name "fuks zork"
.comment "42 born 2 pause"
		
		sti r1, %:live, %1
		sti r1, %:live2, %1
		ld :live2, r6
		ld 	%22, r7
		ld	%238, r4
		ld :end, r3
		ld :sti, r5

live:	live %0
		zjmp %:live

		fork %:live2
		ld	%0, r2
		zjmp %:live

sti:	sti r5, r7, %0
	
live2:	live %0
		sti r6, r4, r4
end:	sti r5, r3, r7

