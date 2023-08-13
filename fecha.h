#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:
    int dia,mes,anio;
public:
///CONSTRUCTOR
    Fecha(int a=0,int m=0,int d=0){
    anio=a;
    mes=m;
    dia=d;
    }
    void Cargar();
    void Mostrar();

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

   bool operator>(Fecha n){
    if(anio>n.anio)return true;
    else if(anio==n.anio && mes>n.mes)return true;
    else if(anio==n.anio && mes==n.mes && dia>n.dia)return true;
    return false;
    }

    int operator-(Fecha &aux){
    return anio-aux.anio;
    }
};
Fecha FechaActual(){
        Fecha n;
        time_t tiempo;
        struct tm *tmPtr;
        tiempo=time(NULL);
        tmPtr=localtime(&tiempo);
        int AnioActual=tmPtr->tm_year+1900;
        int mesActual=tmPtr->tm_mon+1;
        int diaActual=tmPtr->tm_mday;
        n.setDia(diaActual);
        n.setMes(mesActual);
        n.setAnio(AnioActual);
        return n;
}

void Fecha::Cargar(){
    do{
        cout<<"Ingresar dia: ";     cin>>dia;
    }while(dia<1||dia>31);
    do{
        cout<<"Ingresar mes:";      cin>>mes;
    }while(mes<1||mes>12);
    do{
        cout<<"Ingresar anio: ";    cin>>anio;
    }while(anio<1||anio>FechaActual().getAnio());
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

///--------------PROTOTIPO VALIDACIONES-----------------------

    int Edad(Fecha n);
    bool ValidacionEdad(Fecha n);

///------------------------VALIDACIONES-----------------------

int Edad(Fecha n){
    Fecha f;
    f=FechaActual();
    int edad=f-n;
    if(n.getMes()>f.getMes())edad--;
    else if(n.getMes()==f.getMes()&& n.getDia()>f.getDia())edad--;
    return edad;
}

bool ValidacionEdad(Fecha n){
    return Edad(n)>=18;
}

#endif // FECHA_H_INCLUDED
