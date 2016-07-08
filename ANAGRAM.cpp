#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char in1[101];
char in2[101];
int i1[256];
int i2[256];

int main(void)
{
	int N,l1,l2;
	scanf ("%d",&N);

	for (int i=0;i<N;i++)
	{
		memset(i1,0,sizeof(i1));
		memset(i2,0,sizeof(i2));
		scanf("%s%s",in1,in2);
		l1=strlen(in1);
		l2=strlen(in2);
		for (int j=0;j<l1;j++)
			i1[in1[j]]++;
		for (int j=0;j<l2;j++)
			i2[in2[j]]++;
		bool nop=false;
		for (int k=0;k<256;k++)
		{
			if (i1[k]!=i2[k])
				nop=true;
		}
		if (strcmp(in1,in2)==0)	nop=true;
		if (nop)
			printf("No.\n");
		else
			printf("Yes\n");
	}

	return 0;
}