#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){

// Bucle para calcular el número de datos
string yo; ifstream miko; miko.open("data.dat");
int cont = 0;
while(getline(miko, yo)){ cont++; }
miko.close();

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
system("mkdir figuras");
ofstream miki; miki.open("ani.plt");
miki << "set terminal gif enhanced transparent truecolor size 900,600" << endl;
miki << "set title '{/:Size=20 Oscilador de Duffing}'" << endl;
miki << "set xlabel '{/:Size=16 Posición}'" << endl;
miki << "set ylabel '{/:Size=16 Velocidad}'" << endl;
miki << "set xrange[0:100]" << endl;
miki << "set yrange[-2:2]" << endl;
miki << "unset tics" << endl;
miki << "set key" << endl;
miki << "set grid"<< endl << endl;
for(int i = 1; i< 500; i++){

if (10>i){ miki << "set output 'figuras/00" << i << ".png'" <<endl; }
else {
    if (100>i){ miki << "set output 'figuras/0" << i << ".png'" <<endl; }
    else {
        if (1000>i){ miki << "set output 'figuras/" << i << ".png'" <<endl; }
}}
miki << "plot 'data.dat' i 0 u 1:2 every ::"<<i+500<<"::"<<i+500<<" w p ps 3 pt 7 lc 6 t '', '' i 0 u 1:2 every ::::"<<i+500<<" w l lw 3 lt 1 lc 6 t '','' i 1 u 1:2 every ::"<<i+500<<"::"<<i+500<<" w p ps 3 pt 7 lc 7 t '', '' i 1 u 1:2 every ::::"<<i+500<<" w l lw 3 lt 1 lc 7 t ''" <<endl;
miki << "unset output" <<endl;
}
miki.close();


system("mkdir figuras_df");

miki.open("ani_df.plt");
miki << "set terminal gif enhanced transparent truecolor size 900,600" << endl;
miki << "set title '{/:Size=20 Oscilador de Duffing}'" << endl;
miki << "set xlabel '{/:Size=16 Posición}'" << endl;
miki << "set ylabel '{/:Size=16 Velocidad}'" << endl;
miki << "set xrange[-2:2]" << endl;
miki << "set yrange[-1:1]" << endl;
miki << "unset tics" << endl;
miki << "set key" << endl;
miki << "set grid"<< endl << endl;
for(int i = 1; i < 500; i++){

if (10>i){ miki << "set output 'figuras_df/00" << i << ".png'" <<endl; }
else {
    if (100>i){ miki << "set output 'figuras_df/0" << i << ".png'" <<endl; }
    else {
        if (1000>i){ miki << "set output 'figuras_df/" << i << ".png'" <<endl; }
    }}

//graficas
miki << "plot 'data.dat' i 0 u 2:3 every ::"<<i+500<<"::"<<i+500<<" w p ps 3 pt 7 lc 6 t '', '' i 0 u 2:3 every ::::"<<i+500<<" w l lw 3 lt 1 lc 6 t '','' i 1 u 2:3 every ::"<<i+500<<"::"<<i+500<<" w p ps 3 pt 7 lc 7 t '', '' i 1 u 2:3 every ::::"<<i+500<<" w l lw 3 lt 1 lc 7 t ''" <<endl;
miki << "unset output" <<endl;
}
miki.close();

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
system("gnuplot ani.plt");
system("convert -delay 3 -loop 0 figuras/*.png duff1.gif");

system("gnuplot ani_df.plt");
system("convert -delay 3 -loop 0 figuras_df/*.png duff_df1.gif");
return 0;
}



