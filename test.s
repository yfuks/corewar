.comment "hello"
	  .name "salut"


firstlab: 	live %1
			live %1
code:           live %42                        # 5
sti  r15,%0,r1                 # 6
zjmp %-200                      # 3
live %42                        # 5
sti  r15,%0,r14                 # 6
zjmp %-200                      # 3
live %42                        # 5
sti  r15,%0,r14                 # 6
