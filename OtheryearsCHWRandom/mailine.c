#include <string.h>
#include <stdio.h>
#include <stdlib.h> // For exit() function
int main()
{
    char c[1000],c1[1000];
    FILE *fptr;
    FILE *f;
    char *checkesit=NULL;
    char *checknum=NULL;
    int mailsize=0,mailsize1=0;

    if ((fptr = fopen("mail.txt", "r")) == NULL)
    {
      //  printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }

    // reads text until newline 
   while (fgets(c,1000,fptr)!=NULL) {
      

    //printf("%s", c);
    mailsize++;
    									}
    									printf("\n x%d is mail line size",mailsize);
	fclose(fptr);
    
     if ((f = fopen("token.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }

    // reads text until newline 
    printf("\n \n \n");
   while (fgets(c1,1000,f)!=NULL) {
	checkesit=strstr(c1,"=");      
      	if(checkesit==NULL)
		  exit(1);
	//checknum=strstr(c1,"1")
    //search for = , and number 
    //printf("%s", c1);
    mailsize1++;
    									}
    		//							printf("\n x%d is mail line size",mailsize1);
	fclose(f);
	int d;
	int array[]={23,34,12,17,204,99,16};
	for (d=-1;d<=5;d++)
		printf("%d\n",array[d+1]);
    return 0;
}
