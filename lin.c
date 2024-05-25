#include<stdlib.h>
#include<stdio.h>

typedef struct Node{

    int x;
    struct Node* next;

}Node;




void insert(Node** node, int value){
    Node* next_node = malloc(sizeof(Node));
    if(next_node == NULL){
        exit(1);
    }
    next_node -> x = value;
    next_node -> next = NULL;

    if(*node == NULL){
        *node = next_node;
        return;
    }

    Node* curr = *node;
    while (curr->next != NULL){
        curr = curr -> next;
      
    }
    curr->next = next_node;
}



int main(){
    
    Node* node = NULL;

    insert(&node, 10);
    insert(&node, 11);
    
    for(Node* curr = node; curr != NULL; curr = curr->next){
        printf("%d\n", curr->x);
    }

    return 0;
}
