#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct timestamp {
    int day;
    int month;
    int hh;
    int mm;
};

struct measurement {
    float temp;
    float hum;
    struct timestamp time;
};

struct city {
    struct city *next;
    struct measurement m;
    int cityId;
    char city_name[50];
};
void totalMuestras();
void check_null(FILE *);

int main (void){
	
	
    char opcion,seguir = ' ';
	
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Total de las muestras almacenadas en las listas pertenecientes a cada provincia"<<endl;
        cout<<"b) Temperatura promedio de cada provincia"<<endl;
        cout<<"c) Ciudad mas calida de cada provincia"<<endl;
        cout<<"d) Ciudad mas fria de cada provincia"<<endl;
        cout<<"e) Dia mas frio de cada provincia"<<endl;
        cout<<"f) Dia mas calido de cada provincia"<<endl;
        cout<<"g) Mejor provincia para el cultivo de pimientos"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
				totalMuestras();
                break;
            }
            case 'b':
            {

                break;
            }
            case 'c':
            {

                break;
            }
            case 'd':
            {

                break;
            }
            case 'e':
            {

                break;
            }
            case 'f':
            {

                break;
            }
            case 'g':
            {

                break;
            }
            default:
            {
                cout<<"Ingrese una opcion existente"<<endl;
            }
        }
        cout<<"Desea continuar con el programa ? y/n"<<endl;
        cin>>seguir;

    }while(seguir=='y' || seguir== 'Y');


    return 0;
}
void check_null(FILE *fp){
	if(fp==NULL){
		cout<<"No se puede abrir el archivo."<<endl;
		exit(1);
	}
}
	
void totalMuestras(){
		FILE *fp;
		char cadena[100];
		fp = fopen("data_set.txt","r");
		check_null(fp);
		cout<<"Total de muestras:"<<endl;
		while(fscanf(fp,"%s",&cadena) != EOF){ 
			cout<<""<<cadena<<"\t\t"<<endl;
			}
		
		fclose(fp);
	}

