#ifndef NODE_H
#define NODE_H
#include "headers/ctt.h"


typedef struct Node{
    Ctt value;
    struct Node *next;
}Node;

Node *create_node(Arena *arena,Ctt*value);
int age_sum(Node *head);


#endif 

