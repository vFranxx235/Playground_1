/*1. Un depósito de despacho de paquetes trabaja con un pequeño camión que tiene una capacidad de carga máxima de 500kg.
    El dueño encarga un programa que permita ir sumando el peso de cada bulto para que los operarios no sobrepasen
    su capacidad al cargarlo.Escribir un algoritmo que permita calcular el peso total que se va cargando,
    cuando este supere la capacidad del vehículo, deberá mostrar un mensaje que diga “Retire el último bulto”
    y muestre el peso total y la cantidad de bultos cargados.

    Complemento
    a.Cómo podrías adaptar tu algoritmo, si ahora intervienen distintos camiones y vehículos de transporte,
    cada uno con diferentes capacidades de carga.Al finalizar la carga de cada uno debe
    mostrar el peso total con el que sale y su capacidad máxima.*/
#include <iostream>

#include<windows.h>

using namespace std;
int main() {
    int cant = 0, cap;
    char respuesta;
    float suma = 0, peso, disp;
    bool carga_superada = false, flag = false;
    do {
        if (flag == true) {
            cout << "ERROR";
            system("pause");
            system("cls");
        }
        cout << "Ingrese la capacidad de carga del vehiculo: ";
        cin >> cap;
        system("cls");
        if (cap < 1) {
            flag = true;
        }
    } while (cap < 0);
    flag = false;
    while (carga_superada == false) {
        cout << "Ingrese el peso del paquete: ";
        cin >> peso;
        system("cls");
        suma += peso;
        cant++;
        if (suma > cap) {
            cout << "Supera el limite de carga! Retire el paquete.\n";
            system("pause");
            system("cls");
            cant--;
            suma -= peso;
            cout << "Su limite de carga es: " << cap << "kg.\n";
            disp = cap - suma;
            cout << "Usted lleva ahora mismo " << suma << "kg. Le queda disponible " << disp << "kg para usar.\n";
            system("pause");
            system("cls");
            do {
                if (flag == true) {
                    cout << "Error\n";
                    system("cls");
                }
                cout << "Quiere continuar cargando? Y/N\n";
                cin >> respuesta;
                if (respuesta == 'n'
                    or respuesta == 'N') {
                    flag = false;
                    carga_superada = true;
                    system("cls");
                }
                else if (respuesta != 'y'
                    and respuesta != 'Y') {
                    flag = true;
                }
            } while (respuesta != 'y'
                and respuesta != 'Y'
                and respuesta != 'n'
                and respuesta != 'N');

        }
        else if (suma == cap) {
            carga_superada = true;
            cout << "Esta justo en el limite de peso\n";
        }
    }
    cout << "Usted tiene " << cant << " de paquetes listos para enviar.\n";
    cout << "Su peso es " << suma << "/" << cap << "kg.\n";

}
