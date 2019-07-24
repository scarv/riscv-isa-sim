require_extension('x');

uint32_t    switch_mask = XCRS1;
uint32_t    t1          = XCRD;
uint32_t    t2          = 0;
uint32_t    cs          = insn.xc_cs();

#define GETBIT(x,i) ((x>>i)&0x1)
#define SETBIT(x,i,j) ((x & ~(0x1<<i)) | (j << i))

//printf("# xc.pbit %d(%08X) %d(%08X) %d\n",
//    insn.xcrd(),XCRD, insn.xcrs1(),XCRS1, cs);
//fflush(stdout);

for(int i = 0; i < 5; i ++) {
            
    uint32_t tti= i == 0 ? 1 : 2 << (i-1); 

    if((cs >> i) & 0x1) {
        //printf("# Round %d, 2**i=%d\n",i,tti); fflush(stdout);

        for(int j = 0; j < 32; j ++) {
            
            uint32_t k  = 4-j;
            // MOD(k+tti, 2*tti)+(INT(k/(2*tti))*tti*2)

            uint32_t jp  = ((k+tti)%(2*tti)) + ((k/(2*tti)) * tti*2);

            uint32_t s   = GETBIT(switch_mask, k) ? k : jp;

            //printf("\t %d <- %d ? %d : %d\n",
            //    k, GETBIT(switch_mask, k), k, jp);
            //fflush(stdout);

            t2  = SETBIT(t2, k, GETBIT(t1,s));
        }
        t1 = t2;
    }

}

#undef GETBIT
#undef SETBIT

WRITE_XCRD(t1);

