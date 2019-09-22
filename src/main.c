#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "machinecode.h"
#include "test_machinecode.h"

#define TRUE  1
#define FALSE 0
#define MAX   20
#define MACHINE_CODE_LENGTH 32

int main(int argc, char **argv) {    

  /**
   * Taken for project 1
   * Just want to be check for a testing flag
   */
  int testing = FALSE, argIndex;

  for (argIndex=1; argIndex<argc && argv[argIndex][0]=='-'; argIndex++) {
    /* Check of the -t argv */
    switch (argv[argIndex][1]) {
      case 't':
        testing = TRUE;
        break;
      default:
        fprintf (stderr, "Invalid option \"%s\".\n", argv[argIndex]);
        fprintf (stderr, "Correct options are -t for testing\n");
        return (1); /** get out */
    }
  }

  /** If flag -t passed run tests */
  if(testing){
    test_all();
    return(0);
  }

  // declaring some buffers
  char input[MAX];
  char machine_code[MACHINE_CODE_LENGTH] = "0000000000000000000000";

  // Get input from user
  fgets(input, MAX, stdin);
  
  /**
   * Split the input string
   * add rs, rt, rd  -> "add rs" "rt" "rd"
   * Extra work needs to be done to get rs
   * add rs -> rs
   */
  char * op = strtok(input,",");
  char * rt = strtok(NULL,",");
  char * rd = strtok(NULL,",");
  // removing white spaces from 
  char * rs = strtok(op, " ");
  // overide rs because we want the second value
  rs = strtok(NULL," "); 

  /* char * rd = strtok(NULL,","); */
  printf("%s ", op);
  printf("%s ", rs);
  printf("%s ", rt);
  printf("%s \n", rd);
   /* getInstruction(); */
  int opNum = getOp(op);
  int rsNum = getReg(rs);
  int rtNum = getReg(rt);
  int rdNum = getReg(rd);


  // calculate machine code
  

  // Print out the values to the screen
  printf("Operation: %s\n",op);
  printf("Rs:%s (R%d)\n",rs, rsNum);
  printf("Rt:%s (R%d)\n",rt, rtNum);
  printf("Rd:%s (R%d)\n",rd, rdNum);
  printf("Shamt: 0\n");
  printf("Funct: %d\n", opNum);
  printf("Machine Code: %s \n", machine_code);
          

  return(0); 
}
