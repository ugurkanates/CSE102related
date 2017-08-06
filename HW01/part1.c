#define pi 3.14

#include <stdio.h>
#include <stdlib.h>

float diameter(float circumference);
float ageOfTree(float diameter , float growth_factor);

int main(int argc, char** argv) {
    float dia = diameter(60.5);
    float age = ageOfTree(dia, 4.5);   
    printf("dia is %.2f , tree age %.2f",dia,age);
    return 0;
}

float diameter(float circumference){
    
    return(circumference/pi);
}
float ageOfTree(float diameter , float growth_factor){
    
    return(diameter*growth_factor);
}