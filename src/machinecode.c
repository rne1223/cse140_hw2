#include <stdio.h>
#include <string.h>
#include"machinecode.h"

int getOp(char *instr){

  // init array
  char reg[6] = {};

  /** 
   * If an instruction is not passed
   * then ask the user
   * USED FOR TESTING PURPOSES
   */
  if(!strcmp("",instr)){
    scanf("%s", reg);
  }else{
    strcpy(reg,instr);
  }

  
  /** check what instruction was passed */
  if(!strcmp("add", reg)){ 
    return (32);
  }else if(!strcmp("addu", reg)){
    return (33);
  }
  else if(!strcmp("sub", reg)){
    return (34);
  }
  else if(!strcmp("subu", reg)){
    return(35);
  }
  else if(!strcmp("and", reg)){
    return(36);
  }
  else if(!strcmp("or", reg)){
    return(37);
  }
  else if(!strcmp("nor", reg)){
    return(39);
  }
  else if(!strcmp("slt", reg)){
    return(42);
  }
  else if(!strcmp("sltu", reg)){

    return(43);
  }
  else if(!strcmp("sll", reg)){

    return(0);
  }
  else if(!strcmp("srl", reg)){
    return(2);
  }
  else if(!strcmp("jr", reg)){
    return(8);
  }
  else{
    return(-1);
  }

  
  return -1;
}

int getReg(char *reg){
  printf("%s", reg);

  printf("%s ", reg);

  // check what register was passed
  if(!strcmp("zero", reg)){ 
    return (0);
  }
  else if(!strcmp("at", reg)){
    return (1);
  }
  else if(!strcmp("v0", reg)){
    return (2);
  }
  else if(!strcmp("v1", reg)){
    return (3);
  }
  else if(!strcmp("a0", reg)){
    return (4);
  }
  else if(!strcmp("a1", reg)){
    return (5);
  }
  else if(!strcmp("a2", reg)){
    return (6);
  }
  else if(!strcmp("a3", reg)){
    return (7);
  }
  else if(!strcmp("t0", reg)){
    return (8);
  }
  else if(!strcmp("t1", reg)){
    return (9);
  }
  else if(!strcmp("t2", reg)){
    return (10);
  }
  else if(!strcmp("t3", reg)){
    return (11);
  }
  else if(!strcmp("t4", reg)){
    return (12);
  }
  else if(!strcmp("t5", reg)){
    return (13);
  }
  else if(!strcmp("t6", reg)){
    return (14);
  }
  else if(!strcmp("t7", reg)){
    return (15);
  }
  else if(!strcmp("s0", reg)){
    return (16);
  }
  else if(!strcmp("s1", reg)){
    return (17);
  }
  else if(!strcmp("s2", reg)){
    return (18);
  }
  else if(!strcmp("s3", reg)){
    return (19);
  }
  else if(!strcmp("s4", reg)){
    return (20);
  }
  else if(!strcmp("s5", reg)){
    return (21);
  }
  else if(!strcmp("s6", reg)){
    return (22);
  }
  else if(!strcmp("s7", reg)){
    return (23);
  }
  else if(!strcmp("t8", reg)){
    return (24);
  }
  else if(!strcmp("t9", reg)){
    return (25);
  }
  else if(!strcmp("k0", reg)){
    return (26);
  }
  else if(!strcmp("k1", reg)){
    return (27);
  }
  else if(!strcmp("gp", reg)){
    return (28);
  }
  else if(!strcmp("sp", reg)){
    return (29);
  }
  else if(!strcmp("fp", reg)){
    return (30);
  }
  else if(!strcmp("ra", reg)){
    return (31);
  } 
  else{ // not recognizable integer
    return(-1);
  }

  return (-1);
}
