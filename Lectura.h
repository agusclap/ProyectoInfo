#include <iostream>
using namespace std;

class Lectura{
    private:
    float tempe;
    float hum;
    int hora;
    int minutos;
    int dia;
    int mes; 
    int iden_city;
    int ident_prov;
    struct node{
        int id;
        float temperatura;
        float promedio;
        int contador;
        float sumador;
        struct node *next;
    };
    public:
        void promedioTemp();
        void leerArchivo(int opcion);
        Lectura();
        ~Lectura();
};

Lectura::Lectura(){
}

Lectura::~Lectura(){
}

void Lectura::promedioTemp(){
    FILE *fp;
    char nombre[50];
    double cont,cont2,cont1 = 0;
    double sumador,sumador1,sumador2 = 0;
    double promedio,promedio1,promedio2 = 0;
    float temp,temp1,temp2 = 0;
    fp = fopen("data_set.txt","r");
    while(fscanf(fp,"%d %d %s %f %f %d %d %d %d", &iden_city,&ident_prov,&nombre,&tempe,&hum,&hora,&minutos,&dia,&mes) != EOF){
        if(ident_prov==1){
            temp = tempe;
            sumador = sumador + temp;
            cont++;
        }else if(ident_prov==2){
            temp1 = tempe;
            sumador1 = sumador1 + temp1;
            cont1++;
        }else if(ident_prov==3){
            temp2 = tempe;
            sumador2 = sumador2 + temp2;
            cont2++;
        }
    }
    promedio = sumador / cont;
    promedio1 = sumador1 / cont1;
    promedio2 = sumador2 / cont2;
    cout<<"La temperatura promedio de Córdoba es "<<promedio<<endl;
    cout<<"La temperatura promedio de Santa Fé es "<<promedio1<<endl;
    cout<<"La temperatura promedio de Mendoza es "<<promedio2<<endl;
}


void Lectura::leerArchivo(int opcion){
   typedef struct node n;
    struct node *head=NULL;
    struct node *temp=NULL;
    FILE *fp;
    char nombre[50];
    float sumador = 0;    
    fp=fopen("data_set.txt","r");
    while(fscanf(fp,"%d %d %s %f", &iden_city,&ident_prov,&nombre,&tempe) != EOF){
        if(ident_prov==opcion ){
            
            temp=(struct node*)malloc(sizeof(struct node)); //Reservo memoria 
            if(temp==NULL){
                cout<<"No hay memoria disponible"<<endl;
                exit(0);
            }
            temp->temperatura=tempe;
            temp->next=NULL;
            //sumador=sumador+tempe;    
            temp->id=iden_city;
            }
        }
       float promedio=0;
        temp=head;
        while(temp!=NULL){
            promedio+=temp->temperatura;
            temp= temp->next;
        }
        cout<<"El promedio es:"<<promedio<<endl;
    }



