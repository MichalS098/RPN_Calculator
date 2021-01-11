/*--------------------------------------*/
/* Michal Stanislawski                  */
/* Nr indeksu: 259231                   */
/*                                      */
/*                                      */
/*                                      */
/*--------------------------------------*/

/* C calculator with GUI(graphical user interface) */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    t_stack *head=(t_stack *) malloc(sizeof(t_stack));    //creating a structure pointer which always will 
    head=NULL;                                            // -be pointing to the first element of stack
    int endProgram=0;                                     //aka boolean value to operate loop
    char inputChar;                                       //variable to store inputted character

    printf("Welcome to reverse Polish notation calculator.\n");
    printf("Click enter to start.\n");
    getchar();//waits for any key click

    while(endProgram == FALSE)                            //run loop as long as endProgram is equal to false
    {
        menu();                                           //printing menu with options
        scanf("%c",&inputChar);                           //reading input character
        switch(inputChar)
        {
            case '+':                                     //add option
            {
                if(head->next==NULL)      //checks if there is only one number in the stack and print error if it is
                    fprintf(stderr,"Error: there is only 1 number in the stack.");
                double n1=pop(&head);
                double n2=pop(&head);    
                double additionSum=n1+n2;
                push(&head, additionSum); //pushing sum to the stack
                printf("Result: %lf",head->data);
                break;
            }
            case '-':                                     //subtracting two numbers
            {
                if(head->next==NULL)
                    fprintf(stderr,"Error: there is only 1 number in the stack");
                double n1=pop(&head);
                double n2=pop(&head);
                double result=n2-n1; 
                push(&head, result);     //pushing result to the stack
                printf("Result: %lf",head->data);
                break;
            }
            case '*':                                     //multiplication of two elements
            {
                if(head->next==NULL)
                    fprintf(stderr,"Error: there is only 1 number in the stack");
                double n1=pop(&head);
                double n2=pop(&head);
                double result=n1*n2; 
                push(&head, result);     //pushing result to the stack
                printf("Result: %lf",head->data);
                break;
            }
            case '/':                                    //dividing two numbers
            {
                if(head->next==NULL)
                    fprintf(stderr,"Error: there is only 1 number in the stack");
                double n1=pop(&head);
                double n2=pop(&head);
                double result=n2/n1; 
                push(&head, result);     //pushing result to the stack
                printf("Result: %lf",head->data);
                break;
            }
            case '%':                                    //module operation
            {
                if(head->next==NULL)
                    fprintf(stderr,"Error: there is only 1 number in the stack");
                int n1=pop(&head);       //converting numbers to int 
                int n2=pop(&head);
                double result=n2%n1; 
                push(&head, result);     //pushing result to the stack   
                printf("Result: %lf",head->data);             
                break;
            }
            case '^':                                    //power operator
            {
                if(head->next==NULL)
                    fprintf(stderr,"Error: there is only 1 number in the stack");
                double n1=pop(&head);
                double n2=pop(&head);
                double result=pow(n2, n1); 
                push(&head, result);     //pushing result to the stack 
                printf("Result: %lf",head->data);               
                break;
            }
            case 's':                                    //square root of last element
            {
                double result=sqrt(pop(&head)); //returning sqarw root of last element in stack
                push(&head, result);     //pushing result to the stack                
                break;
            }
            case 'P':                                    //deleting last number added to stack
            {
                printf("Deleted last number on stack.\n");
                pop(&head);
                break;
            }
            case 'c':                                    //clearing all stack
            {
                while(head!=NULL)
                {
                    pop(&head);
                }
                printf("Stack has been cleared.\n");
                break;
            }
            case 'r':                                    //swapping two last element of stack
            {
                break;
            }
            case 'd':                                    //duplicate element on top of stack
            {
                push(&head, head->data);
                printf("Result: %lf",head->data);
                break;
            }
            case 'p':                                    //print last element on stack
            {
                printf("Last element on stack: %lf\n",head->data);
                break;
            }
            case 'f':                                    //printing full stack
            {
                printStack(head);
                break;
            }
            case '_':                                    //an prefix representing negative number
            {
                double number;
                scanf("%lf",&number);   //reading number
                number=(-number);      //converting it to negative
                push(&head, number);   //pushing it to the stack
                printf("Added &lf to the stack",number);
                break;
            }
            case 'q':                                    //quit program, equals end of loop
            {
                endProgram=1;
                printf("You've quitted the program, thank you for using it!\n");
                break;
            }
            default:                                    //if inputted character is not one of above it must be a number from 0 to 9
            {
                double inputNumb = (double)inputChar;//converting entered character to type double
                if(inputNumb>=0 && inputNumb<=9.0)
                {
                    push(&head, inputNumb);          //pushing converted character to the stack
                    printf("Added %lf to the stack",inputNumb);                    
                }
                else
                {
                    fprintf(stderr,"Error: you've entered wrong character!\n");
                }
                break;
            }
        }/*end of switch*/
    }/*end of loop*/
    exit (0);
}