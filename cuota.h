#ifndef CUOTA_H_INCLUDED
#define CUOTA_H_INCLUDED

void barraCuo(){
    rlutil::locate(1,1);  cout<<"Venta";
    rlutil::locate(10,1); cout<<"Cuota";
    rlutil::locate(20,1); cout<<"Fecha";
}

class cuota{
private:
    int IdVenta;
    int NCuota;
    Fecha FechaPago;

public:

    void setIdVenta (int i ){IdVenta=i;}        int getIdVenta      (){return IdVenta;}
    void setNCuota  (int n ){NCuota=n;}         int getNCuota       (){return NCuota;}
    void setFechaPago(Fecha f ){FechaPago=f;}   Fecha getFechaPago  (){return FechaPago;}

    void cargarCuota();
    void mostrarCuota(int pos);
    bool leerDiscoCuota(int pos);        ///OK
    bool grabarDiscoCuota();             ///OK
    bool modificarDiscoCuota(int pos);   ///OK
};

///--------------PROTOTIPO VALIDACIONES-----------------------
bool ValidacionIDVenta1(int v);
int CantCuota(int p);
bool ValidacionIDVenta2(int c , int v);
bool ValidacionCargar();
bool ValidacionMostrarCuota(int v);
int autonumericoCuota(int v);
bool fechaVenta(int vv,Fecha f);
bool fechaCuota(int v,int c,Fecha f);
bool ValdacionFeachaEmicion(int v,int c,Fecha f);
///------------------------VALIDACIONES-----------------------

bool ValidacionIDVenta1(int v){
    Venta obj;
    int pos=0;
    while(obj.leerDiscoVenta(pos++)){
        if(obj.getIdVenta()==v && obj.getTipoPlan()!=0 && obj.getEstado()) return true;
    }
    if(pos==0)cout<<"Id De Ventas No Encontrada.\n";
    else cout<<"Id De Ventas No Valida.\n";
    return false;
}

int CantCuota(int p){
    if( p==1 )p= 13;
    else if( p==2 )p= 19;
    else if( p==3 )p= 25;
    else if( p==4 )p= 37;
    return p;
}

bool ValidacionIDVenta2(int c , int v){
    Venta obj;
    int pos=0;
    while(obj.leerDiscoVenta(pos++)){
        if( c==CantCuota( obj.getTipoPlan() ) ){
            cout<<"Id De Ventas No Valida.\n";
            return false;}
    }
    return true;
}

bool ValidacionCargar(){
    Venta obj;
    int pos=0;
    while(obj.leerDiscoVenta(pos++)){
        if(obj.getEstado())return true;
    }
    cout<<"Falta Cargar Archivo De Cliente.\n";
    system("pause");
    return false;
}

bool ValidacionMostrarCuota(int v){
    Venta obj;
    int pos=0;
    while(obj.leerDiscoVenta(pos++)){
        if(obj.getIdVenta()==v && obj.getEstado())return true;
    }
    return false;
}

int autonumericoCuota(int v){
    cuota obj;
    int pos=0,n=0;
    while(obj.leerDiscoCuota(pos++)){
        if(obj.getIdVenta()==v)n = obj.getNCuota();
    }
    return n;
}

bool fechaVenta(int vv,Fecha f){
    Venta obj;
    int pos=0;
    while(obj.leerDiscoVenta(pos++)){
        if(vv==obj.getIdVenta() && f>obj.getFecha())return true;
    }
    return false;
}

bool fechaCuota(int v,int c,Fecha f){
    cuota obj;
    int pos=0;
    while(obj.leerDiscoCuota(pos++)){
        if((v==obj.getIdVenta() && obj.getNCuota()<c )&& f> obj.getFechaPago())return true;
    }
    return false;
}

bool ValdacionFeachaEmicion(int v,int c,Fecha f){
    if(c==1){
    if(fechaVenta(v,f))return true;
    }
    else if(fechaCuota(v,c,f))return true;
    return false;
}

///********************************************************

void cuota::cargarCuota(){
    int n;
    do{
    cout<<"Ingresar Id De Venta: ";     cin>>IdVenta;
    n=autonumericoCuota(IdVenta);       n++;
    }while(!ValidacionIDVenta1(IdVenta) || !ValidacionIDVenta2(n,IdVenta));
    NCuota=n;
    cout<<"Numero De Cuota: "<<NCuota<<endl;
    do{
    cout<<"Ingrese Fecha De Pago De La Cuota.\n";
    FechaPago.Cargar();
    }while( !ValdacionFeachaEmicion(IdVenta,NCuota,FechaPago) );
}

