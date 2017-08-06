#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMELEN 50
#define MAXRECORD 500
/* c homework 8
for anything unknown please contact me via my mail adress
 uates@gtu.edu.tr
 linkedin:https://www.linkedin.com/in/u%C4%9Furkan-ate%C5%9F-333260119/
https://github.com/ugurkanates
 */

typedef struct person_s {
    int id;
    char name[NAMELEN];
} Person;

typedef struct record_s {
    int id;
    char number[NAMELEN];
} Record;

typedef struct Records_s {
    Record data[MAXRECORD];
    int size;
} Records;

typedef struct people_s {
    Person data[MAXRECORD];
    int size;
} People;

/* ========== IMPLEMENT THE FUNCTIONS BELOW ========== */
/*
	Write Records.data array to the filename.
	Note that file should be binary.
*/
void writeRecords(Records records, char* filename) {
    FILE *fp=fopen(filename,"wb");
    int i=0;

    if (!fp)
    {
        printf("Unable to open file!");
        exit (-1);
    }
    for(;i<records.size;i++)
        fwrite(&records.data[i], sizeof(Record),1, fp); //&records data i mi yoksa records.data mi sade?

    fclose(fp);
}

/*
	Reads Record structs from the binary file and places them to Records.data array.
	Note that the number of Record structs in the file is unknown.
*/
void readRecords(Records *records, char* filename) {
    FILE *fp=fopen(filename,"rb");
    Record temp;
    int i=0;
    if (!fp)
    {
        printf("Unable to open file!");
        exit (-1);
    }

    while(fread(&temp, sizeof(Record), 1, fp)!=0){
        //printf("temp id is %d , temp name is %s\n",temp.id,temp.number);
        records->data[i].id=temp.id;
        strcpy(records->data[i].number,temp.number);
        i++;
    }

    records->size=i;
    fclose(fp);
}

/*
	Write People.data array to the filename.
	Note that file should be binary.
*/
void writePeople(People people, char* filename) {
    FILE *fp=fopen(filename,"wb");
    int i=0;

    if (!fp)
    {
        printf("Unable to open file!");
        exit (-1);
    }
    for(;i<people.size;i++)
        fwrite(&people.data[i], sizeof(Record),1, fp); //&records data i mi yoksa records.data mi sade?

    fclose(fp);
}

/*
	Reads Person structs from the binary file and places them to People.data array.
	Note that the number of Person structs in the file is unkown.
*/
void readPeople(People *people, char* filename) {
    FILE *fp=fopen(filename,"rb");
    Record temp;
    int i=0;
    if (!fp)
    {
        printf("Unable to open file!");
        exit (-1);
    }

    while(fread(&temp, sizeof(Record), 1, fp)!=0){
        //printf("temp id is %d , temp name is %s\n",temp.id,temp.number);
        people->data[i].id=temp.id;
        strcpy(people->data[i].name,temp.number);
        i++;
    }

    people->size=i;
    fclose(fp);
}

/**
  * Reads the input file and constructs People and Records structs.
  	Note that each Record in Records is unique (should not present multiple times).
  */
int satir_sayisi(char *filename){
    FILE *fp = fopen(filename,"r");
    if (!fp)
    {
        printf("Unable to open file!");
        exit (-1);
    }
    char ch=0;
    int lines=0;

    if (fp == NULL){
        return 0;
    }
    lines++;
    while ((ch = fgetc(fp)) != EOF)
    {

        if (ch == '\n')
            lines++;
    }
    fclose(fp);
    return lines;
}
void read(char* filename, People *people, Records *records) {
    FILE *fp=fopen(filename,"r");
    int i;
    int x=0;
    int j=0;
    int num_sayac;
    char a[NAMELEN];
    char b[NAMELEN];
    int satir=-1;
    satir=satir_sayisi(filename)-1;
    for(i=0;i<satir;i++){ //j artirilmalimi burda emin olmali
        fscanf(fp,"%d%s%s%d",&people->data[i].id,a,b,&num_sayac);
        //printf("%d %s %s %d \n",people->data[i].id,a,b,num_sayac);
        for(x=0;x<num_sayac;x++,j++){
            fscanf(fp,"%s",records->data[j].number);
            records->data[j].id=people->data[i].id;
        }
        strcat(a," ");
        strcat(a,b);
        strcpy(people->data[i].name,a);
    }
    people->size=i;
    records->size=j;

    fclose(fp);
}

/* ========== IMPLEMENT THE FUNCTIONS ABOVE ========== */

void print(People people, Records records) {
    int i,j,found = 0;
    /* header */
    printf("%-5s %-30s %-20s\n", "ID","NAME","NUMBER(s)");
    /* line */
    for (i = 0; i < 57; ++i)
        printf("-");
    printf("\n");

    for (i = 0; i < people.size; ++i) {
        found = 0;
        printf("%-5d %-30s", people.data[i].id, people.data[i].name);
        for (j = 0; j < records.size; ++j) {
            if(records.data[j].id == people.data[i].id) {
                if(found)
                    printf("%36s", "");
                printf("%-20s\n", records.data[j].number);
                found = 1;
            }
        }
        printf("\n");
    }
}

int isPeopleEq(People ppl1, People ppl2) {
    int i;
    if(ppl1.size != ppl2.size)
        return 0;
    for (i = 0; i < ppl1.size; ++i)
        if(strcmp(ppl1.data[i].name,ppl2.data[i].name) ||
           ppl1.data[i].id != ppl2.data[i].id)
            return 0;
    return 1;
}

int isRecordsEq(Records rec1, Records rec2) {
    int i;
    if(rec1.size != rec2.size)
        return 0;
    for (i = 0; i < rec1.size; ++i)
        if(strcmp(rec1.data[i].number,rec2.data[i].number) ||
           rec1.data[i].id != rec2.data[i].id)
            return 0;
    return 1;
}



int main(int argc, char** argv) {
    People people1,people2;
    Records records1,records2;
    people1.size = 0;
    records1.size = 0;
    read(argv[1],&people1, &records1);
    print(people1, records1);
    writePeople(people1,"people.bin");
    writeRecords(records1,"records.bin");
    readRecords(&records2,"records.bin");
    readPeople(&people2,"people.bin");
    print(people2, records2);
    printf("%s\n", isRecordsEq(records1,records2) ? "RECORDS ARE SAME" : "RECORDS ARE DIFFERENT!");
    printf("%s\n", isPeopleEq(people1,people2) ? "PEOPLE ARE SAME" : "PEOPLE ARE DIFFERENT!");
    return 0;
}

