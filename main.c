#include "headers/arena.h"
#include "headers/ctt.h"
#include "headers/node.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

    Arena *arena = create_arena(1024);
    if( arena == NULL ) return EXIT_FAILURE;

    Ctt *new_ctt = create_ctt(arena,"Breno",22,"12991076796");
    
    Node *head = create_node(arena,new_ctt);

    destroy_arena(arena);
    return EXIT_SUCCESS;
    
}