#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"
#include "functions.h"
#include "operations.h"

int main ()
{
    char *buffer = malloc(BUFFER_MAX * sizeof(char)); /* allocating memory for reading buffer*/
    int i;              /* int to use for "for" loop */
    int to_push;        /* variable to store element to push */
    int temp;           /* temporary variable for some functions */
    int buffersize = 0; /* variable for our buffer size */
    stack_t stack;      
    stack.head = NULL;  /* initialization of stack */
   
    do
    {
        scanf("%s", buffer);                /* reading the buffer from user */
        buffersize = (strlen(buffer));      /* calculating buffer length... */
        for (i = 0; i < buffersize; i++)    /* ...to use it in this loop    */
        {
            if ((isdigit(buffer[i]))!=0)    /* checking if there is any digit in our buffer */
            {
                to_push = atoi(buffer);     /* converting char to int with atoi */
                push(&stack, to_push);      /* pushing given value on stack */
                if (to_push>9 || to_push<-9)    /* if it is two digit number we are skipping next value from buffer */
                {                               /* just because we've already read it with atoi */     
                    i++;                        
                }
                if (to_push>99 || to_push<-99)  /* and same situation with three digit numbers */
                {                                
                    i++;                        
                }
            }
            else                            /* its not a digit in our buffer, so we are     */
            {                               /* searching for another options or operations  */
                switch (buffer[i])
                {
                case 'P':                   /* pop case */
                    pop(&stack);
                    break;
            
                case 'p':                   /* print case */
                    print(&stack);
                    break;
                
                case 'f':                   /* full print case */
                    temp = stack_size(&stack); //here we are getting size of our stack
                    full_print(&stack, temp);
                    break;
                
                case 'r':                   /* reverse case */
                    temp = stack_size(&stack); //here we are getting size of our stack
                    reverse(&stack, temp);
                    break;

                case 'c':                   /* clearing case */
                    clear(&stack);
                    break;

                case 'd':                   /* duplicating case */
                    duplicate(&stack);
                    break;

                case '+':                   /* addition case */
                    addition(&stack);
                    break;

                case '-':                    /* substraction case */
                    if (isdigit(buffer[i+1]) == 0) //here we are checking if it isnt a number
                    {
                        subtraction(&stack);
                    }
                    break;

                case '/':                   /* division case */
                    division(&stack);
                    break;
                    
                case '*':                   /* multiplication case */
                    multiplication(&stack);
                    break;

                case 'q':                   /* quitting case :) */
                    printf("Calculator has finished running! \n");
                    return 0;
                    break;    

                default:
                    printf("Wrong option! \n");
                    break;
                }
            }  
        }     
    } while (buffer[i] != 'q');

    return 0;
}


/****
Hubert Orda, 259268

Program napisalem wraz z "dokumentacja" w jezyku angielskim jako forme
sprawdzenia siebie, mam nadzieje, ze nie bedzie to stanowilo problemu przy
ocenianiu go ;)

Program to prosty kalkulator 4-dzialaniowy, z oblsuga liczb calkowitych
maksymalnie trzycyfrowych. Funckje dostepne dla uzytkownika, poza 
operatorami matematyczymi, to: (d)uplicate, (p)rint, (P)op, (r)everse,
(f)ullprint, (c)lear oraz (q)uit.

Przetestowalem program na dwoch prywatnych komputerach oraz na serwerze
diablo, kompilowal sie poprawnie, z dwoma warningami. Jeden z nich zostal 
przeze mnie zostawiony celowo, drugiego nie potrafilem sie pozbyc. Z tego
co zauwazylem nie mialo to wplywu na niepozadane dzialanie

W kodzie widac jak rozwiazalem kwestie rozroznienia minusow jako operatorow
oraz jako symbolow znakow. Rozwiazanie te jest nieco prymitywne, ale nie 
znalazlem innych funkcji w bibliotece standardowej, ktore moglyby mi pomoc.

Testy programu:

Nie bede rozpisywal sie na temat testow, bo nie ma po co, podstawowe funckje
kalkulatora dzialaja poprawnie, funckje sa odporne na bledy takie jak np.
proba dzielenia przez 0, dodawanie badz odejmowanie liczb bez wczesniejszego
wprowadzenia tychze, czy tez uzywanie funkcji takich jak reverse, ktore wymagaja
przynajmniej dwoch liczb, gdy tych liczb nie ma.

Moge stwierdzic, ze program dziala poprawnie i zgodnie z oczekiwaniami. 

*****/