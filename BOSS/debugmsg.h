#pragma once
#include<Windows.h>
#include<iostream>

#define DebugStringFloat(form,field,hdc,x,y,font_s) {TCHAR disp_msg[100];swprintf((LPWSTR)disp_msg, TEXT(form), field),Str_Put(hdc, x, y, font_s, RGB(255, 255, 255), disp_msg);}
#define DebugStringVal(form,field,hdc,x,y,font_s) {TCHAR disp_msg[100];wsprintf((LPWSTR)disp_msg, TEXT(form), field),Str_Put(hdc, x, y, font_s, RGB(255, 255, 255), disp_msg);}
#define DebugString(form,hdc,x,y,font_s) {TCHAR disp_msg[100];wsprintf((LPWSTR)disp_msg, TEXT(form)),Str_Put(hdc, x, y, font_s, RGB(255, 255, 255), disp_msg);}



int Str_Put(HDC, int, int, int, UINT, TCHAR*);