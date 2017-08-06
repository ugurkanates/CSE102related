#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sfrac.h"

char *sfrac_simplify(char * n);
char * sfrac_add(char * n1, char * n2);
char * sfrac_sub(char * n1, char * n2);
char * sfrac_negate(char * n);

char * sfrac_div(char * n1, char * n2);
char * sfrac_mult(char * n1, char * n2);
char * sfrac_div(char * n1, char * n2);
char * sfrac_fromdouble(double x,double y);
double sfrac_todouble(char * x);
void sfrac_print(char *a1, char *n1, char *a2, char *n2, char *a3, char *n3, char
*a4);
int GCD(int a, int b); // en buyuk orta bilen



int main(void){

char *n1 = "15/135";
char temp1[100];
char temp2[100];
int i=0;
int ikinci=0;
//sfrac_fromdouble(16.4);
//char *n2 = “1/4”;
 //printf("%c",n1[1]);
//sfrac_simplify(n1);
}


int GCD(int a, int b)
{
    while (b > 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

char *sfrac_simplify(char * n){

	//   / işaretine kadar bir kere gcd al, sonra bidaha gcd al geri koy.

	char temp1[25];
	char temp2[25];
	//char *temp3;
	double num1;
	double num2;
	int gcd=0;
	int i=0,ikinci=0;
    
		while(n[i]!='/'){

		temp1[i]=n[i];
		i++;
						}

		i+=1; // slash shouldnt be indexed
		while(n[i]!='\0'){

		temp2[ikinci]=n[i];
		i++;
                ikinci++;
						}
	//num1=sfrac_todouble(temp1);
	//num2=sfrac_todouble(temp2);
                num1=atoi(temp1);
                num2=atoi(temp2);
	gcd=GCD(num1,num2);
        printf("gcd kac %d",gcd);
	num1/=gcd;
	num2/=gcd;
        printf("ABBD");
        printf("%lf \n",num2);
	return(n);
		
}


 double sfrac_todouble(char * x){
   //  printf
     double ak=0;
     double bk=0;
     sscanf(x,"%lf/%lf",&ak,&bk);
     return ak/bk;
}

/*char * sfrac_add(char * n1, char * n2){
	//sfrac_simplify(n1);
	//sfrac_simplify(n2);


} */

char * sfrac_fromdouble(double x,double y){
    // x and y are denum and nomiators couldnt complete full algorithm
    //in this part  so had to change prototype of function to work
//    sprintf(temp,"%d",x); not working at moment
    //double first=0;
    //double second=0;
    char temp[15];
    temp[0]=x;
    temp[1]="/";
    temp[2]=y;
    return(temp);
    //return temp;
    //
                
    }
/*char * sfrac_add(char * n1, char * n2){
    double num1;
    double snum1;
    double num2;
    double snum2;
    double x;
    x=(snum2*num1+num2*snum1)/(num1*num2);
    sfrac_simplifiy(x);
//    return x;
    return n1;
} */
