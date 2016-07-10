#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char input_stream[1012];

string reversing(string::iterator &it)
{
	char head = *it;
	++it;
	if ( head == 'b' || head =='w' )
		return string(1,head);
	string upperleft = reversing(it);
	string upperright = reversing(it);
	string lowerleft = reversing(it);
	string lowerright = reversing(it);

	return string("x") + lowerleft + lowerright + upperleft + upperright;
}

int main(void)
{
	int test;
	freopen("test.txt","r",stdin);
	scanf("%d",&test);

	for ( int i=0;i<test;i++ )
	{
		scanf("%s",input_stream);
		string str1(input_stream);
		string::iterator it1 = str1.begin();
		printf("%s\n",reversing(it1).c_str());
	}

	return 0;
}