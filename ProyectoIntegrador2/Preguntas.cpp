#include "stdafx.h"
#include "Preguntas.h"
#include <sstream>
#include <conio.h>
#include <vector>

using namespace std;

Pregunta::Pregunta( std::string pregunta )
{
	this->pregunta=pregunta;
	memset(respuesta,'\0',512);
}

void Pregunta::responder()
{
	//cin.ignore();
//	this->imprimirPregunta();
	cin.getline(respuesta,512);
	for (int i=0;i<512;i++)
	{
		if (respuesta[i]=='\0')
		{
			break;
		}
		if (respuesta[i]=='\t')
		{
			respuesta[i]=' ';
		}
	}
}

void Pregunta::imprimirPregunta()
{
	cout<<"\n>> "<<pregunta<<": ";
}

std::string Pregunta::getRespuesta()
{
	return *(new string(respuesta));
}

Pregunta5a10::Pregunta5a10( std::string input) : Pregunta(input)
{

}

void Pregunta5a10::responder()
{
//	imprimirPregunta();
__super::responder();
//cout<<respuesta<<"res\n";

istringstream ss(respuesta);
int x;
if (!(ss >> x) || (x>10 || x<5) || respuesta[2]!='\0' ) {
	
	//cin.ignore();
	cout<<"Numero Invalido\n";
	//ss.ignore();
	responder();
}
}

void Pregunta5a10::imprimirPregunta()
{
	//Pregunta::imprimirPregunta();
	__super::imprimirPregunta();
	cout<<" (5 a 10) | ";
}

PreguntaOpcMult::PreguntaOpcMult( std::string input,std::string opci) : Pregunta(input)
{
	//opciones=opci;
	size_t noOpc;
	numeroOpciones=0;
	string container="";
	for (noOpc=0;noOpc<opci.length();noOpc++)
	{
		if (opci[noOpc]=='\t' || noOpc==(opci.length()-1))
		{
			numeroOpciones++;
			opcions.push_back(container);
			container="";
			continue;
		}
		container+=opci[noOpc];
	}
	//cout<<opci.length()<<"lasopcios\n";
	//numeroOpciones=opci.length();
}

void PreguntaOpcMult::responder()
{
	string opciones="";
	for (int j = 0; j < numeroOpciones; j++)
	{
		opciones+=char(j+97);
	}
	char opc = _getch();
	for (unsigned int i=0;i<opciones.length();i++)
	{
		if (opciones[i] == opc)
		{
			respuesta[0]=opc;
			return;
		}
		
	}
	responder();
	
}

void PreguntaOpcMult::imprimirPregunta()
{
	__super::imprimirPregunta();
	cout<<endl;

	for (int i=0;i<numeroOpciones;i++)
	{
		cout<<char(i+97)<<") "<<opcions[i]<<"\t";
	}
	cout<<"\n";
}
