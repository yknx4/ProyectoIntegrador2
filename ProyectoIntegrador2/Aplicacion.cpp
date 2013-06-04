#include "stdafx.h"
#include <thread>
#include <iostream>
#include <chrono>
#include "Encriptador.h"
#include "Preguntas.h"
#include "Cuestionario.h"
#include "Consulta.h"
#include "Aplicacion.h"
#include "Menu.h"
using namespace std;

Aplicacion::~Aplicacion()
{

}

Aplicacion::Aplicacion()
{
	menu.addOpcion("Encuesta");
	menu.addOpcion("Consulta");
	final =true;
}

void Aplicacion::Registros()
{
	Aplicacion();
	Consulta consulta(preguntas);
	if (consulta.leerArchivo("respuesta.txt"))
	{
		consulta.leerDatos();
		consulta.imprimirDatos();
		cin.getline(new char,1);
		cin.ignore();
		final=false;

	}
	else
	{
		cout<<"Error al leer el archivo de las respuestas"<<endl;
	}
}

void Aplicacion::Encuesta()
{
	Cuestionario cuestionario(preguntas);//se crea un cuestionario donde se añadiran las preguntas y se responderan, también con este objeto se guardaran
	//for (size_t i=0;i<preguntas.size();i++) {cuestionario.addPregunta(preguntas[i]);} //En este ciclo se añaden todas las preguntas del vector al cuestionario

	cuestionario.hacerPreguntas();//con este metodo se imprimien y se contestan las preguntas del cuestionario
	if (cuestionario.GuardarCuestionario()) //Aqui intenta guardar el cuestionario en un archivo de texto "respuestas.txt"
	{
		cout<<"Encuesta guardada. Gracias :)"; //si se logra guardar, entonces se imprime este mensaje
		final=false; //se asigna esta variable global a 0, para que el hilo principal salga del ciclo y entonces pueda cerrarse el programa
	}
	else cout<<"Error al guardar la encuesta, Contacte al Encargado"; //Se imprime este mensaje y no se cierra el programa, cuando hay un error al guardar la encuesta
}

void Aplicacion::addPregunta( Pregunta* input )
{
	preguntas.push_back(input);
}

void Aplicacion::iniciar()
{
	if(!validarAcceso())return ; //Aqui se checa que la llave este puesta, si no esta se sale del programa, sí si está continua la ejecución
	cout<<"Clave encontrada, Favor de elegir la opcion adecuada\n ";
	thread * hiloElegido = nullptr;
	switch (menu.SeleccionarOpcion())
	{
	case 1:
		hiloElegido = new thread(&Aplicacion::Encuesta,this);
		break;
	case 2:
		hiloElegido = new thread(&Aplicacion::Registros,this);
		break;
	default:
		final=false;
		break;
	}


	//thread hiloEjecucion(&Aplicacion::Registros,this); //Aqui se llama asíncronamente un hilo de ejecución, llamando a la funcion previamente definida llamada "AplicacionDeEncuesta"
	this_thread::sleep_for(std::chrono::milliseconds(3000)); //Se espera 3 segundos antes de entrar al ciclo infinito
	while (validarAcceso()&&final) //Este es el ciclo While que se realiza infinitamente, hasta que la encuesta se termine (pues la variable final queda en 0 y dado que 1^0=0) 
	{
		this_thread::sleep_for(std::chrono::milliseconds(3000));//El proceso duerme por 3 segundos antes de volver a validar
	}
	if (hiloElegido!=nullptr)
	{
		hiloElegido->detach(); //Se destruye el hilo de ejecución de AplicacionDeEncuesta despues de salir del ciclo
	}

	/*string lala[10];
	lala->size();*/
	//cin.getline(new char,1);
}
