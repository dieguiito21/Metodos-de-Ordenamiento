#include <iostream>
#include <limits>
using namespace std;												// Encabezados

void imprimir(int a[], int n);										// imprime el arreglo
void llenado(int a[], int a2[], int n);								// función para llenar el arreglo
void imprimirvueltas(int a[], int n, int contador);
char obtener_caracter_valido();										// Función de validación de caracteres
void intercambio(int a[], int i, int j, int contador, int n);		//swap
bool esta_ordenado(int a[], int n);									// Verificación de ordenado
void ord_intercambio(int a[], int n);								// Ordenamiento por Intercambio
void ord_seleccion(int a[], int n);									// Ordenamiento por Selección
void ord_burbuja(int a[], int n);									// Ordenamiento Burbuja
void ord_rapido(int a[], int izq, int der, int n);					// Ordenamiento Rapido
int busqueda_binaria(int a[], int bajo, int alto, int clave);		// Busqueda Binaria
int busqueda_secuencial(int a[], int inicio, int clave, int n);		// Busqueda Secuencial

int main(){
	setlocale(LC_ALL, "spanish");									// Idioma en español para los acentos
	int n, buscar;
	char varswitch;
	
	cout << endl << '\t' << '\t'<< "Métodos de ordenamiento" << endl;
	cout << '\t' << '\t' << "Hecho por: Castro Torres Diego - 5CM33" << endl << endl;		// Portada
	cout << '\t' << '\t' << "¿Listo para empezar? (1. Si || 0. Salir)  -->  ";
	varswitch = obtener_caracter_valido();
	
	if(varswitch == '1'){
		system("cls");
		cout << endl << endl << '\t'<< "Dime cúal será el tamaño de tu arreglo: ";
		cin >> n;
		int arreglo[n], arreglo2[n];			// Define el tamaño del arreglo
		
		llenado(arreglo, arreglo2, n);
		
		while(varswitch != '0'){
			
		for(int k = 0; k < n; k++){		// Copia el arreglo para usarlo y despues reutilizar el mismo
			arreglo[k] = arreglo2[k];
		}
		
		system("cls");
		cout << endl << '\t' << '\t' << "Tu arreglo es: "; imprimir(arreglo, n); cout << endl << endl;
		
		cout << endl << '\t' << '\t' << "Menú:" << endl;								// Menú
		cout << endl << '\t' << '\t' << "1. Llenar arreglo" << endl;
		cout << endl << '\t' << '\t' << "2. Ordenamiento por intercambio" << endl;
		cout << endl << '\t' << '\t' << "3. Ordenamiento por selección" << endl;
		cout << endl << '\t' << '\t' << "4. Ordenamiento por burbuja" << endl;
		cout << endl << '\t' << '\t' << "5. Ordenamiento rapido (quicksort)" << endl;
		cout << endl << '\t' << '\t' << "6. Busqueda por busqueda binaria" << endl;
		cout << endl << '\t' << '\t' << "7. Busqueda secuencial" << endl;
		cout << endl << '\t' << '\t' << "0. Salir" << endl;
		
		cout << endl << endl << '\t' << '\t' << "Elije la opción que deseas -->  ";
		cin >> varswitch;
		system("cls");		// Limpia la pantalla
		
		switch(varswitch){
			case '1':
	
			llenado(arreglo, arreglo2, n);	// Volver a llenar el arreglo manualmente
				
			break;

			case '2':
				
			cout << endl << endl << '\t' << '\t' << "El arreglo ingresado es:	" << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo original
			
			if(esta_ordenado(arreglo, n))	// Primero verifica si está ordenado
        		cout << endl << endl << '\t' << '\t' << "El arreglo YA está ordenado" << endl;
    		else{
		    
			cout << endl << endl << '\t' << '\t' << "El proceso es:	" << endl << endl;
			
			ord_intercambio(arreglo, n);	// Ordenamiento por Intercambio
				
			cout << endl << endl << '\t' << '\t' << "El arreglo ordenado es: " << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo ordenado
			
			}
			
			cout << endl << endl << '\t' << '\t' << "¿Deseas salir? (0. Si || 1. Continuar al menú) -->  ";
			varswitch = obtener_caracter_valido();
			
			break;
			
			case '3':
				
			cout << endl << endl << '\t' << '\t' << "El arreglo ingresado es:	" << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo original
			
			if(esta_ordenado(arreglo, n))	// Primero verifica si está ordenado
        		cout << endl << endl << '\t' << '\t' << "El arreglo YA está ordenado" << endl;
    		else{
			
			cout << endl << endl << '\t' << '\t' << "El proceso es:	" << endl << endl;
			
			ord_seleccion(arreglo, n);	// Ordenamiento por seleccion
			
			cout << endl << '\t' << '\t' << "El arreglo ordenado es: " << '\t' << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo ordenado
			
			}
			
			cout << endl << endl << '\t' << '\t' << "¿Deseas salir? (0. Si || 1. Continuar al menú) -->  ";
			varswitch = obtener_caracter_valido();
				
			break;	
				
			case '4':
				
			cout << endl << endl << '\t' << '\t' << "El arreglo ingresado es:	" << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo original
			
			if(esta_ordenado(arreglo, n))	// Primero verifica si está ordenado
        		cout << endl << endl << '\t' << '\t' << "El arreglo YA está ordenado" << endl;
    		else{
			
			cout << endl << endl << '\t' << '\t' << "El proceso es:	" << endl << endl;
			
			ord_burbuja(arreglo, n);	// Ordenamiento burbuja
			
			cout << endl << '\t' << '\t' << "El arreglo ordenado es: " << '\t' << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo ordenado
			
			}
			
			cout << endl << endl << '\t' << '\t' << "¿Deseas salir? (0. Si || 1. Continuar al menú) -->  ";
			varswitch = obtener_caracter_valido();
				
			break;
				
			case '5':		
			
			cout << endl << endl << '\t' << '\t' << "El arreglo ingresado es:	" << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo original
			
			if(esta_ordenado(arreglo, n))	// Primero verifica si está ordenado
        		cout << endl << endl << '\t' << '\t' << "El arreglo YA está ordenado" << endl;
    		else{
			
			cout << endl << endl << '\t' << '\t' << "El proceso es:	" << endl << endl;
			
			ord_rapido(arreglo, 0, n-1, n); // Ordenamiento rapido
			
			cout << endl << '\t' << '\t' << "El arreglo ordenado es: " << '\t' << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo ordenado
			
			}
			
			cout << endl << endl << '\t' << '\t' << "¿Deseas salir? (0. Si || 1. Continuar al menú) -->  ";
			varswitch = obtener_caracter_valido();
				
			break;
				
			case '6':
				
			ord_intercambio(arreglo, n);	// Ordenar el arreglo para que funcione el método
			system("cls");
			cout << endl << '\t' << '\t' << "Es necesario ordenar el arreglo por cualquier método";
			cout << endl << '\t' << '\t' << "El arreglo ordenado es: " << '\t' << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo ordenado
			
			cout << endl << endl << '\t' << '\t' << "Dime el número a buscar en el arreglo:	";
			cin >> buscar;	// Pedimos la clave de búsqueda
			
			if(buscar == arreglo[busqueda_binaria(arreglo, 0, n-1, buscar)])
				cout << endl << endl << '\t' << '\t' << "El valor SI se encuentra en el arreglo en la posicion: " << busqueda_binaria(arreglo, 0, n-1, buscar) + 1;
			else cout << endl << endl << '\t' << '\t' << "El valor NO se encuentra en el arreglo";
			
			cout << endl << endl << '\t' << '\t' << "¿Deseas salir? (0. Si || 1. Continuar al menú) -->  ";
			varswitch = obtener_caracter_valido();
	
			break;
				
			case '7':
			
			cout << endl << '\t' << '\t' << "El arreglo original es: " << '\t' << '\t';
			imprimir(arreglo, n);	// Imprime el arreglo, no es necesario ordenarlo
			
			cout << endl << endl << '\t' << '\t' << "Dime el número a buscar en el arreglo:	";
			cin >> buscar;	// Pedimos la clave de búsqueda
			
			if(buscar == arreglo[busqueda_secuencial(arreglo, 0, buscar, n)])
				cout << endl << endl << '\t' << '\t' << "El valor SI se encuentra en el arreglo en la posicion: " << busqueda_secuencial(arreglo, 0, buscar, n) + 1;
			else cout << endl << endl << '\t' << '\t' << "El valor NO se encuentra en el arreglo";
			
			cout << endl << endl << '\t' << '\t' << "¿Deseas salir? (0. Si || 1. Continuar al menú) -->  ";
			varswitch = obtener_caracter_valido();	
				
				break;
				
			case '0': 
			
			// Salida
		
			break;
			
			default:
				
				break;
				
		}	// Switch-case
		}	// While
	}	// If verificación
	return 0;
}	// Main

