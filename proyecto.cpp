#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype> // Para tolower
#include <iomanip> // Para setw

using namespace std;

// Estructura para representar un Libro
struct sLibro {
	string sTitulo;
	string sAutor;
	string sISBN;
	int iAnioPublicacion;
	string sEditorial;
	int iNumeroPaginas;
};

// Estructura para representar un Usuario
struct sUsuario {
	int iId;
	string sNombre;
	string sApellido;
	string sEmail;
	string sTelefono;
};

// Estructura para representar un Bibliotecario
struct sBibliotecario {
	int iId;
	string sNombre;
	string sApellido;
	string sEmail;
	int iNivel;
};

// Funci�n para imprimir un libro
void imprimir(sLibro libro)
{
	cout << left << setw(25) << "Titulo" << setw(31) << "Autor" << setw(15) << "ISBN" << setw(10) << "A�o" << setw(30) << "Editorial" << setw(10) << "P�ginas" << endl;
	cout << left << setw(25) << libro.sTitulo << setw(31) << libro.sAutor << setw(15) << libro.sISBN << setw(10) << libro.iAnioPublicacion << setw(30) << libro.sEditorial << setw(10) << libro.iNumeroPaginas<<"\n" << endl;
}

// Funci�n para imprimir un usuario
void imprimir(sUsuario usuario)
{
	cout << left << setw(10) << "ID:" <<left << setw(25)<<usuario.iId<< left << setw(20) << "Nombre:" <<left << setw(25)<< usuario.sNombre + " " + usuario.sApellido << endl;<< left << setw(20) << "Email:" <<left << setw(25)<< usuario.sEmail << endl;<< left << setw(20) << "Tel�fono:" <<left << setw(25)<< usuario.sTelefono << "\n" << endl;
}

// Funci�n para imprimir un bibliotecario
void imprimir(sBibliotecario bibliotecario)
{
	cout << left << setw(10) << "ID:" <<left << setw(25)<< bibliotecario.iId << endl;
	cout << left << setw(20) << "Nombre:" <<left << setw(25)<< bibliotecario.sNombre + " " + bibliotecario.sApellido << endl;
	cout << left << setw(20) << "Email:" <<left << setw(25)<< bibliotecario.sEmail << endl;
	cout << left << setw(20) << "Nivel:" <<left << setw(25)<< bibliotecario.iNivel << "\n" << endl;
}

// Funci�n para llenar datos de libros
void llenarDatos(sLibro *arrLibros, int cant)
{
	// Datos predefinidos para los libros
	string listaTitulos[] = {"El Alquimista", "Cien a�os de soledad", "1984", "Don Quijote de la Mancha", "Matar un ruise�or"};
	string listaAutores[] = {"Paulo Coelho", "Gabriel Garc�a M�rquez", "George Orwell", "Miguel de Cervantes", "Harper Lee"};
	string listaISBN[] = {"9780062315007", "9788466333978", "9788416100006", "9781546560743", "9788478888566"};
	int listaAnios[] = {1988, 1967, 1949, 1605, 1960};
	
	for (int i = 0; i < cant; ++i)
	{
		// Asignar valores de acuerdo a las listas predefinidas
		arrLibros[i].sTitulo = listaTitulos[i];
		arrLibros[i].sAutor = listaAutores[i];
		arrLibros[i].sISBN = listaISBN[i];
		arrLibros[i].iAnioPublicacion = listaAnios[i];
		
		// Establecer la editorial y el n�mero de p�ginas basados en un switch
		switch (i)
		{
		case 0:
			arrLibros[i].sEditorial = "Santillana Ediciones Generales";
			arrLibros[i].iNumeroPaginas = 224;
			break;
		case 1:
			arrLibros[i].sEditorial = "Editorial Sudamericana";
			arrLibros[i].iNumeroPaginas = 424;
			break;
		case 2:
			arrLibros[i].sEditorial = "Debolsillo";
			arrLibros[i].iNumeroPaginas = 352;
			break;
		case 3:
			arrLibros[i].sEditorial = "Espasa-Calpe";
			arrLibros[i].iNumeroPaginas = 1044;
			break;
		case 4:
			arrLibros[i].sEditorial = "HarperCollins Publishers";
			arrLibros[i].iNumeroPaginas = 320;
			break;
		}
	}
}

