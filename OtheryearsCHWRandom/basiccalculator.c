/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.c
 * Author: m
 *
 * Created on October 6, 2016, 8:38 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*Ugurkan Ates homework01_part2.c
 * GTU-CE&Science Department
 * 151044012
 * tested and compiled on gcc linux mint
 * 
 * 
 */
int main() {
  
    char sign=0;
    int sayi=0;
    int toplam=0;
    
    
    while(sign!='='){
        scanf("%d",&sayi);
        scanf(" %c",&sign);
        
        if(sign=='+')
            toplam=sayi+toplam;
        else if(sign=='-')
            toplam=toplam-sayi;
        else if(sign=='*')
            toplam=toplam*sayi; 
        else if(sign=='/' && sayi!=0)
            toplam=toplam/sayi;   
        
    }
    printf("%d",toplam);
    return 0;
}
