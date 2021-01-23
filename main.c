/*------------------------------------------*/
/* Michal Stanislawski                      */                                           
/* 23.01.2021r.                             */
/* Documentation is in README file          */
/*                                          */
/*------------------------------------------*/

/* C calculator based on reverse Polish notation */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"

int main()
{
    t_stack *head=NULL;                                    
    t_stack *memoryStack=NULL;                            //pointer to memory stack
    int endProgram=FALSE;                                 //'while loop' operator
    char **inputChar;                                     //2 dim. array to store user input
    int number;                                           //variable to store inputted number

    menu();                                               //printing menu with described options for the user
    printf("Click enter to start\n");
    getchar();//waits for any key click
    system("clear");

    while(endProgram == FALSE)                            //run loop as long as 'endProgram' is equal to false
    {
        inputChar=(char **) malloc(MAX_INPUT*MAX_INPUT);  //allocating memory for 2 dim. char array
        for (int x=0; x < MAX_INPUT; x++){
            inputChar[x] = (char*) malloc(MAX_INPUT);
        }

        read(inputChar);                                  //reading user input

        for(int i=0; inputChar[i][0]!='\0'; i++)          //run as long as we reach end of array
        {              
            if(isdigit(inputChar[i][0])){                 //checks if this is a number
                sscanf(inputChar[i],"%d",&number);        //converting a line in a character array to int
                push(&head, number);                      //pushing converted character to the stack
            }
            else if(inputChar[i][0]=='-' && isdigit(inputChar[i][1])){  //checks if input starts with '-' if it's then push negative value            
                sscanf(inputChar[i],"%d",&number); //converting char to int 
                push(&head, number);      //pushing negative value
            }
            else{                                         //if its not number then find if its one of the options
                switch(inputChar[i][0]){                  //switch managing input options of number operations on stack 
                    case '+':                                     //adding two numbers
                    {
                        if(isEmpty(head) || head->next==NULL){
                            fprintf(stderr,"Error: there is no enough numbers in the stack\n");
                        }
                        else{
                            double n1=pop(&head);
                            double n2=pop(&head);    
                            double additionSum=n1+n2;
                            push(&head, additionSum); 
                        }
                        break;
                    }
                    case '-':                                     //subtracting two numbers
                    {
                        if(isEmpty(head) || head->next==NULL){
                            fprintf(stderr,"Error: there is no enough numbers in the stack\n");
                        }
                        else{
                            double n1=pop(&head);
                            double n2=pop(&head);
                            double result=n2-n1; 
                            push(&head, result); 
                        }
                        break;
                    }
                    case '*':                                     //multiplication of two elements
                    {
                        if(isEmpty(head) || head->next==NULL){
                            fprintf(stderr,"Error: there is no enough numbers in the stack\n");
                        }
                        else{
                            double n1=pop(&head);
                            double n2=pop(&head);
                            double result=n1*n2; 
                            push(&head, result); 
                        }
                        break;
                    }
                    case '/':                                     //dividing two numbers
                    {
                        if(isEmpty(head) || head->next==NULL){
                            fprintf(stderr,"Error: there is no enough numbers in the stack\n");
                        }
                        else{
                            double n1=pop(&head);
                            double n2=pop(&head);
                            double result=n2/n1; 
                            push(&head, result); 
                        }
                        break;
                    }
                    case '%':                                     //module operation
                    {
                        if(isEmpty(head) || head->next==NULL){
                            fprintf(stderr,"Error: there is no enough numbers in the stack\n");
                        }
                        else{
                            int n1=pop(&head);       //converting numbers to int 
                            int n2=pop(&head);
                            double result=n2%n1; 
                            push(&head, result);       
                        }
                        break;
                    }
                    case '^':                                     //power operator
                    {
                        if(isEmpty(head) || head->next==NULL){
                            fprintf(stderr,"Error: there is no enough numbers in the stack\n");
                        }
                        else{
                            double n1=pop(&head);
                            double n2=pop(&head);
                            double result=pow(n2, n1); 
                            push(&head, result);    
                        }
                        break;
                    }
                    case 's':                                     //square root of last element
                    {
                        if(isEmpty(head)){
                            fprintf(stderr,"Error: stack is empty there is no number to square\n");
                        }
                        else{
                            double result=sqrt(pop(&head)); //returning sqare root of last element in stack
                            push(&head, result);         
                        }
                        break;
                    }
                    case 'P':                                     //deleting last number added to stack
                    {
                        printf("Deleted last number on stack\n");
                        pop(&head);
                        break;
                    }
                    case 'c':                                     //clearing all stack
                    {
                        while(head!=NULL)
                        {
                            pop(&head);
                        }
                        printf("Stack has been cleared\n");
                        break;
                    }
                    case 'r':                                     //swapping two last element of stack
                    {
                        if(!swap(&head))                          //if correctly swapped print text
                        {
                            printf("Elements were swapped correctly\n");
                        }
                        break;
                    }
                    case 'd':                                     //duplicate element on top of stack
                    {
                        if(isEmpty(head)){
                            fprintf(stderr,"Error: stack is empty\n");
                        }
                        else{
                            push(&head, head->data);
                            printf("Duplicated element\n");
                        }
                        break;
                    }
                    case 'p':                                     //print last element on stack
                    {
                        if(isEmpty(head)){
                            fprintf(stderr,"Error: stack is empty\n");
                        }
                        else{
                            printf("Last element on stack: %.4lf\n",head->data);
                        }
                        break;
                    }
                    case 'f':                                     //printing full stack
                    {
                        printStack(head);
                        break;
                    }
                    case 'M':                                     //memory managment options
                    {
                        if(inputChar[i][1]=='+'){                 //adding elem to memory stack
                            if(isEmpty(head)){
                                fprintf(stderr,"There is nothing to add\n");
                            }
                            else{
                                push(&memoryStack, pop(&head));
                                printf("Added number to memory\n");
                            }
                        }
                        else if (inputChar[i][1]=='-'){           //deleting first number from memory
                            if(isEmpty(memoryStack)){
                                fprintf(stderr,"There is nothing to delete\n");
                            }
                            else{
                                pop(&memoryStack);
                                printf("Deleted number from memory\n");
                            }
                        }
                        else if (inputChar[i][1]=='C'){           //clearing memory stack
                            while(memoryStack!=NULL)
                            {
                                pop(&memoryStack);
                            }
                            printf("Memory has been cleared\n");
                        }
                        else if (inputChar[i][1]=='R'){           //receiving number from memory
                            if(isEmpty(memoryStack)){
                                fprintf(stderr,"Memory stack is empty there is nothing to pop\n");
                            }
                            else{
                                push(&head,pop(&memoryStack));    
                                printf("Returned number from memory\n");
                            }
                        }
                        else{
                            fprintf(stderr,"Error: Wrong memory option\n");
                        }
                        break;
                    }
                    case 'q':                                     //quit program, equals end of loop
                    {
                        endProgram = TRUE;
                        printf("You've quitted the program, thank you for using it!\n");
                        break;
                    }
                    default:                                      //printing error if the character is wrong
                    {       
                        fprintf(stderr,"Error: you've entered wrong character!\n");
                        break;
                    }
                }/* end of switch */
            }/* end of else */
        }/* end of for */
        for (int x=0; x<MAX_INPUT; x++){   //freeing the array memory to make it empty
            free(inputChar[x]);
        }
        free(inputChar);
    }/*end of while */
    return (0);
}

/* TESTY:















 */

