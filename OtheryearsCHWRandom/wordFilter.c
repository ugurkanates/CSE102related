#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM_WORDS 500
#define WORD_LENGTH 50

int getAndFilterWord(char * w);
void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],int occur[MAX_NUM_WORDS], int *
word_count);
void sortWords(char words[MAX_NUM_WORDS][WORD_LENGTH], int occur[MAX_NUM_WORDS],int
word_count);
int bosluk(char *w);

int main(){
    int i,j,z;
    char temp[WORD_LENGTH];
    char words[MAX_NUM_WORDS][WORD_LENGTH];
    int occur[MAX_NUM_WORDS];
    int word_count=0;
    char w[WORD_LENGTH];
    //getAndFilterWord(w);
    int empty;
    /* first loop is for kelime sayisi boyunca donsun diye iste bosluk+1 kelime olur */
    /*obuurde her kelime icin harfleri alip temp arraye atip ekleme fonksiyonu cagiriyo*/
    /*z degiskeni w'nin nin ilerleticisi o yüzden ikisindede arttirmam llazim */
    for(;;){
        fgets(w,WORD_LENGTH,stdin);
        getAndFilterWord(w);
        empty=bosluk(w);

        for(i=0,z=0;i<empty;i++,z++){

            for(j=0;w[z]!=' ';j++,z++){
                temp[j]=w[z];
            }
            if(strcmp(temp,"end")==0){
                sortWords(words,occur,word_count);
                printf("now going to print sorted matrix\n");
                printf("welcome to the matrix\n");
                printf("---------------- starting ------->>>\n");
                for(i=0;i<word_count;i++)
                    printf("%s\n",words[i]);
                return 55;
            }
            printf("'%s' going to be in call addWord function \n",temp);
            addWord(temp,words,occur,&word_count);
            memset(&temp,0, sizeof(temp));

        }
        for(j=0;w[z]!='\0';j++,z++){
            temp[j]=w[z];
        }
        if(strcmp(temp,"end")==0){
            sortWords(words,occur,word_count);
            printf("now going to print sorted matrix\n");
            printf("welcome to the matrix\n");
            printf("---------------- starting ------->>>\n");
            for(i=0;i<word_count;i++)
                printf("%s\n",words[i]);
            exit(-1);
        }
        printf("'%s' going to be in call addWord function \n",temp);

        addWord(temp,words,occur,&word_count);
        memset(&temp,0, sizeof(temp));
    }

    return 0;
}

int getAndFilterWord(char * w){

    int i,j;
    if(w==NULL)
        return 0;

    for(i = 0; w[i] != '\0'; ++i)
    {
        while (!( (w[i] >= 'a' && w[i] <= 'z') || (w[i] >= 'A' && w[i] <= 'Z') || w[i] == '\0' || w[i]==' ') )
        {
            for(j = i; w[j] != '\0'; ++j)
            {
                w[j] = w[j+1];
            }
            w[j] = '\0';
        }
    }
    /* this simply removes anything not alphabet or space((space for seperating words ;)*/
    for(i=0;w[i]!='\0';i++)
        if(w[i]>='A' && w[i]<='Z')
            w[i]=w[i]+('a'-'A');
        else
            continue;
    /*this changes uppercases to lower letters if not already */


    /*last part for removing too much space like 2 space if you delete a number 192 _space_ like deleteonethm */
    for(i = 0; w[i] != '\0'; ++i)
    {
        while (!( (w[i] >= 'a' && w[i] <= 'z') || (w[i] >= 'A' && w[i] <= 'Z') || w[i] == '\0' || (w[i]==' '
                                                                                                   && w[i+1]!=' ')) )
        {
            for(j = i; w[j] != '\0'; ++j)
            {
                w[j] = w[j+1];
            }
            w[j] = '\0';
        }
    }

    return 1;

}
void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],int occur[MAX_NUM_WORDS], int *
word_count){
    int i;

    for(i=0;i<5;i++){
        if(strcmp(w,words[i])==0){
            occur[i]++;
            return;
        }
    }
    strcpy(words[*word_count],w);
    occur[*word_count]++;
    *word_count+=1;




}
void sortWords(char words[MAX_NUM_WORDS][WORD_LENGTH], int occur[MAX_NUM_WORDS],int
word_count){
    int i,j;
    char swap[50];
    for(i=0;i<word_count-1;i++){
        for(j=0;j<word_count-1;j++){
            if(occur[j]>occur[i]){
                strcpy(swap,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],swap);
            }

        }
    }
}
int bosluk(char *w){
    if(w==NULL)
        exit(-1);

    int i,empty=0;
    for(i=0;w[i]!='\0';i++)
        if(w[i]==' '){
            empty++;
        }

    return empty;
}