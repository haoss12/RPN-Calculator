#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structures.h"

/**************************************************
* push 
**************************************************/
void push (stack_t *stack, int given_value) 
{
    lelem_t *new = (lelem_t*) malloc(sizeof(lelem_t));  /*memory allocation for new element on stack*/
    if (stack->head == NULL)    /* if head==NULL then this is first element on stack */
    {
        new->value = given_value;   /* given value is now stored in our stack*/
        new->next = NULL;       /* pointer for next element is NULL because the is not any another element */
        stack->head = new;      /* stack head is now the new */
    }
    else
    {
        new->value = given_value;   /* given value is now stored in our stack*/
        new->next = stack->head;    /* pointer for next element is now pointer for head */
        stack->head = new;          /* head pointer is now the new pointer */
    }
}

void duplicate (stack_t *stack)
{
    lelem_t *temp;
    if (stack->head == NULL) /* there is no element on stack, so we cannot duplicate anything*/
    {
        fprintf(stderr, "Cannot duplicate, stack is empty!\n"); /* used temporary for debugging */
    }
    else
    {
        lelem_t *new = (lelem_t*) malloc(sizeof(lelem_t));  /*memory allocation for duplicated element on stack*/

        new->value = temp->value;   /* top value is now duplicated in our stack*/
        new->next = stack->head;    /* pointer for next element is now pointer for head */
        stack->head = new;          /* head pointer is now the new pointer */
    }
    
}

int is_empty(stack_t *stack) 
{
    if (stack->head == NULL) /* there is no element on stack, so it is empty*/
    {
        //fprintf(stderr, "Stack is empty!\n"); /* used temporary for debugging */
        return 0;   /* returning 0 for no element on stack */
    }
    else
    {
        return 1;   /* returning 1 when there is any element on stack */
    }
}

int pop (stack_t *stack)
{
    lelem_t *temp;
    int out;                    /* temporary variable to store popped number */
    if ((is_empty(stack)) == 1) /* checking if the stack is empty or not*/
    {
        temp = stack->head;     /* temporary pointer is now pointer for head*/
        out = temp->value;      /* int out is now equal to temp value*/
        stack->head = temp->next;   /* stack head is now next pointer, so we are losing stack top element */
        free(temp);
        return out;             /* here we are returning popped value*/
    }
    else                        /* there is no element on stack, so we cannot pop anything*/
    {
        fprintf(stderr, "Stack is empty!\n"); /* used temporary for debugging */
        return NULL;            /* returning NULL to tell the diference between proper and not proper pop*/
    }    
}

void clear (stack_t *stack)
{
    do
    {
        pop(stack); /* we are just popping out elements until stack is empty */
    } while ((is_empty(stack)) == 1);
}

int stack_size (stack_t *stack) /* this function count number of elements on stack */
{
    int size = 0;   /* variable to store size of stack */
    lelem_t *temp;  /* here we are initializing our stack */
    while (temp != NULL)
    {
        temp = temp->next;  /* in this loop we are just going to end of stack */
        size++;             /* and we increase 'size' variable */
    }
    temp = stack->head;     /* temp is back as our stack head */
    
    return size;            /* return size of stack */
}

void print(stack_t *stack)
{
    int pop_out;
    if ((is_empty(stack)) == 1)
    {
        pop_out = pop(stack);       /* here we are popping value from top of stack */
        printf("%d\n", pop_out);    /* we are printing it */
        push(stack, pop_out);       /* and we are pushing it back */
    }
    else                        /* there is no element on stack, so we cannot print anything*/
    {
        fprintf(stderr, "Stack is empty!\n"); 
    }
}

void full_print(stack_t *stack, int size) /* size is variable for stack size*/
{;
    int i;
    int *tab;
    tab = malloc(size * sizeof(int));   /*allocation space for temporary table */
    for(i=0; i<size; i++)
    { 
        tab[i]=pop(stack);          /* popping value into temp table*/           
        printf("%d\n", tab[i]);     /* printing this value */
        
    }
    i=i-1;                          /* decreasing 'i' because of indexing from 0 */
    for(i=i; i>=0; i--){                    
        push(stack, tab[i]);        /* pushing values back */
    }
    free(tab);
}

void reverse (stack_t *stack, int size) /* size is variable for stack size*/
{
    int a, b; 
    if (size >= 2)
    {
        a = pop(stack);
        b = pop(stack);
        push(stack, a);
        push(stack, b);
    }
    else
    {
        fprintf(stderr, "Too few elements on stack!");
    }
}