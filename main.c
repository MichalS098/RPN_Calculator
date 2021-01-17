/*------------------------------------------*/
/* Michal Stanislawski                      */                    
/*                                          */
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
    t_stack *head=NULL;                                   //creating a structure pointer which always will be pointing to the first element of stack 
    t_stack *memoryStack=NULL;                            //pointer to memory stack
    int endProgram=0;                                     //'while loop' operator
    int i;                                                //'for loop' operator
    char **inputChar;                                     //2d array to store inputted character
    int number;                                           //variable to store inputted number

    menu();                                               //printing menu with described options for the user
    printf("Click enter to start.\n");
    getchar();//waits for any key click
    system("clear");                                      //clearing menu

    while(endProgram == FALSE)                            //run loop as long as 'endProgram' is equal to false
    {
        inputChar=(char **) malloc(MAX_INPUT_SIZE*MAX_INPUT_SIZE);//allocating memory for 2d char array
        for (int x=0; x < MAX_INPUT_SIZE; x++){
            inputChar[x] = (char*) malloc(MAX_INPUT_SIZE);
        }

        read(inputChar);                                  //reading user input

        for(i=0; inputChar[i][0]!='\0'; i++)              //run as long as we reach end of array
        {              
            if(isdigit(inputChar[i][0])){                 //checks if this is a number
                sscanf(inputChar[i],"%d",&number);        //converting char array to int
                push(&head, number);                      //pushing converted character to the stack
                number=0;                                 //empty number
            }
            else{                                         //if its not number then find if its one of the options
                switch(inputChar[i][0]){                  //switch managing input options of number operations on stack 
                    case '+':                                     //adding two numbers
                    {
                        if(head->next==NULL){ //checks if there is only one number in the stack and print error if it is
                            fprintf(stderr,"Error: there is only 1 number in the stack.\n");
                            break;
                        }
                        double n1=pop(&head);
                        double n2=pop(&head);    
                        double additionSum=n1+n2;
                        push(&head, additionSum); 
                        printf("Result: %.4lf\n",head->data);
                        break;
                    }
                    case '-':                                     //subtracting two numbers
                    {
                        if(head->next==NULL){
                            fprintf(stderr,"Error: there is only 1 number in the stack\n");
                            break;
                        }
                        double n1=pop(&head);
                        double n2=pop(&head);
                        double result=n2-n1; 
                        push(&head, result); 
                        printf("Result: %.4lf\n",head->data);
                        break;
                    }
                    case '*':                                     //multiplication of two elements
                    {
                        if(head->next==NULL){
                            fprintf(stderr,"Error: there is only 1 number in the stack\n");
                            break;
                        }
                        double n1=pop(&head);
                        double n2=pop(&head);
                        double result=n1*n2; 
                        push(&head, result); 
                        printf("Result: %.4lf\n",head->data);
                        break;
                    }
                    case '/':                                     //dividing two numbers
                    {
                        if(head->next==NULL){
                            fprintf(stderr,"Error: there is only 1 number in the stack\n");
                            break;
                        }
                        double n1=pop(&head);
                        double n2=pop(&head);
                        double result=n2/n1; 
                        push(&head, result); 
                        printf("Result: %.4lf\n",head->data);
                        break;
                    }
                    case '%':                                     //module operation
                    {
                        if(head->next==NULL){
                            fprintf(stderr,"Error: there is only 1 number in the stack\n");
                            break;
                        }
                        int n1=pop(&head);       //converting numbers to int 
                        int n2=pop(&head);
                        double result=n2%n1; 
                        push(&head, result);       
                        printf("Result: %.4lf\n",head->data);             
                        break;
                    }
                    case '^':                                     //power operator
                    {
                        if(head->next==NULL){
                            fprintf(stderr,"Error: there is only 1 number in the stack\n");
                            break;
                        }
                        double n1=pop(&head);
                        double n2=pop(&head);
                        double result=pow(n2, n1); 
                        push(&head, result);    
                        printf("Result: %.4lf\n",head->data);               
                        break;
                    }
                    case 's':                                     //square root of last element
                    {
                        double result=sqrt(pop(&head)); //returning sqare root of last element in stack
                        push(&head, result);         
                        printf("Result: %.4lf\n",head->data);               
                        break;
                    }
                    case 'P':                                     //deleting last number added to stack
                    {
                        printf("Deleted last number on stack.\n");
                        pop(&head);
                        break;
                    }
                    case 'c':                                     //clearing all stack
                    {
                        while(head!=NULL)
                        {
                            pop(&head);
                        }
                        printf("Stack has been cleared.\n");
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
                        push(&head, head->data);
                        printf("Duplicated element\n");
                        break;
                    }
                    case 'p':                                     //print last element on stack
                    {
                        printf("Last element on stack: %.4lf\n",head->data);
                        break;
                    }
                    case 'f':                                     //printing full stack
                    {
                        printStack(head);
                        break;
                    }
                    case '_':                                     //an prefix representing negative number
                    {
                        if(inputChar[i][1]==0){
                            fprintf(stderr,"There is no number entered, you need to enter for example '_2'\n");
                        }
                        else{
                            char temp[MAX_INPUT_SIZE]; //creating temporary array to store 'inputChar[i]' but without '_' character
                            for(int j=0; j<strlen(inputChar[i]); j++)
                            {
                                temp[j]=inputChar[i][j+1];
                            }
                            sscanf(temp,"%d",&number); //converting char (which user choose to be negative) to int 
                            number = (-number);        //converting it to negative
                            push(&head, number);       //pushing it to the stack
                            number=0;                  //empty variable
                        }
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
                            printf("Memory has been cleared.\n");
                        }
                        else if (inputChar[i][1]=='R'){           //receiving number from memory
                            if(isEmpty(memoryStack)){
                                fprintf(stderr,"Memory stack is empty there is nothing to pop\n");
                            }
                            else{
                                push(&head,pop(&memoryStack));    
                                printf("Added number from memory\n");
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
        for (int x=0; x<MAX_INPUT_SIZE; x++){   //deleting the array memory to make it empty
            free(inputChar[x]);
        }
        free(inputChar);
    }/*end of while */
    return (0);
}

