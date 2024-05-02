#include "barco.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <string.h>
#include <cctype>

using namespace std;

HANDLE  hConsole;
#pragma comment(lib, "winmm.lib")

bool firstRead = true;
Barco barco1;
Barco barco2;
void esperar(int ms) {
	if (firstRead) {
		Sleep(ms);
	}
}
void intro() {
	PlaySound(TEXT("intro_music.wav"), NULL, SND_FILENAME | SND_ASYNC);
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout << "\n\t\t              |    |    |                 " << "\n";
	esperar(250);
	SetConsoleTextAttribute(hConsole, 8);
	cout << "\t\t             )_)  )_)  )_)              " << "\n";
	esperar(250);
	cout << "\t\t            )___))___))___)\            " << "\n";
	esperar(250);
	cout << "\t\t            )___))___))___)\            " << "\n";
	esperar(250);
	SetConsoleTextAttribute(hConsole, 4);
	cout << "\t\t         _____|____|____|____\\\__" << "\n";
	esperar(250);
	SetConsoleTextAttribute(hConsole, 3);
	cout << "\t\t---------|                   /-------- - "<< "\n";
	esperar(250);
	SetConsoleTextAttribute(hConsole, 3);
	cout << "\t\t  ^^^^^ ^^^^^^^^^^^^^^^^^^^^^" << "\n";
	esperar(250);
	cout << "\t\t    ^^^^      ^^^^     ^^^    ^^" << "\n";
	esperar(250);
	cout << "\t\t         ^^^^      ^^^" << "\n";
	esperar(250);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\n";
	cout << "\t\tBienvenido a Boat Racer!\n";
	esperar(250);
	cout << "\t\t   by Ivan Trujillo\n\n ";
	esperar(2500);
	system("PAUSE");
	PlaySound(nullptr, nullptr, 0);
}
void turnos() {
	barco1.SetVelocidad(barco1.aumentoVelocidad(barco1.lanzarDado()));
	if (barco1.getNitro() == 1) {
		string respuesta_nitro;
		cout << "Quieres utilizar el nitro? (S/N) ";
		cin >> respuesta_nitro;
		if (respuesta_nitro == "S" || respuesta_nitro == "s") {
			barco1.usarNitro();
		}
	}
	barco1.calcularDistancia();
	esperar(400);
	int dado_lanzado = barco2.lanzarDado();
	barco2.SetVelocidad(barco2.aumentoVelocidad(dado_lanzado));
	if (barco2.getNitro() == 1 && dado_lanzado > 3){
		barco2.usarNitro();
	}
	barco2.calcularDistancia();
	esperar(400);
	barco1.getParameters();
	esperar(400);
	barco2.getParameters();
	esperar(400);
}
void validacion() {
	if (barco1.getDistancia_recorrida() < barco2.getDistancia_recorrida()) {
		PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_ASYNC);
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "El ganador es";
		esperar(250);
		cout << ".";
		esperar(250);
		cout << ".";
		esperar(250);
		cout << ". ";
		esperar(250);
		cout << barco2.getNombre() << "\n\n\n";
	}
	else if (barco1.getDistancia_recorrida() > barco2.getDistancia_recorrida()) {
		PlaySound(TEXT("victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "El ganador es";
		esperar(250);
		cout << ".";
		esperar(250);
		cout << ".";
		esperar(250);
		cout << ". ";
		esperar(250);
		cout << barco1.getNombre() << "\n\n\n";
	}
	else if (barco1.getDistancia_recorrida() == barco2.getDistancia_recorrida()) {
		cout << "Ha habido un empate tecnico!";
	}
	else {
		cout << "Error en los resultados de la carrera";
	}
}

int main() {
	intro();
	srand(time(0));
	string nombre_personalizado;
	cout << "Introduzca su nombre... ";
	cin >> nombre_personalizado;
	string nombre_rival;
	cout << "Introduzca el nombre de su oponente... ";
	cin >> nombre_rival;
	barco1 = Barco(0, 0, nombre_personalizado, 1);
	barco2 = Barco(0, 0, nombre_rival, 1);
	system("CLS");
	for (int i = 1; i < 6; i++) {
		cout << "\nTurno " << i << ":\n";
		turnos();
	}
	esperar(1500);
	system("PAUSE");
	system("CLS");
	validacion();
	system("PAUSE");
}