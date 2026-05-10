#include <iostream>
#include <limits>
#include <string>

#include "AVL.h"
#include "Student.h"

using namespace std;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int leerEntero(const string& mensaje) {
    int valor;

    while (true) {
        cout << mensaje;

        if (cin >> valor) {
            limpiarEntrada();
            return valor;
        }

        cout << "Entrada invalida. Debes ingresar un numero entero.\n";
        limpiarEntrada();
    }
}

double leerDecimal(const string& mensaje) {
    double valor;

    while (true) {
        cout << mensaje;

        if (cin >> valor) {
            limpiarEntrada();
            return valor;
        }

        cout << "Entrada invalida. Debes ingresar un numero decimal.\n";
        limpiarEntrada();
    }
}

string leerTexto(const string& mensaje) {
    string texto;

    while (true) {
        cout << mensaje;
        getline(cin, texto);

        if (!texto.empty()) {
            return texto;
        }

        cout << "El campo no puede estar vacio.\n";
    }
}

void insertarEstudiante(AVL& avl) {
    Student student;

    cout << "\n===== INSERTAR ESTUDIANTE =====\n";

    student.id = leerEntero("ID del estudiante: ");
    student.full_name = leerTexto("Nombre completo: ");
    student.career = leerTexto("Carrera: ");
    student.semester = leerEntero("Semestre: ");
    student.gpa = leerDecimal("GPA: ");
    student.skill_score = leerEntero("Skill score: ");

    avl.insertStudent(student);

    cout << "\nEstudiante insertado correctamente en el arbol AVL.\n";
}

void mostrarMenu() {
 cout << "\n RONY ALEXANDER BARRIOS BORRAYO\n";
   
 cout << "\n MODULO DE RANKING ACADEMICO - AVL\n";
    cout << "====================================\n";
    cout << "1. Insertar estudiante\n";
    cout << "2. Mostrar ranking academico\n";
    cout << "3. Buscar por skill_score\n";
    cout << "4. Mostrar estadisticas AVL\n";
    cout << "5. Salir\n";
}

int main() {
    AVL avl;
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                insertarEstudiante(avl);
                break;

            case 2:
                avl.showRanking();
                break;

            case 3: {
                int skillScore = leerEntero("Ingrese el skill_score a buscar: ");
                avl.findBySkillScore(skillScore);
                break;
            }

            case 4:
                avl.showStats();
                break;

            case 5:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}