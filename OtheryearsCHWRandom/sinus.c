/*
 UGURKAN ATES 

151044012 - COMPUTER ENGINEERING DEPARTMENT -cs 102 hwork3 - part 1 .c
calculating sinus and returning it.
 */

/* 
 * File:   main.c
 * Author: m
 *
 * Created on 25 Ekim 2016 Salı, 10:39
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> // this is only used for compare function
#define SIZE 50

int part1(void); 
int part2(void);
double factorial(double n);
double turnradian(double n);
double power(double n,double us);
double sin(double n);
int constant(int x,int toplam);
int line(int x,int toplam);
int square(int x,int toplam);
int sqroot(int x,int toplam);
int expon(int x,int toplam);
int logon(int x,int toplam);
int logen(int x,int toplam);
int trigon(int x,int toplam,char *abora);
int terstrigon(int x,int toplam,char *abora);
int liner(int x,int kontrol,int toplam);

int main(void) {
	
	part1();
	part2();
	return 0;
}

int part1(void){
		double x=0;
		char answer='y';
		while(answer=='y'){
		printf("Hello please give angle to calculate it in degree(ex 0-360) \n");
		scanf("%lf",&x);
		x=factorial(x);
		double y=sin(x);
		printf("calculation of your input as sin is '%lf' \n",y);
	}
	return 0;
} 

double factorial(double n){
	
	
    if (n >= 1)
        return n*factorial(n-1);
    else if(n==1 || n==0)
        return 1;
	else
		return -1;

}

double turnradian(double n){
	
	while(n>360){
		n=n-360;
	}
	return n;
} 

double power(double n, double us)
{
        double Return = 1;
        int m;
        if ( us > 0)
        	
               for (m = 0; m < us; m++)
                      Return *= n;
        else
	               printf("base is not allowed to have negative numbers in this homwork3");
	               return -1;
        return Return;
} 

double sin(double x)
{
    int y;
    double deger=0;
    for (y=0;y<8;y++)
    {
        double ilkt = power(-1,y);
        double ikiter = power(x,2*y+1);
        double fak = factorial(2*y+1);
        deger += ilkt *ikiter / fak;
    }
    		return deger;
}


////////////////////////////////////////////////////////////////


/*

	UGURKAN ATES 30 EKIM 2016 CUMHURIYET BAYRAMI SONRASI c-program homework 3 - part 2
	inputs = toplam which is sum, x is value from user
	151044012 -gtu computer engineering department
*/



