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
bool bRepetidosUsuario(string sNombre, string sApellido, sUsuario arrUsuarios[], int iCantUsuarios);
bool bRepetidosBibliotecario(string sNombre, string sApellido, sBibliotecario arrBibliotecarios[], int iCantBibliotecarios);

// Función para imprimir un libro en forma de tabla
void imprimirLibro(sLibro libro)
{
    cout << "+------+-------------------------+----------------------+------------------+-------------------------+----------+" << endl;
    cout << "| Titulo                  | Autor                   | ISBN           | Año Publicacion | Editorial               | Páginas  |" << endl;
    cout << "+-------------------------+-------------------------+----------------------+------------------+-------------------------+----------+" << endl;
    cout << "| " << setw(20) << libro.sTitulo << " | " << setw(24) << libro.sAutor << " | " << setw(16) << libro.sISBN << " | " << setw(16) << libro.iAnioPublicacion << " | " << setw(24) << libro.sEditorial << " | " << setw(8) << libro.iNumeroPaginas << " |" << endl;
    cout << "+-------------------------+-------------------------+----------------------+------------------+-------------------------+----------+" << endl;
}

// Función para imprimir un usuario en forma de tabla
void imprimirUsuario(sUsuario usuario)
{
    cout << "+------+-------------------------+-------------------------+----------------------------+---------------+------------------" << endl;
    cout << "| ID   |    Nombre               |     Apellido            |    Email                   | Teléfono      |     Dirección    |" << endl;
    cout << "+------+-------------------------+-------------------------+----------------------------+---------------+------------------" << endl;
    cout << "| " << setw(4) << usuario.iId << " | " << setw(22) << usuario.sNombre << " | " << setw(18) << usuario.sApellido << " | " << setw(24) << usuario.sEmail << " | " << setw(13) << usuario.sTelefono << " |" <<setw(10)<< usuario.sDireccion<< " |" << endl;
    cout << "+------+-------------------------+----------------------+-------------------------+---------------+------------------" << endl;
}

// Función para imprimir un bibliotecario en forma de tabla
void imprimirBibliotecario(sBibliotecario bibliotecario)
{
    cout << "+------+-------------------------+-------------------------+----------------------------+-------+------------" << endl;
    cout << "| ID   |    Nombre              |     Apellido            |          Email             | Nivel |   Horario  |" << endl;
    cout << "+------+-------------------------+---------------------   -+----------------------------+-------+------------" << endl;
    cout << "| " << setw(4) << bibliotecario.iId << " | " << setw(22) << bibliotecario.sNombre << " | " << setw(18) << bibliotecario.sApellido << " | " << setw(24) << bibliotecario.sEmail << " | " << setw(5) << bibliotecario.iNivel << " |" <<setw(10)<< bibliotecario.sHorario<< " |" << endl;
    cout << "+------+-------------------------+----------------------+-------------------------+-------+------------" << endl;
}

