#ifndef COMPUTER_H
#define COMPUTER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>

#define N 100
#define Error_Adress -1
#define Error_Open_File -2
#define Error_File_Size -3

#define Flag_Reg_Size 5

#define BIT_CLEAR(A,B) (A = ((A) & ~(1 << (B)))) // î÷èòêà â íîëü âñå áèòû
#define BIT_SET(A,B) (A = ((A) | (1 << (B)))) //	óñòàíîâêà áèòà 
#define BIT_CHECK(A,B) (((A) >> B) & 0x1)   //	âîçâðàùàå 0 èëè 1(ëîãè÷åñêàÿ îïåðàöèÿ)
#define COMMAND_LENGTH 15

int sc_memoryInit();
int sc_memorySet(int, int);
int sc_memoryGet(int, int*);
int sc_memorySave(char*);
int sc_memoryLoad(char*);
int sc_regInit();
int sc_regSet(int, int);
int sc_regGet(int, int);
int sc_commandEncode(int, int, int*);
int sc_commandDecode(int, int*, int*);

int Mem_Mas[N];
int Mem_Flag;

#endif
