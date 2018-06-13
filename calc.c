    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>


    #define MAX_STACK_DEPTH 100
    static int stack[MAX_STACK_DEPTH];
    static int stackptr;

    /**************************************
    *  Internal Procedure Specifications  *
    **************************************/
            int   main(int,  char **);
    static  void  addNumbers(void);
    static  void  subNumbers(void);
    static  void  mulNumbers(void);
    static  void  divNumbers(void);
    static  void  push(int);
    static  int   pop();
    static  void  DisplaySyntax(void);


/******************************************************************************************
*   main: The main function of the program, which manages the execution of the project.   *
*   -argc: number of command line arguments.                                              *
*   -argv: list of pointers to the command line arguments.                                *
******************************************************************************************/

int main(int    argc,
         char **argv) {

    int number;
    char chr;
    char getExprChar();


    /*************************************
    *  Check the Command Line Arguments  *
    *************************************/  

    if (argc != 1) {
      DisplaySyntax();
    }

    // Initialize the stack. 
    stackptr = 0;


    /*************************************************
    *  Read the input expression and build the stack.*
    *************************************************/

    while (1) {
      chr = getExprChar();
      if (chr == 0) {
        break;
      }
      if ((chr >= '0') && (chr <= '9')) {
        push(chr - ('0'));
      }
      if (chr == '+') {
        addNumbers();
      }
      if (chr == '-') {
        subNumbers();
      }
      if (chr == '*') {
        mulNumbers();
      }
      if (chr == '/') {
        divNumbers();
      }
    }
    number = pop();
    printf("\nExpression = %d\n", number);

    /*************************************
    *  Finished.                         *
    *************************************/

    exit(EXIT_SUCCESS);

    return 0;
  }

/******************************************************************************************
*                                                                                         *
*   addNumbers: Perform addition operation for the given values.                          *
*                                                                                         *
******************************************************************************************/

static  void  addNumbers(void){
    int value1;
    int value2;

    value2 = pop();
    value1 = pop();
    push(value1 + value2);
}

/******************************************************************************************
*                                                                                         *
*   subNumbers: Perform subtracion operation for the given values.                        *
*                                                                                         *
******************************************************************************************/

static  void  subNumbers(void){
    int value1;
    int value2;

    value2 = pop();
    value1 = pop();
    push(value1 - value2);
}

/******************************************************************************************
*                                                                                         *
*   mulNumbers: Perform multiplication operation for the given values.                    *
*                                                                                         *
******************************************************************************************/

static  void  mulNumbers(void){
    int value1;
    int value2;

    value2 = pop();
    value1 = pop();
    push(value1 * value2);
}

/******************************************************************************************
*                                                                                         *
*   divNumbers: Perform division operation for the given values.                          *
*                                                                                         *
******************************************************************************************/

static  void  divNumbers(void){
    int value1;
    int value2;

    value2 = pop();
    value1 = pop();
    push(value1 / value2);
}


/******************************************************************************************
*                                                                                         *
*   push: adds "value" to the top of the stack.                                           *
*                                                                                         *
******************************************************************************************/

static  void  push(int value) {
    if (stackptr >= MAX_STACK_DEPTH) {
      exit(EXIT_FAILURE);
    }
    stack[stackptr++] = value;
}

/******************************************************************************************
*                                                                                         *
*   pop: adds "value" to the top of the stack.                                            *
*                                                                                         *
******************************************************************************************/

static  int   pop() {
    int value;

    if (stackptr == 0) {
      exit(EXIT_FAILURE);
    }
    value = stack[--stackptr];
    return value;
}



/******************************************************************************************
*                                                                                         *
*   Display Syntax: display error when not enough arguments are given.                    *
*                                                                                         *
******************************************************************************************/

static void DisplaySyntax() {
    fprintf(stderr, "calc: no arguments needed. \n");
    exit(EXIT_FAILURE);
}
