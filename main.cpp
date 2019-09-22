#include <iostream>
using namespace std;
#include <cstdlib>
#include <clocale>
#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include "funciones_medicos.h"
#include "funciones_control.h"



int main(){
int opcion, opcion1, opcion2, opcion3;
paciente a;
medico b;
control c;
c.id=0;
while (true){
        system("cls");
cout<<"MENU PRINCIPAL"<<endl;
cout<<"--------------"<<endl;
cout<<"1) PACIENTES"<<endl;
cout<<"2) MEDICOS"<<endl;
cout<<"3) CONTROLES"<<endl;
cout<<"4) REPORTES"<<endl;
cout<<"5) CONFIGURACION"<<endl;
cout<<"----------------------"<<endl;
cout<<"0) SALIR DEL PROGRAMA"<<endl;


cin>>opcion;
switch (opcion){
case 1:
    opcion1=1;
    while(opcion1!=0){
            system ("cls");
cout<<"    MENU PACIENTES"<<endl;
cout<<"------------------"<<endl;
cout<<"1) NUEVO PACIENTE"<<endl;
cout<<"2) MODIFICAR PACIENTE"<<endl;
cout<<"3) LISTAR PACIENTE POR DNI"<<endl;
cout<<"4) LISTAR TODOS LOS PACIENTES"<<endl;
cout<<"5) ELIMINAR PACIENTE"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cin>>opcion1;
switch (opcion1){
    case 1:
        if (cargar_nuevo_paciente(&a) == true){
          if (guardar_paciente(a) == true){
          cout << "DATOS GUARDADOS CORRECTAMENTE." << endl;
          }
          else{
            cout << "ERROR AL GUARDAR..." << endl;
          }
        }
        else{
          cout << "ERROR DE CARGA..."<<endl;
        }
        system("pause");

    break;
    case 2:

        modificar_paciente();


        system("pause");

    break;
    case 3:

        listar_paciente_x_dni();


        system("pause");

    break;
    case 4:

        listar_pacientes();


        system("pause");

    break;
    case 5:

        eliminar_paciente();


        system("pause");

    break;
    case 0:


        system("pause");

    break;

}
}


    break;
    case 2:
opcion2=1;
    while(opcion2!=0){
            system ("cls");
cout<<"    MENU MEDICOS"<<endl;
cout<<"------------------"<<endl;
cout<<"1) NUEVO MEDICO"<<endl;
cout<<"2) MODIFICAR MEDICO"<<endl;
cout<<"3) LISTAR TODOS LOS MEDICOS"<<endl;
cout<<"4) LISTAR POR N DE MATRICULA"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cin>>opcion2;
switch (opcion2){
case 1:
    if (cargar_nuevo_medico(&b) == true){
          if (guardar_medico(b) == true){
          cout << "DATOS GUARDADOS CORRECTAMENTE." << endl;
          }
          else{
            cout << "ERROR AL GUARDAR..." << endl;
          }
        }
        else{
          cout << "ERROR DE CARGA..."<<endl;
        }
        system("pause");
    break;

case 2:
    modificar_medico();


        system("pause");

break;
    case 3:
         listar_medicos();


        system("pause");

    break;
    case 4:
         listar_medico_x_matricula();


        system("pause");

    break;

    case 0:

    break;
}
    }
    break;
    case 3:
        opcion3=1;
    while(opcion3!=0){
            system ("cls");
cout<<"    MENU CONTROLES"<<endl;
cout<<"------------------"<<endl;
cout<<"1) NUEVO CONTROL"<<endl;
cout<<"2) MODIFICAR CONTROL"<<endl;
cout<<"3) LISTAR CONTROL POR ID"<<endl;
cout<<"4) LISTAR TODOS LOS CONTROLES"<<endl;
cout<<"5) CANCELAR CONTROL"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cin>>opcion3;
switch (opcion3){
    case 1:
        if (cargar_nuevo_control(&c) == true){
          if (guardar_control(c) == true){
          cout << "DATOS GUARDADOS CORRECTAMENTE." << endl;
          }
          else{
            cout << "ERROR AL GUARDAR..." << endl;
          }
        }
        else{
          cout << "ERROR DE CARGA..."<<endl;
        }
        system("pause");

    break;
    case 2:

        modificar_control();


        system("pause");

    break;
    case 3:

        listar_control_x_id();


        system("pause");

    break;
    case 4:

        listar_controles();


        system("pause");

    break;
    case 5:

        eliminar_control();


        system("pause");

    break;
    case 0:


        system("pause");

    break;

}
}



    break;
    case 4:

    break;
    case 5:

    break;
    case 0:
    return 0;
    break;






}







}

return 0;
}










