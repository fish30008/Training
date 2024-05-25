#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;

}Node;

void insert_end(Node** head, int x){
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

void deallocate(Node** head){
    Node* curr = 0;
    while(curr!= NULL){
        Node* aux = curr;
        curr = curr -> next; 
        free(aux); 
    }
    *head = NULL;
}


void insert_after(Node* node, int x){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        return 5;
    }
    new_node -> value = x;
    new_node -> next = node -> next;
    node -> next = new_node;
}


void insert_beginning(Node** root, int x){
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL ){
        exit (3);
    }
    new_node -> value = x;
    new_node -> next = *root;

    *root = new_node;
}
int main(){
 
    Node* node = NULL;
    
    insert_beginning(&node, 10);
    
    insert_end(&node, 5);
    insert_end(&node, 6);

    insert_after(node, 7);

    insert_beginning(&node, 11);

    printlist(node);

    deallocate(&node);
        return 0;
}