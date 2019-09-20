#include <stdio.h> 
#include <string.h>

/**
 * Reads in a string from stdin
 * Detects the operation
 * Returns an the interger that suppose to Funct
 */
int getOp(){

  // 5 characters to represent the operation + \n
  char input[6]; 
  // read in the operation from stdin
addu sub subu and or nor slt sltu sll srl jr
  // detect what operation is by comparing strings
  if (!strcmp("add", input)){
    printf("you typed ADD ");
  }else if (!strcmp("", input)){
    printf("");
  }else if (!strcmp("", input)){
    printf("");
  }else if (!strcmp("", input)){
    printf("");
  }else if (!strcmp("", input)){
    printf("");
  }else if (!strcmp("", input)){
    printf("");
  }else if (!strcmp("", input)){
    printf("");
  }else if (!strcmp("", input)){
    printf("");
  }else if (!strcmp("", input)){
    printf("");
  return (-1);
}

int getReg(){

  // 5 characters because of $zero
  char reg[6]; 
  // read in the operation from stdin
  scanf("%s",reg);
  printf("%s ", reg);
  //drop the ',' if it has one
  /* if(input[strlen(input)-1] == ','){ */
  /*   input[strlen(input)-1] = 0; */
  /* } */
  // string comparisons again
  /* if (!strcmp("t0", input)){ */
  /*   printf("you typed t0 "); */
  /* }else{ */
  /*   printf("you didn't typed t0"); */
  /* } */
  /*  */
  return (-1);
}

int main() {    
  int op = getOp();
  int rs = getReg();
  int rt = getReg();
  int rd = getReg();
  // get the op from inpug
  /* int op = getOp(); */
  /* int rs = getReg(); */
  /* int rt = getReg(); */
  /* int rd = getReg(); */

  return(0); 
}
