#include <stdio.h>
#include <stdlib.h>
typedef enum _paddingType { ZERO, HALF, SAME} PaddingType;

int convolution(double inputArr[], int inputArraySize, double kernelArr[], int kernelArraySize, double outputArr[], int *outputArraySize, int stride, PaddingType
padding);
void addPadding(double inputArr[], int inputArraySize, double outputArr[], int*
outputArraySize, int paddingWidth, void paddingMethod(double[], int, int));
void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth);
void samePadding(double outputArr[], int outputArraySize, int paddingWidth);
void halfPadding(double outputArr[], int outputArraySize, int paddingWidth);

int main(){
	double inputArr[] = {5, 6, 7, 8, 9};
	double outputArr[255];
	int k;
	int outputArrSize = 0;
	convolution(inputArr, 7, kernelArr, 5, outputArr, &outputArrSize, 1, SAME);
	
	return 0;
}

int convolution(double inputArr[], int inputArraySize, double kernelArr[], int kernelArraySize, double outputArr[], int *outputArraySize, int stride, PaddingType
padding){
    

	int i,j,padstyle;
	int sinir,gecici;
	double toplam=0;
	if(kernelArraySize>inputArraySize)
		return -1;
	padstyle=(kernelArraySize-1)/2;
	if(padding==ZERO)
		zeroPadding(inputArr,outputArraySize,padstyle);
	else if(padding==SAME)
		zeroPadding(inputArr,outputArraySize,padstyle);
	else if(padding==HALF)
		zeroPadding(inputArr,outputArraySize,padstyle);
	sinir=sizeof(inputArr) / sizeof(double);
	for(i=0;i<sinir-kernelArraySize;i++){
		gecici=i;
		for(j=0;j<kernelArraySize;j++){

			toplam+=kernelArr[j]*inputArr[gecici];
			gecici++;
		}
		outputArr[i]=toplam;

	}
	
void addPadding(double inputArr[], int inputArraySize, double outputArr[], int
*outputArraySize, int paddingWidth, void paddingMethod(double[], int, int)){
	int i,j=0;
    int out=0;
	out=((paddingWidth*2)+(inputArraySize));
	*outputArraySize=(int)out;
	for(i=paddingWidth;i<inputArraySize+paddingWidth;i++){
		outputArr[i]=inputArr[j];
		j++;
	}

	paddingMethod(outputArr,*outputArraySize,paddingWidth);


}

void halfPadding(double outputArr[], int outputArraySize, int paddingWidth){
	
	double first=outputArr[paddingWidth]/2;
	double last=outputArr[outputArraySize-paddingWidth-1]/2;
	printf("%f is last \n",last);
	int i;
	int ikinci=outputArraySize-paddingWidth;

	for(i=0;i<paddingWidth;i++)
		outputArr[i]=first;
	for(;ikinci<outputArraySize;ikinci++)	
		outputArr[ikinci]=last;
	for(int k=0;k<15;k++)
		printf("%f\n",outputArr[k]);

}
void samePadding(double outputArr[], int outputArraySize, int paddingWidth){

	double first=outputArr[paddingWidth];
	double last=outputArr[outputArraySize-paddingWidth-1];
	int i;
	int ikinci=outputArraySize-paddingWidth;

	for(i=0;i<paddingWidth;i++)
		outputArr[i]=first;
	
	for(;ikinci<outputArraySize;ikinci++)	
		outputArr[ikinci]=last;

}

void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth){
	
	double first=0;
	double last=0;
	int i;
	int ikinci=outputArraySize-paddingWidth;

	for(i=0;i<paddingWidth;i++)
		outputArr[i]=first;
	for(;ikinci<outputArraySize;ikinci++)	
		outputArr[ikinci]=last;
}


