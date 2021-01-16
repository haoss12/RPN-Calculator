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
        new->value = given_value;
        new->next = stack->head;
        stack->head = new;
    }
}

int pop(stack_t *stack)
{
    lelem_t *temp;
    int out;
    if (stack->head == NULL)
    {
        fprintf(stdout, "Stack is empty!\n"); /* used temporary for debugging */
        return NULL;
    }
    else
    {
        temp = stack->head;
        out = temp->value;
        stack->head = temp->next;
        return out;
    }
}

int addition(stack_t *stack)
{
    int a, b, result;    /* variables to store factors to add and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = a + b;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int subtraction(stack_t *stack)
{
    int a, b, result;    /* variables to store factors to subtract and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = a - b;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int division(stack_t *stack)
{
    int a, b, result;    /* variables to store factors to divide and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = a / b;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int multiplication(stack_t *stack)
{
    int a, b, result;    /* variables to store factors to multiplicate and the result*/
    a = pop(stack);      /* here we are popping value from top of stack */
    b = pop(stack);
    result = a * b;
    push(stack, result); /* and here we are pushing our result on top of stack*/
    return result;       /* return used for debugging */
}

int main()
{
    int a, b, c, d ,e;
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
    temp = addition(stack);
    printf("%d\n", temp);
    temp = addition(stack);
    printf("%d\n", temp);
    return 0;
}
