#include <iostream>
#include "Cola.h"

using namespace std;

int main() {
    Cola colaClientes;
    int opcion;
    int totalClientesAtendidos=0;

    do {
        cout<<"\nBanco - Cola de Atencion a Clientes\n";
        cout<<"1.Nuevo cliente llega al banco\n";
        cout<<"2.Cliente pasa a ventanilla\n";
        cout<<"3.Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch (opcion) {
            case 1: {
                int id;
                string nombre;
                cout<<"Ingrese el ID del cliente: ";
                cin>>id;
                cout<<"Ingrese el nombre del cliente: ";
                cin.ignore(); //limpamos p el buffer
                getline(cin, nombre);
                Cliente nuevoCliente(id, nombre);
                colaClientes.Insertar(nuevoCliente);
                cout<<"Cliente agregado a la cola de espera.\n";
                break;
            }
            case 2:{
                if (colaClientes.getFrente() != nullptr) {
                    int ventanilla;
                    cout<<"Ingrese el número de ventanilla: ";
                    cin>>ventanilla;
                    Cliente clienteAtendido = colaClientes.getFrente()->retDato();
                    colaClientes.Eliminar();
                    totalClientesAtendidos++;
                    cout<<"Cliente con ID: "<<clienteAtendido.getId();
                    cout<<", Nombre: "<<clienteAtendido.getNombre();
                    cout<<" está siendo atendido en la ventanilla "<< ventanilla<<".\n";
                }else{
                    cout<<"No hay clientes en espera.\n";
                }
                break;
            }
            case 3:{
                cout<<"Saliendo del programa.\n";
                break;
            }
            default:
                cout<<"Opcion no válida. Intente nuevamente.\n";
        }
    }while(opcion != 3);

    cout<<"\nTotal de clientes atendidos en el dia: "<<totalClientesAtendidos<<endl;
    return 0;
}
