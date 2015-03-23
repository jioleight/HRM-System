#include "HRM.H"

void browse(INFO *start, INFO *tmp)
{
	char k; 
	int s=0;
	while(!s)
	{
		clrscr(); tmp=start;
		printf("***Browse Contacts***\n");
		printf("\n[1] Search");
		printf("\n[2] Show All");
		printf("\n[3] Back to Main");
		printf("\nChoice? ");
		do k=getche(); while(k!='1'&&k!='2'&&k!='3');	
		if(k=='1')
		{
			printf("\n\nEnter name/number of the contact you want to search: ");
			search(&tmp,NULL,NULL);
			if(tmp==NULL) 
				printf("\nnot found...");
		}
		if(k=='2')
		{
			if(tmp==NULL)
			{
				printf("\n\nno contacts found...");
			}
			else
			{
				printf("\n\n--------------------\n");
				while(tmp!=NULL)
				{
					printf("%s %c. %s",tmp->fn,tmp->mn[0],tmp->ln);
					printf("\n%s\n--------------------\n",tmp->num);
					tmp=tmp->n;
				}	
			}
		}
		if(k=='3') s=1;
		if(!s)
		{
			printf("\nagain?(y/n) " );
			do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
			if(k=='n'||k=='N') s=1;
		}
	}
}