void cuota::mostrarCuota(int pos){
    rlutil::locate(1,pos);  cout<<IdVenta;
    rlutil::locate(10,pos); cout<<NCuota;
    rlutil::locate(20,pos); FechaPago.Mostrar();
}

///------------------------------DISCOS-----------------------

bool cuota::leerDiscoCuota(int pos){
    FILE *p=fopen("cuota.dat","rb");
    if(p==NULL&&pos>0){
        cout << "No pudo abrir el archivo.\n";
        return false;   }
    fseek(p,pos*sizeof (cuota),0);
    bool leyo=fread(this,sizeof(cuota),1,p);
    fclose(p);
    return leyo;
}

bool cuota::grabarDiscoCuota(){
    FILE *p=fopen("cuota.dat", "ab");
    if(p==NULL){
        cout << "No pudo abrir el archivo.\n";
        return false;   }
    bool escribio=fwrite(this,sizeof(cuota),1,p);
    fclose(p);
    return escribio;
}

bool cuota::modificarDiscoCuota(int pos){
    FILE *p=fopen("cuota.dat", "rb+");
    if(p==NULL){
        cout << "No pudo abrir el archivo./n";
        return false;}
    fseek (p, pos*sizeof(cuota),0);
    bool modifico=fwrite(this,sizeof(cuota),1,p);
    fclose(p);
    return modifico;
}

///-------------------------PROTOTIPO-----------------------

    int buscarXNCuota(int cA,int cC);
    int buscarXIDVenta(int v);
    void cargarCuota();
    void mostrarCuotas();

///-------------------------FUNCIONES-----------------------

int buscarXNCuota(int cA,int cC){
    int c=0;
    cuota obj;
    while(obj.leerDiscoCuota(c)){
       if(obj.getIdVenta()==cA && obj.getNCuota()==cC){
        return c;
       }
       c++;
    }
    return -1;
}

int buscarXIDVenta(int v){
    int c=0;
    cuota obj;
    while(obj.leerDiscoCuota(c)){
       if(obj.getIdVenta()==v)  return c;
       c++;
    }
    return -1;
}

///********************************************************

void cargarCuota(){
    if(!ValidacionCargar())return ;
    cuota obj;
    obj.cargarCuota();
    obj.grabarDiscoCuota();
    system("pause");
}

void mostrarCuotas(){
    int pos=0;
    cuota obj;
    bool b=false;
    barraCuo();
    while(obj.leerDiscoCuota(pos)){
        if( ValidacionMostrarCuota( obj.getIdVenta() ) ){
            obj.mostrarCuota(pos+2);
            b=true;}
        pos++;
    }
    if(pos==0 || !b ){cout<<"Archivo No Existente";}
    cout<<endl;
    system("pause");
}

void MostarXId(){
    cuota obj;
    int id,pos,poss=0;
    cout<<"Ingrese Id De Venta: ";   cin>>id;
    pos=buscarXIDVenta(id);
    system("cls");
    if(pos==-1){
        cout<<"Id No Encontrada.\n";
        system("pause");
        return ;}
    while(obj.leerDiscoCuota(poss++)){
        if(!ValidacionMostrarCuota( obj.getIdVenta() ) ){
            cout<<"Id No Encontrado.\n";
            system("pause");
            return ;}
        if(obj.getIdVenta()==id){
            barraCuo();
            obj.mostrarCuota(poss+2);
            cout<<endl;
        }
    }
    system("pause");
}

void MostrarXcuota(){
    cuota obj;
    int id,pos,c;
    cout<<"Ingrese Id de Venta:";       cin>>id;
    cout<<"Ingrese Numero de Cuota:";   cin>>c;
    system("cls");
    pos=buscarXNCuota(id,c);
    if(pos==-1){
        cout<<"Id No Encontrado.\n";
        system("pause");
        return ;}
    obj.leerDiscoCuota(pos);
    if(!ValidacionMostrarCuota(obj.getIdVenta())){
        cout<<"Id No Encontrado.\n";
        system("pause");
        return ;}
    barraCuo();
    obj.mostrarCuota(2);
    cout<<"\n";
    system("pause");
}

#endif // CUOTA_H_INCLUDED
