
#include <stdio.h>
#include <stdlib.h>


 
int theAge(int day,int month, int year, int today,int this_month, int this_year);
int daysLeft(int day,int month, int today,int this_month);

int main(int argc, char** argv) {

    int age = theAge(4, 7, 1984,22,2, 2017);
    int days = daysLeft(4, 7, 22, 2);
    printf("Days left to birthday %d, Age of the user %d    ",age,days);
    return 0;
}

int theAge(int day,int month, int year, int today,int this_month, int this_year ){
    return ( ( (today-day) + (this_month-month)*30 + (this_year-year)*365 )/365);
    
}

int daysLeft(int day,int month, int today,int this_month){
    
    return( (day-today)+(month-this_month)*30 );
}