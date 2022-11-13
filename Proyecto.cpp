#include <iostream>
#include "Lectura.h"
#include <iomanip>
using namespace std;

struct help{
    float sumador;
    char nombre[50];
    float promedio;
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
    int countryId; 
    char city_name[50];
};

void carga(struct city **stackptr,struct city **head,struct city **front,struct city **back);
void totalMuestras(struct city *stackptr, struct city *head,struct city *front);
void ciudadCalida(struct city *stackptr,struct city *head,struct city *front);
void ciudadesCalidas(struct city *stackptr, int,struct city *head,struct city *front);
void ciudadFria(struct city *stackptr,struct city *head,struct city *front);
void ciudadesFrias(struct city *stackptr,int,struct city *head,struct city *front);
void diaFrio(struct city *stackptr,struct city *head,struct city *front);
void diaCalido(struct city *stackptr,struct city *head,struct city *front);
void diasCalidos(struct city *stackptr);
void promedioTemp(struct city *stackptr);

int main (void){
    int bandera = 0;
    char opcion,seguir = ' ';
	struct city c;
    struct city *stackptr = NULL;
    struct city *head = NULL;
    struct city *back = NULL;
    struct city *front = NULL;
    Lectura l;
    carga(&stackptr,&head,&front,&back);
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Total de las muestras almacenadas en las listas pertenecientes a cada provincia"<<endl;
        cout<<"b) Temperatura promedio de cada provincia"<<endl;
        cout<<"c) Temperatura promedio de cada ciudad"<<endl;
        cout<<"d) Ciudad mas calida de cada provincia"<<endl;
        cout<<"e) Ciudad mas fria de cada provincia"<<endl;
        cout<<"f) Dia mas frio de cada provincia"<<endl;
        cout<<"g) Dia mas calido de cada ciudad"<<endl;
        cout<<"h) Mejor provincia para el cultivo de pimientos"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
				totalMuestras(stackptr,head,front);
                break;
            }
            case 'b':
            {
                bandera = 1;
                l.promedioTemp(bandera);
                break;
            }
            case 'c':
            {
                promedioTemp(stackptr);
                break;
            }
            case 'd':
            {
                ciudadCalida(stackptr,head,front);
                break;
            }
            case 'e':
            {
                ciudadFria(stackptr,head,front);
                break;
            }
            case 'f':
            {
                diaFrio(stackptr,head,front);
                break;
            }
            case 'g':
            {
                diaCalido(stackptr,head,front);
                break;
            }
            case 'h':
            {
                bandera = 2;
                l.promedioTemp(bandera);
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

void carga(struct city **stackptr,struct city **head,struct city **front,struct city **back){
    FILE *fp;
	struct city *temp = NULL;
    struct city *new_node = NULL;
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
			if(ident_prov==1){
            new_node = NULL;
			new_node = (struct city *) malloc(sizeof(struct city));
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
        }else if(ident_prov==2){
            new_node = NULL;
            new_node = (struct city *) malloc(sizeof(struct city));
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
            new_node->next = NULL;
            if(*head==NULL){
                *head=new_node;
            }else{
                temp = *head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }else if(ident_prov==3){
            new_node = NULL;
            new_node = (struct city *) malloc(sizeof(struct city));
            new_node = (struct city *) new_node;
            if(new_node==NULL){
                cout<<"No memory available"<<endl;
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
            new_node->next = NULL;
            if(*back==NULL){
                *back = new_node;
                *front = *back;
            }else{
                (*back)->next = new_node;
                *back = new_node;
            }
        }else{
			cout<<"Muestra descartada"<<endl;
		}
	}	
	fclose(fp);
}

void totalMuestras(struct city *stackptr, struct city *head,struct city *front){
	struct city *temp = NULL;
    int contador = 0;
    int contador1 = 0;
    int contador2 = 0;
    temp = stackptr;
    while(temp!=NULL){
        contador++;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        contador1++;
        temp = temp->next;
    }
    temp = front;
    while(temp!=NULL){
        contador2++;
        temp = temp->next;
    }
    cout<<"La muestra total de la temperatura y humedad de la provincia de Cordoba es "<<contador<<endl;
    cout<<"La muestra total de la temperatura y humedad de la provincia de Santa Fe es "<<contador1<<endl;
    cout<<"La muestra total de la temperatura y humedad de la provincia de Mendoza es "<<contador2<<endl;
}

void ciudadCalida(struct city *stackptr,struct city *head,struct city *front){
    int opcion=0;
    char continuar= ' ';
    
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
            ciudadesCalidas(stackptr,opcion,head,front);
            break;
        }
        case 2:
        {
            ciudadesCalidas(stackptr,opcion,head,front);
            break;
        }
        case 3:
        {
            ciudadesCalidas(stackptr,opcion,head,front);
            break;
        }
        
        default:
            {
                cout<<"Ingrese una opcion correcta"<<endl;
            }
        }  
        cout<<"Desea continuar(y/n)?"<<endl;
        cin>>continuar;  
    }while(continuar == 'y' || continuar=='Y');
}

