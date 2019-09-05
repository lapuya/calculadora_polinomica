/*
Grupo F
Beatriz Álvarez de Arriba
Laurence Apuya Pangilinan
*/

#include <iostream>
#include <cmath> 
using namespace std;

const int MAX = 6;
typedef double tPolinomio [MAX];

void mostrarMenu ();
int menu ();
void cargarPolinomio(tPolinomio & polinomio);
void derivarPolinomio(tPolinomio & polinomio);
void integrarPolinomio(tPolinomio & polinomio);
void evaluarPolinomio (tPolinomio & polinomio);
void raicesPolinomio (tPolinomio & polinomio);
int calcularGrado(tPolinomio & polinomio);

int main ()
{
	int opcion;
	tPolinomio polinomio;
	
	opcion = menu ();
	while (opcion != 5)
	{
		if (opcion == 1) // Derivar polinomio
		{
			cargarPolinomio(polinomio);
			derivarPolinomio(polinomio);
		}
		else if (opcion == 2) // Integrar polinomio
		{
			cargarPolinomio(polinomio);
			integrarPolinomio(polinomio);
		}
		else if (opcion == 3) // Calcular polinomio para un valor de x
		{
			cargarPolinomio(polinomio);
			evaluarPolinomio (polinomio);
		}
		else // Calcular raices
		{
			cargarPolinomio(polinomio);
			raicesPolinomio (polinomio);
		}
		opcion = menu ();
	}
	
	return 0;
}

void mostrarMenu ()
{
	cout << "1- Derivar polinomio" <<endl;
	cout << "2- Integrar polinomios" <<endl;
	cout << "3- Evaluar" <<endl;
	cout << "4- Calcular raices" <<endl;
	cout << "5- Finalizar" <<endl;
	cout << "Elija opcion: ";
}

int menu ()
{
	int opcion;
	
	mostrarMenu ();
	cin >> opcion;
	while (opcion < 1 || opcion > 5)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "No es un numero" << endl;
		}
		else
			cout << "Numero no valido" << endl;
		mostrarMenu ();
		cin >> opcion;
	}
	
	return opcion;
}

void cargarPolinomio(tPolinomio & polinomio)
{
	//Introducimos valores hasta rellenar el array del polinomio
	for (int i = 0; i < MAX; i++)
	{
		cout << "Introduce el polinomio: ";
		cin >> polinomio[i];
	}
}

void derivarPolinomio(tPolinomio & polinomio)
{
	for (int i = MAX - 1; i > 0; i--)
	{
		if (polinomio[i] != 0)
		{
			if (i == 2 && polinomio[i-1] == 0)
			{
				if (polinomio[i] < 0)
					cout << "(" << polinomio[i] * i << ")" << "x" << i - 1;
				else
					cout << polinomio[i] * i << "x" << i - 1;
			}
			else if (i == 1)
			{
				if (polinomio[i] < 0)
					cout << "(" << polinomio[i] << ")";
				else
					cout << polinomio[i];
			}
			else
				if (polinomio[i] < 0)
					cout << "(" << polinomio[i] * i << ")" << "x" << i - 1 << "+";
				else
					cout << polinomio[i] * i << "x" << i - 1 << "+";
		}
	}
	cout << endl;
}

void integrarPolinomio(tPolinomio & polinomio)
{
	for (int i = MAX - 1; i >= 0; i--)
	{
		if (polinomio[i] != 0)
		{
			if (polinomio[i] < 0)
					cout << "(" << polinomio[i] / (i + 1) << ")" << "x" << i + 1 << "+";
			else
				cout << polinomio[i] / (i + 1) << "x" << i + 1 << "+";
		}
	}
	cout << "C" << endl;
}

void evaluarPolinomio (tPolinomio & polinomio)
{
	int resultado = 0, numero;
	
	cout << "Dame un valor de x: ";
	cin >> numero;
	  
	for (int i = MAX - 1; i >= 0; i--)
		resultado = resultado + polinomio[i]*pow(numero, i);
	
	cout << resultado << endl;
}

void raicesPolinomio (tPolinomio & polinomio)
{
	int grado = 0;
	float resultado1, resultado2;
	
	grado = calcularGrado(polinomio);
	
	resultado1 = (-polinomio[1]+(sqrt(pow(polinomio[1],2)-4*polinomio[2]*polinomio[0])))/(2*polinomio[2]);
	resultado2 = (-polinomio[1]-(sqrt(pow(polinomio[1],2)-4*polinomio[2]*polinomio[0])))/(2*polinomio[2]);
	
	if (grado > 2)
		cout << "Este polinomio es de un grado mayor" << endl;
	else if ((resultado1 <= 0 && resultado2 <= 0) || (resultado1 > 0 && resultado2 > 0 ) || (resultado1 < 0 && resultado2 > 0) || (resultado1 > 0 && resultado2 <0))
	{
		cout << "Las raices son: ";
		cout << resultado1 << " y " << resultado2 << endl;
	}
	else 
		cout << "Son raices complejas" << endl;
}

int calcularGrado(tPolinomio & polinomio)
{
	int i = MAX-1;
	
	while(polinomio[i] == 0 )
		i--;
	
	return i;
}


