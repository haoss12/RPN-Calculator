#ifndef STRUCT_H
#define STRUCT_H

#define BUFFER_MAX 1024         /* max length of reading buffer */

typedef struct lelem
{
  //struct lelem *prev;         /* pointer for previous element in stack, not used at all */
    int value;                  /* usable value */
    struct lelem *next;         /* pointer for next element in stack */
} lelem_t;

typedef struct stack
{
    lelem_t *head;
} stack_t;


#endif