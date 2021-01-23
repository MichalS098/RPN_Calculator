#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/*------------------------------------------------------------*/
/*                                                            */
/* Module containing definitions of functions used in program */
/*                                                            */
/*------------------------------------------------------------*/

/* Stack functions: */

int push(t_stack **head, double data)
{
    t_stack *newElement = (t_stack *) malloc(sizeof(t_stack)); //creating new element
    if(newElement==NULL)
    {
        fprintf(stderr,"Error: stack overflow");
        return(1);
    }
    newElement->data = data;                                   
    newElement->next = *head;                                  //element behind newElement is element pointed by head
    *head = newElement;                                        //now pointer head points to newElement
    return (0);
}

double pop(t_stack **head)                                        //function that return value of the data stored at the start of stack
{
    if(isEmpty(*head)){                                        //checks if the stack is empty
        fprintf(stderr,"Error: The stack is empty, there is nothing to pop\n");
        return (EMPTY_STACK);
    }
    else{
        t_stack *temp=(t_stack *) malloc(sizeof(t_stack));     //creating temp structure to to be head
        temp=*head;
        double tempData=temp->data;            
        *head=(*head)->next;                                   //head starts to be an element behind him
        free(temp);                                            //deleting from memory first element of stack
        return (tempData);                                     //- and returning his value
    }
}

int isEmpty(t_stack *head)              
{
    return (head==NULL);                                //returning 1 when the stack is empty, or 0 when it is not
}

int printStack(t_stack *head)
{
    if(isEmpty(head)){                                        //checks if the stack is empty
        fprintf(stderr,"Error: The stack is empty\n");
        return (EMPTY_STACK);
    }
    else{
        t_stack *current = head;    //creating a temporary pointer to point on head
        for(int i=1; current != NULL; i++)
        {
            printf("Number %d is: %.4lf\n",i,current->data);
            current = current->next;                              //pointer points now to element behind him
        }
        return (0);
    }
}

int swap(t_stack **head)            //function to swap two last elements
{
    t_stack *temp = (*head)->next;  //creating temporary pointer to elem behind head
    if(temp==NULL)
    {
        fprintf(stderr,"Error: there is only one element in stack\n");
        return (1);
    }
    (*head)->next = (*head)->next->next; //head now is pointing to elem behind elem to swap                         
    temp->next = *head;                  //elem to swap is pointing to head
    *head = temp;                        //head is now swapped element
    return (0);
}

/* Other functions: */

void menu(void)
{
    printf("Welcome to reverse Polish notation calculator\n");
    printf("\tYour available options are :\n");
    printf("\tAdd number to the stack: just enter any number\n");
    printf("\tAdd negative number: enter '-' character and then enter number without space between\n");
    printf("\tPrint all stack: enter 'f'\n");
    printf("\tPrint last number on the stack: enter 'p'\n");
    printf("\tClear all stack: enter 'c'\n");
    printf("\tDelete last number on the stack: enter 'P'\n");
    printf("\tAdd numbers: '+'\n");
    printf("\tSubtract numbers: '-'\n");
    printf("\tMultiply numbers: '*'\n");
    printf("\tDivide numbers: '/'\n");
    printf("\tModulo operator: '%%'\n");
    printf("\tPower operator: '^'\n");
    printf("\tSquare root: 's'\n");
    printf("\tSwap two numbers: 'r'\n");
    printf("\tAdding number to memory: 'M+'\n");
    printf("\tRemoving number from memory: 'M-'\n");
    printf("\tClearing memory: 'MC'\n");
    printf("\tReceiving number from memory: 'MR'\n");
    printf("\tQuit program: 'q'\n");
}

int read(char **inputChar)    //function to read input from user and save it to two dimensional char array
{
    int i=0,j=0,k=0;
    char userInput[MAX_INPUT];

    scanf("%s",userInput);                      //reading input

    for (k = 0; userInput[k] != '\0'; k++)      //loop to insert input to array, where every space chararacter represent a new number or option
    {
        if (userInput[k]==' ')                  //if it is space move to another row in array
        {
            i++;
            j=0;
        }
        else                                    //if it is not a space, insert a character and increment array column index
        {
            inputChar[i][j++]=userInput[k];
        }
    }
    inputChar[++i][0]='\0';           
    return (0);
}