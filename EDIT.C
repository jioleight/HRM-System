#include "HRM.H"

void edit(INFO *start, INFO *tmp)
{
	char c,*srch,u_name[MAX_IN_LEN], f_name[MAX_IN], l_name[MAX_IN];
	char gender[MAX_IN], tel_no[MAX_IN], email[MAX_IN], address[MAX_IN];
	int s=0, in_s=0, in_e=0, r=0;
	
	tmp=start; 
	srch=NULL;
		
	setcolor(RED);
	outtextxy(260, 128, "Edit User");
	
	/*Cleaner*/
	for(r = 0; r < MAX_IN; r++)
	{
		u_name[r] = NULL;
		f_name[r] = NULL;
		l_name[r] = NULL;
		gender[r] = NULL;
		tel_no[r] = NULL;
		email[r] = NULL;
		address[r] = NULL;
	}
	r = 0;
	/*do
	{
		*/
		if(srch!=NULL) 
		{
			tmp=tmp->n;
		}
		srch=search(&tmp,NULL,srch);
		
		if(tmp!=NULL)
		{
			
			/*Output pane*/
			setfillstyle(SOLID_FILL, MAGENTA);
			bar(250, 120, 560, 400);
			/*INFO Field*/
			setfillstyle(SOLID_FILL, WHITE);
			bar(250, 120, 560, 140);
			setcolor(RED);
			outtextxy(260, 128, "Edit User");
			
			setcolor(WHITE);
			outtextxy(260, 150, "Username: ");
			outtextxy(260, 170, "First name: ");
			outtextxy(260, 190, "Last name: ");
			outtextxy(260, 210, "Gender: ");
			outtextxy(260, 230, "Tel. No.: ");
			outtextxy(260, 250, "Email: ");
			outtextxy(260, 270, "Address: ");
			
			/*User name*/
			strcpy(u_name, tmp->user_name);
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
						strcpy(tmp->user_name, &u_name);
						break;
					case 27: /* Escape = Abort */
						u_name[0] = 0;
						in_e = 2;
						break;
					default:
						if (in_s < MAX_IN_LEN - 1 && c >= ' ' && c <= '~')
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
			strcpy(f_name, tmp->first_name);
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
						strcpy(tmp->first_name, &f_name);
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
			strcpy(l_name, tmp->last_name);
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
						strcpy(tmp->last_name, &l_name);
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
			strcpy(gender, tmp->gender);
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
						strcpy(tmp->gender, &gender);
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
			strcpy(tel_no, tmp->tel_no);
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
						strcpy(tmp->tel_no, &tel_no);
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
			strcpy(email, tmp->email);
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
						strcpy(tmp->email, &email);
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
			strcpy(address, tmp->address);
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
						strcpy(tmp->address, &address);
						r = 1;
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
			
		outtextxy(320, 350, "***EDIT SUCCESSFUL***");
		sleep(2);
		}
	/*
	}while(r != 1);
	*/
}
