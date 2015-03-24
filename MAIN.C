/*	
 *	File: main.c
 *	Description: Handles log-in, main menu and GUI/TUI
 *	Programmer: Oji Leightton Vynn-Z Bucad
 *	Date Created: 03/18/2015 
 */

#include "HRM.H"

main()
{
	char user[8], pass[16];
	int count, input;
	clrscr();
	
	LOGUI();

	getch();
	closegraph();
	return 0;
}

LOGUI()
{
	char user[MAX_IN_LEN], pass[MAX_IN_LEN_P], hid[MAX_IN_LEN_P];
	int gd = DETECT, gm, c, in_s = 0, in_e = 0;
	initgraph(&gd, &gm, "s:\\turboc\\BGI");
	
	cleardevice();
	
	setbkcolor(GREEN);
	/*Main pane*/
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	bar(140, 90, 510, 300);
	/*Title Bar*/
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(140, 90, 510, 115);
	/*Log-in pane*/
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(left, top, right, bottom);
	/*Log-in Field*/
	setfillstyle(SOLID_FILL, WHITE);
	bar(250, 175, 400, 190);
	/*Password Field*/
	setfillstyle(SOLID_FILL, WHITE);
	bar(250, 225, 400, 240);
	
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	rectangle(140, 90, 510, 300);
	rectangle(left, top, right, bottom);
	
	setcolor(DARKGRAY);
	outtextxy(150, 100, "WELCOME TO HUMAN RESOURCES MANAGEMENT SYSTEM");
	
	setcolor(WHITE);
	outtextxy(210, 160, "LOG-IN AS: ");
	outtextxy(210, 210, "PASSWORD: ");
	
	/*Cleaner*/
	for(c = 0; c < MAX_IN_LEN && MAX_IN_LEN_P; c++)
	{
		user[c] = NULL;
		pass[c] = NULL;
		hid[c] = NULL;
	}
	
	/*LOGIN FIELD*/
	do
	{
		setcolor(RED);
		outtextxy(255, 180, user);
		c = getche();
		switch (c)
		{
			case 8: /* backspace */
				if (in_s)
				{
					in_s--;
					user[in_s] = 0;
					/*Log-in Field*/
					setfillstyle(SOLID_FILL, WHITE);
					bar(250, 175, 400, 190);
				}
				break;
			case 13: /* return */
				in_e = 1;
				break;
			case 27: /* Escape = Abort */
				user[0] = 0;
				in_e = 2;
				break;
			default:
				if (in_s < MAX_IN_LEN - 1 && c >= ' ' && c <= '~')
				{
				user[in_s] = c;
				in_s++;
				user[in_s] = 0;
				}
		}
	}while(!in_e);
	
	/*Aborting Half-way*/
	if(in_e == 2)return 0;
	
	/*Empty Field*/
	if(strlen(user) == NULL)
	{
		setcolor(RED);
		outtextxy(300, 260, "INVALID!!");
		getch();
		LOGUI();
	}
	
	/*Set to NULL to avoid errors*/
	in_e = NULL;
	in_s = NULL;
	c = NULL;
	
	/*PASS FIELD*/
	do
	{
		setcolor(RED);
		
		outtextxy(255, 230, hid);
		
		c = getch();
		switch (c)
		{
			case 8: /* backspace */
				if (in_s)
				{
					in_s--;
					hid[in_s] = 0;
					pass[in_s] = 0;
					/*Password Field*/
					setfillstyle(SOLID_FILL, WHITE);
					bar(250, 225, 400, 240);
				}
				break;
			case 13: /* return */
				in_e = 1;
				break;
			case 27: /* Escape = Abort */
				pass[0] = 0;
				in_e = 2;
				break;
			default:
				if (in_s < MAX_IN_LEN_P - 1 && c >= ' ' && c <= '~')
				{
					hid[in_s] = '*';
					pass[in_s] = c;
					in_s++;
					hid[in_s] = 0;
					pass[in_s] = 0;
				}
		}
	}while(!in_e);
	
	/*Empty Field Pass*/
	if(strlen(pass) == NULL)
	{
		for(c = 0; c < MAX_IN_LEN; c++)
		{
			user[c] = NULL;
		}
		setcolor(RED);
		outtextxy(300, 260, "INVALID!!");
		getch();
		LOGUI();
	}
	LOGIN(user, pass);
}
MENUGUI(char *user[MAX_IN_LEN])
{
	int i = 0, y1 = 0, y2 = 0, usr = NULL, c, s = 1, z = 0;
	char k = ' ', q, tmp_pass[MAX_IN_LEN];
	FILE *f,*t, *fp; 
	INFO *new=NULL,*start=NULL,*tmp, data; 
	INFO **pnew=&new,**pstart=&start;
	
	usr = strcmp(user, "admin");
	cleardevice();
	/*Main pane*/
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	bar(50, 50, 600, 450);
	/*Title Bar*/
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(50, 50, 600, 85);
	/*Selection pane*/
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(80, 120, 210, 350);
	/*Output pane*/
	setfillstyle(SOLID_FILL, MAGENTA);
	bar(250, 120, 560, 400);
	/*INFO Field*/
	setfillstyle(SOLID_FILL, WHITE);
	bar(250, 120, 560, 140);

	/*Borders*/
	setcolor(WHITE);
	rectangle(50, 50, 600, 450);
	setcolor(LIGHTGRAY);
	rectangle(250, 120, 560, 400);
	rectangle(80, 120, 210, 350);
	
	setcolor(DARKGRAY);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(60, 60, "HUMAN RESOURCES MANAGEMENT SYSTEM");
	setcolor(BLUE);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(90, 100, user);

	do
	{
		setcolor(WHITE);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
		if(usr == 0)
		{
			outtextxy(90, 130, "SELECTION");
			outtextxy(90, 150, "[1] VIEW USERS");
			outtextxy(90, 170, "[2] ADD");
			outtextxy(90, 190, "[3] EDIT");
			outtextxy(90, 210, "[4] DELETE");
			outtextxy(90, 230, "[5] SEARCH");
			outtextxy(90, 250, "[6] SORT");
			outtextxy(90, 270, "[x] EXIT");
			
			if(c == 80 && usr == 0 && i < 7)
			{	
				++i;
				/*Selector Cursor*/
				setcolor(LIGHTBLUE);
				rectangle(85, 145+y1-20, 205, 160+y2-20);
				setcolor(RED);
				rectangle(85, 145+y1, 205, 160+y2);
				y1 = y1 + 20;
				y2 = y2 + 20;
				
			}
		
			if(c == 72 && usr == 0 && i > 1)
			{
				y1 = y1 - 20;
				y2 = y2 - 20;
				/*Selector Cursor*/
				setcolor(LIGHTBLUE);
				rectangle(85, 145+y1, 205, 160+y2);
				setcolor(RED);
				rectangle(85, 145+y1-20, 205, 160+y2-20);
				--i;
			}
			if(c == 27)
			{
				i = 8;
				break;
			}
		}
		else if(usr != 0)
		{
			outtextxy(90, 130, "SELECTION");
			outtextxy(90, 150, "[1] PROFILE");
			outtextxy(90, 170, "[2] EDIT");
			outtextxy(90, 190, "[x] EXIT");
			
			if(c == 80 && i < 3)
			{	
				++i;
				/*Selector Cursor*/
				setcolor(LIGHTBLUE);
				rectangle(85, 145+y1-20, 205, 160+y2-20);
				setcolor(RED);
				rectangle(85, 145+y1, 205, 160+y2);
				y1 = y1 + 20;
				y2 = y2 + 20;
				
			}
		
			if(c == 72 && i > 1)
			{
				
				y1 = y1 - 20;
				y2 = y2 - 20;
				/*Selector Cursor*/
				setcolor(LIGHTBLUE);
				rectangle(85, 145+y1, 205, 160+y2);
				setcolor(RED);
				rectangle(85, 145+y1-20, 205, 160+y2-20);
				--i;
			}
			if(c == 27)
			{
				i = 8;
				break;
			}
		}
		c = getch();
	}while(c != 13);
	
	while(i != 8)
	{
		/************************************IMPORT********************************/
		f=fopen("INFO.DAT","r");
		while(s!=3)
		{		
			new=(INFO *)malloc(sizeof(INFO));
			if((fscanf(f,"%[^\n]\ns \n",(*pnew)->user_name))!=EOF)
			{	
				fscanf(f,"%[^\n]\ns \n",(*pnew)->first_name);
				fscanf(f,"%[^\n]\ns \n",(*pnew)->last_name);
				fscanf(f,"%[^\n]\ns \n",(*pnew)->gender);
				fscanf(f,"%[^\n]\ns \n",(*pnew)->tel_no);
				fscanf(f,"%[^\n]\ns \n",(*pnew)->email);
				fscanf(f,"%[^\n]\ns \n\n",(*pnew)->address);
				if(s==1) 
				{
					create(&pnew,&pstart); 
					s=0;
				}
				else 
					insert(&pnew,start);
			}
			else
			{
				free(new); 
				s=3;
			}
		}	
		fclose(f);		
		
		tmp = start;
		/*******************************************************************************/
		switch(i)
		{
			case 1:
				if(usr == 0)
				{
					
					i = 8;
				}
				else
				{
					
					i = 8;
				}
				break;
			case 2:
				if(usr == 0)
				{	
					i = 8;
					add(&new, &start, &user);
					break;
				}
				else
				{
					return 0;
				}
				break;
			case 3:
				if(usr == 0)
				{
					
					i = 8;
				}
				else
				{
					i = 8;
					outtextxy(10, 10, "[x] EXIT");
					closegraph();
					return 0;
					break;
				}
				break;
			case 4:
					i = 8;
				break;
			case 5:
					i = 8;
				break;
			case 6:
					i = 8;
				break;
			case 7:
					i = 8;
				outtextxy(10, 10, "[x] EXIT");
				closegraph();
				return 0;
				break;
			default:
					i = 8;
				break;
		}
		
		t = fopen("tmp.dat","a");
		tmp=start;
		while(tmp!=NULL)
		{
			fprintf(t,"%s\n",tmp->user_name);
			fprintf(f,"%s\n",tmp->first_name);
			fprintf(f,"%s\n",tmp->last_name);
			fprintf(f,"%s\n",tmp->gender);
			fprintf(f,"%s\n",tmp->tel_no);
			fprintf(f,"%s\n",tmp->email);
			fprintf(f,"%s\n\n",tmp->address);
			tmp=tmp->n;
		}	
		fclose(t);
		remove("INFO.DAT"); 
		rename("tmp.dat","INFO.DAT");
	}
	MENUGUI(user);
}

