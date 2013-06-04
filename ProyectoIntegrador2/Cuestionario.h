#ifndef _CUESTIONARIO_H
#define _CUESTIONARIO_H
#include "Preguntas.h"
#include <vector>
using namespace std;
class Cuestionario
{
public:
	Cuestionario();
	Cuestionario(vector <Pregunta*> preguntas);
	~Cuestionario();
	bool GuardarCuestionario();
	void hacerPreguntas();
	void addPregunta(Pregunta*);
private:
	std::vector <Pregunta*> preguntas;
	
};


#endif
