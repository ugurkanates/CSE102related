//UGURKAN ATES 

// 151044012 Computer Engineer CS 102 Homework 07

//purpose: FINDING ERROR AND PRINTING EROR 
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
    int mailsize=1,mailsize1=1;
	int body=0,subject=0,eml=0;
	int i;
	//if last </email> occured body subject eml arent same then program not working. simply .
	

    if ((fptr = fopen("mail.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);    	     
    }
//int i = strcspn (str,"=");


    // reads text until newline 
	//the parts on check email
	printf("----------------------------------------------------------------------------------------------\n");
	printf("|#| subject                  |                                                        body  |\n");

   while (fgets(c,1000,fptr)!=NULL) {
     if(strcmp(c,"<email>")==0)
		eml+=strcmp(c,"<email>");
	 if(strcmp(c,"</email>")==0)
		eml+=strcmp(c,"</email>");
	 if(strcmp(c,"<Body>")==0)
		body+=strcmp(c,"<Body>");
	 if(strcmp(c,"</Body>")==0)
		body+=strcmp(c,"</Body>");
	 if(strcmp(c,"<Subject>")==0)
		subject+=strcmp(c,"<Subject>");
	 if(strcmp(c,"<Subject>")==0)
		subject+=strcmp(c,"</Subject>");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      	if(eml>0 && body>0 && subject>0)
		  printf("***ERROR HAS BEEN FOUND*** \n  there is an error in this line NUM : %d \n",mailsize); 
	if(strcspn(c,"<email>")!=0){
    	
		printf("|%d|%s",mailsize, c);
		
    	mailsize++;}
    									}
    									//printf("\n %d is EMAIL line size",mailsize);
	fclose(fptr);
    
     if ((f = fopen("token.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
	// The parts we check errors on token
    // reads text until newline 
    printf("\n \n \n");
	printf("-----------------------------------------------\n");
	printf("| # | TOKEN                    | Frequency | \n");
   while (fgets(c1,1000,f)!=NULL) {
	checkesit=strstr(c1,"=");
	 i = strcspn (c1,"=");
	//printf("%d bu indexi calisir",i);      
      	if(checkesit==NULL)
		  printf("***ERROR HAS BEEN FOUND*** \n  there is an error in this line NUM : %d \n",mailsize1);
	//checknum=strstr(c1,"1")
    //search for = , and number 
   // printf("%s", c1);
	printf("|%d|",mailsize1);
	for(int ik=0;ik<strlen(c1);ik++){		
		if(c1[ik]!=c1[i])
			printf("%c",c1[ik]);
		if(c1[ik]==c1[i] ){
			for(int j=0;j<strlen(c1);j++)			
				printf(" ");
		 }
	
									}
    mailsize1++;
    									}
    									//printf("\n%d is TOKEN line size\n",mailsize1);
	fclose(f);
	
    return 0;
}
