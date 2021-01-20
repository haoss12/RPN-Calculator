#include "structures.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void push (stack_t *stack, int given_value);
void duplicate (stack_t *stack);
int is_empty(stack_t *stack);
int pop (stack_t *stack);
void clear (stack_t *stack);
int stack_size (stack_t *stack);
void print(stack_t *stack);
void full_print(stack_t *stack, int size);
void reverse (stack_t *stack, int size);

#endif 