void imprimir(int a[], int n){
	for(int i = 0; i < n; i++)
		cout << a[i] << " | ";
	cout << endl;
}

void llenado(int a[], int a2[], int n){
    cout << endl << endl;
    for(int i = 0; i < n; i++){
        cout << '\t' << '\t' << "Dime el elemento " << i + 1 << " de tu arreglo:	";
        cin >> a[i];
        a2[i] = a[i];
    } 
}

void imprimirvueltas(int a[], int n, int contador){ // Imprime los cambios que se hacen
	cout << endl << '\t' << '\t' << " << ";
	for(int i = 0; i < n; i++)
		cout << a[i] << " | ";
	cout << " >>" << '\t' << " <--  Cambio en la iteración No. " << contador << endl;
}

bool esta_ordenado(int a[], int n){
    for (int i = 0; i < n - 1; i++)
        if(a[i] > a[i + 1]) return false; // Si algún elemento es mayor que el siguiente, no está ordenado
    return true; // Si no encontramos problemas, el arreglo está ordenado
}

char obtener_caracter_valido(){
    char opcion;
    
    while(true){
        cin >> opcion;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Limpiar el buffer de entrada

        if(opcion == '0' || opcion == '1'){	// Verificar si la opción ingresada es válida
            return opcion; // Si la opción es válida, la retorna
        } else {
            cout << endl << '\t' << '\t' << "Opción inválida. Por favor, ingresa una opción válida (0 o 1) ---->  ";
        }
    }
}