// Funci�n para llenar datos de usuarios
void llenarDatos(sUsuario *arrUsuarios, int cant)
{
	// Datos predefinidos para los usuarios
	string listaNombres[] = {"Juan", "Pedro", "Maria", "Luisa"};
	string listaApellidos[] = {"Gomez", "Perez", "Lopez", "Gonzalez"};
	
	for (int i = 0; i < cant; ++i)
	{
		// Asignar valores de acuerdo a las listas predefinidas
		arrUsuarios[i].iId = i + 1;
		arrUsuarios[i].sNombre = listaNombres[i];
		arrUsuarios[i].sApellido = listaApellidos[i];
		arrUsuarios[i].sEmail = arrUsuarios[i].sNombre + "." + arrUsuarios[i].sApellido + "@upds.net.com";
		arrUsuarios[i].sTelefono = "123456789";
	}
}

// Funci�n para llenar datos de bibliotecarios
void llenarDatos(sBibliotecario *arrBibliotecarios, int cant)
{
	// Datos predefinidos para los bibliotecarios
	string listaNombres[] = {"Carlos", "Ana", "Diego", "Laura"};
	string listaApellidos[] = {"Martinez", "Gutierrez", "Rodriguez", "Perez"};
	
	for (int i = 0; i < cant; ++i)
	{
		// Asignar valores de acuerdo a las listas predefinidas
		arrBibliotecarios[i].iId = i + 1;
		arrBibliotecarios[i].sNombre = listaNombres[i];
		arrBibliotecarios[i].sApellido = listaApellidos[i];
		arrBibliotecarios[i].sEmail = arrBibliotecarios[i].sNombre + "." + arrBibliotecarios[i].sApellido + "@upds.net.com";
		arrBibliotecarios[i].iNivel = rand() % 10 + 1;
	}
}

// Funci�n para convertir una cadena a min�sculas
string toLower(string str)
{
	for (char& c : str) {
		c = tolower(c);
	}
	return str;
}

