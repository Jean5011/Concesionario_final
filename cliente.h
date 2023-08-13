#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

void barraCli(){
    rlutil::locate(1,1);    cout<<"Nombre";
    rlutil::locate(13,1);   cout<<"Apellido";
    rlutil::locate(23,1);   cout<<"Direccion";
    rlutil::locate(34,1);   cout<<"Localidad";
    rlutil::locate(45,1);   cout<<"Dni";
    rlutil::locate(50,1);   cout<<"telefono";
    rlutil::locate(60,1);   cout<<"ID";
    rlutil::locate(70,1);   cout<<"Gmail";
}

class Cliente:public Persona{
private:
    int ID;
    char Gmail[40];
    bool Estado;
public:

    void setID(int n){ID=n;}                            int getID(){return ID;}
    void setGmail(const char *n){strcpy(Gmail,n);}      const char *getGmail(){return Gmail;}
    void setEstado(bool n){Estado=n;}                   bool getEstado(){return Estado;}

    void cargar(int n);
    void mostrar(int pos);
    bool grabarDisco();
    bool leerDisco(int pos);
    bool modificarDisco(int pos);

    bool operator==(bool aux){
    return Estado==aux;
    }
};

void Cliente::cargar(int n){
    ID=n;
    cout<<"INGRESAR ID CLIENTE: "<<ID<<endl;
    Persona::CargarPersona();
    cout<<"INGRESAR GMAIL: ";
    cargarCadena(Gmail,39);
    Estado=true;
}

void Cliente::mostrar(int pos){
    rlutil::locate(1,pos);    cout<<Nombre;
    rlutil::locate(13,pos);   cout<<Apellido;
    rlutil::locate(23,pos);   cout<<Direccion;
    rlutil::locate(34,pos);   cout<<Localidad;
    rlutil::locate(45,pos);   cout<<Dni;
    rlutil::locate(50,pos);   cout<<telefono;
    rlutil::locate(60,pos);   cout<<ID;
    rlutil::locate(70,pos);   cout<<Gmail;
}

///----------------------------DISCOS-----------------------

bool Cliente::grabarDisco(){
    FILE *p=fopen("cliente.dat","ab");
    if(p==NULL)return false;
    bool Escribio=fwrite(this,sizeof*this,1,p);
    fclose(p);
    return Escribio;
    }

bool Cliente::leerDisco(int pos){
    FILE *p=fopen("cliente.dat","rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof*this,0);
    bool Leyo=fread(this,sizeof*this,1,p);
    fclose(p);
    return Leyo;
    }

bool Cliente::modificarDisco(int pos){
    FILE *p=fopen("cliente.dat","rb+");
    if(p==NULL)return false;
    fseek(p,pos*sizeof*this,0);
    bool Modifico=fwrite(this,sizeof*this,1,p);
    fclose(p);
    return Modifico;
}

///-------------------------PROTOTIPO-----------------------

    int AutonumericoCliente();
    int BuscarIDCliente(int n);
    void CargarCliente();
    void MostrarCliente();
    void MostrarXIDCliente();
    void EliminarCliente();

///------------------------FUNCIONES-----------------------

int AutonumericoCliente(){
    Cliente obj;
    int pos=0,c=999;
    while(obj.leerDisco(pos++)){c=obj.getID();}
    return c;
}

int BuscarIDCliente(int n){
    Cliente obj;
    int pos=0;
    while(obj.leerDisco(pos)){
        if(obj.getID()==n)return pos;
        pos++;
    }
    return -1;
}

///********************************************************

void CargarCliente(){
    Cliente obj;
    int c=AutonumericoCliente()+1;
    obj.cargar(c);
    obj.grabarDisco();
    system("pause");
}

void MostrarCliente(){
    Cliente obj;
    int pos=0;
    bool b=false;
    barraCli();
    while(obj.leerDisco(pos)){
        if( obj.getEstado() ){
            obj.mostrar(pos+2);
            b=true;}
        pos++;
    }
    if(pos==0 || !b)cout<<"Archivo no existente.";
    cout<<"\n";     system("pause");
}

void MostrarXIDCliente(){
    Cliente obj;
    int pos,n;
    cout<<"ingrese ID:";    cin>>n;
    system("cls");
    pos=BuscarIDCliente(n);
    if(pos==-1)cout<<"ID no existente.";
    else {
        if( obj.getEstado() ){
        obj.leerDisco(pos);
        barraCli();
        obj.mostrar(2);
        }
        else cout<<"Archvo no existente.";
    }
    cout<<endl;
    system("pause");    system("cls");
}

void EliminarCliente(){
Cliente obj;
int pos,n;
cout<<"INGRESE ID: ";    cin>>n;
    system("cls");
    pos=BuscarIDCliente(n);
    if(pos==-1){
        cout<<"No Existe el archivo.\n";
        system("pause");
        return ;}
    obj.leerDisco(pos);
    if(!obj.getEstado() ){
        cout<<"Ese ID ya fue eliminado.\n";
        system("pause");
        return ;}
    obj.setEstado(false);
    if(obj.modificarDisco(pos))cout<<"Archivo Eliminado.\n";
    else cout<<"Error de archivo.\n";
    system("pause");    system("cls");
}

#endif // CLIENTE_H_INCLUDED
