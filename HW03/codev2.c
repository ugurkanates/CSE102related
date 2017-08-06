#include <stdio.h>
#include <stdlib.h>
int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, int
*krs10, int *krs5, int *krs1);

int main(){
	double paid = 5, due = 3.75;
int tl1=0,krs50=0,krs25=0,krs10=0,krs5=0,krs1=0;
if(dispenseChange(paid,due,&tl1,&krs50, &krs25, &krs10, &krs5, &krs1)) /* returns 1 */
printf("Change: 1TL:%d, Kurus50:%d,25:%d,10:%d,5:%d,1:%d\n",tl1,krs50,krs25,krs10,krs5,krs1);
else
printf("Unable to dispense change.");

	return 0;
}

int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, int
*krs10, int *krs5, int *krs1){
	int i;
	double temp;
	if(paid<due)
		return 0;
	temp=paid-due;
	printf("temp first %lf",temp);
	while(temp>=1){
		*tl1=*tl1+1;
		temp=temp-1;
	}
	while(temp>=0.50){
		*krs50=*krs50+1;
		temp=temp-0.50;
	}
	while(temp>=0.25){
		*krs25=*krs25+1;
		temp=temp-0.25;
	}
	while(temp>=0.10){
		*krs10=*krs10+1;
		temp=temp-0.10;
	}
	while(temp>=00.05){
		*krs5=*krs5+1;
		temp=temp-0.05;
	}
	while(temp>=0.01){
		*krs1=*krs1+1;
		temp=temp-0.01;
	}
	return 1;
}
