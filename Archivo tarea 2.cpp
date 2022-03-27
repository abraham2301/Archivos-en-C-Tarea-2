#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const char *nombre_archivo= "archivo.dat";

struct Estudiante{
	int codigo, *p_codigo;
	char nombre[50], *p_nombre[50];
	char apellido[50], *p_apellido[50];
	char direccion[50], *p_direccion[50];
	int telefono, *p_telefono;
};

void ingresar_estudiante();
void abrir_estudiante();
void buscar_indice();
void modificar();
void eliminar();

int main(){
/*	int escoger=0;
	cout<<"Hola bienevenido que deseas hacer:"<<endl;
	cout<<endl;
	cout<<"Ingresar estudiante = 1 "<<endl;
	cout<<"Abrir estudiante = 2"<<endl;
	cout<<"Buscar por registro ingresando el ID = 3"<<endl;
	cout<<"Modificar alumno = 4"<<endl;
	cout<<"Eliminar alumno = 5 "<<endl;
	cout<<"Salir = 6"<<endl;
	cout<<"Respuesta: ";
	cin>>escoger;
	if((escoger>6) || (escoger<=0)){
		cout<<"eleccion invalida intenta de nuevo";
	}
	switch(escoger){
		case 1:
			ingresar_estudiante();
			break;
		case 2:
			 abrir_estudiante();
			break;
		case 3:
			 buscar_indice();
			break;
		case 4:
			 modificar();
			break;
		case 5:
			 eliminar();
			break;
		case 6:
	
			break; */
	char eleccion;
	do{
		system("cls");
		fflush(stdin);
		int escoger=0;
	cout<<"Hola bienevenido que deseas hacer:"<<endl;
	cout<<endl;
	cout<<"Ingresar estudiante = 1 "<<endl;
	cout<<"Abrir estudiante = 2"<<endl;
	cout<<"Buscar por registro ingresando el ID = 3"<<endl;
	cout<<"Modificar alumno = 4"<<endl;
	cout<<"Eliminar alumno = 5 "<<endl;
	cout<<"Salir = 6"<<endl;
	cout<<"Respuesta: ";
	cin>>escoger;
	if((escoger>6) || (escoger<=0)){
		cout<<"eleccion invalida intenta de nuevo";
	}
	switch(escoger){
		case 1:
			ingresar_estudiante();
			break;
		case 2:
			 abrir_estudiante();
			break;
		case 3:
			 buscar_indice();
			break;
		case 4:
			 modificar();
			break;
		case 5:
			 eliminar();
			break;
		case 6:
	
			break;
		}
	cout<<"Deseas regresar al menu principal (s/n)";
	cin>>eleccion;
	}while((eleccion=='s')||(eleccion=='S'));
	return 0;
}

void ingresar_estudiante(){
	char continuar;
	FILE* archivo = fopen("archivo.data", "ab");
	
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
		fflush(stdin);
		cout<<"Ingresa el Codigo del estudiante:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingresa el nombre del estudiante:";
		getline(cin,nombre);
		strcpy(estudiante.nombre,nombre.c_str());
		cout<<"Ingresa el apellido del estudiante:";
		getline(cin,apellido);
		strcpy(estudiante.apellido,apellido.c_str());
		cout<<"Ingresa la direccion del estudiante:";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingresa el telefono del estudiante:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Quieres ingresar otro estudiante (s/n)";
		cin>>continuar;
	}while((continuar=='s')||(continuar=='S'));
	
	fclose(archivo);
}

void abrir_estudiante(){
	system("cls");
	FILE* archivo= fopen("archivo.data","rb");
	Estudiante estudiante;
	if(!archivo){
		archivo=fopen("archivo.data","w+b");
	}
	else{
		
		int registro=0;
		fread (&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"___________________________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Direccion"<<"|"<<"Telefono"<<""<<endl;
		do{
			cout<<"______________________________________________________________"<<endl;
			cout<<registro<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellido<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
			fread(&estudiante,sizeof(Estudiante),1,archivo);
			registro +=1;
		}while(feof(archivo)==0);
		cout<<endl;
		fclose(archivo);
	}
	fclose(archivo);
}

void buscar_indice(){
	FILE* archivo= fopen("archivo.data","rb");
	
	int pos=0;
	cout<<"Que registro te gustaria ver:";
	cin>>pos;
	cout<<"---------------"<<pos<<"---------------"<<endl;
	fseek(archivo,pos* sizeof(Estudiante), SEEK_SET);
	Estudiante estudiante;
	fread(&estudiante, sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombre: "<<estudiante.nombre<<endl;
	cout<<"Apellido: "<<estudiante.apellido<<endl;
	cout<<"Direccion: "<<estudiante.direccion<<endl;
	cout<<"Telefono:"<<estudiante.telefono<<endl;
	cout<<endl;
	fclose(archivo);
	
}

void modificar(){
	FILE* archivo= fopen("archivo.data","r+b");
	int id;
	string nombre,apellido,direccion;
	Estudiante estudiante;
	cout<<"Ingresa el ID que quieres cambiar:";
	cin>>id;
	fseek(archivo,id* sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el codigo:";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<"Ingrese el nombre del estudiante:";
	getline(cin,nombre);
	strcpy(estudiante.nombre,nombre.c_str());
	cout<<"Ingrese el apellido del estudiante:";
	getline(cin,apellido);
	strcpy(estudiante.apellido,apellido.c_str());
	cout<<"Ingresa la direccion del estudiante:";
	getline(cin,direccion);
	strcpy(estudiante.direccion,direccion.c_str());
	cout<<"Ingrese el telefono del estudiante:";
	cin>>estudiante.telefono;
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
}

void eliminar(){
		FILE *archivo;
	archivo=fopen("archivo.data","rb");
	if(archivo==NULL)
		exit(1);
	cout<<"Ingresa el codigo a eliminar:";
	int cod;
	cin>>cod;
	Estudiante estudiante;
	FILE* nuevo;
	nuevo=fopen("archivo.tmp","ab");
	if(archivo==NULL)
		exit(1);
	int existe=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	while(!feof(archivo)){
		if(cod==estudiante.codigo){
			cout<<"Elimando a:"<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellido<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
			existe=1;
		}
		else{
			fwrite(&estudiante,sizeof(Estudiante),1,nuevo);
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
	}
	if(existe==0)
		cout<<"No existe alumno con este codigo";
	fclose(archivo);
	fclose(nuevo);
	
	remove("archivo.data");
	rename("archivo.tmp","archivo.data");
}
