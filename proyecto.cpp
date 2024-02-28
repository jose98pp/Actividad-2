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
	string sGenero;
};

// Estructura para representar un Usuario
struct sUsuario {
	int iId;
	string sNombre;
	string sApellido;
	string sEmail;
	string sTelefono;
	string sDireccion;
};

// Estructura para representar un Bibliotecario
struct sBibliotecario {
	int iId;
	string sNombre;
	string sApellido;
	string sEmail;
	int iNivel;
	string sHorario; 
};
// Declaración de la función repetidos
bool repetidos(string nombre, string apellido, sUsuario usuarios[], int cantUsuarios);
bool repetidos(string nombre, string apellido, sBibliotecario bibliotecarios[], int cantBibliotecarios);


// Función para imprimir un libro en forma de tabla
void imprimir(sLibro libro)
{
	cout << "+------+-------------------------+----------------------+------------------+-------------------------+----------+" << endl;
	cout << "| Titulo                  | Autor                   | ISBN           | Año Publicacion | Editorial               | Páginas  |" << endl;
	cout << "+-------------------------+-------------------------+----------------------+------------------+-------------------------+----------+" << endl;
	cout << "| " << setw(20) << libro.sTitulo << " | " << setw(24) << libro.sAutor << " | " << setw(16) << libro.sISBN << " | " << setw(16) << libro.iAnioPublicacion << " | " << setw(24) << libro.sEditorial << " | " << setw(8) << libro.iNumeroPaginas << " |" << endl;
	cout << "+-------------------------+-------------------------+----------------------+------------------+-------------------------+----------+" << endl;
}


// Función para imprimir un usuario en forma de tabla
void imprimir(sUsuario usuario)
{
	cout << "+------+-------------------------+----------------------+-------------------------+---------------+------------------" << endl;
	cout << "| ID   | Nombre                  | Apellido             | Email                   | Teléfono      |     Direccion    |" << endl;
	cout << "+------+-------------------------+----------------------+-------------------------+---------------+------------------" << endl;
	cout << "| " << setw(4) << usuario.iId << " | " << setw(22) << usuario.sNombre << " | " << setw(18) << usuario.sApellido << " | " << setw(24) << usuario.sEmail << " | " << setw(13) << usuario.sTelefono << " |" <<setw(10)<< usuario.sDireccion<< " |" << endl;
	cout << "+------+-------------------------+----------------------+-------------------------+---------------+------------------" << endl;
}


// Función para imprimir un bibliotecario en forma de tabla
void imprimir(sBibliotecario bibliotecario)
{
	cout << "+------+-------------------------+----------------------+-------------------------+-------+------------" << endl;
	cout << "| ID   | Nombre                  | Apellido             | Email                   | Nivel |   Horario  |" << endl;
	cout << "+------+-------------------------+----------------------+-------------------------+-------+------------" << endl;
	cout << "| " << setw(4) << bibliotecario.iId << " | " << setw(22) << bibliotecario.sNombre << " | " << setw(18) << bibliotecario.sApellido << " | " << setw(24) << bibliotecario.sEmail << " | " << setw(5) << bibliotecario.iNivel << " |" <<setw(10)<< bibliotecario.sHorario<< " |" << endl;
	cout << "+------+-------------------------+----------------------+-------------------------+-------+------------" << endl;
}


// Función para llenar datos de libros
void llenarDatos(sLibro *arrLibros, int cant)
{
	// Datos predefinidos para los libros
	string listaTitulos[] = {"El Alquimista", "Cien años de soledad", "1984", "Don Quijote de la Mancha", "Matar un ruiseñor", "Harry Potter y la piedra filosofal", "El señor de los anillos", "Crimen y castigo"};
	string listaAutores[] = {"Paulo Coelho", "Gabriel García Márquez", "George Orwell", "Miguel de Cervantes", "Harper Lee", "J.K. Rowling", "J.R.R. Tolkien", "Fyodor Dostoevsky"};
	string listaISBN[] = {"9780062315007", "9788466333978", "9788416100006", "9781546560743", "9788478888566", "9788478884452", "9780544003415", "9780141439617"};
	int listaAnios[] = {1988, 1967, 1949, 1605, 1960, 1997, 1954, 1866};
	
	for (int i = 0; i < cant; ++i)
	{
		// Asignar valores de acuerdo a las listas predefinidas
		arrLibros[i].sTitulo = listaTitulos[i];
		arrLibros[i].sAutor = listaAutores[i];
		arrLibros[i].sISBN = listaISBN[i];
		arrLibros[i].iAnioPublicacion = listaAnios[i];
		
		// Establecer la editorial y el número de páginas basados en un switch
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
		case 5:
			arrLibros[i].sEditorial = "Bloomsbury Publishing";
			arrLibros[i].iNumeroPaginas = 332;
			break;
		case 6:
			arrLibros[i].sEditorial = "Editorial Reverté";
			arrLibros[i].iNumeroPaginas = 551;
			break;
		case 7:
			arrLibros[i].sEditorial = "T. Egerton, Whitehall";
			arrLibros[i].iNumeroPaginas = 279;
			break;
		}
	}
}

