#include <iostream>
#include <conio2.h>
using namespace std;

class Ficha{
private:
	char fichita;
public:
	Ficha();
	Ficha(char _fichita);
	void setFichita(char _fichita);
	char getFichita();
};
Ficha::Ficha(){
}
Ficha::Ficha(char _fichita){
	fichita=_fichita;
}
//No entiendo si es necesario poner el set o no para luego poner el GETFICHITA
void Ficha::setFichita(char _fichita){
	fichita=_fichita;
}
char Ficha::getFichita(){
	return fichita;
}
//************************************************************
class Tablero{
private: 
	Ficha tabla[3][3];
	//LA IDEA DE ESTE BOOLEANO ES QUE DETERMINE SI EL ESPACIO EN TABLA ESTA O NO OCUPADO
	bool arreBool[3][3];
public:
	Tablero();
	void SetFichaEnTabla(int x, int y, char c);
	void mostrarTabla();
};

Tablero::Tablero(){
	//INICIALIZANDO ARREGLO
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tabla[i][j]=' ';
		}
	}
	
	//INICIALIZANDO ARREGLO BOOLEANO
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			arreBool[i][j]=true;
		}
	}
}
//****************************************************************************************************************************
//****************************************************************************************************************************
void Tablero::SetFichaEnTabla(int x, int y, char c){
	tabla[x][y]=c;
	
	//ME GUSTARIA HACE QUE EL JUEGO NO TE PERMITA PONER EN ESE LUGAR.-
	if(arreBool[x][y]==true){
		arreBool[x][y]=false;
	}else{
		cout<<"Especio ocupado"<<endl;
		}
	}
//*****************************************************************************************************************************
//*****************************************************************************************************************************

void Tablero::mostrarTabla(){	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			//luego del arreglo poner ".getFichita()".
			cout<<tabla[i][j].getFichita()<<" | ";
		}
		cout<<endl;
	}
}

int main(int argc, char *argv[]) {
	/*
	4) Realizar un Tatetí para dos jugadores. El juego finaliza cuando se completa el tablero:
	Se da como ejemplo las clases Ficha, Tablero (que posee 9 fichas) y la Clase Juego que
	sirve para gestionar todas las reglas e impresión de pantalla.
	Se brindan los .h (cabeceras de métodos) cómo ayuda, no es obligatorio su uso aunque
	debe haber al menos 2 clases.
	*/
	
	Tablero tab1;
	tab1.SetFichaEnTabla(0,0,'X');
	tab1.SetFichaEnTabla(1,1,'X');
	tab1.SetFichaEnTabla(2,2,'O');
	tab1.mostrarTabla();
	cout<<endl;
	tab1.SetFichaEnTabla(0,2,'O');
	tab1.mostrarTabla();
	cout<<endl;
	//SELECCIONE UNA POSICION YA OCUPADA PERO LA REMPLAZA IGUAL
	tab1.SetFichaEnTabla(1,1,'O');
	tab1.mostrarTabla();
	
	return 0;
}

