#include <stdio.h>
#include <stdlib.h>
double testResults(int questionNumbersArr[],int qNArrSize,char answerArr[],int ansArrSize,char keysArr[],int keysArrSize);
double calculateResult(int trueAns,int falseAns,int totalAns);

int main(){

	int questionNumbersArr[]={1,2,4,5,7,9},qNArrSize=6,ansArrSize=6,keysArrSize=10;
	char answerArr[]={'A','C','D','B','E','B'};
	char keysArr[]={'A','C','E','D','B','A','A','D','B','E'};
	double x=testResults(questionNumbersArr,qNArrSize,answerArr,ansArrSize,keysArr,keysArrSize);
	calculateResult(5,1,10);
	printf("net %f \n",x);
	return 0;
}
double testResults(int questionNumbersArr[],int qNArrSize,char answerArr[],int ansArrSize,char keysArr[],int keysArrSize){
	int i;
	int dogru=0;
	int yanlis=0;
	

	for(i=0;i<qNArrSize;i++){
		if(answerArr[i]==keysArr[questionNumbersArr[i]-1])
			dogru++;
		else
			yanlis++;


	}
	printf("%d dogru sayisi, %d yanlis,",dogru,yanlis);
	return(calculateResult(dogru,yanlis,keysArrSize));

}

double calculateResult(int trueAns,int falseAns,int totalAns){
	int toplam=totalAns+1;
	double net=0;
	int bos=toplam-trueAns-falseAns;
	//printf("dogru %d,yanlis %d, bos %d, toplam %d",trueAns,falseAns,bos,totalAns);
	net=trueAns-falseAns*(0.25);
	net=(net)/(double)totalAns;
	return net;
}