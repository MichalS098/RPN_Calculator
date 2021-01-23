#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    #define MAX_INPUT 1000       //defining max input to store from stdin
    #define EMPTY_STACK 2            //defining simple macros
    #define TRUE 1
    #define FALSE 0

    typedef struct stack{            //defining stack structure
        double data;
        struct stack *next;
    }t_stack;                        

    int push(t_stack **, double);       //functions declaration
    double pop(t_stack **);
    int isEmpty(t_stack *);
    int printStack(t_stack *);
    int swap(t_stack **);
    void menu(void);
    int read(char **);

#endif 