#include "barco.h"

int Barco::GetVelocidad()
{
	return velocidad;
}

void Barco::SetVelocidad(int pvelocidad)
{
	velocidad = pvelocidad;
}

int Barco::getDistancia_recorrida()
{
	return distancia_recorrida;
}

void Barco::setDistancia_recorrida(int pdistancia)
{
	distancia_recorrida = pdistancia;
}

int Barco::getNitro()
{
	return nitro;
}

void Barco::setNitro(bool pnitro)
{
	nitro = pnitro;
}

string Barco::getNombre()
{
	return nombre_corredor;
}

void Barco::setNombre(string pnombre)
{
	nombre_corredor = pnombre;
}

void Barco::calcularDistancia()
{
	distancia_recorrida = distancia_recorrida + velocidad * 100;
}

void Barco::usarNitro()
{
	if (nitro > 0){
		int randomMultiplier = rand() % 2;
		if(randomMultiplier == 0){
			cout << "El nitro de: " << nombre_corredor << " ha forzado tu motor demasiado y se ha reducido tu velocidad a la mitad!\n";
			velocidad /= 2;
		}
		else{
			cout << "El nitro de: " << nombre_corredor << " ha funcionado a la perfeccion, tu velocidad se duplica\n";
			velocidad *= 2;
		}
		nitro--;
	}
}
int Barco::aumentoVelocidad(int resultadoDado)
{
	velocidad += resultadoDado;
	return velocidad;
}
int Barco::lanzarDado()
{
	resultadoDado = rand() % 6 + 1;
	cout << "El corredor " << nombre_corredor << " ha sacado un " << resultadoDado << "\n";
	return resultadoDado;
}
void Barco::getParameters()
{
	cout << "El corredor: " << nombre_corredor << " ha recorrido: " << distancia_recorrida << "m de distancia. Y lleva una velocidad de " << velocidad << "Km/h.\n";
}


// CONSTRUCTORES
Barco::Barco()
{
}

Barco::Barco(int pvelocidad, int pdistancia, string pnombre, bool pnitro)
{
	velocidad = pvelocidad;
	distancia_recorrida = pdistancia;
	nombre_corredor = pnombre;
	nitro = pnitro;
}
