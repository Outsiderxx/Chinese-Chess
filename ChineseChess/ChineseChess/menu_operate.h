#pragma once
#include <functional>			//function pointer		execute   function<type( args )> menuFunction[] = { a ,b , c };
#include<fstream>
#include"start_menu.h"
using namespace std;
void start();
void load();
void caption();
void end();
//void check_enter();
void initial_start();
void escmenu();
void load_down_gotoxy(int no);
void load_up_gotoxy(int no);
function<void()> menuFunction[];

