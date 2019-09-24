#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "machinecode.h"
#include "test_machinecode.h"

#define TRUE  1
#define FALSE 0
#define MAX   20
#define MACHINE_CODE_LENGTH 32

// recursive function to get the binary
void inner(int num, char buffer[],  int base){
  
  char tmp[2]= {0};
  if(num <= 1 ){
    sprintf(tmp, "%d", num%2);
    strcat(buffer, tmp);
  }else{
    sprintf(tmp, "%d", num%2);
    strcat(buffer, tmp);
    inner(num/base,buffer, base);
  }
}

// function to 
char * itobi(int num,int base){

  char buffer[9];
  inner(num,buffer,base);

  char c[2];
  c[1]='\0';
  char *final= malloc(sizeof (char) * 9);
  for(int i = 7; i >= 0; i--){
    if(buffer[i]==0 ){
      c[0] = '0';
    } else
      c[0] = buffer[i];

    strcat(final,c);
  }
  /* printf("%s \n", final); */
  return final;
}


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
  char *t;
  // Get binary of op
  t = itobi(opNum,2);
  strcat(machine_code, t);
  free(t);
  // Get binary of rs
  t = itobi(rsNum,2);
  strcat(machine_code, t);
  free(t);
  t = itobi(rtNum,2);
  strcat(machine_code, t);
  free(t);
  t = itobi(rdNum,2);
  strcat(machine_code, t);
  free(t);

  // Print out the values to the screen
  printf("Operation: %s\n",op);
  printf("Rs:%s (R%d)\n",rs, rsNum);
  printf("Rt:%s (R%d)\n",rt, rtNum);
  printf("Rd:%s (R%d)\n",rd, rdNum);
  printf("Shamt: 0\n");
  printf("Funct: %d\n", opNum);
  printf("Machine Code: %s \n", machine_code);
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
  
  /* int n = 10; */
  /* char te[10] = {0}; */
  

  /* char * p = itobi(8,2);  */
  /* printf("8 : %s\n", p); */
  /* free(t); */
  // clear up the array
  /* memset(te, 0, 10*sizeof(te[0])); */
  /* itobi(2,te,2); */
  /* printf("output:%s \n", te); */
  /*  */
  /* arr_size = sizeof(te)/sizeof(te[0]); */
  /* printf("size of array:%d \n", arr_size); */
  /*  */
  /* printf("%d \n", te[7]); */

  /* printf("%s",itobi(12)); */
  /* getInput(); */
  return(0); 
}
