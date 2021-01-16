#ifndef STRUCT_H
#define STRUCT_H

typedef struct lelem
{
  //struct lelem *prev;         /* pointer for previous element in stack */
    int value;                  /* usable value */
    struct lelem *next;         /* pointer for next element in stack */
} lelem_t;

typedef struct stack
{
    lelem_t *head;
} stack_t;


#endif