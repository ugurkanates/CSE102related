#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double maxSumOfIncSeq();

int main(){
	
	maxSumOfIncSeq();

	return 0;
}

double maxSumOfIncSeq(){

	int size=0;
	double x; 
	double y=0;
	double z=0;
	double sum=0;
	double maxsize=0;
	double kez=0;
	double prex=0;
	double maxsum=0;
	double increasing_size=0;
		scanf("%lf",&x);
		prex=x;
		sum=x;
		maxsum=sum;
	if(x<=0)
		return 0;

			while(y==0){
					printf("bisi  sayi istiyom\n");
					scanf("%lf",&x);
					printf("BURAYA Gremiyom \n");
					if(x<=0){
						y=1;
							}
						while(prex<x){							
									sum=sum+x;	
									size++;
									 
						if(kez==0){
							kez++;
							maxsize=size;
						
								}
									}
				 if(prex>=x){
					if(size<maxsize){
						maxsize=size;	
						maxsum=sum;
									}				 
					size=0;
					sum=0;
			
							}
				 
					prex=x;
						}
	
	return(maxsum);
	
}