#ifndef REPORTE_RUBEN_H_INCLUDED
#define REPORTE_RUBEN_H_INCLUDED
///-----------------------------------------------------------------------
/*
                            PRIMER REPORTE
*/
///-----------------------------------------------------------------------
/***
crear un archivo con las siguiente propiedades Nombre de cliente, apellido de clientes y cantidad de compras
***/

void barraCom(){
    rlutil::locate(1,1);     cout<<"Nombre";
    rlutil::locate(15,1);    cout<<"Apellido";
    rlutil::locate(25,1);    cout<<"Compras";
}

class compras{
private:

    char nombre[40];
    char apellido[40];
    int CanCompra;

public:
    void setNombre      (const char *n){strcpy(nombre,n);  }    char *GetNombre        (){return nombre;}
    void setApellido    (const char *n){strcpy(apellido,n);}    const char *GetApellido(){return apellido;}
    void setCantidadCompras(int n)     {CanCompra=n;       }    int getCantidadCompras (){return CanCompra;}

        bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("compras.dat", "rb");
        if(p==NULL) return false;
        fseek(p, sizeof*this*pos,0);
        bool leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    bool grabarEnDisco(){
        FILE *p;
        p=fopen("compras.dat", "ab");
        if(p==NULL) return false;
        bool grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }
    void Mostrar(int pos){
        rlutil::locate(1,pos);    cout<<nombre;
        rlutil::locate(15,pos);   cout<<apellido;
        rlutil::locate(25,pos);   cout<<CanCompra;
    }

    void operator=(Cliente &aux){
    strcpy(nombre,aux.GetNombre());
    strcpy(apellido,aux.GetApellido());
    }
};
///PROTOTIPOS

    int CanCompras(int c);
    void CompraCliente();

///DESARROLLO

int CanCompras(int c){
    Venta v;
    int pos=0,cant=0;
    while(v.leerDiscoVenta(pos++)){
        if(v.getIdCliente()==c)cant++;
    }
    return cant;
}

void CompraCliente(){
    Cliente c;
    compras comp;
    int pos=0;
    while(c.leerDisco(pos++)){
        comp=c;
        comp.setCantidadCompras(CanCompras(c.getID()));
        comp.grabarEnDisco();
    }
    int poss=0;
    barraCom();
    while(comp.leerDeDisco(poss++)){comp.Mostrar(poss+1);}
    cout<<endl;
    system("pause");
}

///-----------------------------------------------------------------------
/*
                            SEGUNDO REPORTE
*/
///-----------------------------------------------------------------------
/*** muestra en orden alfabético los apellidos de los vendedores ***/
///PROTOTIPOS

    int contarRegistrosVendedor();
    void cargarArchivoVendedorEnVector(Vendedor *v, int cant);
    void mostrarVectorVendedores(Vendedor *v, int cant);
    void listarVendedoresXAlfa();
    void ordenarVendedoresAlfa(Vendedor *v, int cant);

///DESARROLLO
int contarRegistrosVendedor(){
    FILE *p;
    p=fopen("vendedor.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cant=ftell(p)/sizeof(Vendedor);
    fclose(p);
    return cant;
}

void cargarArchivoVendedorEnVector(Vendedor *v, int cant){
    int pos;
    for(pos=0;pos<cant;pos++){
        v[pos].leerDeDiscoVendedor(pos);
    }
}

void mostrarVectorVendedores(Vendedor *v, int cant){
    int pos;
    barraVend();
    for(pos=0;pos<cant;pos++){
        v[pos].mostrar(pos+2);
        cout<<endl;
    }
}

void listarVendedoresXAlfa(){
    int cant=contarRegistrosVendedor();
    if(cant<=0) exit(1);
    Vendedor *vec;
    vec=new Vendedor[cant];
    if(vec==NULL) exit(2);
    cargarArchivoVendedorEnVector(vec, cant);
    ordenarVendedoresAlfa(vec, cant);
    mostrarVectorVendedores(vec, cant);
    delete vec;
    system("pause");
}

void ordenarVendedoresAlfa(Vendedor *v, int cant){
    int i, j;
    int posMin=0;
    Vendedor aux;
    for(i=0;i<cant-1;i++){
        posMin=i;
        for(j=i+1;j<cant;j++){
            if(strcmp(v[j].GetApellido(),v[posMin].GetApellido())<0)    posMin=j;
        }
        aux=v[i];
        v[i]=v[posMin];
        v[posMin]=aux;
    }
}

#endif // REPORTE_RUBEN_H_INCLUDED
