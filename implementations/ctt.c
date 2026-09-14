#include "headers/arena.h"
#include "headers/ctt.h"
#include <string.h>

char* copy_string(Arena *arena , char* const name){
    if( name == NULL ) return NULL;
    
    char* str = arena_allocate(arena,strlen(name) + 1);
    if( str == NULL ) {
        destroy_arena(arena);
        return NULL;
    }

    strcpy(str,name);
    return str;
}

Ctt *create_ctt(Arena *arena , char* const name , 
    int age, char* const phone){

        Ctt *new_ctt = arena_allocate(arena,sizeof(Ctt));
        
        if( new_ctt == NULL ) {
            destroy_arena(arena);
            return NULL;
        }

        new_ctt->name = copy_string(arena,name);
        
        if( new_ctt->name == NULL ){
            free(new_ctt);
            destroy_arena(arena);
            return NULL;
        }
        
        new_ctt->age = age;
        new_ctt->phone = copy_string(arena,phone);

        if( new_ctt->phone == NULL ){
            free(new_ctt->name);
            free(new_ctt);
            destroy_arena(arena);
            return NULL;
        }

        return new_ctt; 
    }


void print_out(Ctt *ctt)
{

    if( ctt ==  NULL ) return;

    printf("Name:%s\n",ctt->name);
    printf("Phone:%s\n",ctt->phone);
    printf("Age:%d\n",ctt->age);

    return;
}