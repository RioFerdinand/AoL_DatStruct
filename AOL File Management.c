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
void display(){
    int m;  
    if (head == NULL){
        printf("Inventory Data is empty\n");
    }else{
        printf("Selet view method: ");
        printf("1. View all\n");
        printf("2. View by name\n");
        printf("3. View by category\n");
        switch(m){
            case 1:
                displayAll();
                break;
            case 2:
                displayName();
                break;
        }
  
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