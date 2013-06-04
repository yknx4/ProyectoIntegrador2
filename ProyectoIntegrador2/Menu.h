#ifndef MENU_H
#define MENU_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;
class Menu
{
public:
	Menu();
	Menu(vector<string> opciones);;
	
	int SeleccionarOpcion();
	void addOpcion(string opcion);


private:
	vector<string> opciones;
	int opc;

};

#endif