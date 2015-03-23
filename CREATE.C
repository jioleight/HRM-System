#include "HRM.H"

void create(INFO ***new, INFO ***start)
{
	(**new)->n=NULL;
	**start=**new;
}
