#include <stdio.h>
#include <stdlib.h>

typedef struct_node {
	int val;
	struct _node* next;
}Node;

void addToLast(Node *head,int val);
int addToIndex(Node **head,int val,int n);
void removeLast(Node *head);
int removeByIndex(Node **head,int n);
Node * arrayToLinkedList(int arr[],int size);
int main(){

	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	Node *list;
		list = arrayToLinkedList(arr,10);
		addToLast(list,10);
		removeLast(list);
		removeByIndex(&list,0);
		addToIndex(&list,0,0);
		removeByIndex(&list,4);
		addToIndex(&list,4,4);
		return 0;
}

Node* arrayToLinkedList(int arr[],int size){
	struct Node *donus=(struct Node*)malloc(sizeof(Node)*size);
	int i;
	for(i=0;i<size;i++){
		donus[i]->val=arr[i];
		donus[i]->next=donus[i+1];
	}
	

	


	free(donus);
	return donus;
}

void addToLast(Node *head,int val){
    struct Node *temp;
    temp= (struct Node *)malloc(sizeof(struct Node));
    temp->val=val;
    temp->next=head;

    free(temp);
}

int addToIndex(Node **head,int val,int n){


}

void removeLast(Node *head){


}

int removeByIndex(Node **head,int n){

}