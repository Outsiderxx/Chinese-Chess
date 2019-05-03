#include "menu_operate.h"
#include"start_menu.h"

int main()
{
	int opa;
	menuprint();			//menuµe­±
	opa=menu_control();			//get select from user
	menuFunction[opa]();			//function pointer execute selection
	system("pause");
	return 0;
}