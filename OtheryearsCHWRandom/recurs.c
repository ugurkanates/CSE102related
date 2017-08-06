#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANDOM -1
#define SIZE 99
char recur(char**x,int count);


int main(void) {
    //char const* const fileName ;//= argv[1]; /* should check that argc > 1 */
    FILE* file = fopen("maze.txt", "r"); /* should check the result */
    int line;
    //int **lineTUT;
    
    char is;
    int count = 0;
    do {
        fscanf(file, "%c", &is);
        if (is != ' ' && is != '\n') 
            count++;                
        

        }while (is != '\n');
        //fclose
       //int x[count][count]; 
      // x[0][0]=9;
       //x[0][28]=913;
      // printf("%d",x[0][28]);
/*
int **array = malloc(count * sizeof (*array)) + (count * (count * sizeof (**array)) );
array[0][0]=9;
        //printf("%d",array[0][0]);
*/      printf("count:   %d\n", count);
        char** x;

        x = malloc(count * sizeof(char*));
        for (int i = 0; i < count; i++) {
          x[i] = malloc(count * sizeof(char));
        }
        
        fclose(file);
         
       
        // re opening of function again !??
        FILE *filer = fopen("maze.txt", "r");
        is=0;
        fscanf(filer, "%c", &is);
        printf("%c calis",is);
        for(int p=0;p<count;p++){
            for(int c=0;c<count;c++){
                fscanf(filer, "%c", &is);
                if(is=='1' || is=='0')
                    x[p][c]=is;
                                    }
                                }
        //asci'0' cıkar
        fclose(filer);
        recur(x,count);
        free(x);               
        return 0;
    }

char recur(char**x,int count){
    
    if(x[0][0]=='0' && x[count][count]=='0'){
        printf("error");
        exit(1);
                    }
    
      if(x[0][1]=='0') 
          recur(x[0][1],count);
      else
          recur(x[1][0],count);
}