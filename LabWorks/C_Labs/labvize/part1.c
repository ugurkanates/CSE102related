#include <stdio.h>
#include <stdlib.h>
int ifind(char haystack[],char needle[]);
int count(char haystack[],char needle[]);
void kucukles(char *x);

int main(){
	char haystack[255]="deHedeheDeHEDE",needle[255]="hede";
	printf("position %d,count : %d,needle:%s,haystack:%s \n",ifind(haystack,needle),count(haystack,needle),needle,haystack);
	return 0;
}


int ifind(char haystack[],char needle[]){
	int i,j,z=1,m;
	int tempi;	
	kucukles(haystack);
	kucukles(needle);
	for(i=0;haystack[i]!='\0';i++){
		if(needle[0]==haystack[i]){
			z=2;
			tempi=i;
			
			for(j=i,m=0;needle[m]!='\0';j++,m++)
				if(needle[m]!=haystack[j]){
					z=-99;
				}


		}
		if(z==2)
			return tempi;
	}
	return -1;
}

int count(char haystack[],char needle[]){
	int i;
	int count=0;
	int position=ifind(haystack,needle);
	for(i=0;haystack[i]!='\0';i++){

		if(ifind(haystack,needle)!=-1 && haystack[i]==needle[0]){

			i=i+ifind(haystack,needle);

			count++;
		}

	}
	printf("position %d,count %d,needle %s,haystack %s \n",position,count,needle,haystack);
	return count;
}
void kucukles(char *x){
	int i;
	for(i=0;x[i]!='\0';i++)
		if(x[i]>='A' && x[i]<='Z')
			x[i]+='a'-'A';
}
