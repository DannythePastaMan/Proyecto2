#include "Archivo.h"

#include <fstream>
#include "arbolB.h"

#include  <iostream>

using namespace std;




BTree * Registros(int cantidad, BTree * t, int llaves) {

    t = new BTree(llaves);;



    ifstream archivoPos("data.dat", ios::in | ios::binary);

    if (!archivoPos)
    {
        cout << " Error al intentar abrir archivo data.dat";
        return NULL;
    }

    archivoPos.seekg(0, ios::beg);
    invoice nuevo;

    archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer
    int posicion = 0;


    while (!archivoPos.eof())
    {
        t->insert(nuevo.year);




        if (posicion == cantidad)
        {
            archivoPos.close();
            return t;
            break;

        }

        posicion++;
        archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer

    }

    archivoPos.close();
    return t ;



}

BTree * Registro(int cantidad, BTree * t , int llaves) {

    t = new BTree(llaves);

    ifstream archivoPos("data.dat", ios::in | ios::binary);

    if (!archivoPos) {
        cout << " Error al intentar abrir archivo data.dat";
        return NULL;
    }

    archivoPos.seekg(0, ios::beg);
    invoice nuevo;

    archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer

    for (int i = 0; i < cantidad; i++) {

        t->insert(nuevo.year);

        cout << nuevo.code << endl;
        cout << nuevo.name << endl;
        cout << nuevo.invoice_code << endl;
        cout << nuevo.date << endl;
        cout << nuevo.month << endl;
        cout << nuevo.day << endl;
        cout << nuevo.year << endl;
        cout << nuevo.payment_type << endl;
        cout << nuevo.total << endl;
        cout << nuevo.business_type << endl;
        cout << nuevo.name << endl;
        archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer


        cout << "----------------------------------------------------------------------------" << endl;
    }
    return t;

}