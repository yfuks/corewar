.name "fuks zork"
.comment "42 born 2 pause"
		
		sti r1, %:live, %1
		sti r1, %:live2, %1
		ld	%0, r2
live:	live %0
		fork %:live2
		zjmp %:live
live2:	live %0
		zjmp %:live2
	