void ciudadesCalidas(struct city *stackptr, int opcion,struct city *head,struct city *front){
    struct help *new_node = NULL;
    struct help *main = NULL;
    struct city *temp=NULL;
    float maxtemp = 0;
    float tempe = 0;
    float sumador = 0;    
    int contador = 0;
    string provincia = " ";
    if(opcion==1){
        maxtemp = 0;
        temp = stackptr;
        provincia = "Cordoba";
        while(temp!=NULL){
        if(temp->countryId==opcion){
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
                cout<<"La ciudad mas calida de la provincia de "<<provincia<<" es "<<new_node->nombre<<endl;
            }
            new_node = new_node->next;
        }
    }
    if(opcion==2){
        maxtemp = 0;
        temp = head;
        provincia = "Santa Fe";
        while(temp!=NULL){
        if(temp->countryId==opcion){
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
                cout<<"La ciudad mas calida de la provincia de "<<provincia<<" es "<<new_node->nombre<<endl;
            }
            new_node = new_node->next;
        }
    }
    if(opcion==3){
        maxtemp = 0;
        temp = front;
        provincia = "Mendoza";
        while(temp!=NULL){
        if(temp->countryId==opcion){
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
                cout<<"La ciudad mas calida de la provincia de "<<provincia<<" es "<<new_node->nombre<<endl;
            }
            new_node = new_node->next;
        }
    }
}

void ciudadFria(struct city *stackptr,struct city *head,struct city *front){
    int opcion=0;
    char continuar= ' ';
    do{
        cout<<"MENU DE OPCIONES"<<endl;
        cout<<"1. Ciudad mas fria de la provincia de Cordoba"<<endl;
        cout<<"2. Ciudad mas fria de la provincia de Santa Fe"<<endl;
        cout<<"3. Ciudad mas fria de la provincia de Mendoza"<<endl;
        cin>>opcion;
        
        switch (opcion)
        {
        case 1:
        {
            ciudadesFrias(stackptr,opcion,head,front);
            break;
        }
        case 2:
        {
            ciudadesFrias(stackptr,opcion,head,front);
            break;
        }
        case 3:
        {
            ciudadesFrias(stackptr,opcion,head,front);
            break;
        }
        
        default:
            {
                cout<<"Ingrese una opcion correcta"<<endl;
            }
        }  
        cout<<"Desea continuar(y/n)?"<<endl;
        cin>>continuar;  
    }while(continuar == 'y' || continuar=='Y');    
}

