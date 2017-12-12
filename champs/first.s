.name "BITE"
.comment "v0.0.1"

start:	sti     r1, %:l1, %1		#put player ID in command live
	ld      %4, r3								#load 4 in r3
	lldi	5, %5, r1

	l1:     live    %0						#put command live with 00 00 00 00
	zjmp		%:start
	ld			%0, r2								#load 0 in r2

	l3:     ldi     %:l2, r2, r4	#addr r4 = end of proc + r2

	ld			%1, r4							#put 1 in r4 (command live code)
	sti 		r4, %:l2, r2				#put live in end of the proc + r2
	add			r2, r3, r2					# r2 += 4

	sti     r1, %:l2, r2				#put player ID at end of proc + r2

	add     r2, r3, r2					# r2 += 4
	xor     r4, r4, r4					#carry a 1
	zjmp    %:l1								#jump to l1
l2:
