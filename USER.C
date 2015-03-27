#include "HRM.H"

char *user_info(INFO **tmp, INFO **prev, char *srch)
{
	INFO *t=*tmp,*tprev=*prev;
	char buf[30], c;
	int m,n=0;
	
	setcolor(RED);
	outtextxy(260, 128, "User Info");
	
	setcolor(WHITE);
	outtextxy(260, 150, "Username: ");
	strcpy(buf, srch);
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
	
	if(m>0 || n < 1)
	{
		outtextxy(300, 350, "***USER DOES NOT EXIST***");
	}
	
	if(n==0)
	{
		*tmp=NULL;
	}
	getch();
}