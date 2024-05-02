#pragma once
#include <iostream>

using namespace std;
class Barco
{
//Atributos barcos
private:
	int velocidad;
	int distancia_recorrida;
	int nitro;
	string nombre_corredor;

//Metodos
public:
	int GetVelocidad();
	void SetVelocidad(int pvelocidad);
	int getDistancia_recorrida();
	void setDistancia_recorrida(int pdistancia);
	int getNitro();
	void setNitro(bool pnitro);
	string getNombre();
	int resultadoDado;
	//Constructor
	Barco();
	Barco(int pvelocidad, int pdistancia, string pnombre, bool pnitro);
	//Funciones
	void calcularDistancia();
	void usarNitro();
	int aumentoVelocidad(int resultadoDado);
	int lanzarDado();

	void setNombre(string pnombre);
	void getParameters();
};