// Función para llenar datos de usuarios
void llenarDatos(sUsuario *arrUsuarios, int cant)
{
	// Datos predefinidos para los usuarios
	string listaNombres[] = {"Juan", "Pedro", "Maria", "Luisa", "Carlos", "Ana", "Diego", "Laura"};
	string listaApellidos[] = {"Gomez", "Perez", "Lopez", "Gonzalez", "Martinez", "Gutierrez", "Rodriguez", "Perez"};
	string listaDirecciones[] = {"Calle A", "Calle B", "Calle C", "Calle D", "Calle E", "Calle F", "Calle G", "Calle H"};

	
	for (int i = 0; i < cant; ++i)
	{
		// Generar un nombre y apellido único
		string nombre, apellido;
		do {
			nombre = listaNombres[rand() % 8];
			apellido = listaApellidos[rand() % 8];
		} while (repetidos(nombre, apellido, arrUsuarios, i)); // Verificar si el nombre y apellido ya existen
		
		// Asignar valores de acuerdo a los nombres y apellidos generados
		arrUsuarios[i].iId = i + 1;
		arrUsuarios[i].sNombre = nombre;
		arrUsuarios[i].sApellido = apellido;
		arrUsuarios[i].sEmail = arrUsuarios[i].sNombre + to_string('.') + arrUsuarios[i].sApellido + "@upds.net.com";		
		arrUsuarios[i].sTelefono = "123456789";
		arrUsuarios[i].sDireccion = listaDirecciones[rand() % 8];
	}
}

// Función para llenar datos de bibliotecarios
void llenarDatos(sBibliotecario *arrBibliotecarios, int cant)
{
	// Datos predefinidos para los bibliotecarios
	string listaNombres[] = {"Carlos", "Ana", "Diego", "Laura", "Roberto", "María", "Javier", "Lucía"};
	string listaApellidos[] = {"Martinez", "Gutierrez", "Rodriguez", "Perez", "Fernandez", "Sanchez", "Lopez", "Garcia"};
	string listaHorarios[] = {"Mañana", "Tarde", "Noche"};
	
	for (int i = 0; i < cant; ++i)
	{
		// Generar un nombre y apellido único
		string nombre, apellido;
		do {
			nombre = listaNombres[rand() % 8];
			apellido = listaApellidos[rand() % 8];
		} while (repetidos(nombre, apellido, arrBibliotecarios, i)); // Verificar si el nombre y apellido ya existen
		
		// Asignar valores de acuerdo a los nombres y apellidos generados
		arrBibliotecarios[i].iId = i + 1;
		arrBibliotecarios[i].sNombre = nombre;
		arrBibliotecarios[i].sApellido = apellido;
		arrBibliotecarios[i].sEmail = arrBibliotecarios[i].sNombre + to_string('.') + arrBibliotecarios[i].sApellido + "@upds.net.com";		
		arrBibliotecarios[i].iNivel = rand() % 10 + 1;
		arrBibliotecarios[i].sHorario = listaHorarios[rand() % 3];
	}
}

// Función para verificar si un nombre y apellido ya está repetido en el array de personas
bool repetidos(string nombre, string apellido, sUsuario usuarios[], int cantUsuarios) {
	for (int i = 0; i < cantUsuarios; i++) {
		if (nombre == usuarios[i].sNombre && apellido == usuarios[i].sApellido)
			return true; // Si encuentra un nombre y apellido igual, devuelve true
	}
	return false; // Si no encuentra nombres y apellidos iguales, devuelve false
}

// Función para verificar si un nombre y apellido ya está repetido en el array de bibliotecarios
bool repetidos(string nombre, string apellido, sBibliotecario bibliotecarios[], int cantBibliotecarios) {
	for (int i = 0; i < cantBibliotecarios; i++) {
		if (nombre == bibliotecarios[i].sNombre && apellido == bibliotecarios[i].sApellido)
			return true; // Si encuentra un nombre y apellido igual, devuelve true
	}
	return false; // Si no encuentra nombres y apellidos iguales, devuelve false
}

