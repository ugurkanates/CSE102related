#include <stdio.h>
#include <stdlib.h>
char *reverse(char str[],char rev[]);
char *tostr(int num,char str[]);
char *combine(char str1[],char str2[],char str3[],char res[]);
char *convert(char str[],int num,char res[]);
int sizer(char str[]);

int main(){
	char str[255]="herhalde",str2[255]="turta",str3[255]="donmus",res[255],res2[255];
	int dec=65109;

	printf("reverse of %s\n",reverse(str,res));
	
	printf("tostr of %s\n",tostr(dec,res2));
	return 0;
}


char *reverse(char str[],char rev[]){
	int i,m;
	int n=sizer(str);
	for(i=n-1,m=0;i>0;i--,m++){
		rev[m]=str[i];

	}
	rev[m]=str[i];
	return rev;
}
int sizer(char str[]){
	int count=0;
	int i;
		for(i=0;str[i]!='\0';i++)
			count++;

		return count;
}
char *tostr(int num,char str[]){
	int i=0;
	char ters[255];
	i=0;	
	while(num>0){

		if(num%10 == 0)
			str[i]='0';
		else if(num%10 == 1)
			str[i]='1';
		else if(num%10 == 2)
			str[i]='2';
		else if(num%10 == 3)
			str[i]='3';
		else if(num%10 == 4)
			str[i]='4';
		else if(num%10 ==5)
			str[i]='5';
		else if(num%10 == 6)
			str[i]='6';
		else if(num%10 == 7)
			str[i]='7';
		else if(num%10 == 8)
			str[i]='8';
		else if(num%10 == 9)
			str[i]='9';

		num=(num/10);
		i++;
	}
	printf("%s",str);
	reverse(str,ters);
}