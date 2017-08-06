#include <stdio.h>
#include <stdlib.h>
  
typedef struct node {
  int value;
  struct node* next;
} Node;

/* Prototypes */

/* Add value to ordered linked list */
void add_value_to_linkedlist(Node** head, int value);

/* Assign values to array */
int *convert_to_dynamic_array(char *argv[], int argc, int *arraySize);

/* Print array values */
void print_dynamic_array(int arr[], int size);

/* Print values of linked list recursively */
void print_linkedlist(Node* current);

/* Add Nodes one by one */
Node* convert_dynamic_array_to_linkedlist(int arr[], int size);

/* Free allocated memory of linked list */
void delete_linkedlist(Node* current);

/* Main */
int main(int argc, char* argv[])
{
  int *dArray = NULL, arraySize; 
  Node* head = NULL;      
  
  /* assign console input values to dynamic array */
  dArray = convert_to_dynamic_array(argv, argc, &arraySize);  
  print_dynamic_array(dArray, arraySize);  
  
  /* print linked list as null */
  print_linkedlist(head);
  head = convert_dynamic_array_to_linkedlist(dArray, arraySize);
  free(dArray);
  
  /* print linked list as filled */
  print_linkedlist(head);

  /* deletes values one by one and prints linked list */ 
  delete_linkedlist(head);
  
  return 0;
}

/* Implementation part */

/* Add value to ordered linked list - 25 Points */
void add_value_to_linkedlist(Node** head, int value)
{
  Node* current, *before;

  /* Creating new node */
  Node* newNode = (Node *)malloc(sizeof(Node));
  if(newNode == NULL)
  {
    printf("Allocation error!\n");
    delete_linkedlist(*head);
    exit(1);   
  }
  newNode->value = value;
  
  /* Add Node to empty linked list */
  if(*head == NULL)
  {
    *head = newNode;  
    return;
  }
    
  current = *head;
  /* Loop to find place of new Node */
  while(current->next != NULL && current->value < value)
  {
    before = current;
    current = current->next;
  }
  
  if(current == *head && current->value >= value)
  {
    newNode->next = current;
    *head = newNode; /* Add new Node to head */
  } else if(current->value >= value){
    before->next = newNode;
    newNode->next = current; /* Add new Node to between Nodes */
  } else {
    current->next = newNode;
    current->next->next = NULL; /* Add new Node to tail */
  }
}

/* Assign values to array - 15 Points */
int* convert_to_dynamic_array(char *argv[], int argc, int *arraySize)
{
  int *dArray=NULL, i;
  *arraySize = argc - 1;
  
  /* allocate memory for dynamic array */
  dArray = (int *) malloc(sizeof(int)* (*arraySize));
  if(dArray == NULL)
  {
    printf("Allocation error!\n");
    exit(1);    
  }

  for(i=0; i<*arraySize; ++i)
  {
    dArray[i] = atoi(argv[i+1]);
  }
  
  return dArray;
}

/* Print array values */
void print_dynamic_array(int arr[], int size)
{
  int i;
  printf("Values: ");
  for(i=0; i<size; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

/* Print values of linked list recursively */
void print_linkedlist(Node* current)
{
  if(current == NULL)
  {
    printf("NULL\n");
    return;
  }
  printf("%d -> ", current->value);
  print_linkedlist(current->next);
}

/* Add Nodes one by one - 5 Points */
Node* convert_dynamic_array_to_linkedlist(int arr[], int size)
{
  Node* list = NULL;
  int i;
  for(i=0; i<size; ++i)
  {
    add_value_to_linkedlist(&list, arr[i]);
    print_linkedlist(list);
  }
  return list;
}

/* Free allocated memory of linked list - 5 Points */
void delete_linkedlist(Node* current)
{
  Node* other;
  if(current == NULL)
    return;
    
  other = current->next;
  free(current);
  print_linkedlist(other);
  delete_linkedlist(other);  
}
