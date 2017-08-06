#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double minimum();
double maximum();

int main(){
	minimum();
	

	return 0;
}

double minimum(){
	double y=0;
	double x=0;
	double max;
	scanf("%lf",&x);
	if(x<=0)
		return 0;
	max=x;

	while(y==0){
			scanf("%lf",&x);
			if(x<=0){
					y=1;
					return(max);
		
					}

			if(x>max)
				max=x;


			}


}


double maximum(){
	double y=0;
	double x=0;
	double min;
	scanf("%lf",&x);
	if(x<=0)
		return 0;
	min=x;

	while(y==0){
			scanf("%lf",&x);
			if(x<=0){
					y=1;
					return(min);
		
					}

			if(x<min)
				min=x;


			}


}

