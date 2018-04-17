#include "menu.h"
#include <QtWidgets/QApplication>
#include <Windows.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	//DEBUG CONSOLE CAUSE QT GUI APPS DONT HAVE ONE FOR SOME REASON....
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	printf("Debugging Window:\n");
	QApplication a(argc, argv);
	Menu w;
	w.show();
	return a.exec();
}
