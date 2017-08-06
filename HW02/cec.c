#include <stdio.h>
#include <stdlib.h>
 void drawFunction(int xAxis,int yAxis,int functionNumber);
int function(int x);
int main(){

	







	drawFunction(10,10,1);








	return 0;
}

 void drawFunction(int xAxis,int yAxis,int functionNumber){
	int result=function(4);

	for(int i=0;i<yAxis;i++){
		printf("I");
		for(int j=0;j<xAxis;j++){
					if(j==result)
						printf("*");
					else
						printf(" ");
				}
	result--;
	printf("\n");

		}
for(int k=0;k<yAxis;k++)
	printf("-");

}

int function(int x){
 return(2*x);
}
