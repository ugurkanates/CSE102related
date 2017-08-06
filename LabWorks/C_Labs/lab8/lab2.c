#include <stdio.h>
#include <stdlib.h>
#define LEN 8
int bin2dec(int bin[]);
int dec2bin(int dec,int bin[]);
int two2factor(int i);
int sayi_size(int m);
void printByte(int byte[]);

int main(){
	
	int a[8]={0,0,0,0,0,0,0,1};
	int b[8];
	//printf("byte:\t");
	//printf("%d",sayi_size(149));
	//printf("%d is two factor 3 ise mali",two2factor(3));
	printf("-> %d\n",bin2dec(a));
	//printByte(a);


	//printf("num %d == \t",249);
	//dec2bin(3,b);
	//printByte(b);
	printf("\n");

	return 0;
}

void printByte(int byte[]){
	int i;
	for(i=0;i<LEN;i++)
		printf("%d",byte[i]);
}

int bin2dec(int bin[]){
	int i,j=0;
	int sum=0;
	int sayi=0;

	for(i=0,j=7;i<8;i++,j--){
		sum=sum+bin[i]*two2factor(j);
	}
	
	return sum;

}

int dec2bin(int dec,int bin[]){
	int i;
	for(i=0;i<8;i++)
		bin[i]=0;
	if(dec>255 || dec<0)
		return -1;
	for(i=7;dec!=0 && dec!=1;i--,dec=dec/2)
		bin[i]=dec%2;
	bin[i]=dec;
	return 0;
}


int two2factor(int i){
	int j;
	int top=1;
	for(j=0;j<i;j++)
		top=top*2;
	return top;
}
int sayi_size(int m){
	int i=0;
	for(i=0;m>0;m=m/10,i++){
	}
		
	return i;
	}


/*	printf("%d Xsum",sum);
	for(i=sayi,j=0;sayi>0;sayi--,j++){
		bin[j]=sum%10;
		sum=sum/10;
	} */