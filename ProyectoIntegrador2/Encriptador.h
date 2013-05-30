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
	Encriptador(std::string claveE, std::string claveD)
	{
		if (claveE.length() != claveD.length())
		{
			return;
		}
		claveEncriptacion=claveE;
		claveDesencriptacion=claveD;
		tamanoClave = claveD.length()-1;
	}
	~Encriptador(){}
	std::string Cifrar(std::string input){

		for (size_t i =0;i<input.length();i++)
		{
			int posE = claveDesencriptacion.find(input[i]);
			int posF = posE+i;
			if (posF>tamanoClave) posF = ((posE+i)%tamanoClave)-1;
			if(posE != std::string::npos)input[i]=claveEncriptacion[posF];
			else input[i]='#';
			//std::cout<<posF<<"<Pf Tc>"<<tamanoClave<<std::endl;
		}



		return input;
	}
	std::string Decifrar(std::string input){

		for (size_t i =0;i<input.length();i++)
		{
			int posE = claveEncriptacion.find(input[i]);
			int posF = posE - i;
			if (posF<0)
			{
				posF %= tamanoClave;
				posF += tamanoClave;
				posF++;
			}
			if(posE != std::string::npos)input[i]=claveDesencriptacion[posF];
			else input[i]='#';
			//std::cout<<posF<<"<Pf Tc>"<<tamanoClave<<std::endl;
		}
		return input;


	}
private:
	std::string claveEncriptacion;
	std::string claveDesencriptacion;
	int tamanoClave;
};



class Validador
{
public:
	Validador(std::string filename){
		for (char i='A';i<='Z';i++)
		{
			//std::cout<<i<<std::endl;
			std::string tmpcontent;
			path = "N:\\"+filename;
			path[0]=i;
			//std::cout<<"Checando en "+path<<std::endl;
			std::ifstream archivoClave (path, std::ifstream::binary);
			if (archivoClave.is_open())
			{

				content.assign( (std::istreambuf_iterator<char>(archivoClave) ),
					(std::istreambuf_iterator<char>()    ) );
				break;
				tmpcontent.assign(content.data());
			}

			//std::cout<<tmpcontent<<std::endl;
			
		}
	}
	~Validador(){}

	std::string path;
	int size;
	bool esValido(std::string input){

		std::string contenido = getContent();
		if (input == contenido)
		{
			return true;
		} 
		else
		{
			return false;
		}

	}
	std::string getContent(){
		return content;
	}


private:
	std::string content;
};


using namespace std;



bool validarAcceso(){
	Encriptador crypt("RSeCDf23g4ihjlk6auvMLxpQUmAEBwzyFGontJHIqKr7 Ts8ON9PXVWZ0Y15bcd", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ");
	Validador valid("clave.txt");
	string clave = "pablito clavo un clavito en la calva de un calvito";
	//cout<<"Buscando el archivo"<<endl;
	//if(valid.encontrado)cout<<"Archivo encontrado en " << valid.path<<endl;
	//cout<<crypt.Cifrar(clave)<<endl;
	bool validacion =valid.esValido(crypt.Cifrar(clave));
	if (validacion)
	{
		//		Acceso=true;
		//cout<<"Acceso Permitido"<<endl;
		return true;
	}
	else
	{
		//		Acceso=false;
		cout<<"Acceso Denegado"<<endl;
		
		return false;

	}
	//cout<<"Contenido del archivo: "<<valid.getContent()<<endl;
	//	cout<<"Contenido del archivo decifrado: " << crypt.Decifrar(valid.content)<<endl;
	//	cout<<"Clave correcta: " << clave<<endl;

}





#endif