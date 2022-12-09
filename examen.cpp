//FONSECA SANCHEZ JORGE JARED GRUPO:2CV3
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <ctime>
using namespace std;


struct NODO{
	
	string clave;
	string producto;
	string precio;
	string caducidad;
	NODO *sig;
};

void insertar(string clave, string producto, string precio, string caducidad, NODO *&p)
{
	NODO *nuevo = new NODO();
	
	nuevo->clave = clave;
	nuevo->producto = producto;
	nuevo->precio = precio;
	nuevo->caducidad = caducidad;
	nuevo->sig = p;
	
	p = nuevo;
}

void ver_carrito(NODO *&p)
{
	if(p != NULL)
	{
		fflush(stdin);
		cout << "   CLAVE    PRODUCTO    PRECIO       CADUCIDAD"<< endl;
		for(p->sig; p->sig != NULL; p = p->sig)
		{
			cout << "   " << p->clave << "   " << p->producto << "   " << p->precio <<"   " << p->caducidad << endl;
		}
	}
	else
	cout << "El carrito esta vacio" << endl;
	
}

void quitar(NODO *p)
{
	if(p != NULL)
	{
		string clave ="";
		fflush(stdin);
		cout << "Que producto desea quitar: ";
		cin >> clave;
		for(p->sig; p->sig != NULL; p = p->sig)
		{
			if(clave == p->clave)
			{
				p->sig = p->sig->sig;
				delete(p);
			}
		}
	}
	else
	cout << "El carrito esta vacio" << endl;
}

void pagar(NODO *p)
{
	int suma = 0, pt = 0;
	if(p != NULL)
	{
		fflush(stdin);
		for(p->sig; p->sig != NULL; p = p->sig)
		{
			pt = (((11)*60)/100) + 11;
			suma = suma + pt;
		}
		cout << "La cantidad a pagar es de " << suma << " dolares" << endl;
	}
	else
	cout << "El carrito esta vacio" << endl;
}

string linea;
int main()
{
	NODO *p;
	int m = 4, n = 5;
	int i = 0, j = 0;
	int clave = 0;
	string A[m][n];
	stringstream clonazepam;
	string ss  = "";
	int opc = 0, pay = 0;
	string clave_carrito = "";
	
	
	do{
			cout << "     TIENDA LA ODISEA" << endl;
			cout << "-------------------------" << endl;
			cout << "1. Agregar al carrito" << endl;
			cout << "2. Ver el carrito" << endl;
			cout << "3. Quitar del carrito" << endl;
			cout << "4. Pagar" << endl;
			cout << "5. Cerrar" << endl;
			cin >> opc;
			
			switch(opc)
			{
				case 1: //leer valores TABLA HASH
				{
					system("cls");
					ifstream archivo("valores.txt");
					
					srand(time(NULL));
					A[0][0] = "CLAVE";
					A[0][1] = "PRODUCTO";
					A[0][2] = "PRECIO";
					A[0][3] = "UNIDADES";
					A[0][4] = "CADUCIDAD";
					for(i = 1; i < m; i++)
					{
						for(j = 0; j < n; j++)
						{
							if(j == 0)
							{
								clave = rand()%100;
								clonazepam << clave;
								clonazepam >> ss;
				
								A[i][j] = ss;
							}
							else
							{
								getline(archivo, linea);
								A[i][j] = linea;
							}	
							clave = 0;
						}
					}
					
					//MENU DE PRODUCTOS
					
					cout << "Menu de productos" << endl;
					for(i = 0; i < m; i++)
					{
						for(j = 0; j < n; j++)
						{
							cout << "          " << A[i][j] << "   ";
						}
						cout << endl << "--------------------------------------------------------------------------" << endl;
					}
					
					
				}
				
				cout << "Inserte el nombre de lo que quiera agregar al carrito / Si pone fin dejara de agregar cosas" << endl;
				
				do{
					cout << "inserte : ";
					cin >> clave_carrito;
					
					if(clave_carrito != "fin")
					{
						for(i = 1; i < m; i++)
						{
							if(clave_carrito == A[i][0]) //PRODUCTO ENCONTRADO
							{
								insertar(A[i][0], A[i][1], A[i][2], A[i][4], p);
							}
						}
					}
					
				}while(clave_carrito != "fin");
				
				
				system("pause");
				system("cls");
				break;
		
				case 2: //VER EL CARRITO
				{
					ver_carrito(p);
				}	
				break;
		
				case 3: //QUITAR COSAS DEL CARRITO
				{
					quitar(p);
				}
				break;
		
				case 4: 
				{
					pagar(p);
				}
				break;
			}
		}while(opc != 5);
	
	
	return 0;
}
