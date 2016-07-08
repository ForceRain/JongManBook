#include <iostream>
#include <cstdio>

using namespace std;

int currents[16];
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS+1] = 
{
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned()
{
	bool aligned = true;
	for ( int i=0;i<16;i++ )
		if ( currents[i] != 12 )
			aligned = false;
	return aligned;
}

void push( int sw )
{
	for ( int clock = 0; clock < CLOCKS; clock++ )
	{
		if ( linked[sw][clock]== 'x' )
		{
			currents[clock] +=3;
			if ( currents[clock] == 15 )	currents[clock] = 3;
		}
	}
}

int solve( int sw )
{
	if ( sw == SWITCHES )	return areAligned() ? 0 : INF;
	int ret = INF;
	for ( int cnt = 0 ; cnt < 4; cnt++ )
	{
		ret = min(ret, cnt+solve(sw+1));
		push( sw );
	}
	return ret;
}

int main(void)
{
	int test;
	freopen("test.txt","r",stdin);
	scanf("%d",&test);

	for ( int i=0;i<test;i++ )
	{
		for ( int j=0;j<16;j++) scanf("%d",&currents[j]);
		int min = 0x7FFFFFFF;
		for ( int j=0;j<10;j++ )
		{
			int res = solve( j );
			if ( res < min )
				min = res;
		}
		if ( min >= INF )	printf("-1\n");
		else printf("%d\n",min);
	}

	return 0;
}