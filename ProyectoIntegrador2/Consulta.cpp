#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Preguntas.h"
#include "Consulta.h"

void Consulta::addPregunta( Pregunta* input )
{
	preguntas.push_back(input);
}

bool Consulta::leerArchivo( string filename )
{
	archivo.open(filename,ios::binary|ios::in);
	//fs.read(buffer,1000000);
	if(!archivo){
		return false;
	}
	return true;
}

void Consulta::leerDatos()
{
	vector<string> Respuestas;
	string temporal="";
	char buffer;
	while (archivo.good())
	{
		buffer=archivo.get();
		if(buffer=='\t'){
			Respuestas.push_back(temporal);
			//cout<<temporal<<endl;
			temporal="";
			continue;
		}
		if(buffer=='\n'){
			Registros.push_back(Respuestas);
			Respuestas.clear();
			//cout<<"Nuevo Registro"<<endl;
			continue;
		}
		temporal+=buffer;
	}
}

void Consulta::imprimirDatos()
{
	for (int i = 0; i < Registros.size(); i++)
	{
		cout << "\nCuestionario #"<<i+1<<endl;
		cout<<"Fecha: "<<Registros[i][0]<<endl;
		//cout<<preguntas.size()<<endl;
		for (int j = 0; j < preguntas.size(); j++)
		{
			preguntas[j]->imprimirPregunta();
			cout << Registros[i][j+1] << endl;
		}

	}
}

Consulta::~Consulta()
{

}

Consulta::Consulta()
{

}

Consulta::Consulta( vector <Pregunta*> preguntas )
{
	this->preguntas=preguntas;
}
