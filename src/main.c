#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "machinecode.h"
#include "test_machinecode.h"

#define TRUE  1
#define FALSE 0
#define MAX   20
#define MACHINE_CODE_LENGTH 32



void getInput(){
  // declaring some buffers
  char input[MAX];
  char machine_code[MACHINE_CODE_LENGTH] = {0};

  // Get input from user
  fgets(input, MAX, stdin);

  char * op=NULL;
  char * rs=NULL;
  char * rt=NULL;
  char * rd=NULL;
  
  // split by ','
  op = strtok(input,",");
  rs = strtok(NULL, ",");
  // if Rs is NULL
  // then there are only two fields
  if(rs == NULL){
    rs = strtok(op," ");
    rs = strtok(NULL," "); // get second field
    rs = strtok(rs,"\n");  // get rid of '\n'
  }else { // get the rest of the fields
    rt = strtok(NULL,",");
    // take out '\n' 
    rt = strtok(rt,"\n"); 
    // take out the space
    rd = strtok(op," ");
    // get the second token
    rd=strtok(NULL," ");
  }

  int opNum = 0, rsNum=0, rtNum = 0, rdNum = 0;

  // If there are only two fields
  if(rt == NULL){
    rt = "0";
    rd = "0";
  }
  rtNum = getReg(rt);
  rdNum = getReg(rd);
  opNum = getOp(op);
  rsNum = getReg(rs);


  // calculate machine code
  

  // Print out the values to the screen
  printf("Operation: %s\n",op);
  printf("Rs:%s (R%d)\n",rs, rsNum);
  printf("Rt:%s (R%d)\n",rt, rtNum);
  printf("Rd:%s (R%d)\n",rd, rdNum);
  printf("Shamt: 0\n");
  printf("Funct: %d\n", opNum);
  printf("Machine Code: %s \n", machine_code);

}

void itobi(int num){

  int rem= num/10;
  printf("%d", rem);
  if(rem < 0 ){
    printf("done");
  }else{
    itobi(rem);
  }

}

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

  itobi(123);
  /* getInput(); */
  return(0); 
}
