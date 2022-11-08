/* Aca ir�a un include de la clase que la funcion principal que va a tener es que va a leer la
informacion de el archivo.txt.
Entonces justo lo que estoy haciendo aca con leer en la funcion totalMuestras es lo que vamos a tener que llevar a ahcer a la clase
mediante una funcion. Si ustedes ejecutan el codigo se van a dar cuenta que en efecto cada dato del bloc de notas es guardado e impreso
exisotamente. Ahora, la bocha es la siguiente: guardar los datos de cada provincia con una estructura de tipo de datos abstractos
(pila, cola y lista) [Por lo que dice en el pdf]. 
Bien, yo les deje adentro de la funcion ademas del cout que es lo que hace que imprima los datos, les deje una idea con condicionales (if`s)
para que en cada if con la identificacion de provincia guardemos en la misma estructura los datos a almacenar (Ese es un concepto, puede que cambie).
Por lo que mientras escribo esto se me ocurre hacer 3 veces la leida del archiv para que en una guardemos datos de cordoba, otro de mendoza y asi con el ultimo.
Cada uno tiene que tener un guardado de datos en la estructura diferente (eligen entre pila, cola o lista).
Digo que lo hagamos diferente porque vamos a involucrar todo lo visto 
Posdata: 
Para mi una vez que leamos el archivo y almacenemos de manera ordenada los datos, a partir de ahi ya podemos manejarnos con la estructura city que va a 
contener todos los datos del archivo .txt [esto por las dudas se lo preguntaria a el/la profe.
*/

#include <iostream>
#include <string.h>
#include "Lectura.h"
using namespace std;

struct help{
    float sumador;
    char nombre[50];
    struct help *next;
};



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
    int countryId; // agregue esto porque sino iden_prov va a contener el ultimo valor antes de salir del ciclod el while
    char city_name[50];
};

void totalMuestras(struct city **stackptr, struct city);
void TemperaturaProm();
void ciudadCalida(Lectura l,struct city *stackptr);

int main (void){

    char opcion,seguir = ' ';
	struct city c;
    struct city *stackptr = NULL;
    Lectura l;
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
				totalMuestras(&stackptr,c);
                break;
            }
            case 'b':
            {
                TemperaturaProm();
                break;
            }
            case 'c':
            {
                
                ciudadCalida(l, stackptr);
                
            
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


void totalMuestras(struct city **stackptr, struct city){
	FILE *fp;
	struct city *temp = NULL;
	int hora,minutos,dia,mes = 0;
    int iden_city,ident_prov = 0;
	char nombre[50];
	float tempe,hum = 0;
	fp = fopen("data_set.txt","r");
    	if(fp==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    	}
	cout<<"Total de muestras:"<<endl;     
	while(fscanf(fp,"%d %d %s %f %f %d %d %d %d", &iden_city,&ident_prov,&nombre,&tempe,&hum,&hora,&minutos,&dia,&mes) != EOF){
		if(ident_prov==1 || ident_prov==2 || ident_prov==3){
			struct city *new_node = NULL;
			new_node = (struct city *) malloc(sizeof(city));
			new_node = (struct city *) new_node;
			if(new_node == NULL) {
				cout<<"No hay memoria disponible"<<endl;
				exit(0);
			}
	        new_node->cityId = iden_city;
            new_node->countryId = ident_prov;
            for(int i=0;i<50;i++){
	    	new_node->city_name[i] = nombre[i];
	        }
            new_node->m.temp = tempe;
            new_node->m.hum = hum;
            new_node->m.time.day = dia;
            new_node->m.time.month = mes;
            new_node->m.time.hh = hora;
            new_node->m.time.mm = minutos;
            new_node->next = *stackptr;
            (*stackptr) = new_node;
        }else{
			cout<<"Muestra descartada"<<endl;
		}
		//cout<<iden<<"\t"<<ident_prov<<"\t"<<nombre<<"\t"<<temp<<"\t"<<hum<<"\t"<<hora<<"\t"<<minutos<<"\t"<<dia<<"\t"<<mes<<endl;
	}
    cout<<"Estructura cargada"<<endl;
	fclose(fp);
	temp = *stackptr;
	while(temp!=NULL){
		cout<<temp->cityId<<"\t"<<temp->countryId<<"\t"<<temp->city_name<<"\t"<<temp->m.temp<<"\t"<<temp->m.hum<<"\t"
			<<temp->m.time.hh<<"\t"<<temp->m.time.mm<<"\t"<<temp->m.time.day<<"\t"<<temp->m.time.month<<endl;
		temp = temp->next;
	}
}

void TemperaturaProm(){
    Lectura l;
    l.promedioTemp();
}
void ciudadCalida(Lectura l,struct city *stackptr){
    int opcion=0;
    struct help *new_node = NULL;
    struct help *main = NULL;
    struct city *temp=NULL;
    char continuar= ' ';
    float maxtemp = 0;
    float tempe = 0;
    float array[24] = {0};
    char nombre[50];
    float sumador,promedio= 0;    
    int contador,cont = 0;
    int i = 0;
    string provincia = " ";
    
	do{
        cout<<"MENU DE OPCIONES"<<endl;
        cout<<"1. Ciudad mas calida de la provincia de Cordoba"<<endl;
        cout<<"2. Ciudad mas calida de la provincia de Santa Fe"<<endl;
        cout<<"3. Ciudad mas calida de la provincia de Mendoza"<<endl;
        cin>>opcion;
        
        switch (opcion)
        {
        case 1:
        {
            temp = stackptr;
            provincia = "Cordoba";
            while(temp!=NULL){
                if(temp->countryId==1){
                    contador++;
                    tempe = temp->m.temp;
                    sumador = sumador + tempe;
                    if(contador==80){
                    new_node = (struct help *) malloc(sizeof(help));
                    new_node = (struct help *) new_node;
                    new_node->sumador = sumador;
                    for(int i=0;i<50;i++){
                        new_node->nombre[i] = temp->city_name[i];
                    }
                    new_node->next = main;
                    main = new_node;
                    contador = 0;
                    sumador = 0;
                    }
                }
                temp = temp->next;
            }
            new_node = main;
            maxtemp = new_node->sumador;
            while(new_node!=NULL){
                if(maxtemp<new_node->sumador){
                    maxtemp = new_node->sumador;
                }
                new_node = new_node->next;
            }
            new_node = main;
            while(new_node!=NULL){
                if(new_node->sumador==maxtemp){
                    cout<<"La ciudad mas calida es "<<new_node->nombre<<endl; // ESTO ANDAAA
                }
                new_node = new_node->next;
            }
        } 
            break;
        
        default:
            {
                break;
            }
        }  
        cout<<"Desea continuar(s/n)?"<<endl;
        cin>>continuar;  
    }while(continuar == 's' || continuar=='S');
}

   
    

