#ifndef REPORTE_JEAN_H_INCLUDED
#define REPORTE_JEAN_H_INCLUDED
///-----------------------------------------------------------------------
/*
                            PRIMER REPORTE
*/
///-----------------------------------------------------------------------
/***
Consiste de generar un archivo con las propiedades ID_venta,ID_cliente,
Can_cuotas y valor_cuota. Can_cuotas se encargar de sacar la cantidad de cuotas registradas.
valor_cuota saca el valor de cada cuota.

***/

void barraFac(){
    rlutil::locate(1,1);     cout<<"Venta";
    rlutil::locate(10,1);    cout<<"Cliente";
    rlutil::locate(20,1);    cout<<"Cuotas";
    rlutil::locate(30,1);    cout<<"Valor";
}

class Facturacion{
private:

    int ID_venta;
    int ID_cliente;
    int Can_cuotas;
    int valor_cuota;

public:
    void setIDventa(int n){ID_venta=n;}         int getIDventa(){return ID_venta;}
    void setIDcliente(int n){ID_cliente=n;}     int getIDcliente(){return ID_cliente;}
    void setCanCuota(int n){Can_cuotas=n;}      int getCanCuota(){return Can_cuotas;}
    void setValorCuotas(int n){valor_cuota=n;}  int getValorCuotas(){return valor_cuota;}

    bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("Facturacion.dat", "rb");
        if(p==NULL) return false;
        fseek(p, sizeof*this*pos,0);
        bool leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    bool grabarEnDisco(){
        FILE *p;
        p=fopen("Facturacion.dat", "ab");
        if(p==NULL) return false;
        bool grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }

    void Mostrar(int pos){
           rlutil::locate(1,pos);     cout<<ID_venta;
           rlutil::locate(10,pos);    cout<<ID_cliente;
           rlutil::locate(20,pos);    cout<<Can_cuotas;
           rlutil::locate(30,pos);    cout<<valor_cuota;
    }

    void operator=(Venta &v){
    ID_venta=v.getIdVenta();
    ID_cliente=v.getIdCliente();
    }
};
///PROTOTIPOS

    void facturacion();
    int CanCuota(int v);
    int ValorCuotas(float v, int p);

///DESARROLLO
int CanCuota(int v){
    cuota c;
    int pos=0,cc=0;
    while(c.leerDiscoCuota(pos++)){
        if(c.getIdVenta()==v)cc++;
    }
    return cc;
    }

int ValorCuotas(float v, int p){
    int valor,cuota=0;
    if(p!=0)cuota=CantCuota(p)-1;
    return valor=v/cuota;
}

void facturacion(){
    Venta v;
    Facturacion f;
    int pos=0;
    while(v.leerDiscoVenta(pos++)){
        if(v.getTipoPlan()!=0){
            f=v;
            f.setCanCuota(CanCuota(v.getIdVenta()));
            f.setValorCuotas(ValorCuotas(v.getPrecioFinal(),v.getTipoPlan()));
            f.grabarEnDisco();
        }
        int poss=0;
        barraFac();
        while(f.leerDeDisco(poss++)){f.Mostrar(pos+1);}
    }
    cout<<endl;
    system("pause");
}
///-----------------------------------------------------------------------
/*
                            SEGUNDO REPORTE
*/
///-----------------------------------------------------------------------
/*** Muestra las ventas de tipo 0 es decir que pagaron el su totalidad***/
///PROTOTIPOS

void PagoTotal();
int tamvec();
void cargarvec(Venta *vec);
void mostrarvec(Venta *vec,int tam);

///DESARROLLO
int tamvec(){
    Venta v;
    int pos=0,cant=0;
    while(v.leerDiscoVenta(pos++)){
        if(v.getTipoPlan()==0)cant++;
    }
    return cant;
}

void cargarvec(Venta *vec){
    Venta v;
    int pos=0,cant=0;
    while(v.leerDiscoVenta(pos++)){
        if(v.getTipoPlan()==0){
                vec[cant]=v;
                cant++;
        }
    }
}

void mostrarvec(Venta *vec,int tam){
   for(int i=0;i<tam;i++){
        vec[i].mostrar(i+2);
    }
}

void PagoTotal(){
    int tam;                Venta *vec;
    tam=tamvec();           vec=new Venta[tam];
    cargarvec(vec);         barraVent();
    mostrarvec(vec,tam);    delete vec;
    cout<<endl;             system("pause");
}

#endif // REPORTE_JEAN_H_INCLUDED
