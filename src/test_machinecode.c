#include <stdio.h>
#include "../src/machinecode.h"
#include "test_machinecode.h"

#define TRUE 1
#define FALSE 0

/** Simple test function taken from
 * https://repl.it/@fernandozamoraj/ThoughtfulBustlingSnowmonkey
 */
void test(int expected, int actual, const char* testName){
  if(expected == actual){
    printf("\nPASSED %s\n", testName);
  }
  else{
    printf("\nFAILED %s \n", testName);
    printf("  expected: %d actual: %d\n", expected, actual);
 } 
}

/**
 * Test getOp function
 * Makes sure that the right type of Funct is return
 */
void test_getOp(){
    test(32, getOp("add"), "getOp(ADD)");
    test(33, getOp("addu" ), "getOp(ADDU)");
    test(34, getOp("sub"), "getOp(SUB)");
    test(35, getOp("subu"), "getOp(SUBU)");
    test(36, getOp("and"), "getOp(AND)");
    test(37, getOp("or"), "getOp(OR)");
    test(39, getOp("nor"), "getOp(NOR)");
    test(42, getOp("slt"), "getOp(SLT)");
    test(43, getOp("sltu"), "getOp(SLTU)");
    test(0, getOp("sll"), "getOp(SLL)");
    test(2, getOp("srl"), "getOp(SRL)");
    test(8, getOp("jr"), "getOp(JR)");
    test(-1, getOp("bla bla"), "getOp(bla bla)");
}

/**
 * Test getOp function
 * Makes sure that the right type of Funct is return
 */
void test_getReg(){
    /** Check registers */
    test(0, getReg("zero"), "getReg(ZERO)");
    test(1, getReg("at"), "getReg(AT)");
    test(2, getReg("v0"), "getReg(V0)");
    test(3, getReg("v1"), "getReg(V1)");
    test(4, getReg("a0"), "getReg(A0)");
    test(5, getReg("a1"), "getReg(A1)");
    test(6, getReg("a2"), "getReg(A2)");
    test(7, getReg("a3"), "getReg(A3)");
    test(8, getReg("t0"), "getReg(T0)");
    test(9, getReg("t1"), "getReg(T1)");
    test(10, getReg("t2"), "getReg(T2)");
    test(11, getReg("t3"), "getReg(T3)");
    test(12, getReg("t4"), "getReg(T4)");
    test(13, getReg("t5"), "getReg(T5)");
    test(14, getReg("t6"), "getReg(T6)");
    test(15, getReg("t7"), "getReg(T7)");
    test(16, getReg("s0"), "getReg(S0)");
    test(17, getReg("s1"), "getReg(S1)");
    test(18, getReg("s2"), "getReg(S2)");
    test(19, getReg("s3"), "getReg(S3)");
    test(20, getReg("s4"), "getReg(S4)");
    test(21, getReg("s5"), "getReg(S5)");
    test(22, getReg("s6"), "getReg(S6)");
    test(23, getReg("s7"), "getReg(S7)");
    test(24, getReg("t8"), "getReg(T8)");
    test(25, getReg("t9"), "getReg(T9)");
    test(26, getReg("k0"), "getReg(K0)");
    test(27, getReg("k1"), "getReg(K1)");
    test(28, getReg("gp"), "getReg(GP)");
    test(29, getReg("sp"), "getReg(SP)");
    test(30, getReg("fp"), "getReg(FP)");
    test(31, getReg("ra"), "getReg(RA)");
    test(-1, getReg("bla"), "getReg(bla)");
}

/** Start testing functions **/
void test_all(){
    // test get input from stdin
    //test(-1, getOp("getReg()"), "getOp('')");

    // test all R-type functions
    //test_getOp();
    test_getReg();
}
