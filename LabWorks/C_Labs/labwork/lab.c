#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double mean();

int main(){

 	mean();
	//printf("%lf",x);


	return 0;
}

double mean(){

	double x;
	double y=0;
	double sum=0;
	int len=0;
	while(y==0){	
			 scanf("%lf",&x);
			 if(x<=0 ){
				y=1;
			if(len==0){
			return 0;}
						}
			else{		
			sum=sum+x;
			len++;
			}

					}			
	printf("%lf",(double)sum/len);
	
	return((double)sum/len);


}
