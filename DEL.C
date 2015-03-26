#include "HRM.H"

void deleter(INFO *tmp, INFO *prev, INFO ****start)
{
	strcpy(tmp->user_name,NULL);
	strcpy(tmp->first_name,NULL);
	strcpy(tmp->last_name,NULL);
	strcpy(tmp->gender,NULL);
	strcpy(tmp->tel_no,NULL);
	strcpy(tmp->email,NULL);
	strcpy(tmp->address,NULL);
	
	if(prev==NULL) 
		***start=tmp->n;
	else 
	{
		prev->n=tmp->n;
		free(tmp);
	}
}

void delete(INFO **start, INFO *tmp)
{
	char k,*srch,t[30]; int s=0;
	INFO *prev,***pstart=&start;
	outtextxy(260, 128, "Deleting User");
	while(!s)
	{
		tmp=*start; 
		srch=NULL; 
		prev=NULL;
		
		do
		{
			if(srch!=NULL) 
			{
				prev=tmp;
				tmp=tmp->n;
			}
			srch=search(&tmp,&prev,srch);
			clrscr();
			if(tmp!=NULL)
			{
				setcolor(WHITE);
				outtextxy(260, 150, "Username: ");
				outtextxy(260, 170, "First name: ");
				outtextxy(260, 190, "Last name: ");
				outtextxy(260, 210, "Gender: ");
				outtextxy(260, 230, "Tel. No.: ");
				outtextxy(260, 250, "Email: ");
				outtextxy(260, 270, "Address: ");
				
				outtextxy(350, 150, tmp->user_name);
				outtextxy(350, 170, tmp->first_name);
				outtextxy(350, 190, tmp->last_name);
				outtextxy(350, 210, tmp->gender);
				outtextxy(350, 230, tmp->tel_no);
				outtextxy(350, 250, tmp->email);
				outtextxy(350, 270, tmp->address);
				do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
				if(k=='n'||k=='N') k='n'; 
			}
		}	while(k=='n'&&tmp!=NULL);
		if(tmp!=NULL)
		{
			printf("\nare you sure you want to delete this User and Details?(y/n) ");
			do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
			if(k=='n'||k=='N') k='n'; 
			if(k!='n')
			{
				deleter(tmp,prev,&pstart);
				printf("\n\ndeleted!");
			}
		}
		else printf("\nUser does not exist");	
		}
	}
}


