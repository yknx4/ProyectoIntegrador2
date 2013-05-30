//#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "Cuestionario.h"
#include "Preguntas.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
using namespace std;
Cuestionario::Cuestionario()
{
	
}

Cuestionario::~Cuestionario()
{

}

bool Cuestionario::GuardarCuestionario()
{
	typedef std::chrono::system_clock Clock;
	auto now = Clock::now();
	std::time_t now_c = Clock::to_time_t(now);

	struct tm *parts = std::localtime(&now_c);
	int anio= 1900 + parts->tm_year;
	int month= 1    + parts->tm_mon;
	int day = parts->tm_mday ;

	ofstream myfile;
	myfile.open("respuesta.txt",ios::out | ios::app);
	string respues = "";
	if (myfile.is_open())
	{
		for (size_t i=0;i<preguntas.size();i++)
		{
			respues+=preguntas[i]->getRespuesta()+"\t";
		}
		myfile << 1900 + parts->tm_year  << "_";
		myfile << 1    + parts->tm_mon   << "_";
		myfile <<        parts->tm_mday  << "\t";
		myfile << respues <<"\n";
		myfile.close();
		return true;
	}
	else cout << "No se puede guardar";
	return false;
}

void Cuestionario::hacerPreguntas()
{
	int numeroPreguntas = this->preguntas.size();
//	cout<<preguntas.size()<<"eltama~no\n";
	for (int contadorPreguntas=0;contadorPreguntas<numeroPreguntas;contadorPreguntas++)
	{
		preguntas[contadorPreguntas]->imprimirPregunta();
		preguntas[contadorPreguntas]->responder();
	}
}

void Cuestionario::addPregunta(Pregunta* input){
	preguntas.push_back(input);

}


