#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

void barraVend(){
    rlutil::locate(1,1);    cout<<"Nombre";
    rlutil::locate(10,1);   cout<<"Apellido";
    rlutil::locate(21,1);   cout<<"Direccion";
    rlutil::locate(34,1);   cout<<"Localidad";
    rlutil::locate(44,1);   cout<<"DNI";
    rlutil::locate(50,1);   cout<<"Fecha Ini";
    rlutil::locate(61,1);   cout<<"Telefono";
    rlutil::locate(72,1);   cout<<"ID";
    rlutil::locate(81,1);   cout<<"Cuil";
}

class Vendedor:public Persona{
    private:
        int ID;     Fecha FechaInicio;
        int CUIL;   bool Estado;
    public:

        void setID          (int id)  {ID=id;}            int   getID()         {return ID;}
        void setCUIL        (int c)   {CUIL=c;}           int   getCUIL()       {return CUIL;}
        void setFechaInicio (Fecha fi){FechaInicio=fi;}   Fecha getFechaInicio(){return FechaInicio;}
        void setEstado      (bool e)  {Estado=e;}         bool  getEstado()     {return Estado;}

        void cargar(int n);                     ///OK
        void mostrar(int pos);                  ///OK
        bool grabarEnDiscoVendedor();           ///OK
        bool leerDeDiscoVendedor(int pos);      ///OK
        bool modificarDiscoVendedor(int pos);   ///OK

        bool operator==(bool aux){
        return Estado==aux;}
};

///-------------------PROTOTIPO VALIDACIONES-----------------------

    bool ValidacionFechaInicio(Fecha f_inicio,Fecha f_nacimiento);

///------------------------VALIDACIONES-----------------------

bool ValidacionFechaInicio(Fecha f_inicio,Fecha f_nacimiento){
    Fecha f=f_nacimiento;
    int cumpleanios=f.getAnio()+18;
    f.setAnio(cumpleanios);
    return f>f_inicio;
}

///---------------------------------------------------------

void Vendedor::cargar(int n){
    Fecha f;
    ID=n;
    cout<<"Id Vendedor: "<<ID<<endl;
    Persona::CargarPersona();
    cout<<"Ingresar Cuil: ";
    cin>>CUIL;
    do{
        cout<<"Fecha De Inicio De Actividad:\n";
        FechaInicio.Cargar();
    }while(!ValidacionFechaInicio(FechaInicio,F_nacimiento));
    Estado=true;
}

void Vendedor::mostrar(int pos){
    rlutil::locate(1,pos);    cout<<Nombre;
    rlutil::locate(10,pos);   cout<<Apellido;
    rlutil::locate(21,pos);   cout<<Direccion;
    rlutil::locate(34,pos);   cout<<Localidad;
    rlutil::locate(44,pos);   cout<<Dni;
    rlutil::locate(50,pos);   FechaInicio.Mostrar();
    rlutil::locate(61,pos);   cout<<telefono;
    rlutil::locate(72,pos);   cout<<ID;
    rlutil::locate(81,pos);   cout<<CUIL;
}

///----------------------------- DISCO -----------------------------

bool Vendedor::grabarEnDiscoVendedor(){
    FILE *p=fopen("vendedor.dat", "ab");
    if(p==NULL){
        cout << "No pudo abrir el archivo\n";
        return false;   }.
    bool escribio=fwrite(this,sizeof(Vendedor),1,p);
    fclose(p);
    return escribio;
}

bool Vendedor::leerDeDiscoVendedor(int pos){
    FILE *p=fopen("vendedor.dat","rb");
    if(p==NULL&&pos>0){
        cout << "No pudo abrir el archivo.\n";
        return false;   }
    fseek(p,pos*sizeof (Vendedor),0);
    bool leyo=fread(this,sizeof(Vendedor),1,p);
    fclose(p);
    return leyo;
}

bool Vendedor::modificarDiscoVendedor(int pos){
    FILE *p=fopen("vendedor.dat", "rb+");
    if(p==NULL){
        cout << "No pudo abrir el archivo.\n";
        return false;   }
    fseek (p, pos*sizeof(Vendedor),0);
    bool modifico=fwrite(this,sizeof(Vendedor),1,p);
    fclose(p);
    return modifico;
}

///-------------------------PROTOTIPO-----------------------

        int autonumericoVendedor();
        int buscarIDVendedor(int n);
        void cargarVendedor();
        void mostrarVendedor();
        void mostrarXIDVendedor() ;
        void cambiarEstadoVendedor();

///------------------------FUNCIONES-----------------------

int autonumericoVendedor(){
    Vendedor obj;
    int pos=0,c=999;
    while(obj.leerDeDiscoVendedor(pos++)){c=obj.getID();}
    return c;
}

int buscarIDVendedor(int n){
    Vendedor obj;
    int pos=0;
    while(obj.leerDeDiscoVendedor(pos)){
        if( obj.getID()==n )return pos;
        pos++;
    }
    return -1;
}

///********************************************************

void cargarVendedor(){
    Vendedor obj;
    obj.cargar(autonumericoVendedor()+1);
    obj.grabarEnDiscoVendedor();
    system("pause");
}

void mostrarVendedor(){
    Vendedor obj;
    int pos=0;
    bool b=false;
    barraVend();
    while(obj.leerDeDiscoVendedor(pos)){
        if( obj.getEstado() ){
            obj.mostrar(pos+2);
            b=true;}
        pos++;
    }
    if(pos==0 || !b )cout<<"Archivo No Existente.";
    cout<<endl;
    system("pause");
}

void mostrarXIDVendedor(){
    Vendedor obj;
    int pos;
    cout<<"Ingrese Id De Vendedor: ";
    cin>>pos;
    system("cls");
    pos=buscarIDVendedor(pos);
    if(pos==-1)cout<<"Id No Existente.";
    else {
        if( obj.getEstado() ){
            barraVend();
            obj.leerDeDiscoVendedor(pos);
            obj.mostrar(2);
        }
        else cout<<"Archivo No Existente.";
    }
    cout<<"\n";
    system("pause");    system("cls");
}

void cambiarEstadoVendedor(){
    Vendedor obj;
    int pos;
    cout<<"Ingrese Id"; cin>>pos;
    system("cls");
    pos=buscarIDVendedor(pos);
    if( pos==-1 ){
        cout<<"Ese Id No Esta En El Archivo.\n";
        system("pause");
        return ;}
    obj.leerDeDiscoVendedor(pos);
    if( !obj.getEstado() ){
        cout<<"Ese Id No Esta En El Archivo.\n";
        system("pause");
        return ;}
    obj.setEstado(false);
    if (obj.modificarDiscoVendedor(pos))cout<<"Archivo Modificado.";
    else cout<<"Error de archivo.";
    cout<<endl;
    system("pause");
}
#endif // VENDEDOR_H_INCLUDED
