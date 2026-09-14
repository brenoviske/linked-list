#include "headers/arena.h"
#include "headers/ctt.h"
#include "headers/node.h"

// Creating here the program here

Node *create_node(Arena *arena, Ctt *value){
    if( arena == NULL || value == NULL) return NULL;

    Node *new_node = arena_allocate(arena,sizeof(Node));

    if( new_node == NULL ) return NULL;

    new_node->value = *value;
    new_node->next = NULL;
    return new_node;
}

int age_sum(Node *head){

    if( head == NULL ) return 0 ; 

    int total = 0 ;
    while(head!=NULL){
        total+=head->value.age;
        head = head->next;
    }
    return total;
}

