#ifndef __HRM_H
#define __HRM_H
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include "HRM.H"
#define MAX_IN_LEN 9
#define MAX_IN_LEN_P 16

LOGUI();
MENUGUI(char user[MAX_IN_LEN], char pass[MAX_IN_LEN_P]);
void LOGIN(char user[MAX_IN_LEN], char pass[MAX_IN_LEN_P]);

#endif