#pragma once
#include<iostream>
#include <windows.h>
#include<string>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y);				//initial positin execute
void menuprint();						//����H�� & ���
void up_gotoxy(int num);				//up execute
void down_gotoxy(int num);		//down execute
int menu_control();						//return  operation

