#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _score{
	char name[20];
	int score;

}Score;

int readTable(char filename[],Score table[],int *tableSize);
int writeTable(char filename[],Score table[],int tableSize);
void insertRow(Score row,Score table[],int *tableSize);
void insertRowAndSave(char filename[],Score row);
void Sort(Score table[],int tableSize);
void setRowValues(Score *row,char string[],int num);


int main(){
	Score table[10];
	Score row;
	int tableSize=0;

		readTable("table.txt",table,&tableSize);

			setRowValues(&row,"player99",60);

			insertRow(row,table,&tableSize);
		
	setRowValues(&row,"player22",70);
	insertRow(row,table,&tableSize);
	for(int i=0;i<10;i++)
			printf("%s %d\n",table[i].name,table[i].score);
	//writeTable("table.txt",table,tableSize);
	//readTable("table.txt",table,&tableSize);
	//setRowValues(&row,"player5",80);

	//insertRowAndSave("table.txt",row);


	return 0;
}
int readTable(char filename[],Score table[],int *tableSize){
	FILE *fp=fopen(filename,"r");
	int num=0;
	int i=0;
	char stri[20];
	if(fp==NULL)
		return -1;
	while(!feof(fp)){
		fscanf(fp,"%s",stri);
		fscanf(fp,"%d",&num);
		//fread(&table[i],sizeof(Score),1,fp);
		table[i].score=num;
		strcpy(table[i].name,stri);
		i++;
	}

	*tableSize=i-1;
	fclose(fp);
	return 0;
}


int writeTable(char filename[],Score table[],int tableSize){

	FILE *fp=fopen(filename,"w");
	int i=0;

	if(fp==NULL)
		return -1;
	while(i<tableSize){
		fprintf(fp,"%s %d\n",table[i].name,table[i].score);
		//fwrite(&table[i],sizeof(Score),1,fp);
		i++;
	}
	
	fclose(fp);
	return 0;
}


void insertRow(Score row,Score table[],int *tableSize){
	int i;
	int k=1;
	Sort(table,*tableSize);
	for(i=0;i<*tableSize;i++){
		if(table[i].score<row.score && *tableSize<10){
			table[*tableSize].score=row.score;
			strcpy(table[*tableSize].name,row.name);
			break;
		}
		else if(table[i].score<row.score){
			k=99;
		}

	}

	if(k==99){
		Sort(table,*tableSize);
		table[*tableSize].score=row.score;
		strcpy(table[*tableSize].name,row.name);
	}
	Sort(table,*tableSize);
}


void insertRowAndSave(char filename[],Score row){
	int tableSize;
	Score table[10];
	readTable(filename,table,&tableSize);
	insertRow(row,table,&tableSize);
	writeTable(filename,table,tableSize);
}

void Sort(Score table[],int tableSize){
	int i=0,j=0;
	int swap;
	char swa[20];
	for(;i<tableSize;i++){
		for(;j<tableSize;j++){
			if(table[j].score<table[i].score){
				strcpy(swa,table[j].name);
				strcpy(table[j].name,table[i].name);
				strcpy(table[i].name,swa);

				swap=table[i].score;
				table[j].score=table[i].score;
				table[j].score=swap;
			}
		}
	}
}

void setRowValues(Score *row,char string[],int num){
	strcpy(row->name,string);
	row->score=num;
}