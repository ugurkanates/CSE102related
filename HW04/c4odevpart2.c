
C program to compare two strings without using string functions



#include<stdio.h>

int stringCompare(char[],char[]);
int main(){

    char str1[100],str2[100];
    int compare;

    printf("Enter first string: ");
    scanf("%s",str1);

    printf("Enter second string: ");
    scanf("%s",str2);

    compare = stringCompare(str1,str2);

    if(compare == 1)
         printf("Both strings are equal.");
    else
         printf("Both strings are not equal");
 
    return 0;
}

int stringCompare(char str1[],char str2[]){
    int i=0,flag=0;
   
    while(str1[i]!='\0' && str2[i]!='\0'){
         if(str1[i]!=str2[i]){
             flag=1;
             break;
         }
         i++;
    }

    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         return 1;
    else
         return 0;

}

Sample output:
Enter first string: cquestionbank.blogspot.com
Enter second string: cquestionbank.blogspot.com
Both strings are equal.

C program to compare two strings without using string functions



#include<stdio.h>

int stringCompare(char[],char[]);
int main(){

    char str1[100],str2[100];
    int compare;

    printf("Enter first string: ");
    scanf("%s",str1);

    printf("Enter second string: ");
    scanf("%s",str2);

    compare = stringCompare(str1,str2);

    if(compare == 1)
         printf("Both strings are equal.");
    else
         printf("Both strings are not equal");
 
    return 0;
}

int stringCompare(char str1[],char str2[]){
    int i=0,flag=0;
   
    while(str1[i]!='\0' && str2[i]!='\0'){
         if(str1[i]!=str2[i]){
             flag=1;
             break;
         }
         i++;
    }

    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         return 1;
    else
         return 0;

}

Sample output:
Enter first string: cquestionbank.blogspot.com
Enter second string: cquestionbank.blogspot.com
Both strings are equal.

#include <stdio.h>
int findSubstring(char *str, char *substring);
void safer_gets(char *str, size_t max);
int main(void)
{
    char str[40], substr[40];
    printf("Enter the string: ");
    safer_gets(str, sizeof(str));
    printf("Enter the substring: ");
    saer_gets(substr, sizeof(str));
    printf("findSubstring(): %d\n", findSubstring(str, substr));
    return 0;
}
int findSubstring(char *str, char *substr)
{
    /* write your code here */
    int i = 0, j = 0;
    while ((*(str + j) != '\0')&&(*(substr + i) != '\0')) {
        if (*(substr + i) != *(str + j)) {
            j++;
            i = 0;
        }
        else {
            i++;
            j++;
        }
    }
    if (*(substr + i) == '\0')
        return 1;
    else
        return -1;
}
void safer_gets(char *str, size_t max)
{
    int i;
    fgets(str, max, stdin);
    for (i = 0; *(str + i) != '\0'; i++) {
        if (*(str + i) == '\n') {
            *(str + i) = '\0';
            break;
        }
    }
}

void to_upper(char *message) {
    while (*message) {
        if (*message >= 'a' && *message <= 'z')
            *message = *message - 'a' + 'A';
        message++;
    }   
}  
#include<stdio.h>
#include<string.h>
 
void concat(char[], char[]);
 
int main() {
   char s1[50], s2[30];
 
   printf("\nEnter String 1 :");
   gets(s1);
   printf("\nEnter String 2 :");
   gets(s2);
 
   concat(s1, s2);
   printf("nConcated string is :%s", s1);
 
   return (0);
}
 
void concat(char s1[], char s2[]) {
   int i, j;
 
   i = strlen(s1);
 
   for (j = 0; s2[j] != '\0'; i++, j++) {
      s1[i] = s2[j];
   }
 
   s1[i] = '\0';
}