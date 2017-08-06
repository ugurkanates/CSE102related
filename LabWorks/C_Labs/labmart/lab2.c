#include <stdio.h>
#include <stdlib.h>

double testResults2d(char questionNumbersArr[][5],int qNArrSize,char keysArr[],int keysArrSize);
double calculateResult(int trueAns,int falseAns,int totalAns);
int main(){

	char answerArr[][5]={
		{'*','-','-','-','*'},
		{'-','-','-','*','-'},
		{'-','-','-','-','-'},
		{'-','-','-','*','*'},
		{'-','-','-','-','-'},
		{'-','-','-','-','-'},
		{'*','*','-','-','*'},
		{'-','-','-','-','-'},
		{'-','*','*','-','-'},
		{'-','-','-','-','-'},

	};
	int numOfQuestions = 10,keysArrSize=10;
	char keysArr[]={'A','C','E','D','B','A','A','D','B','E'};
	double x=testResults2d(answerArr,numOfQuestions,keysArr,keysArrSize);
	printf("net result is %lf",x);
	return 0;
}
double testResults2d(char questionNumbersArr[][5],int qNArrSize,char keysArr[],int keysArrSize){
	int dogru=0,yanlis=0,bos=0,toplam=qNArrSize;
	int gecicid,yildiz=0;
	int i,j;

	for(i=0;i<qNArrSize;i++){
		gecicid=dogru;
		yildiz=0;
		for(j=0;j<5;j++)
		{
			if(questionNumbersArr[i][j]=='*'){
				yildiz++;
				if(j==0 && keysArr[i]=='A')
					dogru++;
				else if(j==1 && keysArr[i]=='B')
					dogru++;
				else if(j==2 && keysArr[i]=='C')
					dogru++;
				else if(j==3 && keysArr[i]=='D')
					dogru++;
				else if(j==4 && keysArr[i]=='E')
					dogru++;
											}
		}
		if(yildiz>1){
			yanlis++;
			if(gecicid!=dogru)
				dogru=gecicid;
		}
		else if(yildiz==0){
			bos++;
			printf(" hangi sair bos gosteriyo onun seyleri keys %c ve satiri %d \n",keysArr[i],i+1);
		}


		}
		calculateResult(dogru,yanlis,toplam);
	}




double calculateResult(int trueAns,int falseAns,int totalAns){
	printf("dogru %d,yanlis %d, , toplam %d \n",trueAns,falseAns,totalAns);

	int toplam=totalAns+1;
	double net=0;
	int bos=toplam-trueAns-falseAns;
	//printf("dogru %d,yanlis %d, bos %d, toplam %d",trueAns,falseAns,bos,totalAns);
	net=trueAns-falseAns*(0.25);
	net=(net)/(double)totalAns;
	return net;
}