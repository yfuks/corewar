.name "zork"
.comment "just a basic living prog"

fd:
sti 			r1,  	%:live,%1
and r1,%0,		 	r1
live: 		  		 live %1
ld :live, r3
ld :live, r3
zjmp %:live
