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
				
					if(x<=0){
						y=1;
							}
					 			 
					if(kez==0){
							
							maxsize=size;
						
							}

						if(prex<x && kez>0){
									increasing_size++;	
									printf("muz");						
									sum=sum+x;
									printf("%f",sum);	
									size++;
									if(maxsize<size){
										
										maxsum=sum;
										maxsize=size;
										printf("maxsum %f",maxsum);
													}
									}
				 if(prex>=x && kez>0 && increasing_size>0){
					printf("abi");
					if(size>maxsize){
						maxsize=size;	
						maxsum=sum;
									}				 
					size=0;
					sum=0;
			
							}
				 
					prex=x;
					if(kez==0){
						kez++;
						sum=sum+x;
							}
						}
	if(increasing_size<0)
		maxsum=0;
    printf("%f",maxsum);
	return(maxsum);
	
}
