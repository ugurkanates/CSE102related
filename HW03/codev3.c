#include <stdio.h>
#include <stdlib.h>
int charge(int cardType, int* monthlyUse, double* balance);

int main(){
	int monthlyUse = 120;
double balance = 20.0;
if(!charge(1,&monthlyUse, &balance) < 0)
printf("Remaining monthly use: %d – Remaining Balance: %.2f\n",monthlyUse,balance);
else
printf("Insufficient balance.");

	return 0;
}


int charge(int cardType, int* monthlyUse, double* balance){
	int sub=0; /*1 if subscriber*/
	if(cardType!=1 || cardType!=2 || cardType!=3)
		return -2;
	switch(cardType){
	case(1):
		if(1.30*30<*balance && *monthlyUse>1){
			*monthlyUse=*monthlyUse-30;
			*balance=*balance-1.30*30;
		}
		else if(2.30*30<*balance && *monthlyUse<1){
			*balance=*balance-2.30*30;
		}
		else
			return -1;
		break;
	case(2):
		if(0.15*30<*balance && *monthlyUse>1){
			*monthlyUse=*monthlyUse-30;
			*balance=*balance-0.15*30;
		}
		else if(1.5*30<*balance && *monthlyUse<1){
			*balance=*balance-1.15*30;
		}
		else
			return -1;
		break;
	case(3):
		if(0.65*30<*balance && *monthlyUse>1){
			*monthlyUse=*monthlyUse-30;
			*balance=*balance-0.65*30;
		}
		else if(1.65*30<*balance && *monthlyUse<1){
			*balance=*balance-1.65*30;
		}
		else
			return -1;
		break;

	}


	return 0;
}