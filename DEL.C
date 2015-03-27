#include "HRM.H"

void delete(INFO *tmp, INFO *prev, INFO ****start)
{
	strcpy(tmp->user_name,"");
	strcpy(tmp->first_name,"");
	strcpy(tmp->last_name,"");
	strcpy(tmp->gender,"");
	strcpy(tmp->tel_no,"");
	strcpy(tmp->email,"");
	strcpy(tmp->address,"");
	
	if(prev==NULL) 
		***start=tmp->n;
	else 
	{
		prev->n=tmp->n;
		free(tmp);
	}
	outtextxy(340, 350, "User Deleted!!");
	sleep(2);
}

void deleter(INFO **start, INFO *tmp)
{
	char k,*srch;
	int s=0;
	INFO *prev,***pstart=&start;
		
	setcolor(RED);
	outtextxy(260, 128, "Delete User");
	
	srch = NULL;
	if(srch==NULL)
	{
		prev=tmp;
		tmp=tmp->n;
	}
	srch = search(&tmp, &prev, srch);
	if(tmp!=NULL)
	{
		delete(tmp,prev,&pstart);
	}
}


