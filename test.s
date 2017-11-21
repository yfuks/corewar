.name "salut"
.comment "hello"

l2: sti r1,%2,%0
	and r1,%0,r1
live: live %1
zjmp %2
