#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct{
    unsigned char* buffer;
    size_t offset,max;
}Arena;

Arena *create_arena(size_t max);
void* arena_allocate(Arena *arena , size_t size);
void destroy_arena(Arena *arena);


#endif
