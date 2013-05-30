#ifndef CUESTIONARIO_H
#define CUESTIONARIO_H

// SistemaConTimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <chrono>


class Encriptador
{
public:
	Encriptador(std::string claveE, std::string claveD);
	~Encriptador();
	std::string Cifrar(std::string input);
	std::string Decifrar(std::string input);
private:
	std::string claveEncriptacion;
	std::string claveDesencriptacion;
	int tamanoClave;
};



class Validador
{
public:
	Validador(std::string filename);
	~Validador();

	std::string path;
	int size;
	bool esValido(std::string input);
	std::string getContent();


private:
	std::string content;
};


using namespace std;



bool validarAcceso();





#endif