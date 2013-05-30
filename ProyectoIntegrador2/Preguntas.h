
#ifndef PREGUNTAS_H
#define PREGUNTAS_H
#include <string>
#include <vector>
class Pregunta
{
public:
	Pregunta(std::string);
	~Pregunta(){};
	virtual void responder();
	virtual void imprimirPregunta();
	std::string getRespuesta();
private:
	std::string pregunta;
protected:
	char respuesta[512];
};

class Pregunta5a10 : public Pregunta
{
public:
	Pregunta5a10(std::string);
	~Pregunta5a10(){};
	void responder();
	void imprimirPregunta();
private:
};

class PreguntaOpcMult : public Pregunta
{
public:
	PreguntaOpcMult(std::string,std::string);
	~PreguntaOpcMult(){};
	void responder();
	void imprimirPregunta();
private:
	//std::string opciones;
	int numeroOpciones;
	std::vector<std::string> opcions;
};




#endif