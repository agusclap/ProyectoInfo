#include <iostream>
/* Aca irìa un include de la clase que la funcion principal que va a tener es que va a leer la
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


void totalMuestras(struct timestamp t, struct measurement m, struct city c){
	FILE *fp;
	int iden,ident_prov = 0;
	char nombre[50];
	float temp,hum,hora,minutos,dia,mes = 0;
	fp = fopen("data_set.txt","r");
	cout<<"Total de muestras:"<<endl;         // "
	while(fscanf(fp,"%d %d %s %f %f %f %f %f %f", &iden,&ident_prov,&nombre,&temp,&hum,&hora,&minutos,&dia,&mes) != EOF){
		/*if(ident_prov==1){
			struct city *new_node = NULL;
			new_node = (struct city *) malloc(sizeof(city));
			new_node = (struct city *) new_node;
			if(new_node == NULL) {
				cout<<"No hay memoria disponible"<<endl;
				exit(0);
			}
			c.cityId = ident_prov;
			c.city_name[50] = nombre;
		}else if(ident_prov==2){
			
		}else if(ident_prov==3){
			
		}else{
			cout<<"Muestra descartada"<<endl;
		}*/
		
		cout<<iden<<"\t"<<ident_prov<<"\t"<<nombre<<"\t"<<temp<<"\t"<<hum<<"\t"<<hora<<"\t"<<minutos<<"\t"<<dia<<"\t"<<mes<<endl;
	}
	fclose(fp);
}

int main (void){

    char opcion,seguir = ' ';
	struct timestamp t;
	struct measurement m;
	struct city c;
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
				totalMuestras(t,m,c);
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
