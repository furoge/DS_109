#include <stdio.h>
#ifndef _AX_
#define _AX_

// power x of base a 
int aX(int a,int x)
{
	if(x==0)
		return 1;
	else if(x==1)
		return a;
	else
	{
		int val=1;
		while(x>=1)
		{
			val=val*a;
			--x;
		}
		return val;
	}
}
#endif