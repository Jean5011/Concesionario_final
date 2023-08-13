#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

void barraVent(){
    rlutil::locate(1,1);    cout<<"Id Venta";
    rlutil::locate(10,1);    cout<<"Cliente";
    rlutil::locate(20,1);    cout<<"Vendedor";
    rlutil::locate(30,1);    cout<<"Vehiculo";
    rlutil::locate(40,1);    cout<<"Plan";
    rlutil::locate(50,1);    cout<<"Fec Venta";
    rlutil::locate(61,1);    cout<<"Total";
    rlutil::locate(71,1);    cout<<"Comision";
}

class Venta{
private:
    int IdVenta;
    int IdCliente;
    int IdVendedor;
    int IdVehiculo;
    int TipoPlan;               ///de pago( planes: 0)pago total, 1) 12, 2) 18, 3)  24,4) 36  en cuotas fijas)
    float PrecioFinal;          ///(ENTRE 3 Y 4 AUMENTA EL DOBLE)
    float comision;             /// para el vendedor (un 1% del costo de la venta)
    Fecha fec;
    bool Estado;

public:

    void setIdVenta     (int i)     {IdVenta=i;     }   int getIdVenta      (){return IdVenta;    }
    void setIdCliente   (int i)     {IdCliente=i;   }   int getIdCliente    (){return IdCliente;  }
    void setIdvendedor  (int i)     {IdVendedor=i;  }   int getIdVendedor   (){return IdVendedor; }
    void setIdVehiculo  (int i)     {IdVehiculo=i;  }   int getVehiculo     (){return IdVehiculo; }
    void setTipoPlan    (int t)     {TipoPlan=t;    }   int getTipoPlan     (){return TipoPlan;   }
    void setPrecioFinal (float pf)  {PrecioFinal=pf;}   float getPrecioFinal(){return PrecioFinal;}
    void setGanacia     (float c)   {comision=c;    }   float getcomision   (){return comision;   }
    void setFecha       (Fecha f)   {fec=f;         }   Fecha getFecha      (){return fec;        }
    void setEstado      (bool e)    {Estado=e;      }   bool getEstado      (){return Estado;     }

    void cargar(int n);                  ///OK
    void mostrar(int pos);               ///OK
    bool leerDiscoVenta(int pos);        ///OK
    bool grabarDiscoVenta();             ///OK
    bool modificarDiscoVenta(int pos);   ///OK

    bool operator =(bool &aux){ return Estado=aux;}
    bool operator == (bool aux){if(Estado==aux)return true;
    return false;}

};

///--------------PROTOTIPO VALIDACIONES-----------------------

    bool ValidacionArchivosCliente();
    bool ValidacionArchivosVendedor();
    bool ValidacionArchivosVehiculo();
    bool ValidacionArchivo();
    bool ValidacionCliente(int n);
    bool ValidacionVendedor(int n);
    bool ValidacionVehiculo(int n);
    bool ValidacionFechaVenta(Fecha f,int c,int v);
    float CargarComicion(int v, int tp);
    float PrecioFinal(float n);

///------------------------VALIDACIONES-----------------------

bool ValidacionArchivosCliente(){
    Cliente c;
    int pos=0;
    while(c.leerDisco(pos++)){
        if(c.getEstado())return true;
    }
    return false;
}

bool ValidacionArchivosVendedor(){
    Vendedor v;
    int pos=0;
    while(v.leerDeDiscoVendedor(pos++)){
        if(v.getEstado() )return true;
    }
    return false;
}

bool ValidacionArchivosVehiculo(){
    vehiculo v;
    int pos=0;
    while(v.leerDiscoVehiculo(pos++)){
        if(v.getEstado())return true;
    }
    return false;
}

bool ValidacionArchivo(){
    Vendedor ven;
    Cliente c;
    bool b=true;
    if(!ValidacionArchivosVehiculo()){
        cout<<"Falta Cargar Archivo De Vehículo\n";
        b=false;
    }
    if(!ValidacionArchivosVendedor()){
        cout<<"Falta Cargar Archivo De Vendedores\n";
        b=false;
    }
    if(!ValidacionArchivosCliente()){
        cout<<"Falta Cargar Archivo De Cliente\n";
        b=false;
    }
    return b;
}

bool ValidacionCliente(int n){
    Cliente c;
    int pos=0;
    while(c.leerDisco(pos++)){
        if(c.getID()==n && c.getEstado())return true;
    }
    return false;
}

bool ValidacionVendedor(int n){
    Vendedor v;
    int pos=0;
    while(v.leerDeDiscoVendedor(pos++)){
        if(v.getID()==n && v.getEstado())return true;
    }
    return false;
}

bool ValidacionVehiculo(int n){
    vehiculo v;
    int pos=0;
    while(v.leerDiscoVehiculo(pos++)){
        if(v.getID()==n && v.getEstado())return true;
    }
    return false;
}

bool ValidacionFechaVenta(Fecha f,int c,int v){
    Vendedor vv;
    Cliente cc;
    bool bv=false,bc=false,b=true;
    int pos=0,poss=0;
    while(vv.leerDeDiscoVendedor(pos++)){
        if(vv.getID()==v && vv.getFechaInicio()>f)bv=true;
    }
    while(cc.leerDisco(poss++)){
        if(cc.getID()==c && ValidacionEdad(cc.getFecha_nacimiento()))bc=true;
    }
    if( !bv || !bc ){b=false;}
    return b;
}



