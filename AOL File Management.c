#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
// In each data, there is quantity, name, category
struct data {
    int quantity;
    char name[MAX];
    char category[MAX];
    int weight;
    struct data *next;    
    struct data *prev;
};

struct data *head = NULL, *newnode, *temp;
//Menu 
void menu(){
    printf("================================================\n");
    printf("================Warehouse Inventory=============\n");
    printf("1. Input Data\n");
    printf("2. View Data\n");
    printf("3. Delete Data\n");
    printf("0. Exit\n");
    printf("================================================\n");

}
void createData() {
    newnode = (struct data*)malloc(sizeof(struct data));
    printf("Masukan Nama Barang: ");
    scanf("%s", newnode->name);
    printf("Jumlah Barang: ");
    scanf("%d", &newnode->quantity);
    printf("Berat Barang: ");
    scanf("%d", &newnode->weight);
    newnode->prev = NULL;
    newnode->next = NULL;
}



void inputData(){
    createData();
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Barang telah masuk ke dalam database\n");
}


void deleteData(){
    
}
void displayAll(){
    temp = head;
     printf("Name\t Quantity\t Weight\t Category\t\n");
    while(temp!=NULL){
        printf("%s\t %d\t %d\t %s\n",temp->name, temp->quantity, temp->weight, temp->category);
        temp = temp->next;
    }
}
void displayName(){
    temp = head;
    char ref[MAX];
    printf("Input the name of the item");
    scanf("%s", ref);
    printf("Name\t Quantity\t Weight\t Category\t\n");
    while (temp != NULL){
        if(strcmp(temp->name, ref)==0){
           printf("%s\t %d\t %d\t %s\n",temp->name, temp->quantity, temp->weight, temp->category);
        }
        temp = temp->next;
    }
}
void displayCategory() {
    temp = head;
    char ref[MAX];
    printf("Input the category of the item: ");
    scanf("%s", ref);
    printf("Name\t Quantity\t Weight\t Category\t\n");
    while (temp != NULL) {
        if (strcmp(temp->category, ref) == 0) {
            printf("%s\t %d\t %d\t %s\n", temp->name, temp->quantity, temp->weight, temp->category);
        }
        temp = temp->next;
    }
}
void display(){
    int m;  
    if (head == NULL){
        printf("Inventory Data is empty\n");
    }
    printf("Selet view method: \n");
    printf("1. View all\n");
    printf("2. View by name\n");
    printf("3. View by category\n");
    printf("Enter your input: ");
    scanf("%s", &m);
        switch(m){
            case 1:
                displayAll();
                break;
            case 2:
                displayName();
                break;
            case 3:
                displayCategory();
                break;
            
        }
}


int main(){
    int m;
    do
    {
        menu();
        printf(">>");scanf("%d",&m);
        
        switch(m){
            case 1:
                inputData();
                break;
            case 2:
                display();
                break;
            case 3:
                deleteData();
                break; 
            case 0:
                printf("Exiting...\n");
            default:
                printf("Invalid Choice");
        }
    }while(m != 0);
}
