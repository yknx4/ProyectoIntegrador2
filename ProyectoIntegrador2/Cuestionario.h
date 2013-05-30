#ifndef _CUESTIONARIO_H
#define _CUESTIONARIO_H
#include "Preguntas.h"
#include <vector>

class Cuestionario
{
public:
	Cuestionario();
	~Cuestionario();
	bool GuardarCuestionario();
	void hacerPreguntas();
	void addPregunta(Pregunta*);
private:
	std::vector <Pregunta*> preguntas;
	
};


#endif