float CargarPrecioFinal(int v, int tp){
    vehiculo vv;
    int pos=0;
    float p=0;
    while(vv.leerDiscoVehiculo(pos++)){
        if(vv.getID()==v)p=vv.getPrecio();
    }
    if(tp>2)p*=2;
    return p;
}

float CargarComicion(float n){
    return n*0.1;
}

///********************************************************

void Venta::cargar(int ID){

    IdVenta=ID;
    cout<<"Id Venta: "<<IdVenta<<endl;

    do{
    cout<<"Ingresar Id Cliente: ";   cin>>IdCliente;
    }while(!ValidacionCliente(IdCliente));

    do{
    cout<<"Ingresar Id Vendedor: ";  cin>>IdVendedor;
    }while(!ValidacionVendedor(IdVendedor));

    do{
    cout<<"Ingresar Id Vehículo: ";  cin>>IdVehiculo;
    }while(!ValidacionVehiculo(IdVehiculo));

    do{
    cout<<"Ingresar Tipo Plan De Pago: ";   cin>>TipoPlan;
    }while(TipoPlan>4 && TipoPlan>0);

    do{
    cout<<"Ingresar Fecha De Venta:/n";     fec.Cargar();
    }while(ValidacionFechaVenta(fec, IdCliente,IdVendedor));

    PrecioFinal=CargarPrecioFinal(IdVendedor,TipoPlan);

    comision=CargarComicion(PrecioFinal);

    Estado=true;
}

void Venta::mostrar(int pos){
    rlutil::locate(1 ,pos); cout<<IdVenta;
    rlutil::locate(10,pos); cout<<IdCliente;
    rlutil::locate(20,pos); cout<<IdVendedor;
    rlutil::locate(30,pos); cout<<IdVehiculo;
    rlutil::locate(40,pos); cout<<TipoPlan;
    rlutil::locate(50,pos); fec.Mostrar();
    rlutil::locate(61,pos); cout<<PrecioFinal;
    rlutil::locate(71,pos); cout<<comision;
}

///------------------------------DISCOS-----------------------

bool Venta::leerDiscoVenta(int pos){
    FILE *p=fopen("venta.dat","rb");
    if(p==NULL&&pos>0){
        cout << "No pudo abrir el archivo\n";
        return false;   }
    fseek(p,pos*sizeof (Venta),0);
    bool leyo=fread(this,sizeof(Venta),1,p);
    fclose(p);
    return leyo;
}

bool Venta::grabarDiscoVenta(){
    FILE *p=fopen("venta.dat", "ab");
    if(p==NULL){
        cout << "No pudo abrir el archivo\n";
        return false;   }
    bool escribio=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return escribio;
}

bool Venta::modificarDiscoVenta(int pos){
    FILE *p=fopen("venta.dat", "rb+");
    if(p==NULL){
        cout << "No pudo abrir el archivo\n";
        return false;   }
    fseek (p, pos*sizeof(Venta),0);
    bool modifico=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return modifico;
}

///-------------------------PROTOTIPO-----------------------

    int autonumericoVenta();
    int buscarIDVenta(int cA);
    void cargarVenta();
    void mostrarVenta();
    void mostrarXIDVentas();
    void eliminarVenta();

///------------------------FUNCIONES-----------------------

int autonumericoVenta(){
Venta obj;
int pos=0,c=999;
while(obj.leerDiscoVenta(pos++)){c=obj.getIdVenta();}
return c;
}

int buscarIDVenta(int cA){
    int c=0;
    Venta obj;
    while( obj.leerDiscoVenta(c) ){
       if(obj.getIdVenta()==cA) return c;
       c++;
    }
    return -1;
}

///********************************************************

void cargarVenta(){
    if(!ValidacionArchivo()){
        system("pause");
        return ;}
    Venta obj;
    int c;
    c=autonumericoVenta()+1;
    obj.cargar(c);
    obj.grabarDiscoVenta();
    system("pause");
}

void mostrarVenta(){
    int pos=0;
    Venta obj;
    bool b=false;
    barraVent();
    while(obj.leerDiscoVenta(pos)){
        if( obj.getEstado() ){
            obj.mostrar(pos+2);
            b=true;}
        pos++;
    }
    if(pos==0 || !b)cout<<"Archivo no Exitente";
    cout<<endl;
    system("pause");
}

void mostrarXIDVentas(){
    int pos,id;
    Venta obj;
    cout<<"Ingrese Id: ";   cin>>id;
    pos=buscarIDVenta(id);
    if(pos==-1){
        cout<<"Id No Existente\n";
        system("pause");
        return ;}
    obj.leerDiscoVenta(pos);
    barraVent();
    obj.mostrar(2);
    cout<<endl;
    system("pause");
}

void eliminarVenta(){
    Venta obj;
    int pos,n;
    cout<<"Ingrese Id:";    cin>>n;
    system("cls");
    pos=buscarIDVenta(n);
    if(pos==-1){
        cout<<"El archivo no existe.\n";
        system("pause");
        return ;}
    obj.leerDiscoVenta(pos);
    if(!obj.getEstado()){
        cout<<"El archivo ya fue eliminado.\n";
        system("pause");
        return ;}
    obj.setEstado(false);
    if(obj.modificarDiscoVenta(pos))cout<<"Archivo Eliminado.";
    else cout<<"Error de Archivo.";
    system("pause");
}

///-------------------- MENU --------------------

#endif // VENTA_H_INCLUDED
