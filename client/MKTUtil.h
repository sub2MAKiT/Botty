#define MKTDOUBLE double
// guys I swear, there is a reason for this define, just trust me guys, it's not a pointless define that will change nothing, just trust

long long MKTfloor(MKTDOUBLE input);

extern int _step;

#ifdef MKT_DEBUG
#define DEBUG(x)              \
printf("\033[%d;40m[%d]" x "\033[0;40m\n",(int)((_step % 6) + 1 + MKTfloor((float)(((_step % 2) + 1)*1.5)) * 30),_step);_step++
//assert(x);printf("\n");step++
#else
#define DEBUG(x)                                                \
0
#endif
