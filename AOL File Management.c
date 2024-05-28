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
// Menu
void menu() {
    printf("================================================\n");
    printf("================Warehouse Inventory=============\n");
    printf("1. Input Data\n");
    printf("2. View Data\n");
    printf("3. Delete Data\n");
    printf("================================================\n");
}

void createData() {
    newnode = (struct data*)malloc(sizeof(struct data));
    printf("Masukan Nama Barang: ");
    scanf("%s", newnode->name);
    printf("\nJumlah Barang: ");
    scanf("%d", &newnode->quantity);
    printf("\nBerat Barang: ");
    scanf("%d", &newnode->weight);
    printf("Category Barang: ");
    scanf("%s", newnode->category);
    newnode->prev = NULL;
    newnode->next = NULL;
}

void insertDepan(){
    createData();
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Posisi barang telah masuk di depan\n");
}

void insertTengah(){
    int pos, i;
    printf("Masukan posisi barang masuk (dari 1): ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertDepan();
        return;
    }

    createData();
    temp = head;
    for (i = 1; i < pos - 1; i++) {
        if (temp != NULL) {
            temp = temp->next;
        } else {
            printf("Posisi barang tidak ditemukan.\n");
            free(newnode);
            return;
        }
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
    printf("Posisi barang telah masuk di tengah.\n");
}

void insertBelakang(){
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
    printf("Posisi barang telah masuk di belakang.\n");
}

void input(){
    createData();
}

void deleteData(){
    
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
