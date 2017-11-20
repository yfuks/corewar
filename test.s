.comment "hello"
	  .name "salut"


firstlab: live %1
and  12, r1,r3
live %1
code:       live %42        # 5
sti	r10,%1,%12                # 6
zjmp %-200                      # 3
live %42                        # 5
sti  r5,%1,r14                 # 6
zjmp %-200                      # 3
live %42                        # 5
sti  r15,%0,r14                 # 6