// Función para llenar datos de libros
void llenarDatosLibros(sLibro *arrLibros, int iCant)
{
    // Datos predefinidos para los libros
    string arrTitulos[] = {"El Alquimista", "Cien años de soledad", "1984", "Don Quijote de la Mancha", "Matar un ruiseñor", "Harry Potter y la piedra filosofal", "El señor de los anillos", "Crimen y castigo"};
    string arrAutores[] = {"Paulo Coelho", "Gabriel García Márquez", "George Orwell", "Miguel de Cervantes", "Harper Lee", "J.K. Rowling", "J.R.R. Tolkien", "Fyodor Dostoevsky"};
    string arrISBN[] = {"9780062315007", "9788466333978", "9788416100006", "9781546560743", "9788478888566", "9788478884452", "9780544003415", "9780141439617"};
    int arrAnios[] = {1988, 1967, 1949, 1605, 1960, 1997, 1954, 1866};
    
    for (int i = 0; i < iCant; ++i)
    {
        // Asignar valores de acuerdo a las listas predefinidas
        arrLibros[i].sTitulo = arrTitulos[i];
        arrLibros[i].sAutor = arrAutores[i];
        arrLibros[i].sISBN = arrISBN[i];
        arrLibros[i].iAnioPublicacion = arrAnios[i];
        
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
void llenarDatosUsuarios(sUsuario *arrUsuarios, int iCant)
{
    // Datos predefinidos para los usuarios
    string arrNombres[] = {"Juan", "Pedro", "Maria", "Luisa", "Carlos", "Ana", "Diego", "Laura"};
    string arrApellidos[] = {"Gomez", "Perez", "Lopez", "Gonzalez", "Martinez", "Gutierrez", "Rodriguez", "Perez"};
    string arrDirecciones[] = {"Calle A", "Calle B", "Calle C", "Calle D", "Calle E", "Calle F", "Calle G", "Calle H"};
    
    
    for (int i = 0; i < iCant; ++i)
    {
        // Generar un nombre y apellido único
        string sNombre, sApellido;
        do {
            sNombre = arrNombres[rand() % 8];
            sApellido = arrApellidos[rand() % 8];
        } while (bRepetidosUsuario(sNombre, sApellido, arrUsuarios, i)); // Verificar si el nombre y apellido ya existen
        
        // Asignar valores de acuerdo a los nombres y apellidos generados
        arrUsuarios[i].iId = i + 1;
        arrUsuarios[i].sNombre = sNombre;
        arrUsuarios[i].sApellido = sApellido;
        arrUsuarios[i].sEmail = arrUsuarios[i].sNombre + to_string('.') + arrUsuarios[i].sApellido + "@upds.net.com";        
        arrUsuarios[i].sTelefono = "123456789";
        arrUsuarios[i].sDireccion = arrDirecciones[rand() % 8];
    }
}

// Función para llenar datos de bibliotecarios
void llenarDatosBibliotecarios(sBibliotecario *arrBibliotecarios, int iCant)
{
    // Datos predefinidos para los bibliotecarios
    string arrNombres[] = {"Carlos", "Ana", "Diego", "Laura", "Roberto", "María", "Javier", "Lucía"};
    string arrApellidos[] = {"Martinez", "Gutierrez", "Rodriguez", "Perez", "Fernandez", "Sanchez", "Lopez", "Garcia"};
    string arrHorarios[] = {"Mañana", "Tarde", "Noche"};
    
    for (int i = 0; i < iCant; ++i)
    {
        // Generar un nombre y apellido único
        string sNombre, sApellido;
        do {
            sNombre = arrNombres[rand() % 8];
            sApellido = arrApellidos[rand() % 8];
        } while (bRepetidosBibliotecario(sNombre, sApellido, arrBibliotecarios, i)); // Verificar si el nombre y apellido ya existen
        
        // Asignar valores de acuerdo a los nombres y apellidos generados
        arrBibliotecarios[i].iId = i + 1;
        arrBibliotecarios[i].sNombre = sNombre;
        arrBibliotecarios[i].sApellido = sApellido;
        arrBibliotecarios[i].sEmail = arrBibliotecarios[i].sNombre + to_string('.') + arrBibliotecarios[i].sApellido + "@upds.net.com";        
        arrBibliotecarios[i].iNivel = rand() % 10 + 1;
        arrBibliotecarios[i].sHorario = arrHorarios[rand() % 3];
    }
}

// Función para verificar si un nombre y apellido ya están repetidos en el array de usuarios
bool bRepetidosUsuario(string sNombre, string sApellido, sUsuario arrUsuarios[], int iCantUsuarios) {
    for (int i = 0; i < iCantUsuarios; i++) {
        if (sNombre == arrUsuarios[i].sNombre && sApellido == arrUsuarios[i].sApellido)
            return true; // Si encuentra un nombre y apellido igual, devuelve true
    }
    return false; // Si no encuentra nombres y apellidos iguales, devuelve false
}

// Función para verificar si un nombre y apellido ya están repetidos en el array de bibliotecarios
bool bRepetidosBibliotecario(string sNombre, string sApellido, sBibliotecario arrBibliotecarios[], int iCantBibliotecarios) {
    for (int i = 0; i < iCantBibliotecarios; i++) {
        if (sNombre == arrBibliotecarios[i].sNombre && sApellido == arrBibliotecarios[i].sApellido)
            return true; // Si encuentra un nombre y apellido igual, devuelve true
    }
    return false; // Si no encuentra nombres y apellidos iguales, devuelve false
}

// Función para convertir una cadena a minúsculas
string sConvertirMinusculas(string str)
{
    for (char& c : str) {
        c = tolower(c);
    }
    return str;
}

int main()
{
    srand(time(0));
    
    const int iNUM_ELEMENTOS = 4; // Número de libros, usuarios y bibliotecarios
    
    sLibro arrLibros[iNUM_ELEMENTOS];
    sUsuario arrUsuarios[iNUM_ELEMENTOS];
    sBibliotecario arrBibliotecarios[iNUM_ELEMENTOS];
    
    char cOpcionMenuPrincipal;
    
    do
    {
        system("cls"); // Borrar la pantalla antes de mostrar el menú
        
        // Menú principal
        cout << "1. Llenado de datos\n";
        cout << "2. Listados\n";
        cout << "3. Búsquedas\n";
        cout << "0. Salir\n";
        cout << "Ingrese opción: ";
        cin >> cOpcionMenuPrincipal;
        cOpcionMenuPrincipal = tolower(cOpcionMenuPrincipal); // Convertir la opción a minúsculas
        
        switch (cOpcionMenuPrincipal)
        {
            case '1':
            {
                // Llenado de datos
                llenarDatosLibros(arrLibros, iNUM_ELEMENTOS); // Llenar datos de libros
                llenarDatosUsuarios(arrUsuarios, iNUM_ELEMENTOS); // Llenar datos de usuarios
                llenarDatosBibliotecarios(arrBibliotecarios, iNUM_ELEMENTOS); // Llenar datos de bibliotecarios
                break;
            }
            case '2':
            {
                // Menú de listados
                char cOpcionListados;
                do {
                    cout << "a) Listado de libros\n";
                    cout << "b) Listado de usuarios\n";
                    cout << "c) Listado de bibliotecarios\n";
                    cout << "x) Volver al menú principal\n";
                    cout << "Ingrese opción: ";
                    cin >> cOpcionListados;
                    cOpcionListados = tolower(cOpcionListados); // Convertir la opción a minúsculas
                    
                    switch (cOpcionListados)
                    {
                        case 'a':
                            cout << "Listado de libros:\n";
                            for (int i = 0; i < iNUM_ELEMENTOS; ++i)
                            {
                                imprimir(arrLibros[i]);
                            }
                            break;
                        case 'b':
                            cout << "Listado de usuarios:\n";
                            for (int i = 0; i < iNUM_ELEMENTOS; ++i)
                            {
                                imprimir(arrUsuarios[i]);
                            }
                            break;
                        case 'c':
                            cout << "Listado de bibliotecarios:\n";
                            for (int i = 0; i < iNUM_ELEMENTOS; ++i)
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
                } while (cOpcionListados != 'x');
                break;
            }
            case '3':
            {
                // Menú de búsquedas
                char cOpcionBusqueda;
                do {
                    cout << "A) Búsqueda de libro\n";
                    cout << "B) Búsqueda de usuario\n";
                    cout << "C) Búsqueda de bibliotecario\n";
                    cout << "x) Volver al menú principal\n";
                    cout << "Ingrese opción: ";
                    cin >> cOpcionBusqueda;
                    cOpcionBusqueda = tolower(cOpcionBusqueda); // Convertir la opción a minúsculas
                    
                    switch (cOpcionBusqueda)
                    {
                        case 'a':
                        {
                            string sTituloBusqueda;
                            cout << "Ingrese el título del libro a buscar: ";
                            cin.ignore();
                            getline(cin, sTituloBusqueda);
                            
                            // Convertir el título de la búsqueda a minúsculas
                            sTituloBusqueda = sConvertirMinusculas(sTituloBusqueda);
                            
                            bool bEncontrado = false;
                            for (int i = 0; i < iNUM_ELEMENTOS; ++i)
                            {
                                // Convertir el título del libro almacenado a minúsculas para comparar
                                string sTituloLibro = sConvertirMinusculas(arrLibros[i].sTitulo);
                                if (sTituloLibro.find(sTituloBusqueda) != string::npos)
                                {
                                    cout << "Libro encontrado:\n";
                                    imprimir(arrLibros[i]);
                                    bEncontrado = true;
                                }
                            }
                            if (!bEncontrado)
                                cout << "Libro no encontrado.\n";
                            break;
                        }
                        case 'b':
                        {
                            string sNombreApellidoBusqueda;
                            cout << "Ingrese parte del nombre o del apellido del usuario a buscar: ";
                            cin.ignore();
                            getline(cin, sNombreApellidoBusqueda);
                            
                            // Convertimos la búsqueda a minúsculas
                            sNombreApellidoBusqueda = sConvertirMinusculas(sNombreApellidoBusqueda);
                            
                            bool bEncontrado = false;
                            for (int i = 0; i < iNUM_ELEMENTOS; ++i)
                            {
                                string sNombreCompleto = sConvertirMinusculas(arrUsuarios[i].sNombre + " " + arrUsuarios[i].sApellido);
                                string sApellido = sConvertirMinusculas(arrUsuarios[i].sApellido);
                                // Realizamos la búsqueda tanto en el nombre completo como en el apellido
                                if (sNombreCompleto.find(sNombreApellidoBusqueda) != string::npos || sApellido.find(sNombreApellidoBusqueda) != string::npos)
                                {
                                    cout << "Usuario encontrado:\n";
                                    imprimir(arrUsuarios[i]);
                                    bEncontrado = true;
                                }
                            }
                            if (!bEncontrado)
                                cout << "Usuario no encontrado.\n";
                            break;
                        }
                        case 'c':
                        {
                            string sNombreApellidoBusqueda;
                            cout << "Ingrese parte del nombre o del apellido del bibliotecario a buscar: ";
                            cin.ignore();
                            getline(cin, sNombreApellidoBusqueda);
                            
                            // Convertimos la búsqueda a minúsculas
                            sNombreApellidoBusqueda = sConvertirMinusculas(sNombreApellidoBusqueda);
                            
                            bool bEncontrado = false;
                            for (int i = 0; i < iNUM_ELEMENTOS; ++i)
                            {
                                string sNombreCompleto = sConvertirMinusculas(arrBibliotecarios[i].sNombre + " " + arrBibliotecarios[i].sApellido);
                                string sApellido = sConvertirMinusculas(arrBibliotecarios[i].sApellido);
                                // Realizamos la búsqueda tanto en el nombre completo como en el apellido
                                if (sNombreCompleto.find(sNombreApellidoBusqueda) != string::npos || sApellido.find(sNombreApellidoBusqueda) != string::npos)
                                {
                                    cout << "Bibliotecario encontrado:\n";
                                    imprimir(arrBibliotecarios[i]);
                                    bEncontrado = true;
                                }
                            }
                            if (!bEncontrado)
                                cout << "Bibliotecario no encontrado.\n";
                            break;
                        }
                        
                        default:
                            cout << "Opción no válida.\n";
                            break;
                    }
                } while (cOpcionBusqueda != 'x');
                break;
            }
            case '0':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
        
    } while (cOpcionMenuPrincipal != '0');
    
    return 0;
}
