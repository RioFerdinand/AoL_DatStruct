#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
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
    printf("================Warehouse Inventory=============\n");
    printf("1. Input Data\n");
    printf("2. View Data\n");
    printf("3. Delete Data\n");
    printf("4. Export Data to CSV\n");
    printf("0. Exit\n");
    printf("================================================\n");

}

void inputData() {
    char itemName[MAX];
    int itemQuantity, itemWeight;
    char itemCategory[MAX];

    printf("Masukan Nama Barang: ");
    scanf("%[^\n]", itemName);
    printf("Jumlah Barang: ");
    scanf("%d", &itemQuantity);
    printf("Berat Barang: ");
    scanf("%d", &itemWeight);
    printf("Kategori Barang: ");
    scanf("%[^\n]", itemCategory);

    temp = head;
    //mengecek apabila ada data yang sama, data akan diperbarui jumlahnya dan beratnya
    while (temp != NULL) {
        if (strcmp(temp->name, itemName) == 0) {
            temp->quantity += itemQuantity;
            temp->weight += itemWeight;
            printf("Jumlah barang telah diperbarui.\n");
            return;
        }
        temp = temp->next;
    }

    newnode = (struct data*)malloc(sizeof(struct data));
    strcpy(newnode->name, itemName);
    newnode->quantity = itemQuantity;
    newnode->weight = itemWeight;
    strcpy(newnode->category, itemCategory);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL){
        head = newnode;
    }else{
        newnode -> next = head;
        head = newnode;
    }
    printf("Barang telah masuk ke dalam database\n");
}
//delete seesuai nama
void deleteName() {
    if (head == NULL) {
        printf("No such item inside the inventory\n");
        return;
    }
    char delName[MAX];
    printf("Enter the name of the item to delete: ");
    scanf("%[^\n]", delName);

    temp = head;
    while (temp != NULL && strcmp(temp->name, delName) != 0) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Item not found\n");
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    printf("Item has been deleted successfully\n");
}
//implementasi stack
void checkout(){
      if (head == NULL){
        printf("No such item inside the inventory\n");
        return;
    }

    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("Item has been deleted successfully\n");
}
//menu delete data
void deleteData(){
       int c;  
    if (head == NULL){
        printf("Inventory Data is empty\n");
        return;
    }
    printf("Select view method: \n");
    printf("1. Check out\n");
    printf("2. Delete by name\n");
    printf("Enter your input: ");
    scanf("%d", &c);
    
    switch(c){
        case 1:
            checkout();
            break;
        case 2:
            deleteName();
            break;
        default:
            printf("Invalid Choice\n");
            break;
    }
    
}
//display seluruh inventory berdasarkan barang yang paling baru di masukan
void displayAll() {
    if (head == NULL) {
        printf("Inventory Data is empty\n");
        return;
    }

    temp = head;
    printf("Name\t\tQuantity\tWeight\tCategory\n");
    while (temp != NULL) {
        printf("%s\t\t%d\t\t%d KG\t%s\n", temp->name, temp->quantity, temp->weight, temp->category);
        temp = temp->next;
    }
}
//mengdisplay data sesuai dengan nama yang dicari
void displayName(){
    if (head == NULL) {
        printf("Inventory Data is empty\n");
        return;
    }

    temp = head;
    char ref[MAX];
    printf("Input the name of the item: ");
    scanf("%[^\n]", ref);
    printf("Name\t Quantity\t Weight\t Category\n");
    while (temp != NULL){
        if(strcmp(temp->name, ref) == 0){
            printf("%s\t %d\t\t %d KG\t %s\n", temp->name, temp->quantity, temp->weight, temp->category);
        }
        temp = temp->next;
    }
}
//mengdisplay data yang kategorinya sama
void displayCategory() {
    if (head == NULL) {
        printf("Inventory Data is empty\n");
        return;
    }

    temp = head;
    char ref[MAX];
    printf("Input the category of the item: ");
    scanf("%[^\n]", ref);
    printf("Name\t Quantity\t Weight\t Category\n");
    while (temp != NULL) {
        if (strcmp(temp->category, ref) == 0) {
            printf("%s\t %d\t\t %d KG\t %s\n", temp->name, temp->quantity, temp->weight, temp->category);
        }
        temp = temp->next;
    }
}
//menu display
void display(){
    int c;  
    if (head == NULL){
        printf("Inventory Data is empty\n");
        return;
    }
    printf("Select view method: \n");
    printf("1. View all\n");
    printf("2. View by name\n");
    printf("3. View by category\n");
    printf("Enter your input: ");
    scanf("%d", &c);
    
    switch(c){
        case 1:
            displayAll();
            break;
        case 2:
            displayName();
            break;
        case 3:
            displayCategory();
            break;
        default:
            printf("Invalid Choice\n");
            break;
    }
}
//melakukan export to csv (masih ada bug)
void exportToCSV(){
    FILE *fp = fopen("Inventory.csv","w");
    if (fp == NULL){
        printf("failed to make a file\n");
    }
    fprintf(fp, "Name,Quantity,Weight,Category\n");
    temp = head;
    while (temp != NULL) {
        fprintf(fp, "%s,%d,%d,%s\n", temp->name, temp->quantity, temp->weight, temp->category);
        temp = temp->next;
    }
    
    fclose(fp);
    printf("Data has been exported to inventory.csv successfully.\n");
}
//main
int main(){
  int m;
    do{
        menu();
        do{
            printf(">>> ");
            scanf("%d", &m);   
               }while(m > 4);
    switch(m) {
        case 1:
           inputData();
           break;
        case 2:
           display();
           break;
        case 3:
           deleteData();
           break;
        case 4:
            exportToCSV();
            break;
        case 0:
            printf("BYE BYE!\n");
            break;
        default:
           printf("Waduh ga ada pilihannya cok\n");
           break;
    }
  }while(m !=0);
 return 0;   
}