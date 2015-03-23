#include "HRM.H"

void insert(INFO ***new, INFO *tmp)
{
	(**new)->n=NULL;
	while(1)
	{
		if(tmp->n!=NULL) tmp=tmp->n;
		else break;
	}
	tmp->n=**new;
}