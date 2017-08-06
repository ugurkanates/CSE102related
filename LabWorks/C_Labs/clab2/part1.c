#include <stdio.h>
#include <stdlib.h>
char* interleave(char  str1[],char str2[],char res[]);

int main(){
	char str1[255]="kelime",str2[255]="1234",result[255];
	printf("interleave(%s,%s) => %s\n",str1,str2,interleave(str1,str2,result));

	return 0;
}


/* 


*/
char* interleave(char  str1[],char str2[],char res[]){

	int i,j=0,z=0;
	for(i=0;str2[j]!='\0';i++){
		if(i%2==0){
			res[i]=str1[j];
			j++;
		}
		else if(i%2==1){
			res[i]=str2[z];
			z++;
		}

	}

				res[i]=str2[z];
				i++;
	for(;str1[j]!='\0';i++,j++){
		res[i]=str1[j];
	}
	res[i]='\0';
	return res;
}