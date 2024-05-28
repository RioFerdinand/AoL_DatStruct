#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
//in each data, there is quantity, name, category
struct data{
    int quantity;
    char name[MAX];
    char category[MAX];
    struct data *next;    
};

struct node *head, *node, *temp;
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
    
}
void input(){
    
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