/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: m
 *
 * Created on October 19, 2016, 9:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Draw_Triangle(int starting_point, int length, int layer_type);
void Draw_Rectangle(int starting_point, int length, int width, int layer_type);
void Draw_Triangle(int starting_point, int length, int layer_type);
void Draw_Circle(int center, int radius, int layer_type);
//Draw_Circle(int center, int radius, int layer_type);
/*
 * 
 */
int main(void) {
    int starting_point,length,width,layer_type;
   // Draw_Rectangle(6,4,6,2);
    //Draw_Triangle(10,9,2);
    Draw_Circle(3,3,1);
    return 0;
}

void Draw_Rectangle(int starting_point, int length, int width ,int layer_type){
    if(layer_type==1)
    {
    for(int i=0;i<width;i++){
        for(int l=0;l<starting_point;l++){
            printf(" ");          
        }
        
        if(i==0 || i==width-1){
            for(int boslukcu=0;boslukcu<length;boslukcu++){
                printf("*");
            }}
            else{
                for(int boslukcu=0;boslukcu<length;boslukcu++){
                    if(boslukcu==0 || boslukcu==length-1)
                        printf("*");
                    else
                        printf(" ");
                            
                    
                }
            }
        printf("\n");
        }
    }   
    
    else if(layer_type==2){
        width=width*layer_type;
        length=length*layer_type;
        for(int i=0;i<width;i++){
        for(int l=0;l<starting_point;l++){
            printf(" ");          
        }
        
        if(i==0 || i==width-1 || i==1 || i==width-2){
            for(int boslukcu=0;boslukcu<length;boslukcu++){
                printf("**");
            }}
            else{
                for(int boslukcu=0;boslukcu<length;boslukcu++){
                    if(boslukcu==0 || boslukcu==length-1)
                        printf("**");
                    else
                        printf("  ");
                            
                    
                }
            }
        printf("\n");
        }
        
    }
    
    
     
}

void Draw_Triangle(int starting_point, int length, int layer_type){
    if(layer_type==1){
        
    
    int counter=0;
      for(int boslukcu=0;boslukcu<starting_point;boslukcu++){
                printf(" ");}
                 printf("*\n");   
    for(int i=1;i<length;i++){
        
        int tempstart=starting_point;
        int tempstart2=starting_point;
        int tempfake=starting_point;
        tempstart=tempstart-counter;
       
        tempfake=counter;
                    
        
        
            while(tempstart>1){
                    printf(" ");
                    tempstart--;       }
            printf("*");
            while(tempfake>-1){
                if(i!=length-1)
                {printf("  ");}
                else
                    printf(" *");
                tempfake--;
            }
            
           
            printf("*");
            counter++;
             
    printf("\n");
        }
            
    }    
    else if(layer_type==2){
        
        
        
    int counter=0;
      for(int boslukcu=0;boslukcu<starting_point;boslukcu++){
                printf(" ");}
                 printf("*\n");   
    for(int i=1;i<length;i++){
        
        int tempstart=starting_point;
        int tempstart2=starting_point;
        int tempfake=starting_point;
        tempstart=tempstart-counter;
       
        tempfake=counter;
                    
        
        
            while(tempstart>1){
                    printf(" ");
                    tempstart--;       }
            printf("**");
            while(tempfake>-1){
                if(i!=length-1)
                {printf("  ");}
                else
                    printf(" **");
                tempfake--;
            }
            
           
            printf("**");
            counter++;
             
    printf("\n");
        }
    }
    
   
}

void Draw_Circle(int center, int radius, int layer_type){
    
    


    if(layer_type==1){
        
    int i,j;
    for (i=0; i<=2*radius; i++)
    {
        for (j=0; j<=2*radius; j++)
        {
            double distance = sqrt((double)(i-radius)*(i-radius) + (j-radius)*(j-radius));
            if (distance>radius-0.5 && distance<radius+0.5)
            {
                printf("*");
            }
            else
            { printf(" ");}
        }
        printf("\n");
    }
   
    }
    
    else if(layer_type==2){
        
    int i,j;
    for (i=0; i<=2*radius; i++)
    {
        for (j=0; j<=2*radius; j++)
        {
            double distance = sqrt((double)(i-radius)*(i-radius) + (j-radius)*(j-radius));
            if (distance>radius-0.5 && distance<radius+0.5)
            {
                printf(" **");
            }
            else
            { printf("  ");}
        }
        printf("\n");
    }
   
    }
    
    
}