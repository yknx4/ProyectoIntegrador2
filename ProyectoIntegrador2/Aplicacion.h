#ifndef APLICACION_H
#define APLICACION_H

#include <thread>
#include <iostream>
#include <chrono>
#include "Encriptador.h"
#include "Preguntas.h"
#include "Cuestionario.h"
#include "Consulta.h"
#include "Menu.h"
using namespace std;
class Aplicacion
{
public:
	Aplicacion();
	~Aplicacion();
	void iniciar();
	void addPregunta(Pregunta* input);
private:
	bool final;
	vector<Pregunta*> preguntas; //Se crea un vector de punteros del tipo Pregunta, para almacenar las preguntas de la encuesta
	Menu menu;
	void Encuesta();
	void Registros();
};

#endif