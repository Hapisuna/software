#include <stdio.h>
int kasan(int);
int k = 0;

int main(void)
{
	int inp;
	

	printf("正の整数(4桁)：");
	scanf("%d",&inp);
	printf("%d\n",kasan(inp));

}

int kasan(int n)
{
	int hako[4],a,max,min,i,j;

	hako[0] = n / 1000;
	hako[1] = (n - hako[0] * 1000) / 100;
	hako[2] = ((n - hako[0] * 1000) - hako[1] * 100) / 10;
	hako[3] = (((n - hako[0] * 1000) - hako[1] * 100) - hako[2] * 10) / 1;

	for(i = 0 ; i < 4 ; i++){
		for(j = i + 1 ; j < 4 ; j++){
			if (hako[i] < hako[j]){
				a = hako[j];
				hako[j] = hako[i];
				hako[i] = a;
			}
		}
	}
	max = hako[0]*1000 + hako[1]*100 + hako[2] * 10 + hako[3];
	min = hako[3]*1000 + hako[2]*100 + hako[1] * 10 + hako[0];

	n = max-min;
	k++;
	if (n == 0 || n == 6174){
		return k;
	}else {
		kasan(n);
	}
}