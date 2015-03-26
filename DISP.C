#include "HRM.H"

void display(INFO *start, INFO *tmp)
{
	int s=0, k=0, t=0;
	setcolor(RED);
	outtextxy(260, 128, "Viewing All Users!");
	setcolor(WHITE);
	while(!s)
	{
		tmp=start;
	
	
		if(tmp==NULL)
		{
			outtextxy(360, 250, "***EMPTY***");
			s = 1;
		}
		else
		{
			while(tmp!=NULL)
			{
				if(k < 230)
				{
					outtextxy(260, 150 + k, tmp->user_name);
					tmp=tmp->n;
					k = k + 15;
				}
				else
				{	
					if(t < 230)
					{
						outtextxy(400, 150 + t, tmp->user_name);
						tmp=tmp->n;
						t = t + 15;
					}
				}
			}	
			s = 1;
		}
		getch();
	}
}