void intercambio(int a[], int i, int j, int contador, int n){
	int aux;
	if (a[i] > a[j]){
		aux = a[j];
		a[j] = a[i];
		a[i] = aux;
		imprimirvueltas(a, n, contador);
	}
}

void ord_intercambio(int a[], int n){
	int contador = 0;
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++){
			intercambio(a, i, j, contador, n);
			contador++;
		}
}

void ord_seleccion(int a[], int n){
	int menor, contador = 0;
	for(int correcta = 0; correcta < n - 1; correcta++){
		menor = correcta;
		for(int i = correcta + 1; i < n; i++)
			if(a[i] < a[menor])		menor = i;
		intercambio(a, correcta, menor, contador, n);
		contador++;
	}
}

void ord_burbuja(int a[], int n){
	int aux, j, pasada, contador = 0;
	bool interruptor = true;
	for(pasada = 0; pasada < (n-1) && (interruptor = true); pasada++){
		interruptor = false;
		for(j = 0; j < n - 1 - pasada; j++)
			if(a[j] > a[j + 1]){
				intercambio(a, j, j+1, contador, n);
				contador++;
				interruptor = true;
			}
	}
}

void ord_rapido(int a[], int izq, int der, int tam) {
    int pivote, aux;

    if (izq >= der) return; // Pivote de salida
    int m = izq;
    int n = der + 1;
    pivote = a[izq];

    cout << endl << '\t' << '\t' << "Llamada a ord_rapido con izq = " << izq << ", der = " << der << ", pivote = " << pivote << endl;

    while(true){
        do{
            m = m + 1;	// Recorre m a la derecha
        }while (m <= der && a[m] < pivote);

        do{
            n = n - 1;	// Recorre n a la izquierda
        }while (n >= izq && a[n] > pivote);

        if(m >= n) break;
        
        aux = a[m];									// Intercambio de elementos
        a[m] = a[n];
        a[n] = aux;
        
        cout << '\t' << '\t' << "Intercambio: ";	// Imprimir el arreglo completo después de cada intercambio
        imprimir(a, tam);
    } // While

    a[izq] = a[n];									// Ajuste final del pivote
    a[n] = pivote;

    cout << '\t' << '\t' << "Pivote colocado: ";
    imprimir(a, tam);

    ord_rapido(a, izq, n - 1, tam);					// Llamadas recursivas
    ord_rapido(a, n + 1, der, tam);					// Llamadas recursivas
}

int busqueda_binaria(int a[], int bajo, int alto, int clave){
	int central, valorCentral;
		while(bajo <= alto){
			central = (bajo + alto)/2;		// Central toma el valor medio entre el indicie menor y mayor
			valorCentral = a[central];
			if(clave == valorCentral)
				return central;				// Regresa la posición central
			else	if(clave < valorCentral)
					alto = central - 1;		// Si la clave es menor al número medio, alto toma la posición media menos una
			else	bajo = central + 1;		// Si la clave es mayor al número medio, bajo toma la posición media más una
		}	// while
}

int busqueda_secuencial(int a[], int inicio, int clave, int n){
	for(int i = inicio; i < n; i++)
		if(a[i] == clave)
			return i;
		return -1;
}
