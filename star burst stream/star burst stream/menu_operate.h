#pragma once
#include<fstream>
#include"start_menu.h"
using namespace std;
//void load();
void caption();
void escmenu();
void esc_right_gotoxy(int num);
void esc_left_gotoxy(int num);
void escclear();
void initial_start();
//void load_down_gotoxy(int no);
//void load_up_gotoxy(int no);
void board_basic(int boardx, int boardy);
void replay_left_gotoxy();
void replay_right_gotoxy();