void LOGIN(char user[MAX_IN_LEN], char pass[MAX_IN_LEN_P])
{
	FILE *fp, *fopen();
	int i = 0, pos;
	char c, tmp_user[MAX_IN_LEN], tmp_pass[MAX_IN_LEN_P];
	
	fp = fopen("ACC.DAT", "r");
	c = getc(fp);
	
	/*Cleaner*/
	for(i; i < MAX_IN_LEN && MAX_IN_LEN_P; i++)
	{
		tmp_user[i] = NULL;
		tmp_pass[i] = NULL;
	}
	while(c != EOF)
	{
		fscanf(fp, "%s	%s", tmp_user, tmp_pass);
		
		if(strcmp(user, tmp_user) == 0 && strcmp(pass, tmp_pass) == 0)
		{
			fclose(fp);
			MENUGUI(&tmp_user);
			break;
		}
		/*Remember to put space after the last acc to trap*/
		else if(c == ' ')
		{
			fclose(fp);
			setcolor(RED);
			outtextxy(220, 260, "INVALID USER OR PASSWORD!!");
			getch();
			/*
			LOGIN_USER(user, pass);
			*/
			main();
		}
		c = getc(fp);
	}
	fclose(fp);
}
/*
void LOGIN_USER(char user[MAX_IN_LEN], char pass[MAX_IN_LEN_P])
{
	FILE *fp, *fopen();
	int i = 0, pos;
	char c, tmp_user[MAX_IN_LEN], tmp_pass[MAX_IN_LEN_P];
	
	fp = fopen("INFO.DAT", "r");
	c = getc(fp);
	
	/*Cleaner
	for(i; i < MAX_IN_LEN && MAX_IN_LEN_P; i++)
	{
		tmp_user[i] = NULL;
		tmp_pass[i] = NULL;
	}
	while(c != EOF)
	{
		fscanf(fp, "%s\n\n%s", tmp_user, tmp_pass);
		puts(c);
		if(strcmp(user, tmp_user) == 0 && strcmp(pass, tmp_pass) == 0)
		{
			fclose(fp);
			MENUGUI(&tmp_user);
			break;
		}
		/*Remember to put space after the last acc to trap
		else if(c == ' ')
		{
			fclose(fp);
			
			setcolor(RED);
			outtextxy(220, 260, "INVALID USER OR PASSWORD!!");
			
			getch();
			main();
		}
		puts(tmp_user);
		puts(tmp_pass);
		getch();
		c = getc(fp);
	}
	fclose(fp);
	
}*/
