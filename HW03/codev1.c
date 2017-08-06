#include <stdio.h>
#include <stdlib.h>
int isPrime(int num);
int goldbach(int num, int *p1, int *p2);

int main(){
	int num = 824, p1, p2;
if(goldbach(num,&p1,&p2))
printf("%d = %d + %d",num,p1,p2); /* may print 824 = 821 + 3 */
else
printf("You should provide even number.");
printf(" \n %d prime",isPrime(3) );
	return 0;
}
int isPrime(int num){
	int temp=0;
	int i;
	for(i=2;i<num;i++){
		if(num%i==0 )
			temp++;

	}
	if(temp==0)
		return 1;
	else
		return 0;

}

int goldbach(int num, int *p1, int *p2){
	int i;
	if(num%2==1)
		return 0;
	for(i=num-2;i>1;i--){
		if(isPrime(i)==1 && isPrime(num-i)==1){
			*p1=i;
			*p2=num-i	;
			return 1;
		}
	}
	return 0;

}