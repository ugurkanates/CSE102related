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
}