/*int constant(int x,int toplam);
int line(int x,int toplam);
int square(int x,int toplam);
int sqroot(int x,int toplam);
int expon(int x,int toplam);
int logon(int x,int toplam);
int logen(int x,int toplam);
int trigon(int x,int toplam,char *abora);
int terstrigon(int x,int toplam,char *abora);
int liner(int x,int kontrol,int toplam);
int numbertoplama(int x);
int logaritma(int base,int x);
int trigon(char,int); */
int part2(void){
	char abora[SIZE];
	int export[10][SIZE];
	int toplam=0;
	int kontrol=0;
	int x;
 	/*use this matrix to keep numbers of function callings
		0=constant
		1=line
		2=square
		3=sq root
		4=exponential
		5=logarithm natural base
		6=logartihm 10 base
		7=trigonometry 
		8=invert trigonometry
		9=line with a component
	
	       */
	int numberelem; // number of elements
	printf("to enter constant  use 'constant'\n");
	printf("to enter number  use 'x ' \n");
	printf("to square  use 'x 2'");
	printf("to enter square root  use 'x 0.5 \n'");
	printf("to enter exponential  use 'e x'\n");
	printf("to enter log e use 'log e x'\n");
	printf("to enter log 10 use 'log 10 x\n");				
	printf("to enter trigonometry  use 'sin x'\n");
	printf("to enter inverse trigonometry  use 'sin -1 x' \n");
	printf("to enter a*x just use 'a' as  in number ' a x' \n");	
	printf("note x is just letter you will enter x in end\n\n");

	printf("Now enter number of elements:");
	scanf("%d",&numberelem);
	printf("now you will enter value of x \n");
	scanf(" %d",&x);
	for(int z=0;z<numberelem;z++){

	fgets(abora,sizeof(abora),stdin);
 	
	if( strstr(abora, "x") == NULL )  
			export[0][z]++;
	else
	if( strstr(abora, "x") != NULL )
			export[1][z]++;
	else
	if( strstr(abora, "x") != NULL  && strstr(abora,"2") != NULL)
			export[2][z]++;
	else
	if( strstr(abora, "x") != NULL  && strstr(abora,"0.5") != NULL)
			export[3][z]++;
	else
	if( strstr(abora, "e") != NULL && strstr(abora, "x") != NULL)
			export[4][z]++;
	else
	if( strstr(abora, "log") != NULL && strstr(abora, "x") != NULL && strstr(abora, "e") != NULL )
			export[5][z]++;
	else
	if( strstr(abora, "log") != NULL && strstr(abora, "10") != NULL && strstr(abora, "x") != NULL )
			export[6][z]++;
	else
	if( strstr(abora, "sin") != NULL || strstr(abora, "cot") != NULL || strstr(abora, "tan") != NULL || strstr(abora, "cos") != NULL )
			export[7][z]++;
	else
	if((strstr(abora, "sin") != NULL || strstr(abora, "cot") != NULL || strstr(abora, "tan") != NULL || strstr(abora, "cos") != NULL ) && strstr(abora, "-1") != NULL )
			export[8][z]++;
	else
	if(strstr(abora, "x") != NULL){

		int kontrol=atoi(abora);
		//this kontrol if its ax or x a even that i wrote this at last meaning that x will be checked first 
		// if its greater then 0 cause atoi returns 0 in failure
		if(kontrol!=0){
			export[9][z]++;
			return kontrol;
						}		
		


								}	


	for(int outer=0;outer<10;outer++){

		for(int inner=0;inner<numberelem;inner++){

			if(export[inner][outer]==export[0][outer]){
				constant(x,toplam);
			
														}
			if(export[inner][outer]==export[1][outer]){

			line(x,toplam);
																	}
			if(export[inner][outer]==export[2][outer]){
			square(x,toplam);
		
																	}
			if(export[inner][outer]==export[3][outer]){

			sqroot(x,toplam);
																	}
			if(export[inner][outer]==export[4][outer]){

			expon(x,toplam);
																	}
			if(export[inner][outer]==export[5][outer]){

			logen(x,toplam);
																	}
			if(export[inner][outer]==export[6][outer]){

			logon(x,toplam);
																	}
			if(export[inner][outer]==export[7][outer]){

			trigon(x,toplam,abora);
																	}
			if(export[inner][outer]==export[8][outer]){

			terstrigon(x,toplam,abora);
																	}

			if(export[inner][outer]==export[9][outer]){

			liner(x,kontrol,toplam);
														}

	
	
		}


	
		}

}






	
		printf("%d toplam yaz",toplam);
	
	return 0;
}



int constant(int x,int toplam){
	
return (toplam);

}

int line(int x,int toplam){

	return(toplam=toplam+1);
}

int square(int x,int toplam){

	return(toplam=toplam+2*x);
}

int sqroot(int x,int toplam){

	return(toplam=toplam+(1/2)*(1/2*x));
}

int expon(int x,int toplam){

	return(toplam=toplam+2.71*x); // unutma burda double degl o yuzden not precious degelrer verir
}

int logon(int x,int toplam){
	int loger=log10(x);
	return(toplam=toplam+ 1/x*loger );
							}

int logen(int x,int toplam){

	int logen=log(x);
	return(toplam=toplam+ 1/x*logen );

	
}
int terstrigon(int x,int toplam,char *abora){

	if (strstr(abora, "sin") != NULL){
		int sink=1/sqrt(1-x*x);
		return (toplam=toplam+sink);
		}
		
		else if (strstr(abora, "cos") != NULL){
		int cosk=-1/sqrt(1-x*x);
		return (toplam=toplam+cosk);
		}
		
		else if (strstr(abora, "tan") != NULL){
		int tank=1/(1+x*x);
		return toplam=toplam+tank;
		}

	else if (strstr(abora, "cot") != NULL){
		int cotk=1/tan(x);
		return toplam=toplam+cotk;
		}
}

int trigon(int x,int toplam,char *abora){

	if (strstr(abora, "sin") != NULL){
		int sink=cos(x);
		return toplam=toplam+sink;
		}
		
		else if (strstr(abora, "cos") != NULL){
		int cosk=-sin(x);
		return toplam=toplam+cosk;
		}
		
		else if (strstr(abora, "tan") != NULL){
		int tank=1/cos(x);
		tank=tank/cos(x);
		return toplam=toplam+tank;
		}

	else if (strstr(abora, "cot") != NULL){
		int cotk=1/cos(x);
		cotk=cotk/cos(x);
		cotk=1/cotk;
		return toplam=toplam+cotk;
		}
}
 

int liner(int x,int kontrol,int toplam){

	return(toplam=toplam+(kontrol*x));
}
