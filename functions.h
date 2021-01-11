#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    #define EMPTY_STACK 1            //defining simple macros
    #define TRUE 1
    #define FALSE 0

    typedef struct stack{            //defining stack structure
        double data;
        struct stack *next;
    }t_stack;                        

    int push(t_stack **, double);       //functions declaration
    double pop(t_stack **);
    int IsEmpty(t_stack *);
    int printStack(t_stack *);
    void menu(void);

#endif 