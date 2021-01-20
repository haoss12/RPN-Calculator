#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structures.h"
#include "functions.h"

int addition (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to add and the result*/
    if ((is_empty(stack)) != 0)
    {
        a = pop(stack);      /* here we are popping value from top of stack */
        b = pop(stack);
        result = a + b;
        push(stack, result); /* and here we are pushing our result on top of stack*/
        return result;       /* return used for debugging */
    }
    else
    {
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }
    
}

int subtraction (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to subtract and the result*/
    if ((is_empty(stack)) != 0)
    {
        a = pop(stack);      /* here we are popping value from top of stack */
        b = pop(stack);
        result = a - b;
        push(stack, result); /* and here we are pushing our result on top of stack*/
        return result;       /* return used for debugging */
    }
    else
    {
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }
    
}

int division (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to divide and the result*/
    if ((is_empty(stack)) != 0)
    {
        a = pop(stack);     /* here we are popping value from top of stack */
        if (a == 0)         /* checking denominator */
        {
            fprintf(stderr, "You cannot divide by zero!\n");
            push(stack, a); /* we can't divide so number is pushed back*/
            return 0;
        }
        else
        {
            b = pop(stack);
            result = b / a;
            push(stack, result); /* and here we are pushing our result on top of stack*/
            return result;       /* return used for debugging */
        }
    }
    else
    {
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }
}

int multiplication (stack_t *stack)
{
    int a, b, result;    /* variables to store factors to multiplicate and the result*/
    if ((is_empty(stack)) != 0)
    {
        a = pop(stack);      /* here we are popping value from top of stack */
        b = pop(stack);
        result = a * b;
        push(stack, result); /* and here we are pushing our result on top of stack*/
        return result;       /* return used for debugging */
    }
    else
    {
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }
}

