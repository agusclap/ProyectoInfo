#include <iostream>
#include <string>
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
    public:
        void promedioTemp(int);
        float leerArchivo(int opcion);
        Lectura();
        ~Lectura();
};

Lectura::Lectura(){
}

Lectura::~Lectura(){
}

void Lectura::promedioTemp(int bandera){
    FILE *fp;
    string provincia = " ";
    char nombre[50];
    double array[3] = {0};
    double cont,cont2,cont1 = 0;
    double sumador = 0;
    double sumador1 = 0;
    double sumador2 = 0;
    double promedio = 0;
    double promedio1 = 0;
    double promedio2 = 0;
    float temp,temp1,temp2 = 0;
    fp = fopen("data_set.txt","r");
    while(fscanf(fp,"%d %d %s %f %f %d %d %d %d\n", &iden_city,&ident_prov,&nombre,&tempe,&hum,&hora,&minutos,&dia,&mes) != EOF){
        if(ident_prov==1){ //Cordoba
            temp = tempe;
            sumador = sumador + temp;
            cont++;
        }else if(ident_prov==2){ // Santa Fe
            temp1 = tempe;
            sumador1 = sumador1 + temp1;
            cont1++;
        }else if(ident_prov==3){ // Mendoza
            temp2 = tempe;
            sumador2 = sumador2 + temp2;
            cont2++;
        }
    }
    fclose(fp);
    promedio = sumador / cont;
    promedio1 = sumador1 / cont1;
    promedio2 = sumador2 / cont2;
    if(bandera==1){
        cout<<"Temperatura promedio de Cordoba es "<<promedio<<endl;
        cout<<"Temperatura promedio de Santa Fe es "<<promedio1<<endl;
        cout<<"Temperatura promedio de Mendoza es "<<promedio2<<endl;
    }else{
    array[0] = promedio;
    array[1] = promedio1;
    array[2] = promedio2;
    for(int i=0;i<3;i++){
        if(array[i] > array[i+1]){
            array[0] = array[i];
        }
    }
    if(array[0]==promedio){
        provincia = "Cordoba";
    }
    if(array[0]==promedio1){
        provincia = "Santa Fe";
    }
    if(array[0]==promedio2){
        provincia = "Mendoza";
    }
    cout<<"La mejor provincia para cultivar pimientos es "<<provincia<<endl;
    }
}






