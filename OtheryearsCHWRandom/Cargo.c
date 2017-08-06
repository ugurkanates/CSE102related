/* 
 * File:   Part2.c
 * Author: evren
 *
 * Created on May 25, 2015, 6:57 PM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int s_id;
    int r_id;
} Cargo_t;

typedef struct{
    int id;
    char name[20];
    char city[20];
    char address[50];
} Customer_t;


void create_customer_file(const char* f_name);
Cargo_t* read_cargos(const char* f_name, int* size);
void print_cargos(const Cargo_t cargos[], int size);
Customer_t* read_customers(const char* fName, int* size);
void print_customers(const Customer_t customers[], int size);
void print_cargo_with_name(Cargo_t cargo, const Customer_t customers[], int size);
Cargo_t* search_cargos(const Cargo_t cargos[], int size_cargo, const Customer_t customers[], int size_customers, const char* city, int* size_result);


const char* CUSTOMER_FILE = "Customers.bin";
const char* CARGO_FILE = "Cargos.txt";

/*
 * 
 */
int main() {
    Cargo_t* cargos;
    Customer_t* customers;
    Cargo_t* cargos_to_ist;
    
    int size_cargos, size_customers, size_ist;
    
    
    /*create_customer_file(CUSTOMER_FILE);*/
    
    cargos = read_cargos(CARGO_FILE, &size_cargos);
    print_cargos(cargos, size_cargos);
    
    customers = read_customers(CUSTOMER_FILE, &size_customers);
    print_customers(customers, size_customers);
    
    print_cargo_with_name(cargos[1], customers, size_customers);
    
    printf("\nCargos toIstanbul:\n");
    cargos_to_ist = search_cargos(cargos, size_cargos, customers, size_customers, "Istanbul", &size_ist);
    print_cargos(cargos_to_ist, size_ist);
    
    free(cargos);
    free(customers);
    free(cargos_to_ist);
    return (0);
}

void create_customer_file(const char* f_name){
    FILE* file;
    Customer_t customers[] = {
    {2, "Alcatel", "Istanbul", "Adr of Alcatel"}, 
    {1, "ASELSAN", "Ankara", "Adr of ASELSAN"}, 
    {5, "TBMM", "Ankara", "Adrr of TBMM"},
    {4, "THY", "Istanbul", "Addr of THY"}, 
    {3, "Izeltas", "Izmir", "Adr of Izeltas"},
    {0, "IzmirBel", "Izmir", "Ad of IzmirBel"},
    {7, "IGDAS", "Istanbul", "Ad of IGDAS"},
    {6, "ASTI", "Ankara", "Add of ASTI"}};
    
    file = fopen(f_name, "wb");
    fwrite((void*)customers, sizeof(Customer_t), 7, file);
    
    fclose(file);
}

Cargo_t* read_cargos(const char* f_name, int* size){
    int i=0;
    Cargo_t* cargos;
    FILE* file = fopen(f_name, "r");
 
    fscanf(file, "%d", size);
    
    cargos = (Cargo_t*)malloc(sizeof(Cargo_t)*(*size));
    while(fscanf(file, "%d %d %d", &cargos[i].id, &cargos[i].s_id, &cargos[i].r_id) != EOF)
        ++i;
    
    fclose(file);
    return cargos; 
}

void print_cargos(const Cargo_t cargos[], int size){
    int i;
    for(i=0; i<size; ++i)
        printf("Cargo id:%d,  Sender id:%d, Receiver id:%d\n", cargos[i].id, cargos[i].s_id, cargos[i].r_id);
}

Customer_t* read_customers(const char* fName, int* size){
    int s=0;
    Customer_t* customers;
    Customer_t skip[1];
    FILE* file = fopen(fName, "rb");
    
    while(fread(skip, sizeof(Customer_t), 1, file) == 1)
        ++s;
    printf("s:%d", s);
    
    *size=s;
    customers = (Customer_t*)malloc(sizeof(Customer_t)*s);
    rewind(file);
    
   fread(customers, sizeof(Customer_t), s, file);
        
   fclose(file);     
   return customers;
}


void print_customers(const Customer_t customers[], int size){
    int i;
    
    for(i=0; i<size; ++i)
        printf("id:%d\nname:%s\ncity:%s\nAddress:%s\n\n", customers[i].id, customers[i].name, customers[i].city, customers[i].address);
}

const char* get_name_ref(const Customer_t customers[], int size, int id){
    int i;
    for(i=0; i<size; ++i)
        if(customers[i].id == id)
            return customers[i].name;
    return NULL; /*not found*/
}

void print_cargo_with_name(Cargo_t cargo, const Customer_t customers[], int size){
    const char* s_name, *r_name; 
    s_name = get_name_ref(customers, size, cargo.s_id);
    r_name = get_name_ref(customers, size, cargo.r_id);
    
    if(s_name == NULL)
        s_name = "\0";
    if(r_name == NULL)
        r_name = "\0";
    
    printf("Cargo id: %d, from %s to %s\n", cargo.id, s_name, r_name);
}


Cargo_t* search_cargos(const Cargo_t cargos[], int size_cargo, const Customer_t customers[], int size_customers, const char* city, int* size_result){
    int id;
    int i, j, k=0;
    int s=0;
    Cargo_t* res;
    
    for(i=0; i<size_cargo; ++i)
        for(j=0; j<size_customers; ++j){
            if((cargos[i].r_id == customers[j].id) && (strcmp(customers[j].city, city) == 0))
                ++s;
        }
    
    *size_result = s;
    res = (Cargo_t*)malloc(sizeof(Cargo_t)*s);
    
    for(i=0; i<size_cargo; ++i)
        for(j=0; j<size_customers; ++j){
            if((cargos[i].r_id == customers[j].id) && (strcmp(customers[j].city, city) == 0))
                res[k++] = cargos[i];
        }
    
    return res;
    
}
