#include <stdio.h>
#include <stdlib.h>

int part1(void); 
double factorial(double n);
double turnradian(double n);
double power(double n,double us);
double sin(double n);

int main(void) {
	
	
	return 0;
}

int part1(void){
		double x=0;
		char answer='y';
		while(answer==y){
		printf("Hello please give angle to calculate it \n");
		scanf("%d",&x);
		double y=sin(x);
		printf("calculation of your input as sin is '%d' \n",y);
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
	return;
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
/*
#include <stdio.h>
#include <math.h>

long int factorial(int m)
{
    if (m==0 || m==1) return (1);
    else      return (m*factorial(m-1));
}
double power(double x,int n)
{
    double val=1;
    int i;
    for (i=1;i<=n;i++)
    {
        val*=x;
    }
    return val;
}

double sine(double x)
{
    int n;
    double val=0;
    for (n=0;n<8;n++)
    {
        double p = power(-1,n);
        double px = power(x,2*n+1);
        long fac = factorial(2*n+1);
        val += p * px / fac;
    }
    return val;
}

int main()
{
    double x;
    printf("Enter angles in degrees: ");
    scanf("%lf",&x);
    printf("\nValue of sine of %.2f is %.2lf\n",x,sine(x * M_PI / 180));
    printf("\nValue of sine of %.2f from library function is %.2lf\n",x,sin(x * M_PI / 180));
    return 0;
} */
