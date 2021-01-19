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
    int out;                    /* temporary variable to */
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

int stack_size (stack_t *stack) /* this fun*/
{
    int size;
    do
    {

        size++;
    } while ((is_empty(stack)) == 1);
}

void full_print(stack_t *stack)
{
    int *temp;
    int i;
    do
    {
        temp[] = (int *) malloc(sizeof(int));
        temppop(stack);
    } while ((is_empty(stack)) == 1);
}

int addition (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to add and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = a + b;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int subtraction (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to subtract and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = a - b;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int division (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to divide and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = b / a;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int multiplication (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to multiplicate and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = a * b;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int main ()
{
    int a, b, c, d, e, f;
    int pop_out = 0;
    int temp;
    stack_t *stack;
    stack->head = NULL;
    if ((pop_out = pop(stack))!=NULL)
        printf("%d\n", pop_out);
    scanf("%d %d %d", &a, &d, &e);
    push(stack, a);
    push(stack, d);
    push(stack, e);
    scanf("%d", &b);
    push(stack, b);
    scanf("%d", &c);
    push(stack, c);
    scanf("%d", &f);
    push(stack, f);
    clear(stack);
    /*
    duplicate(stack);
    if ((pop_out = pop(stack))!=NULL)
        printf("%d\n", pop_out);
    temp = addition(stack);
    printf("%d\n", temp);
    temp = addition(stack);
    printf("%d\n", temp);
    */
    temp = multiplication(stack);
    printf("%d\n", temp);
    
    return 0;
}
