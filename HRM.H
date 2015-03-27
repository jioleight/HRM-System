#ifndef __HRM_H
#define __HRM_H
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_IN_LEN 9
#define MAX_IN_LEN_P 16
#define MAX_IN 30
#define left 200
#define top 150
#define right 450
#define bottom 250

struct info_db
{
	char user_name[30], first_name[30], last_name[30];
	char gender[30], email[30], address[30], tel_no[30];
	struct info_db *n;
};

typedef struct info_db INFO;

LOGUI();
MENUGUI(char *user[MAX_IN_LEN]);
void LOGIN(char user[MAX_IN_LEN], char pass[MAX_IN_LEN_P]);

void add(INFO **new, INFO **start, INFO *tmp, char *user[MAX_IN_LEN]);
void insert(INFO ***new, INFO *tmp);
void create(INFO ***new, INFO ***start);
void display(INFO *start, INFO *tmp);
void checker(INFO *start, INFO *tmp);
char *search(INFO **tmp, INFO **prev, char *srch);
void edit(INFO *start, INFO *tmp);
void acc_user(char user[MAX_IN_LEN], char pass[MAX_IN_LEN_P]);
char *user_info(INFO **tmp, INFO **prev, char *srch);
void edit_user(INFO *start, INFO *tmp, char *user);

#endif