int main()
{
	srand(time(0));
	
	const int NUM_ELEMENTOS = 4;// numero de usurios, blibiotecarios y libros que se van a imprimir
	
	sLibro arrLibros[NUM_ELEMENTOS];
	sUsuario arrUsuarios[NUM_ELEMENTOS];
	sBibliotecario arrBibliotecarios[NUM_ELEMENTOS];
	
	llenarDatos(arrLibros, NUM_ELEMENTOS); // Llenar datos de libros
	llenarDatos(arrUsuarios, NUM_ELEMENTOS); // Llenar datos de usuarios
	llenarDatos(arrBibliotecarios, NUM_ELEMENTOS); // Llenar datos de bibliotecarios
	
	char opcionMenuPrincipal;
	
	do
	{
		// Men� principal
		cout << "1. Llenado de datos\n";
		cout << "2. Listados\n";
		cout << "3. Busquedas\n";
		cout << "0. Salir\n";
		cout << "Ingrese opci�n: ";
		cin >> opcionMenuPrincipal;
		opcionMenuPrincipal = tolower(opcionMenuPrincipal); // Convertir la opci�n a min�sculas
		
		switch (opcionMenuPrincipal)
		{
		case '1':
			// Llenado de datos, ya se realiz� previamente
			break;
		case '2':
		{
			// Men� de listados
			char opcionListados;
			cout << "a) Listado de libros\n";
			cout << "b) Listado de usuarios\n";
			cout << "c) Listado de bibliotecarios\n";
			cout << "x) Salir\n";
			cout << "Ingrese opci�n: ";
			cin >> opcionListados;
			opcionListados = tolower(opcionListados); // Convertir la opci�n a min�sculas
			
			switch (opcionListados)
			{
			case 'a':
				cout << "Listado de libros:\n";
				for (int i = 0; i < NUM_ELEMENTOS; ++i)
				{
					imprimir(arrLibros[i]);
				}
				break;
			case 'b':
				cout << "Listado de usuarios:\n";
				for (int i = 0; i < NUM_ELEMENTOS; ++i)
				{
					imprimir(arrUsuarios[i]);
				}
				break;
			case 'c':
				cout << "Listado de bibliotecarios:\n";
				for (int i = 0; i < NUM_ELEMENTOS; ++i)
				{
					imprimir(arrBibliotecarios[i]);
				}
				break;
			case 'x':
				break;
			default:
				cout << "Opci�n no v�lida.\n";
				break;
			}
			break;
		}
		case '3':
		{
			// Men� de b�squedas
			char opcionBusqueda;
			cout << "A) Busqueda de libro\n";
			cout << "B) Busqueda de usuario\n";
			cout << "C) Busqueda de bibliotecario\n";
			cout << "X) Salir\n";
			cout << "Ingrese opci�n: ";
			cin >> opcionBusqueda;
			opcionBusqueda = tolower(opcionBusqueda); // Convertir la opci�n a min�sculas
			
			switch (opcionBusqueda)
			{
			case 'a':
			{
				string tituloBusqueda;
				cout << "Ingrese parte del t�tulo del libro a buscar: ";
				cin.ignore();
				getline(cin, tituloBusqueda);
				
				// Convertir el t�tulo de la b�squeda a min�sculas
				tituloBusqueda = toLower(tituloBusqueda);
				
				bool encontrado = false;
				for (int i = 0; i < NUM_ELEMENTOS; ++i)
				{
					// Convertir el t�tulo del libro almacenado a min�sculas para comparar
					string tituloLibro = toLower(arrLibros[i].sTitulo);
					if (tituloLibro.find(tituloBusqueda) != string::npos)
					{
						cout << "Libro encontrado:\n";
						imprimir(arrLibros[i]);
						encontrado = true;
					}
				}
				if (!encontrado)
					cout << "Libro no encontrado.\n";
				break;
			}
			case 'b':
			{
				string nombreUsuarioBusqueda;
				cout << "Ingrese el nombre del usuario a buscar: ";
				cin.ignore();
				getline(cin, nombreUsuarioBusqueda);
				
				bool encontrado = false;
				for (int i = 0; i < NUM_ELEMENTOS; ++i)
				{
					string nombreUsuario = arrUsuarios[i].sNombre + " " + arrUsuarios[i].sApellido;
					if (toLower(nombreUsuario) == toLower(nombreUsuarioBusqueda))
					{
						cout << "Usuario encontrado:\n";
						imprimir(arrUsuarios[i]);
						encontrado = true;
					}
				}
				if (!encontrado)
					cout << "Usuario no encontrado.\n";
				break;
			}
			case 'c':
			{
				string nombreBibliotecarioBusqueda;
				cout << "Ingrese el nombre del bibliotecario a buscar: ";
				cin.ignore();
				getline(cin, nombreBibliotecarioBusqueda);
				
				bool encontrado = false;
				for (int i = 0; i < NUM_ELEMENTOS; ++i)
				{
					string nombreBibliotecario = arrBibliotecarios[i].sNombre + " " + arrBibliotecarios[i].sApellido;
					if (toLower(nombreBibliotecario) == toLower(nombreBibliotecarioBusqueda))
					{
						cout << "Bibliotecario encontrado:\n";
						imprimir(arrBibliotecarios[i]);
						encontrado = true;
					}
				}
				if (!encontrado)
					cout << "Bibliotecario no encontrado.\n";
				break;
			}
			
			case 'x':
				break;
			default:
				cout << "Opci�n no v�lida.\n";
				break;
			}
			break;
		}
		case '0':
			cout << "Saliendo del programa.\n";
			break;
		default:
			cout << "Opci�n no v�lida.\n";
			break;
		}
		
	} while (opcionMenuPrincipal != '0');
	
	return 0;
}
