#ifndef CTT_H
#define CTT_H

#include "headers/arena.h"
typedef struct{
    
    char *name;
    int age;
    char *phone;

}Ctt;


char* copy_string(Arena *arena, char* const name);
Ctt *create_ctt(Arena *arena , char* const name , int age , 
    char* const phone); 
void print_out(Ctt *ctt);

#endif