void ciudadesFrias(struct city *stackptr,int opcion,struct city *head,struct city *front){
    struct help *new_node = NULL;
    struct help *main = NULL;
    struct city *temp=NULL;
    float mintemp = 0;
    float tempe = 0;
    float sumador = 0;    
    int contador = 0;
    string provincia = " ";
    if(opcion==1){
        provincia = "Cordoba";
        temp = stackptr;
        while(temp!=NULL){
            if(temp->countryId==opcion){
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
        mintemp = new_node->sumador;
        while(new_node!=NULL){
            if(mintemp>new_node->sumador){
                mintemp = new_node->sumador;
            }
            new_node = new_node->next;
        }
        new_node = main;
        while(new_node!=NULL){
            if(new_node->sumador==mintemp){
                cout<<"La ciudad mas fria de la provincia de "<<provincia<<" es "<<new_node->nombre<<endl;
            }
            new_node = new_node->next;
        }
    }
    if(opcion==2){
        provincia = "Santa Fe";
        temp = head;
        mintemp = 0;
        while(temp!=NULL){
            if(temp->countryId==opcion){
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
        mintemp = new_node->sumador;
        while(new_node!=NULL){
            if(mintemp>new_node->sumador){
                mintemp = new_node->sumador;
            }
            new_node = new_node->next;
        }
        new_node = main;
        while(new_node!=NULL){
            if(new_node->sumador==mintemp){
                cout<<"La ciudad mas fria de la provincia de "<<provincia<<" es "<<new_node->nombre<<endl;
            }
            new_node = new_node->next;
        }
    }
    if(opcion==3){
        provincia = "Mendoza";
        mintemp = 0;
        temp = front;
        while(temp!=NULL){
            if(temp->countryId==opcion){
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
        mintemp = new_node->sumador;
        while(new_node!=NULL){
            if(mintemp>new_node->sumador){
                mintemp = new_node->sumador;
            }
            new_node = new_node->next;
        }
        new_node = main;
        while(new_node!=NULL){
            if(new_node->sumador==mintemp){
                cout<<"La ciudad mas fria de la provincia de "<<provincia<<" es "<<new_node->nombre<<endl;
            }
            new_node = new_node->next;
        }
    }
}

void diaFrio(struct city *stackptr,struct city *head,struct city *front){
    struct city *temp=NULL;
    int diamin = 0;
    int i = 0;
    float sumador,tempe = 0;
    int cont = 0;
    temp = stackptr;
    while(temp!=NULL){  
        if(temp->countryId==1){
            if(i==0){
                tempe = temp->m.temp;
                i++;
            }
            if(tempe > temp->m.temp){
                tempe = temp->m.temp;
                diamin = temp->m.time.day;
            }
        }
        temp = temp->next;
    }
    cout<<"La fecha mas fria de Cordoba es "<<diamin<<" con una temperatura de "<<tempe<<" grados centigrados"<<endl;
    tempe = 0;
    diamin = 0;
    i=0;
    temp = head;
    while(temp!=NULL){  
        if(temp->countryId==2){
            if(i==0){
                tempe = temp->m.temp;
                i++;
            }
            if(tempe > temp->m.temp){
                tempe = temp->m.temp;
                diamin = temp->m.time.day;
            }
        }
        temp = temp->next;
    }
    cout<<"La fecha mas fria de Santa Fe es "<<diamin<<" con una temperatura de "<<tempe<<" grados centigrados"<<endl;
    tempe = 0;
    diamin = 0;
    i=0;
    temp = front;
    while(temp!=NULL){  
        if(temp->countryId==3){
            if(i==0){
                tempe = temp->m.temp;
                i++;
            }
            if(tempe > temp->m.temp){
                tempe = temp->m.temp;
                diamin = temp->m.time.day;
            }
        }
        temp = temp->next;
    }
    cout<<"La fecha mas fria de Mendoza es "<<diamin<<" con una temperatura de "<<tempe<<" grados centigrados"<<endl;
}

void diaCalido(struct city *stackptr,struct city *head,struct city *front){
    struct city *temp=NULL;
    struct help *main=NULL;
    struct help *new_node=NULL;
    float tempe = 0;
    int dia = 0;
    int contador = 0;
    float temp_max = 0;
    int dia_max = 0;
    temp = stackptr;
    temp_max = temp->m.temp;
    cout<<"Ciudades de Cordoba:"<<endl;
    while(temp!=NULL){
        contador++;
        tempe = temp->m.temp;
        dia = temp->m.time.day;
        if(temp_max<tempe){
            temp_max = tempe;
            dia_max = dia;
        }
        if(contador==80){
            cout<<"El dia mas calido de la ciudad de "<<temp->city_name<<" es "<<dia_max<<" con el valor de "<<temp_max<<" grados centigrados"<<endl;
            contador = 0;
            if(temp->next!=NULL){
                temp_max = temp->next->m.temp;
            }
        }
        temp = temp->next;
    } 
    dia = 0;
    dia_max = 0;
    contador = 0;
    temp = head;
    temp_max = temp->m.temp;
    cout<<"Ciudades de Santa Fe: "<<endl;
    while(temp!=NULL){
        contador++;
        tempe = temp->m.temp;
        dia = temp->m.time.day;
        if(temp_max<tempe){
            temp_max = tempe;
            dia_max = dia;
        }
        if(contador==80){
            cout<<"El dia mas calido de la ciudad de "<<temp->city_name<<" es "<<dia_max<<" con el valor de "<<temp_max<<" grados centigrados"<<endl;
            contador = 0;
            if(temp->next!=NULL){
                temp_max = temp->next->m.temp;
            }
        }
        temp = temp->next;
    } 
    dia = 0;
    dia_max = 0;
    contador = 0;
    temp = front;
    temp_max = temp->m.temp;
    cout<<"Ciudades de Mendoza: "<<endl;
    while(temp!=NULL){
        contador++;
        tempe = temp->m.temp;
        dia = temp->m.time.day;
        if(temp_max<tempe){
            temp_max = tempe;
            dia_max = dia;
        }
        if(contador==80){
            cout<<"El dia mas calido de la ciudad de "<<temp->city_name<<" es "<<dia_max<<" con el valor de "<<temp_max<<" grados centigrados"<<endl;
            contador = 0;
            if(temp->next!=NULL){
                temp_max = temp->next->m.temp;
            }
        }
        temp = temp->next;
    }
}

void promedioTemp(struct city *stackptr){
    struct city *temp=NULL;
    struct help *main=NULL;
    struct help *new_node=NULL;
    int contador = 0;
    float tempe = 0;
    float sumador = 0;
    float promedio = 0;
    temp = stackptr;
    while(temp!=NULL){
        contador++;
        tempe = temp->m.temp;
        sumador = sumador + tempe;
        if(contador==80){
            new_node = (struct help *) malloc(sizeof(help));
            new_node = (struct help *) new_node;
            new_node->sumador = sumador;
            promedio = sumador/contador;
            new_node->promedio = promedio;
            for(int i=0;i<50;i++){
                new_node->nombre[i] = temp->city_name[i];
            }
            cout<<"El promedio de la temperatura de la ciudad "<<new_node->nombre;
            cout<<" es "<<fixed<<setprecision(2)<<new_node->promedio<<
            " grados centigrados"<<endl;
            new_node->next = main;
            main = new_node;
            contador = 0;
            sumador = 0;
        }
        temp = temp->next;
    }
}

