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
	int gd = DETECT, gm, c, in_s = 0, in_e = 0;;
	initgraph(&gd, &gm, "c:\\turboc\\BGI");
	
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
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
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
MENUGUI(char user[MAX_IN_LEN], char pass[MAX_IN_LEN_P])
{
	int i = 0;
	cleardevice();
	
	/*Main pane*/
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	bar(50, 50, 600, 450);
	/*Title Bar*/
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(50, 50, 600, 75);
	/*Selection pane*/
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(80, 120, 210, 350);
	/*Output pane*/
	setfillstyle(SOLID_FILL, MAGENTA);
	bar(250, 120, 560, 400);
	/*Input Field*/
	setfillstyle(SOLID_FILL, WHITE);
	bar(90, 320, 200, 340);

	/*Borders*/
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	rectangle(50, 50, 600, 450);
	setcolor(LIGHTGRAY);
	rectangle(250, 120, 560, 400);
	rectangle(80, 120, 210, 350);
	
	setcolor(DARKGRAY);
	outtextxy(60, 60, "HUMAN RESOURCES MANAGEMENT SYSTEM");
	
	if(strcmp(user, "admin") == 0)
	{
		/*Admin Selection*/
		setcolor(WHITE);
		outtextxy(90, 130, "SELECTION");
		outtextxy(90, 150, "[1] VIEW USERS");
		outtextxy(90, 170, "[2] ADD");
		outtextxy(90, 190, "[3] EDIT");
		outtextxy(90, 210, "[4] DELETE");
		outtextxy(90, 230, "[5] SEARCH");
		outtextxy(90, 250, "[6] SORT");
		outtextxy(90, 270, "[x] EXIT");
		outtextxy(90, 310, "INPUT");
		
		/*Selector Cursor*/
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(90, 145, 200, 160);
	
	}
	else
	{
		/*User Selection*/
		setcolor(WHITE);
		outtextxy(90, 130, "SELECTION");
		outtextxy(90, 150, "[1] PROFILE");
		outtextxy(90, 170, "[2] EDIT");
		outtextxy(90, 190, "[x] EXIT");
		outtextxy(90, 310, "INPUT");
		
		/*Selector Cursor*/
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(90, 145, 200, 160);
	
	}
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
			MENUGUI(tmp_user, tmp_pass);
			break;
		}
		/*Remember to put space after the last acc to trap*/
		else if(c == ' ')
		{
			fclose(fp);
			setcolor(RED);
			outtextxy(220, 260, "INVALID USER OR PASSWORD!!");
			getch();
			main();
		}
		c = getc(fp);
	}
	fclose(fp);
}

