#include <stdio.h>
#include <string.h>
#include "machinecode.h"

int getOp(char *instr){

  // init array
  char op[6] = {0};
  strcpy(op,instr);

  /** 
   * If an instruction is not passed
   * then ask the user
   * USED FOR TESTING PURPOSES
   */
  /* if(!strcmp("",instr)){ */
  /*   scanf("%s", op); */
  /* }else{ */
  /*   strcpy(op,instr); */
  /* } */

  
  /** check what instruction was passed */
  if(!strcmp("add", op)){ 
    return (32);
  }else if(!strcmp("addu", op)){
    return (33);
  }
  else if(!strcmp("sub", op)){
    return (34);
  }
  else if(!strcmp("subu", op)){
    return(35);
  }
  else if(!strcmp("and", op)){
    return(36);
  }
  else if(!strcmp("or", op)){
    return(37);
  }
  else if(!strcmp("nor", op)){
    return(39);
  }
  else if(!strcmp("slt", op)){
    return(42);
  }
  else if(!strcmp("sltu", op)){

    return(43);
  }
  else if(!strcmp("sll", op)){

    return(0);
  }
  else if(!strcmp("srl", op)){
    return(2);
  }
  else if(!strcmp("jr", op)){
    return(8);
  }
  else{
    return(-1); //not found
  }

  
  return -1;
}

int getReg(char *input){
 
  // init array
  char reg_in[6] = {0};
  strcpy(reg_in, input);
  
  // check what reg_inister was passed
  if(!strcmp("zero", reg_in)){ 
    return (0);
  }
  else if(!strcmp("0", reg_in)){
    return (0);
  }
  else if(!strcmp("at", reg_in)){
    return (1);
  }
  else if(!strcmp("v0", reg_in)){
    return (2);
  }
  else if(!strcmp("v1", reg_in)){
    return (3);
  }
  else if(!strcmp("a0", reg_in)){
    return (4);
  }
  else if(!strcmp("a1", reg_in)){
    return (5);
  }
  else if(!strcmp("a2", reg_in)){
    return (6);
  }
  else if(!strcmp("a3", reg_in)){
    return (7);
  }
  else if(!strcmp("t0", reg_in)){
    return (8);
  }
  else if(!strcmp("t1", reg_in)){
    return (9);
  }
  else if(!strcmp("t2", reg_in)){
    return (10);
  }
  else if(!strcmp("t3", reg_in)){
    return (11);
  }
  else if(!strcmp("t4", reg_in)){
    return (12);
  }
  else if(!strcmp("t5", reg_in)){
    return (13);
  }
  else if(!strcmp("t6", reg_in)){
    return (14);
  }
  else if(!strcmp("t7", reg_in)){
    return (15);
  }
  else if(!strcmp("s0", reg_in)){
    return (16);
  }
  else if(!strcmp("s1", reg_in)){
    return (17);
  }
  else if(!strcmp("s2", reg_in)){
    return (18);
  }
  else if(!strcmp("s3", reg_in)){
    return (19);
  }
  else if(!strcmp("s4", reg_in)){
    return (20);
  }
  else if(!strcmp("s5", reg_in)){
    return (21);
  }
  else if(!strcmp("s6", reg_in)){
    return (22);
  }
  else if(!strcmp("s7", reg_in)){
    return (23);
  }
  else if(!strcmp("t8", reg_in)){
    return (24);
  }
  else if(!strcmp("t9", reg_in)){
    return (25);
  }
  else if(!strcmp("k0", reg_in)){
    return (26);
  }
  else if(!strcmp("k1", reg_in)){
    return (27);
  }
  else if(!strcmp("gp", reg_in)){
    return (28);
  }
  else if(!strcmp("sp", reg_in)){
    return (29);
  }
  else if(!strcmp("fp", reg_in)){
    return (30);
  }
  else if(!strcmp("ra", reg_in)){
    return (31);
  } 
  else{ // not recognizable integer
    return(0);
  }

  return (0);
}
