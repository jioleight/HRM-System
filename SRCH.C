#include "HRM.H"

void checker(INFO *start, INFO *tmp)
{
	tmp = start;
	
	setcolor(RED);
	outtextxy(260, 128, "Search User");
	
	search(&tmp,NULL,NULL);

	/*
	if(tmp==NULL) 
	outtextxy(300, 250, "***DOES NOT EXIST***");
	*/
	getch();
}
char *search(INFO **tmp, INFO **prev, char *srch)
{
	INFO *t=*tmp,*tprev=*prev;
	char buf[30], tmp_srch[MAX_IN_LEN], c;
	int m,n=0, in_s = 0, in_e = 0, i = 0;
	
	setcolor(WHITE);
	outtextxy(260, 150, "Username: ");
	
	for(i; i<MAX_IN_LEN;i++)
	{
		tmp_srch[i] = NULL;
	}
	i = 0;
	if(srch==NULL)
	{
		do
		{
			outtextxy(350, 150, tmp_srch);
			c = getche();
			switch (c)
			{
				case 8: /* backspace */
					if (in_s)
					{
						in_s--;
						tmp_srch[in_s] = 0;
						setfillstyle(SOLID_FILL, MAGENTA);
						bar(350, 150, 560, 160);
					}
					break;
				case 13: /* return */
					in_e = 1;
					strcpy(buf, tmp_srch);
					strcpy(srch, tmp_srch);
					break;
				case 27: /* Escape = Abort */
					srch[0] = 0;
					in_e = 2;
					break;
				default:
					if (in_s < MAX_IN_LEN - 1 && c >= ' ' && c <= '~')
					{
						tmp_srch[in_s] = c;
						in_s++;
						tmp_srch[in_s] = 0;
					}
			}
		}while(!in_e);
	}
	/*
	else if(srch!=NULL)
	{
		
		outtextxy(300, 310, srch);
		while(t!=NULL)
		{	
			m=0;
			if(!strcmp(t->user_name,buf)) m=1;  
			if(!strcmp(t->first_name,buf)) m=1;
			if(!strcmp(t->last_name,buf)) m=1; 
			if(!strcmp(t->gender,buf)) m=1; 
			if(!strcmp(t->tel_no,buf)) m=1; 
			if(!strcmp(t->email,buf)) m=1; 
			if(!strcmp(t->address,buf)) m=1;
			if(m)
			{
				n++;
				outtextxy(260, 170, "First name: ");
				outtextxy(260, 190, "Last name: ");
				outtextxy(260, 210, "Gender: ");
				outtextxy(260, 230, "Tel. No.: ");
				outtextxy(260, 250, "Email: ");
				outtextxy(260, 270, "Address: ");
				outtextxy(350, 150, t->user_name);
				outtextxy(350, 170, t->first_name);
				outtextxy(350, 190, t->last_name);
				outtextxy(350, 210, t->gender);
				outtextxy(350, 230, t->tel_no);
				outtextxy(350, 250, t->email);
				outtextxy(350, 270, t->address);
				if(n==1) 
				{
					*tmp=t; 
					*prev=tprev;
				}
			}
			tprev=t;
			t=t->n;
		}
		i = 1;
	}*/
	while(t!=NULL)
	{	
		m=0;
		if(!strcmp(t->user_name,buf)) m=1;  
		if(!strcmp(t->first_name,buf)) m=1;
		if(!strcmp(t->last_name,buf)) m=1; 
		if(!strcmp(t->gender,buf)) m=1; 
		if(!strcmp(t->tel_no,buf)) m=1; 
		if(!strcmp(t->email,buf)) m=1; 
		if(!strcmp(t->address,buf)) m=1;
		if(m)
		{
			n++;
			outtextxy(260, 170, "First name: ");
			outtextxy(260, 190, "Last name: ");
			outtextxy(260, 210, "Gender: ");
			outtextxy(260, 230, "Tel. No.: ");
			outtextxy(260, 250, "Email: ");
			outtextxy(260, 270, "Address: ");
			outtextxy(350, 150, t->user_name);
			outtextxy(350, 170, t->first_name);
			outtextxy(350, 190, t->last_name);
			outtextxy(350, 210, t->gender);
			outtextxy(350, 230, t->tel_no);
			outtextxy(350, 250, t->email);
			outtextxy(350, 270, t->address);
			if(n==1) 
			{
				*tmp=t; 
				*prev=tprev;
			}
		}
		
		tprev=t;
		t=t->n;
	}
	
	if(m == 0 && n == 0)
	{
		outtextxy(300, 360, "***USER DOES NOT EXIST***");
	}
	
	if(n==0)
	{
		*tmp=NULL;
	}
	getch();
}

