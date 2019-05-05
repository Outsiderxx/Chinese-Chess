#pragma once
#include <functional>			//function pointer		execute   function<type( args )> menuFunction[] = { a ,b , c };
#include<fstream>
#include"start_menu.h"
using namespace std;
void load();
void caption();
//void check_enter();
void initial_start();
void load_down_gotoxy(int no);
void load_up_gotoxy(int no);
void board_basic(int boardx, int boardy);
function<void()> menuFunction[];

