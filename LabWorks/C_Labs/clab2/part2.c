#include <stdio.h>
#include <stdlib.h>
char* append(char str1[],char str2[]);
int roman(int num,char romanstr[]);
int main(){

	char romanstr[255]="\0";
	int dec=58;

	
		if(roman(dec,romanstr))
			printf("%d\n",dec);
		else
			printf("unable\n");
	 for(int i=0;i<10;i++)
	 	printf("%c kacinci , %d\n",romanstr[i],i);
	return 0;
}

char* append(char str1[],char str2[]){

   int i, j;
 
   for(i=0;str1[i]!='\0';i++){

   }


   for(j=0;str2[j]!='\0';j++,i++){
   		str1[i]=str2[j];
   }
   str1[i]='\0';
   return str1;


}

int roman(int num,char romanstr[]){
	int del[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	char test[255]="\0";
	char *sym[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int i = 0;                  
	if(num<=0)
		return 0;
    printf("\n test %s \n",romanstr);    
    while (num){                
        while (num/del[i]){      
            append(romanstr, sym[i]); 
            num -= del[i];       
        }
        i++;                    
    }

    


	while(num>0){

		if(num>=1000){
				append(test,"M");
				num=num-1000;
		}

		else if(num>500 && num<900){
						append(test,"D");
						num=num-500;
		}
		else if(num>=900 && num<1000){
						append(test,"MC");
						num=num-900;
		}

		else if(num>=100 && num<400){
						append(test,"CM");
						num=num-100;
		}
		else if(num>=400 && num<500){
						append(test,"DC");
						num=num-400;

		}


		else if(num>50 && num<90){
						append(test,"L");
						num=num-50;

		}
		else if(num>=90 && num<100){
						append(test,"XC");
						num=num-90;

		}

		else if(num>10 && num<40){
						append(test,"XL");
						num=num-10;
		}

		else if(num>5){
						append(test,"V");
						num=num-5;

		}

		else if(num<4){
						append(test,"I");
						num=num-1;
		}


	} 



	return 1;
}