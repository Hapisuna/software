#include <stdio.h>
#include <math.h>
int ran(int);
int k = 0;

int main(void)
{
	int n;
	
	printf("正の整数(4桁)：");
	scanf("%d",&n);
    for(int i = 0; i < 10; i++)
    {
        n = ran(n);
        printf("%d\n",n);
    }
}

int ran(int a)
{
	int hako[8],i,j,b,c;
    
    for(i = 7; i >= 0; i--)
    {
        hako[i] = (int)(a*a / pow(10,i)) % 10;
    }
    a = hako[5]*1000 + hako[4]*100 + hako[3]*10 + hako[2];
    return a;
}



	
	
	