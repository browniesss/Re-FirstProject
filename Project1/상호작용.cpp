#include "resource.h"
#include "�Լ�.h"

BOOL InRect(RECT prt, OBJECTIVE* ob) //ob.x, ob.y
{
	RECT tmp;
	if (IntersectRect(&tmp,&ob->rect, &prt))
	{
		return true;
	}
	return false;
}