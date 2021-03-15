#include <iostream>
#include <iostream>
#include <stdio.h>
#include <string.h>

usando el espacio de nombres std;

const char * nombre_archivo = "archivo.dat";
const char * nombre2 = "temporal.dat";

struct Empleado {

	int codigo;
	nombres de char [50];
	char apellidos [50];
	char puesto [50];
	int sueldo;
	int boni;
};
anular ingresar ();
menú vacío ();
vacío abrir ();
/ * anular buscar_id ();
anular buscar_codigo (); * /
anular eliminar ();
void modificar_empleado ();
principal(){

	menú();
}

menú vacío () {
    sistema ("cls");
    int opc;
    hacer{
        cout << "\ n \ t \ t _______ HOLA ______ \ n \ n" << endl;
        cout << "\ n1. Ingresar." << endl;
        cout << "2. Ver Registros." << endl;
        cout << "3. Buscar Codigo." << endl;
        cout << "4. Eliminar." << endl;
        cout << "5. Editar Dato." << endl;
        cout << "Digite una opcion:";
        cin >> opc;

        cambiar (opc) {
            caso 1: ingresar (); descanso;
            caso 2: abrir (); descanso;
            caso 4: eliminar (); descanso;
            caso 5: modificar_empleado (); descanso;
            // caso 6:  DESCANSO 

        }

    } mientras (opc! = 5);

}

anular ingresar () {
    sistema ("cls");
	char continuar;
    cout << "\ n \ t \ t _____ Agregar informacion _____ \ n \ n" << endl;

	ARCHIVO * archivo = fopen (nombre_archivo, "ab");
	Empleado empleado;
	nombre de cadena, apellido, puesto;
	hacer{
		fflush (stdin);
		cout << "Ingrese el Codigo :";
		cin >> empleado.codigo;
		cin.ignore ();

		cout << "Ingrese Los Nombres:";
		getline (cin, nombre);
		strcpy (empleado.nombres, nombre.c_str ());

		cout << "Ingrese Los Apellidos:";
		getline (cin, apellido);
		strcpy (empleado.a antecedentes, apellido.c_str ());

		cout << "Ingrese Los Puesto:";
		getline (cin, puesto);
		strcpy (empleado.puesto, puesto.c_str ());

		cout << "Ingrese el Sueldo:";
		cin >> empleado.sueldo;		
		cout << "Ingrese el bonificacion:";

		cin >> empleado.boni;
		fwrite (& empleado, sizeof (Empleado), 1, archivo);

		cout << "Desea ingresar otro dato (s / n):";
		cin >> continuar;

	} while (continuar == 's' || continuar == 'S');

	fclose (archivo);
	cout << "\ n \ n \ t \ t \ tDATOS AGREGADOS ... \ n \ n";
    sistema ("pausa");
    menú();

}

void abrir () {
	sistema ("cls");
    cout << "\ n \ t \ t _____ REGISTROS _____ \ n \ n" << endl;
	ARCHIVO * archivo = fopen (nombre_archivo, "rb");

	if (! archivo) {
		archivo = fopen (nombre_archivo, "w + b");
	}

	Empleado empleado;
	int sueldo_total = 0;
	sueldo_total = empleado.sueldo + empleado.boni;
	int id = 0;

	fread (& empleado, sizeof (Empleado), 1, archivo);
	cout << "id |" << "Codigo |" << "Nombres |" << "Apellidos |" << "Puesto |" << "Sueldo" << "Bonificación |" << "Sueldo total |" < <endl;

	hacer{
	cout << id << "|" << empleado.codigo << "|" << empleado.nombres << "|" << empleado.a usos << "|" << empleado.puesto << "|" < <empleado.sueldo << "|" << empleado.boni << "|" << (empleado.sueldo + empleado.boni) << "|" << endl;
	fread (& empleado, sizeof (Empleado), 1, archivo);
		id + = 1;
	} while (feof (archivo) == 0);

	fclose (archivo);

    cout << "\ n \ n";
    sistema ("pausa");
    menú();

}




void modificar_empleado () {	
	ARCHIVO * archivo = fopen (nombre_archivo, "r + b");	
		int id;
		nombre de cadena, apellido, puesto;	
    	Empleado empleado;

		cout << "\ n \ n ______ Ingrese el ID que desea Modificar______";
    	cin >> id;
    	fseek (archivo, id * sizeof (Empleado), SEEK_SET); // esto es lo que permite modificar en la pocision

		cout << "Ingrese el Codigo:";
		cin >> empleado.codigo;
        cin.ignore ();

		cout << "Ingrese Los Nombres:";
		getline (cin, nombre);
		strcpy (empleado.nombres, nombre.c_str ());

		cout << "Ingrese Los Apellidos:";
		getline (cin, apellido);
		strcpy (empleado.a antecedentes, apellido.c_str ());

		cout << "Ingrese Los Puesto:";
		getline (cin, puesto);
		strcpy (empleado.puesto, puesto.c_str ());

		cout << "Ingrese el Sueldo:";
		cin >> empleado.sueldo;		

		cout << "Ingrese el bonificacion:";
		cin >> empleado.boni;

		fwrite (& empleado, sizeof (Empleado), 1, archivo);

	fclose (archivo);
	sistema ("PAUSA");
}

void eliminar () {
    sistema ("cls");
    cout << "\ n \ t \ ______ Eliminar Registro ______ \ n" << endl;
	ARCHIVO * archivo = fopen (nombre_archivo, "rb");
    ARCHIVO * archivo2 = fopen (nombre2, "w + b");
	if (! archivo) {
		archivo = fopen (nombre_archivo, "w + b");
	}
	int id = 0, codigo;
    nombre de cadena, apellido, puesto;

	cout << "Ingrese el Codigo para eliminar:";
	cin >> codigo;

	Empleado empleado;
	fread (& empleado, sizeof (Empleado), 1, archivo);
	hacer{       
		if (empleado.codigo == codigo) {
            cout << "_____ Datos eliminados _____ .. \ n \ n" << endl;
            sistema ("pausa");
            fread (& empleado, sizeof (Empleado), 1, archivo);
        }

        demás{

            fwrite (& empleado, sizeof (Empleado), 1, archivo2);
            fread (& empleado, sizeof (Empleado), 1, archivo);
            id + = 1;
        }

	} while (feof (archivo) == 0);

	fclose (archivo);
    fclose (archivo2);
    eliminar ("archivo.dat");
    renombrar ("temporal.dat", "archivo.dat");

    cout << "\ n \ n";
    sistema ("pausa");
    menú();


}
