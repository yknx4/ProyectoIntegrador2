// ProyectoIntegrador2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <chrono>
#include "Encriptador.h"
#include "Preguntas.h"
#include "Cuestionario.h"

bool final=true;

void Aplicacion(){
	//Cuestionario cuest;
	vector<Pregunta*> preguntas;
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
	Cuestionario cuestionario;
	for (size_t i=0;i<preguntas.size();i++) cuestionario.addPregunta(preguntas[i]);
	cuestionario.hacerPreguntas();
	if (cuestionario.GuardarCuestionario())
	{
		cout<<"Encuesta guardada. Gracias :)";
		final=false;
	}
	else cout<<"Error al guardar la encuesta, Contacte al Encargado";
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	if(!validarAcceso())return 1;

	thread main(Aplicacion);


	
	while (true&&final)
	{
		
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));

		if (!validarAcceso())break;
		//cout<<"\nt"<<final<<"t\n";





	}
	main.detach();
	return 0;
}

