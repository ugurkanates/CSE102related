#include <stdio.h>
#include <stdlib.h>
#define ALPHABET 27
void hist(char str[],int hist[27]);
void printHist(int his [ALPHABET]);
int main(){
	char str[]="The quick brown fox jumps over the lazy dog.";

	int histogram[ALPHABET];
	for(int j=0;j<27;j++)
		histogram[j]=0;
 	hist(str,histogram);
 	printHist(histogram);


	return 0;
}
void hist(char str[],int hist[27]){
	int i,j;
	for( j=0;j<27;j++)
		hist[j]=0;
	for(i=0;str[i]!='\0';i++){
		if(	str[i]>='A' && str[i]<='Z' ){
			hist[(str[i]-'A')]++;
			printf("test1 %c\n",str[i]);
		}
		else if((str[i]>='a' && str[i]<='z') ){
			hist[str[i]-'a']++;
			printf("test2 %c\n",str[i]);
		}
		else
			hist[26]++;

	}


}

void printHist(int hist[ALPHABET]){
	int i;
	for (i=0;i<ALPHABET-1;i++)
		printf("%c --> %d\n",'A'+i,hist[i]);
	printf("others %d\n",hist[i]);

}
