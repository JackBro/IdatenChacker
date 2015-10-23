#pragma once
#include<Windows.h>
#include<iostream>

#define DebugStringFloatR(form,field,hdc,x,y,font_s,r) {TCHAR disp_msg[100];swprintf((LPWSTR)disp_msg, TEXT(form), field),Str_Put(hdc, x, y, font_s, RGB(255, 255, 255), disp_msg,r);}
#define DebugStringFloat(form,field,hdc,x,y,font_s) {TCHAR disp_msg[100];swprintf((LPWSTR)disp_msg, TEXT(form), field),Str_Put(hdc, x, y, font_s, RGB(255, 255, 255), disp_msg,0);}
#define DebugStringVal(form,field,hdc,x,y,font_s) {TCHAR disp_msg[100];wsprintf((LPWSTR)disp_msg, TEXT(form), field),Str_Put(hdc, x, y, font_s, RGB(255, 255, 255), disp_msg,0);}
#define DebugString(form,hdc,x,y,font_s) {TCHAR disp_msg[100];wsprintf((LPWSTR)disp_msg, TEXT(form)),Str_Put(hdc, x, y, font_s, RGB(255, 255, 255), disp_msg,0);}
#define DebugStringColor(form,field,hdc,x,y,font_s,r,g,b) {TCHAR disp_msg[100];swprintf((LPWSTR)disp_msg, TEXT(form), field),Str_Put(hdc, x, y, font_s, RGB(r, g, b), disp_msg,0);}


int Str_Put(HDC, int, int, int, UINT, TCHAR*,int);