// Función para convertir una cadena a minúsculas
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
	
	const int NUM_ELEMENTOS = 4; // Número de libros, usuarios y bibliotecarios
	
	sLibro arrLibros[NUM_ELEMENTOS];
	sUsuario arrUsuarios[NUM_ELEMENTOS];
	sBibliotecario arrBibliotecarios[NUM_ELEMENTOS];
	
	char opcionMenuPrincipal;
	
	do
	{
		system("cls"); // Borrar la pantalla antes de mostrar el menú
		
		// Menú principal
		cout << "1. Llenado de datos\n";
		cout << "2. Listados\n";
		cout << "3. Búsquedas\n";
		cout << "0. Salir\n";
		cout << "Ingrese opción: ";
		cin >> opcionMenuPrincipal;
		opcionMenuPrincipal = tolower(opcionMenuPrincipal); // Convertir la opción a minúsculas
		
		switch (opcionMenuPrincipal)
		{
		case '1':
		{
			// Llenado de datos
			llenarDatos(arrLibros, NUM_ELEMENTOS); // Llenar datos de libros
			llenarDatos(arrUsuarios, NUM_ELEMENTOS); // Llenar datos de usuarios
			llenarDatos(arrBibliotecarios, NUM_ELEMENTOS); // Llenar datos de bibliotecarios
			break;
		}
		case '2':
		{
			// Menú de listados
			char opcionListados;
			do {
				cout << "a) Listado de libros\n";
				cout << "b) Listado de usuarios\n";
				cout << "c) Listado de bibliotecarios\n";
				cout << "x) Volver al menú principal\n";
				cout << "Ingrese opción: ";
				cin >> opcionListados;
				opcionListados = tolower(opcionListados); // Convertir la opción a minúsculas
				
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
					cout << "Volviendo al menú principal.\n";
					break;
				default:
					cout << "Opción no válida.\n";
					break;
				}
			} while (opcionListados != 'x');
			break;
		}
		case '3':
		{
			// Menú de búsquedas
			char opcionBusqueda;
			do {
				cout << "A) Búsqueda de libro\n";
				cout << "B) Búsqueda de usuario\n";
				cout << "C) Búsqueda de bibliotecario\n";
				cout << "x) Volver al menú principal\n";
				cout << "Ingrese opción: ";
				cin >> opcionBusqueda;
				opcionBusqueda = tolower(opcionBusqueda); // Convertir la opción a minúsculas
				
				switch (opcionBusqueda)
				{
				case 'a':
				{
					string tituloBusqueda;
					cout << "Ingrese el título del libro a buscar: ";
					cin.ignore();
					getline(cin, tituloBusqueda);
					
					// Convertir el título de la búsqueda a minúsculas
					tituloBusqueda = toLower(tituloBusqueda);
					
					bool encontrado = false;
					for (int i = 0; i < NUM_ELEMENTOS; ++i)
					{
						// Convertir el título del libro almacenado a minúsculas para comparar
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
					string nombreApellidoBusqueda;
					cout << "Ingrese parte del nombre o del apellido del usuario a buscar: ";
					cin.ignore();
					getline(cin, nombreApellidoBusqueda);
					
					// Convertimos la búsqueda a minúsculas
					nombreApellidoBusqueda = toLower(nombreApellidoBusqueda);
					
					bool encontrado = false;
					for (int i = 0; i < NUM_ELEMENTOS; ++i)
					{
						string nombreCompleto = toLower(arrUsuarios[i].sNombre + " " + arrUsuarios[i].sApellido);
						string apellido = toLower(arrUsuarios[i].sApellido);
						// Realizamos la búsqueda tanto en el nombre completo como en el apellido
						if (nombreCompleto.find(nombreApellidoBusqueda) != string::npos || apellido.find(nombreApellidoBusqueda) != string::npos)
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
					string nombreApellidoBusqueda;
					cout << "Ingrese parte del nombre o del apellido del bibliotecario a buscar: ";
					cin.ignore();
					getline(cin, nombreApellidoBusqueda);
					
					// Convertimos la búsqueda a minúsculas
					nombreApellidoBusqueda = toLower(nombreApellidoBusqueda);
					
					bool encontrado = false;
					for (int i = 0; i < NUM_ELEMENTOS; ++i)
					{
						string nombreCompleto = toLower(arrBibliotecarios[i].sNombre + " " + arrBibliotecarios[i].sApellido);
						string apellido = toLower(arrBibliotecarios[i].sApellido);
						// Realizamos la búsqueda tanto en el nombre completo como en el apellido
						if (nombreCompleto.find(nombreApellidoBusqueda) != string::npos || apellido.find(nombreApellidoBusqueda) != string::npos)
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
				
				default:
					cout << "Opción no válida.\n";
					break;
				}
			} while (opcionBusqueda != 'x');
			break;
		}
		case '0':
			cout << "Saliendo del programa.\n";
			break;
		default:
			cout << "Opción no válida.\n";
			break;
		}
		
	} while (opcionMenuPrincipal != '0');
	
	return 0;
}
