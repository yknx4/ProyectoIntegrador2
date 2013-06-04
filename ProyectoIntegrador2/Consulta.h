#ifndef CONSULTA_H
#define CONSULTA_H

// SistemaConTimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Preguntas.h"
using namespace std;
class Consulta
{
public:
	Consulta();
	Consulta(vector <Pregunta*> preguntas);
	~Consulta();
	void addPregunta(Pregunta* input);
	bool leerArchivo(string filename);
	void leerDatos();
	void imprimirDatos();
private:
	ifstream archivo;
	vector<vector<string>> Registros;
	vector <Pregunta*> preguntas;
};
#endif