// ProyectoIntegrador2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Preguntas.h"
#include "Aplicacion.h"



int _tmain(int argc, _TCHAR* argv[])
{
	Aplicacion programa;
	vector<Pregunta*> preguntas; //Se crea un vector de punteros del tipo Pregunta, para almacenar las preguntas de la encuesta
	preguntas.push_back(new Pregunta("Biblioteca"));
	preguntas.push_back(new PreguntaOpcMult("Seleccione una Opcion","Alumno	Docente	Investigador	Otros"));
	preguntas.push_back(new Pregunta("Carrera"));
	preguntas.push_back(new Pregunta("Semestre"));
	preguntas.push_back(new Pregunta5a10("Instalaciones (Comodidad, Limpieza, Iluminacion, Espacios)"));
	preguntas.push_back(new Pregunta("Que mejoras propone?"));
	preguntas.push_back(new Pregunta5a10("Acervo Bibliografico y documental (Actualizado, Suficiente)"));
	preguntas.push_back(new Pregunta("Que mejoras propone?"));
	preguntas.push_back(new Pregunta5a10("Herramientas y servicios de informacion (Prestamo de computadoras, Consulta en el catalogo, Acceso a bases de datos)"));
	preguntas.push_back(new Pregunta("Que mejoras propone?"));
	preguntas.push_back(new Pregunta5a10("Servicios del Personal (Rapidez, Asesoria)"));
	preguntas.push_back(new Pregunta("Que mejoras propone?"));
	for (size_t i=0;i<preguntas.size();i++) {programa.addPregunta(preguntas[i]);} //En este ciclo se añaden todas las preguntas del vector al cuestionario
	programa.iniciar();
	return 0;
}

