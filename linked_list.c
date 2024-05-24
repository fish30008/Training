#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;

}Node;

void addnode(Node** head, int x){
    Node* nextnode = malloc(sizeof(Node));
    if(nextnode == NULL){
        exit(1);
    }
    nextnode->value = x;
    nextnode->next = NULL;
    
    if(*head == NULL){
        *head = nextnode;
        return;
    }
    Node* curr = *head;
    /**/
    while (curr->next != NULL){
        curr = curr -> next;
    }
    curr->next = nextnode;
}

void printlist(Node* head){
    for (Node* curr = head; curr !=NULL; curr = curr -> next ){
        printf("%d\n", curr->value);
    }
}


int main(){

    Node* node = NULL;
    
    addnode(&node, 5);
    addnode(&node, 6);

    printlist(node);
    return 0;
}