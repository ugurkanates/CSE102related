#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <sys/wait.h>

	#include <stdlib.h>
#include <stdio.h>




void drawRectangle(int width,int height, int startingPoint, int printLastLine);
void drawDoubleCircle(int radius,int  startingPoint ,int whellDistance);
void drawCar();

int main(void){

 	//drawRectangle(40,10,11,1);

	drawCar();

	
	return 0;
		}
void drawRectangle(int width,int height, int startingPoint, int printLastLine){


	for(int i=0;i<height;i++){
	  	for(int z=0;z<startingPoint;z++)
			printf(" ");
		if(i==0)
	{ 
      for(int j=0;j<width;j++){
			printf("*");
			if(j==width-1)
				printf("\n");
							  }
	}
	else if(i!=height-1)
	{
	 printf("*");
	 for(int k=0;k<width-2;k++)
		printf(" ");
	 printf("*\n");
	}
	else{
		if(printLastLine==1){
								for(int m=0;m<width;m++)
								 	printf("*");
							}
		else if(printLastLine==0)
			{
				printf("*");
				for(int o=0;o<width-2;o++)
				 printf(" ");
				printf("*");
			}
		printf("\n");
		}
	
	

							}



	}

void drawDoubleCircle(int radius, int startingPoint ,int whellDistance){

	

for(int i = -radius; i < radius; i++) 
{
for(int h=0;h<startingPoint;h++)
printf(" ");
for(int j = -radius; j < radius; j++)
{

if(i*i + j*j < radius*radius){
printf("*");
}
else
printf(" ");

}
for(int m=0;m<whellDistance;m++)
printf(" ");
for(int j = -radius; j < radius; j++)
{

if(i*i + j*j < radius*radius){
printf("*");
}
else
printf(" ");

}
printf("\n");
}


}

void drawCar(){
	drawRectangle(20,15,10,0);
	drawRectangle(30,20,5,1);
	drawDoubleCircle(4,7,12);

}

