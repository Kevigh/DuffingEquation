/* Proyecto final - Física computacional

 ₊˚ EL OSCILADOR DE DUFFING ₊˚

 x'' + dx' + rx + αx^2 + bx^3 = g cos(ft) 

 @Autores: Alejandra A. y Kevin G.
*/
 
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;

// Variables del sistema
double x, y, t, dt(0.1);

// Parámetros
double d = 0.3;    // gamma
double r = -1;	  // alpha
double a = 0;	  // theta
double b = 1;    // beta
double g = 0.28;	  // delta
double f = 1.2;    // omega

// ------- Funciones acopladas -------------------------------------------------------------

// x' = y
double f1(double x, double y) {	return y; }

// y'' = - dy - rx - ax^2 - bx^3 + g cos(ft)
double f2(double x, double y) { return -d*y - r*x - a*pow(x,2) - b*pow(x,3) + g*cos(f*t); }

// -----------------------------------------------------------------------------------------

void RK4(){
	double k1, k2, k3, k4, l1, l2, l3, l4;

	k1 = dt * f1(x, y);
	l1 = dt * f2(x, y);
	k2 = dt * f1(x + dt/2, y + k1/2);
	l2 = dt * f2(x + dt/2, y + l1/2);
	k3 = dt * f1(x + dt/2, y + k2/2);
	l3 = dt * f2(x + dt/2, y + l2/2);
	k4 = dt * f1(x + dt, y + k3);
	l4 = dt * f2(x + dt, y + l3);

	x += (k1 + 2*k2 + 2*k3 + k4)/6;
	y += (l1 + 2*l2 + 2*l3 + l4)/6;
}

// ═════════════════════════════════════════════════════════════════════════════════════════

int main(){

double x_2, y_2, t_2;
	cout << "\n     ₊˚ EL OSCILADOR DE DUFFING ₊˚ \n";
	cout << "\n x'' + dx' + rx + ax^2 + bx^3 = g cos(ft)\n";
	cout << "\n Ingrese las condiciones inciales del sistema.\n\n";
	
	double *DINA; // Arreglo dinámico
	DINA = new double [6]; // DINA = {t, x, y}

	char entry[8]; // Número de digitos posibles a ingresar
	string text;
	
	for(int k = 0; k < 6; k++){ // Condiciones ingresadas por el usuario
		switch(k){
			case 0: text = "  t = "; break; // 0
			case 1: text = "  x = "; break; // 1
			case 2: text = "  y = "; break; // 0
			case 3: text = " t1 = "; break; // 0
			case 4: text = " x1 = "; break; // 1
			case 5: text = " y1 = "; break; // 0
		}
		cout << text; cin >> entry;
		DINA[k] = atof(entry); // Convierte cadena de texto a double
	}

	t = DINA[0]; x = DINA[1]; y = DINA[2]; // Datos iniciales NUMERO 1
t_2 = DINA[3]; x_2 = DINA[4]; y_2 = DINA[5]; // Datos iniciales NUMERO 1
	
//  ﻿ ﻿· ﻿ ·﻿ ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿· ﻿ ·﻿ ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿· ﻿ ·﻿ ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿· ﻿ ·﻿ ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿·﻿ ﻿ ﻿· ﻿ ﻿· ﻿ ·﻿ ﻿ ﻿· ﻿ ·﻿ ﻿ ﻿· ﻿ ·﻿

   double *flecha = DINA; // puntero
   double coso;
   
	ofstream miki; miki.open("data.dat");	

	for (t; t < 100; t += dt) {
		for(int p = 0; p < 3; p++){ // Itera entre las posiciones de DINA
			switch (p){
				case 0: coso = t; break;
				case 1: coso = x; break;
				case 2: coso = y; break;
			}
			*(flecha+p) = coso; // modifica los datos en DINA
		}
		
		RK4();
		miki << DINA[0] << " " << DINA[1] << " " << DINA[2] << endl;
		//miki << endl << endl;
	}
miki << endl << endl;
x = y = t = 0;
t = t_2; x = x_2; y = y_2;
	for (t; t < 100; t += dt) {
		for(int p = 3; p < 6; p++){ // Itera entre las posiciones de DINA
			switch (p){
				case 3: coso = t; break;
				case 4: coso = x; break;
				case 5: coso = y; break;
			}
			*(flecha+p) = coso; // modifica los datos en DINA
		}
		
		RK4();
		miki << DINA[3] << " " << DINA[4] << " " << DINA[5] << endl;
		//miki << endl << endl;
	}

	miki.close();
	delete DINA;

	miki.open("duff.plt");
	miki << "set terminal pngcairo size 900,600" <<endl;
	miki << "set title '{/:Size=20 Oscilador de Duffing Caótico}'" << endl;
	miki << "set xlabel '{/:Size=16 Posición}'" << endl;
	miki << "set ylabel '{/:Size=16 Velocidad}'" << endl;
	miki << "set output \"duff1.png\"" <<endl;
	miki << "set yrange [-2:2]"<<endl;
	miki << "plot 'data.dat' i 0 u 1:2 w l lw 4 lc 6 t '', '' i 1 u 1:2 w l lw 4 lc 7 t ''" <<endl;
	//miki << "\t '' u 1:2 w l t 'y'" <<endl;
	miki << "unset output" <<endl;
	miki.close();

	miki.open("duff_df.plt");
	miki << "set terminal pngcairo size 900,600" <<endl;
	miki << "set title '{/:Size=20 Oscilador de Duffing Caótico}'" << endl;
	miki << "set xlabel '{/:Size=16 Posición}'" << endl;
	miki << "set ylabel '{/:Size=16 Velocidad}'" << endl;
	miki << "set output \"duff1_df.png\"" <<endl;
	miki << "set xrange [-2:2]"<<endl;

	miki << "plot 'data.dat' i 0 u 2:3 w l lw 2 lc 6 t '', '' i 1 u 2:3 w l lw 2 lc 7 t ''" <<endl;
	//miki << "\t '' u 1:2 w l t 'y'" <<endl;
	miki << "unset output" <<endl;
	miki.close();

	system("gnuplot duff.plt");
	system("gnuplot duff_df.plt");


	return 0;
}
