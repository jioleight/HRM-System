#include "HRM.H"

void add(INFO **new, INFO **start, char *user[MAX_IN_LEN])
{
	char k, u_name[MAX_IN], f_name[MAX_IN], l_name[MAX_IN], gender[MAX_IN], tel_no[MAX_IN];
	char email[MAX_IN], address[MAX_IN], tmp_user[MAX_IN_LEN];
	int s = 0, in_s = 0, in_e = 0, c;
	strcpy(tmp_user, *user);
	setcolor(WHITE);
	outtextxy(260, 150, "Username: ");
	outtextxy(260, 170, "First name: ");
	outtextxy(260, 190, "Last name: ");
	outtextxy(260, 210, "Gender: ");
	outtextxy(260, 230, "Tel. No.: ");
	outtextxy(260, 250, "Email: ");
	outtextxy(260, 270, "Address: ");
	outtextxy(1, 11, *user);
	outtextxy(1, 22, tmp_user);
	while(!s)
	{
		*new=(INFO *)malloc(sizeof(INFO));
			
		/*Cleaner*/
		for(c = 0; c < MAX_IN; c++)
		{
			u_name[c] = NULL;
			f_name[c] = NULL;
			l_name[c] = NULL;
			gender[c] = NULL;
			tel_no[c] = NULL;
			email[c] = NULL;
			address[c] = NULL;
		}
		/*User name*/
		do
		{
			outtextxy(350, 150, u_name);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						u_name[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 150, 560, 160);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy((*new)->user_name, u_name);
					break;
				case 27: /* Escape = Abort */
					u_name[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN - 1 && c >= ' ' && c <= '~')
					{
						u_name[in_s] = c;
						in_s++;
						u_name[in_s] = 0;
					}
			}
		}while(!in_e);
		in_s = 0;
		in_e = 0;
		/*first name*/
		do
		{
			outtextxy(350, 170, f_name);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						f_name[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 170, 560, 180);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy((*new)->user_name, f_name);
					break;
				case 27: /* Escape = Abort */
					f_name[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN - 1 && c >= ' ' && c <= '~')
					{
						f_name[in_s] = c;
						in_s++;
						f_name[in_s] = 0;
					}
			}
		}while(!in_e);
		in_s = 0;
		in_e = 0;
		/*last name*/
		do
		{
			outtextxy(350, 190, l_name);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						l_name[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 190, 560, 200);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy((*new)->user_name, l_name);
					break;
				case 27: /* Escape = Abort */
					l_name[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN - 1 && c >= ' ' && c <= '~')
					{
						l_name[in_s] = c;
						in_s++;
						l_name[in_s] = 0;
					}
			}
		}while(!in_e);
		in_s = 0;
		in_e = 0;
		/*gender*/
		do
		{
			outtextxy(350, 210, gender);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						gender[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 210, 560, 220);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy((*new)->user_name, gender);
					break;
				case 27: /* Escape = Abort */
					gender[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN - 1 && c >= ' ' && c <= '~')
					{
						gender[in_s] = c;
						in_s++;
						gender[in_s] = 0;
					}
			}
		}while(!in_e);
		in_s = 0;
		in_e = 0;
		/*tel no*/
		do
		{
			outtextxy(350, 230, tel_no);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						tel_no[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 230, 560, 240);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy((*new)->user_name, tel_no);
					break;
				case 27: /* Escape = Abort */
					tel_no[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN - 1 && c >= ' ' && c <= '~')
					{
						tel_no[in_s] = c;
						in_s++;
						tel_no[in_s] = 0;
					}
			}
		}while(!in_e);
		in_s = 0;
		in_e = 0;
		/*email*/
		do
		{
			outtextxy(350, 250, email);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						email[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 250, 560, 260);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy((*new)->user_name, email);
					break;
				case 27: /* Escape = Abort */
					email[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN - 1 && c >= ' ' && c <= '~')
					{
						email[in_s] = c;
						in_s++;
						email[in_s] = 0;
					}
			}
		}while(!in_e);
		in_s = 0;
		in_e = 0;
		/*address*/
		do
		{
			outtextxy(350, 270, address);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						address[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 270, 560, 280);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy((*new)->user_name, address);
					break;
				case 27: /* Escape = Abort */
					address[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN - 1 && c >= ' ' && c <= '~')
					{
						address[in_s] = c;
						in_s++;
						address[in_s] = 0;
					}
			}
		}while(!in_e);
		
		
		if(*start==NULL)
		{			
			create(&new,&start);
		}
		else 
		{
			insert(&new,*start);
		}
		setcolor(RED);
		outtextxy(260, 128, "Do you want to add more?[y/n]");
		do
		{
			k=getch(); 
		}
		while(k!='y' && k!='Y'&& k!='n' && k!='N' && k!=13);

		if(k=='n'||k=='N'||k==27)
		{
			s=1;
		}	
	}
	MENUGUI(tmp_user);
}
