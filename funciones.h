#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct fecha{
int dia;
int mes;
int anio;
};

struct paciente{
   int dni;
  char nombre[30];
  char apellido[30];
  char genero;
  fecha f;
  int obrasocial;
  bool estado;
};





///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



int buscar_paciente(int codigo){
  FILE *p;
  p = fopen("pacientes.dat", "rb");
  if (p == NULL){
    return -2;
  }
  paciente a;
  int i=0;
  while(fread(&a, sizeof(paciente), 1, p)){
    if (codigo == a.dni){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}



///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



bool cargar_nuevo_paciente(paciente *a){
  cout << "DNI: ";
  cin >> a->dni;
  while(buscar_paciente(a->dni)>=0){
    cout<<"ESE DNI YA SE ENCUENTRA EN NUESTROS REGISTROS, INTENTAR NUEVAMENTE: ";
    cin>>a->dni;
  }
  cout << "NOMBRE: ";
  cin.ignore();
  cin.getline(a->nombre, 30);
  while(strlen(a->nombre)<=0){
    cout << "EL NOMBRE NO PUEDE ESTAR VACIO, INTENTAR NUEVAMENTE: ";
    cin.getline(a->nombre, 30);
  }
    cout << "APELLIDO: ";
  cin.getline(a->apellido, 30);
  while(strlen(a->apellido)<=0){
    cout << "EL APELLIDO NO PUEDE ESTAR VACIO, INTENTAR NUEVAMENTE: ";
    cin.getline(a->apellido, 30);
  }
  cout << "GENERO (M/F/O): ";
  cin >> a->genero;
  while (a->genero!='M' && a->genero!='F' && a->genero!='O'){
    cout << "INGRESAR UN GENERO CORRECTO (M-masculino/F-femenino/O-otro) : ";
    cin >> a->genero;
  }
    cout << "INGRESE EL DIA: ";
  cin >> a->f.dia;
  while(a->f.dia<=0 || a->f.dia>31){
    cout<<"POR FAVOR INGRESAR UN DIA VALIDO: ";
    cin >> a->f.dia;
  }

    cout << "INGRESE EL MES: ";
  cin >> a->f.mes;
   while(a->f.mes<=0 || a->f.mes>12){
    cout<<"POR FAVOR INGRESAR UN MES VALIDO: ";
    cin >> a->f.mes;
  }
    cout << "INGRESE EL ANIO: ";
  cin >> a->f.anio;
  while(a->f.anio<=0){
    cout<<"POR FAVOR INGRESAR UN ANIO VALIDO: ";
    cin >> a->f.anio;
  }
  cout << "NRO DE OBRA SOCIAL: ";
  cin >> a->obrasocial;
  while (a->obrasocial<1||a->obrasocial>50){
    cout << "INGRESE UN NUMERO DE OBRA SOCIAL VALIDO (1 a 50)"<<endl;
    cin >>a->obrasocial;
  }
  a->estado=true;
  return true;
}



///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



void mostrar_pacientes(paciente a){
    if (a.estado==true){
  cout << "DNI:"<<endl;
  cout << a.dni << endl;
  cout << "NOMBRE: ";
  cout << a.nombre << endl;
  cout << "APELLIDO: ";
  cout << a.apellido << endl;
  cout << "GENERO: ";
  cout << a.genero << endl;
  cout << "FECHA: ";
  cout << a.f.dia<<"/"<<a.f.mes<<"/"<<a.f.anio << endl;
  cout << "OBRA SOCIAL: ";
  cout << a.obrasocial << endl;
  cout << endl;
}
}



///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


bool guardar_paciente(paciente a){
  FILE *p;
  p = fopen("pacientes.dat", "ab");
  if (p == NULL){
    return false;
  }
  bool i=fwrite(&a, sizeof(paciente), 1, p);
  fclose(p);
  return i;
}



///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


void listar_pacientes(){
  paciente a;
  FILE *p;
  p = fopen("pacientes.dat", "rb");
  if (p == NULL){
    cout << "ERROR AL ABRIR EL ARCHIVO..."<<endl;
    return;
  }
  while(fread(&a, sizeof(paciente), 1, p) == 1){
    mostrar_pacientes(a);
    cout << endl;
  }
  fclose(p);
}

///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||




paciente leer_paciente(int pos){
  paciente reg;
  FILE *p;
  p = fopen("pacientes.dat", "rb");
  if (p==NULL){
    reg.obrasocial = -1;
    return reg;
  }
  fseek(p, sizeof(paciente)*pos, SEEK_SET);
  bool leyo=fread(&reg, sizeof(paciente), 1, p);
  if (leyo == false){
    reg.obrasocial = -1;
  }
  fclose(p);
  return reg;
}






///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



void listar_paciente_x_dni(){
  int codigo;
  int pos;
  cout << "DNI DEL PACIENTE: ";
  cin >> codigo;
  pos = buscar_paciente(codigo);
  if (pos >= 0){
    paciente reg;
    reg = leer_paciente(pos);
    mostrar_pacientes(reg);
  }
  else{
    cout << "NO EXISTE EL REGISTRO..."<<endl;
  }
}



///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||




bool sobreescribir_paciente(paciente reg, int pos){
  FILE *p;
  p = fopen("pacientes.dat", "rb+");
  if (p == NULL){
    return false;
  }
  fseek(p, sizeof(paciente)*pos, 0);
  bool i=fwrite(&reg, sizeof(paciente), 1, p);
  fclose(p);
  return i;
}

///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


void modificar_paciente(){
   int codigo;
  int pos;
  cout << "DNI DEL PACIENTE A MODIFICAR: ";
  cin >> codigo;
  pos = buscar_paciente(codigo);
  if (pos >= 0){
    paciente reg;
    reg = leer_paciente(pos);
    mostrar_pacientes(reg);
    cout << endl << "NUEVO NUMERO DE OBRA SOCIAL: ";
    cin >> reg.obrasocial;
    if (sobreescribir_paciente(reg, pos) == true){
      cout << endl << "PACIENTE MODIFICADO."<<endl;
    }
  }
  else{
    cout << "NO EXISTE EL PACIENTE."<<endl;
  }
}


///||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


void eliminar_paciente(){
   int codigo;
  int pos;
  cout << "DNI DEL PACIENTE A ELIMINAR: ";
  cin >> codigo;
  pos = buscar_paciente(codigo);
  if (pos >= 0){
    paciente reg;
    reg = leer_paciente(pos);
    mostrar_pacientes(reg);
    cout << endl << "ELIMINANDO PACIENTE... "<<endl;
    reg.estado=false;
    if (sobreescribir_paciente(reg, pos) == true){
      cout << endl << "PACIENTE ELIMINADO."<<endl;
    }
  }
  else{
    cout << "NO EXISTE EL PACIENTE."<<endl;
  }
}




#endif // FUNCIONES_H_INCLUDED


