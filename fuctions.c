#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

/*------------------------------------------------------------*/
/*                                                            */
/* Module containing definitions of functions used in program */
/*                                                            */
/*------------------------------------------------------------*/


void main()
{
    printf("Options:\n");
    printf("Enter + to add\n");
    printf("Enter - to subtract\n");
    printf("Enter * to multiplicate\n");
    printf("E\n");
    printf("Options:\n");
    printf("Options:\n");
    printf("Options:\n");
    printf("Options:\n");
    printf("Options:\n");
    printf("Options:\n");

}

/* Stack functions: */

int push(t_stack **head, double data)
{
    t_stack *newElement = (t_stack *) malloc(sizeof(t_stack)); //creating new element
    newElement->data = data;                                   
    newElement->next = *head;                                  //element behind newElement is element pointed by head
    *head = newElement;                                        //now pointer head points to newElement
    return (0);
}

double pop(t_stack **head)                                        //function that return value of the data stored at the start of stack
{
    if(isEmpty(*head)){                                        //checks if the stack is empty
        fprintf(stderr,"The stack is empty, there is nothing to pop.\n");
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
    return (head->next==NULL);                                //returning 1 when the stack is empty, or 0 when it is not
}

int printStack(t_stack *head)
{
    if(isEmpty(head)){                                        //checks if the stack is empty
        fprintf(stderr,"The stack is empty.");
        return (EMPTY_STACK);
    }
    else{
        t_stack *current = (t_stack *) malloc(sizeof(t_stack));   //creating a temporary clone of head
        current = head;                                           // to iterate over it in the loop
        for(int i=1; current->next!=NULL; i++)
        {
            printf("Number in %d element is: %.4lf\n",i,current->next->data);
            current = current->next;                              //pointer points now to element behind him
        }
        return (0);
    }
}

/* Math functions: */