#include<iostream>
#include<windows.h>
#include<stdlib.h>
#define IZQUIERDA 0x41
#define ARRIBA 0x57
#define DERECHA 0x44
#define ABAJO 0x53
using namespace std;

void gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 10;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
}

class Object{
	int x, y;
public:
	Object(int _x, int _y) : x(_x), y(_y){};
	int X(){ return x; };
	int Y(){ return y; };
	void pintar();
	void borrar();
	void mover();
};

bool isKeyDown(int vkey) {
	return GetKeyState(vkey) < 0;
}

void Object::pintar(){
	gotoxy(x, y);
	cout << "*";
}

void Object::borrar(){
	gotoxy(x, y);
	cout << " ";
}

void Object::mover() {
	if (isKeyDown(IZQUIERDA)){
		borrar();
		x--;
		pintar();
	}
	if (isKeyDown(DERECHA)){
		borrar();
		x++;
		pintar();
	}
	if (isKeyDown(ARRIBA)){
		borrar();
		y--;
		pintar();
	}
	if (isKeyDown(ABAJO)){
		borrar();
		y++;
		pintar();
	}
}

int main(){
	OcultarCursor();
	Object a(34, 27);
	a.pintar();
	system("mode con: cols=80 lines=40");
	while (true){


		a.mover();
		Sleep(30);
	}
	return 0;
}
