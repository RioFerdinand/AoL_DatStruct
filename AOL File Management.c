#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
//in each data, there is quantity, name, category
struct data{
    int quantity;
    char name[MAX];
    char category[MAX];
    int weight;
    struct data *next;    
    struct data *prev;
};

struct data *head, *newnode, *temp;
//Menu 
void menu(){
    printf("================================================");
    printf("================Warehouse Inventory=============");
    printf("1. Input Data");
    printf("2. View Data");
    printf("3. Delete Data");
    printf("================================================");

}
void createData(){
    newnode = (struct data*)malloc(sizeof(struct data));
    printf("Masukan Nama Barang: ");
    scanf("%s", newnode->name);
    printf("Jumlah Barang: ");
    scanf("%d", &newnode->quantity);
    printf("Berat Barang: ");
    scanf("%d", &newnode->weight);
    printf("Category Barang: ");
    scanf("%s", newnode->category);
    newnode->prev = NULL;
    newnode->next = NULL;
}
void input(){
    createData();
}

void deleteData(){

}

void display(){
    if (head == NULL){
        printf("Inventory Data is empty\n");
    }else{
        printf("Selet view method: ");
        printf("1. View all\n");
        printf("2. View by name\n");
        printf("3. View by category\n");
  
    }
}

int main(){
    int m;
    do
    {
        menu();
        do{
            printf(">>");scanf("%d",&m);
        }while(m > 9);
        switch(m){
            case 1:

                break;
            case 2:
                break;
            case 3:
                break; 
        }
    }while(m != 0);
}