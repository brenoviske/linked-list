#include <stdlib.h>
#include <stddef.h>
#include "arena.h"

Arena *create_arena(size_t max){

    Arena *arena = malloc(sizeof(Arena));

    if( arena == NULL ) return NULL;

    arena->buffer = malloc(max);

    if( arena->buffer == NULL ) {
        free(arena);
        return NULL;
    }

    arena->offset = 0 ;
    arena->max = max;
    return arena;
}

void* arena_allocate(Arena *arena,size_t size){
    
    if( arena == NULL ) return NULL;

    if( arena->offset + size > arena->max) return NULL;

    void *ptr = arena->buffer + arena->offset;
    arena->offset+=size;
    return ptr;

}

void destroy_arena(Arena *arena ){
    if( arena == NULL ) return ;

    free(arena->buffer);
    free(arena);
    return;
}

