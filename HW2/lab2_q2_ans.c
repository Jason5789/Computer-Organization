// TODO :
"li t1,16\n\t"
"li t2,-1\n\t"
"li x21,0\n\t"
"li x22,0\n\t"
"vsetvli t0, a0, e16, ta, ma\n\t"
"vle16.v v0,(%[p_x])\n\t"
"loop1:\n\t"
	"add %[p_tmp1],%[p_x],x21\n\t"
	"lh a0,0(%[p_tmp1])\n\t"
	"vadd.vx v1, v0, a0\n\t"
	"vmseq.vx v2, v1, %[target]\n\t"
	"vfirst.m t0,v2\n\t"
	"bne t0,t2,conti\n\t"
	"addi x21,x21,2\n\t"
	"bne x21,t1,loop1\n\t"
	"beq x21,t1,bre\n\t"
"conti:\n\t"
	"add %[flag],x22,1\n\t"
"bre:\n\t"

