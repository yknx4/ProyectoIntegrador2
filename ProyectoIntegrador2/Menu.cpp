#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include "Menu.h"
using namespace std;

Menu::Menu()
{
	opc=0;
}

Menu::Menu( vector<string> opciones )
{
	Menu();
	this->opciones=opciones;
}

int Menu::SeleccionarOpcion()
{
	//int opc=0; //opcion del Menu
	while (opc!=(opciones.size()+1))//Imprimir el Menu hasta que se seleccione salir(opcion 3)
	{
		do{
			system("cls");
			//cout << "------------------------ Menu -------------------------" << endl ;
			cout << "-------Elija la opcion que desea realizar---------: " << endl << endl ;
			for (size_t i = 0; i < opciones.size(); i++)
			{
				cout<<(i+1)<<".- "<<opciones[i]<<"."<<endl;
			}
			cout << (opciones.size()+1) <<".- Salir." << endl ;
			cout << "Seleccionado: ";
			//cin.ignore();
			opc = _getche()-48;
			if( opc<1 || opc >(int)(opciones.size()+1))
			{
				cout << "Ese numero no es una opcion, vuelve a ingresar tu opcion." <<endl;
				opc=0;

				//system("pause");
			}
			else
			{
				//6cin.ignore();
				return opc;
			}
		}while(true); //condicional
		//cout << "Switch para las opciones";
	}
	return -1;
}

void Menu::addOpcion( string opcion )
{
	opciones.push_back(opcion);
}
