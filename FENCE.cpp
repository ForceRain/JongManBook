#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int panja[20010];

int solve( int low, int high )
{
	if ( low == high )	return panja[low];

	int mid = (low+high)/2;
	int ret = max( solve(low,mid), solve(mid+1,high) );
	int l = mid, hi = mid+1;
	int height = min( panja[l],panja[hi] );

	ret = max ( ret, height*2 );

	while ( low < l || hi < high )
	{
		if ( hi < high && ( l == low || panja[l-1] < panja[hi+1] ) )
		{
			hi++;
			height = min(height,panja[hi]);
		}
		else
		{
			l--;
			height = min(height,panja[l]);
		}
		ret = max(ret, height * ( hi-l+1 ));
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
		int N;
		memset(panja,0,sizeof(panja));
		scanf("%d",&N);

		for ( int j=0;j<N;j++ )
			scanf("%d",&panja[j]);

		printf( "%d\n",solve(0,N) );
	}

	return 0;
}