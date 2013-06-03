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
//! Funcion para realizar encuesta.
/*!
En esta función se crean preguntas para el cuestionario, se añaden a este, despues se pasa a responderlas por la consola del comando, y finaliza intentado guardarlas.
*/
void AplicacionDeEncuesta(){
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
	Cuestionario cuestionario;//se crea un cuestionario donde se añadiran las preguntas y se responderan, también con este objeto se guardaran
	for (size_t i=0;i<preguntas.size();i++) cuestionario.addPregunta(preguntas[i]); //En este ciclo se añaden todas las preguntas del vector al cuestionario
	cuestionario.hacerPreguntas();//con este metodo se imprimien y se contestan las preguntas del cuestionario
	if (cuestionario.GuardarCuestionario()) //Aqui intenta guardar el cuestionario en un archivo de texto "respuestas.txt"
	{
		cout<<"Encuesta guardada. Gracias :)"; //si se logra guardar, entonces se imprime este mensaje
		final=false; //se asigna esta variable global a 0, para que el hilo principal salga del ciclo y entonces pueda cerrarse el programa
	}
	else cout<<"Error al guardar la encuesta, Contacte al Encargado"; //Se imprime este mensaje y no se cierra el programa, cuando hay un error al guardar la encuesta
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	if(!validarAcceso())return 1; //Aqui se checa que la llave este puesta, si no esta se sale del programa, sí si está continua la ejecución
	thread hiloEjecucion(AplicacionDeEncuesta); //Aqui se llama asíncronamente un hilo de ejecución, llamando a la funcion previamente definida llamada "AplicacionDeEncuesta"
	this_thread::sleep_for(std::chrono::milliseconds(3000)); //Se espera 3 segundos antes de entrar al ciclo infinito
	while (validarAcceso()&&final) //Este es el ciclo While que se realiza infinitamente, hasta que la encuesta se termine (pues la variable final queda en 0 y dado que 1^0=0) 
	{
		this_thread::sleep_for(std::chrono::milliseconds(3000));//El proceso duerme por 3 segundos antes de volver a validar
	}
	hiloEjecucion.detach(); //Se destruye el hilo de ejecución de AplicacionDeEncuesta despues de salir del ciclo
	/*string lala[10];
	lala->size();*/
	return 0;
}

