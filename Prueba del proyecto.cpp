//Esto es el codigo completo / This is the code completed
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <fstream>
using namespace std;

// Funcion que identifica si el username y passsword ingresado es correcto o no
bool securityMeasure(string username, string password) {
    const string adminUsername = "admin";
    const string adminPassword = "1234";
    return username == adminUsername && password == adminPassword;
}

// Evalua si el ID del estudiante ingresado por el usuario sigue las reglas dadas utilizando la clase cctype.
bool studentNumberValidator(const string& studentNum) {
    if (studentNum.length() != 6) {
        return false;
    }
    if (!isalpha(studentNum[0])) {
        return false;
    }
    for (int i = 1; i < 6; i++) {
        if (!isdigit(studentNum[i])) {
            return false;
        }
    }
    return true;
}

// Calcula el promedio del estudiante
void promedio(double prom) {
    if (prom == 0 || prom <= 59) {
        cout << "sacaste " << prom << "% y su resultado es F.\n";
        cout << "commentario: Hubieras estudiado\n";
    }
    else if (prom == 60 || prom <= 69) {
        cout << "sacaste " << prom << "% y su resultado es D.\n";
        cout << "commentario: Esta medio mal, pero necesita mas estudio\n";
    }
    else if (prom == 70 || prom <= 79) {
        cout << "sacaste " << prom << "% y su resultado es C.\n";
        cout << "commentario: Estas medio bien, extra estudios mas y estubies bien\n";
    }
    else if (prom == 80 || prom <= 89) {
        cout << "sacaste " << prom << "% y su resultado es B.\n";
        cout << "commentario: Muy bien, estas a punto\n";
    }
    else if (prom == 90 || prom <= 100) {
        cout << "sacaste " << prom << "% y su resultado es A.\n";
        cout << "commentario: Excelente has superado el curso!!!\n";
    }
    else {
        cout << "INPUT INVALIDO\n";
        cout << "commentario: Por favor de asegurar que el resultado del promedio no sea negativo o letra.\n";
    }
}
int main() {

    // Variables para la informacion del estudiante
    string studentName;
    string studentNumber;
    string studentClass;

    //Variables de username y password
    string username;
    string password;

    //Loop de while en donde le pide al usuario el username y password para acceder
    //Se repite si esta mal uno de los dos.
    while (true) {
        cout << "Inserte el username: ";
        cin >> username;

        cout << "Inserte el password: ";
        cin >> password;

        if (securityMeasure(username, password)) {
            cout << "Credenciales correctas, bienvenido admin!" << endl;
            break;
        }
        else {
            cout << "CREDENCIALES INCORRECTAS, TRATE OTRAVEZ." << endl;
        }
    }
    // Le pide al usuario  el nombre del estudainte y su numero, repite si no sigue las instrucciones.
    while (true) {
        cout << "Ingrese el nombre del estudiante: ";
        cin >> studentName;
        cout << "Ingrese el ID del estudiante (1 letra mayuscula y 5 numeros): ";
        cin >> studentNumber;
        if (studentNumberValidator(studentNumber)) {
            cout << "El nombre del estudiante es " << studentName << " y el ID de estudiante es " << studentNumber << endl;
            break;
        }
        else {
            cout << "ID de estudiante invalido, trata otravez." << endl;
        }
    }

    // Variables para la evaluacion del estudiante
    int n, total;
    double prom;
    int periodo[4];

    // Array que le pide al usario las puntuaciones de los trabajos 
    for (int i = 0; i < 4; i++) {
        cout << "Periodo #" << i + 1 << ": ";
        cin >> periodo[i];
    }
    total = periodo[0] + periodo[1] + periodo[2] + periodo[3];

    // Le pide al usuario cuantas notas tiene el estudiante
    cout << "-------------------\n";
    cout << "Notas: ";
    cin >> n;
    cout << "-------------------\n";
    cout << "Total de puntos: " << total << endl;
    cout << "Cantidad de notas: " << n << endl;
    prom = total / n;
    cout << "-------------------\n";
    promedio(prom);    // Llamando funcion

    // Crea el file usando la libreria de fstream con la informacion del estudiante
    ofstream file("student_evaluation_info.txt");
    if (file.is_open()) {
        file << "Nombre del Estudiante: " << studentName << endl;
        file << "ID de Estudiante: " << studentNumber << endl;
        file << "Total de puntos: " << total << endl;
        file << "Cantidad de Notas: " << n << endl;
        file << "Promedio del Estudiante: " << prom << "%" << endl;
        file.close();
        cout << "La evaluacion completa del estudiante fue guardada en in text file.";
    }
    else {
        cout << "Lamentablemente no se pudo crear el archivo.";
    }

    return 0;
}
