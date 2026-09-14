#include "arena.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    Arena *arena = create_arena(1024);
    if(arena == NULL ) return EXIT_FAILURE;

    Node *head = create_node(arena,10);
    head->next = create_node(arena,20);
    
    int total = sum(head);

    printf("Total sum:%d\n",total);
    destroy_arena(arena);// Releasing the memory here;

    return EXIT_SUCCESS;
}