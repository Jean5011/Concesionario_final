#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

void barraVeh(){
    rlutil::locate(1,1);    cout<<"ID";
    rlutil::locate(10,1);   cout<<"Tipo";
    rlutil::locate(20,1);   cout<<"Modelo";
    rlutil::locate(31,1);   cout<<"Nombre";
    rlutil::locate(43,1);   cout<<"Marca";
    rlutil::locate(53,1);   cout<<"Precio";
}

class vehiculo{
private:
    int Id;         char Nombre[40];    float Precio;
    int Tipo;       char Marca[40];     bool Estado;
    int Modelo;
    /// Tipo 1. Auto - 2. Moto - 3. Camioneta
    /// Modelo Debe ser mayor a 2010
public:

    void setId      (int i)           {Id = i;}                 int getID       (){return Id;    }
    void setTipo    (int t)           {Tipo = t;}               int getTipo     (){return Tipo;  }
    void setModelo  (int m)           {Modelo = m;}             int getModelo   (){return Modelo;}
    void setNombre  (const char *n)   {strcpy(Nombre, n);}      char *getNombre (){return Nombre;}
    void setMarca   (const char *ma)  {strcpy(Marca, ma);}      char *getMarca  (){return Marca; }
    void setPrecio  (float p)         {Precio = p;}             float getPrecio (){return Precio;}
    void setEstado  (bool e)          {Estado = e;}             bool getEstado  (){return Estado;}

    void cargarVehiculo(int n);             ///OK
    void mostrarVehiculo(int pos);          ///OK
    bool leerDiscoVehiculo(int pos);        ///OK
    bool grabarDiscoVehiculo();             ///OK
    bool modificarDiscoVehiculo(int pos);   ///OK

    bool operator == (bool aux){
    if(Estado==aux)return true;
    return false;
    }
};
///---------------------------------------------------------

void vehiculo::cargarVehiculo(int n){

    Id=n;
    cout<<"Id Vehiculo: "<<Id<<endl;

    do{cout<<"Ingresar Tipo De Vehiculo: ";
    cin>>Tipo;  }while( Tipo<1 || Tipo>3 );

    do{cout<<"Ingresar Modelo: ";
    cin>>Modelo;  }while( Modelo<2010 || Modelo>FechaActual().getAnio() );

    cout<<"Ingresar Nombre: ";
    cargarCadena(Nombre, 39);

    cout<<"Ingresar Marca: ";
    cargarCadena(Marca, 39);

    do{cout<<"Inresar Precio: ";
    cin>>Precio;    }while( Precio<0 );
    Estado=true;
}

void vehiculo::mostrarVehiculo(int pos){
    rlutil::locate(1, pos); cout<<Id;
    rlutil::locate(10,pos); cout<<Tipo;
    rlutil::locate(20,pos); cout<<Modelo;
    rlutil::locate(30,pos); cout<<Nombre;
    rlutil::locate(43,pos); cout<<Marca;
    rlutil::locate(53,pos); cout<<Precio;}

///----------------------------DISCOS-----------------------

bool vehiculo::leerDiscoVehiculo(int pos){
    FILE *p=fopen("vehiculo.dat","rb");
    if(p==NULL&&pos>0){
        cout << "No pudo abrir el archivo.\n";
        return false;   }
    fseek(p,pos*sizeof (vehiculo),0);
    bool leyo=fread(this,sizeof(vehiculo),1,p);
    fclose(p);
    return leyo;
}

bool vehiculo::grabarDiscoVehiculo(){
    FILE *p=fopen("vehiculo.dat", "ab");
    if(p==NULL){
        cout << "No pudo abrir el archivo.\n";
        return false;   }
    bool escribio=fwrite(this,sizeof(vehiculo),1,p);
    fclose(p);
    return escribio;
}

bool vehiculo::modificarDiscoVehiculo(int pos){
    FILE *p=fopen("vehiculo.dat", "rb+");
    if(p==NULL){
        cout << "No pudo abrir el archivo.\n";
        return false;   }
    fseek (p, pos*sizeof(vehiculo),0);
    bool modifico=fwrite(this,sizeof(vehiculo),1,p);
    fclose(p);
    return modifico;
}

///-------------------------PROTOTIPO-----------------------

        int autonumericoVehiculo();
        int buscarIDvehiculo(int cA);
        void cargarVehiculo();
        void mostrarVehiculos();
        void mostrarVehiculo();
        void eliminarVehiculo();

///------------------------FUNCIONES-----------------------

int autonumericoVehiculo(){
    vehiculo obj;
    int pos=0,c=999;
    while(obj.leerDiscoVehiculo(pos++)){c=obj.getID();}
    return c;
}

int buscarIDvehiculo(int cA){
    int pos=0;
    vehiculo obj;
    while(obj.leerDiscoVehiculo(pos)){
       if(obj.getID()==cA){
        return pos;
       }    pos++;    }
    return -1;
}

///********************************************************

void cargarVehiculo(){
    vehiculo obj;
    int ID=autonumericoVehiculo()+1;
    obj.cargarVehiculo(ID);
    obj.grabarDiscoVehiculo();
    system("pause");
}

void mostrarVehiculos(){
    int pos=0;
    vehiculo obj;
    bool flag=false;
    barraVeh();
    while( obj.leerDiscoVehiculo(pos) ){
        if( obj.getEstado() ){
            obj.mostrarVehiculo(pos+2);
            flag=true;}    pos++;    }
    if( pos==0 || !flag )cout<<"Archivo No Existente.\n";
    cout<<"\n";
    system("pause");
}

void mostrarVehiculo(){
    int pos;
    vehiculo obj;
    cout<<"Ingrese Id ";
    cin>>pos;
    system("cls");
    pos=buscarIDvehiculo(pos);
    if(pos==-1){
        cout<<"No Se Encuentra Archivo.\n";
        system("pause");
        return ;}
    obj.leerDiscoVehiculo(pos);
    if( obj.getEstado() ){
        barraVeh();
        obj.mostrarVehiculo(2);
        }
    else{cout<<"No Se Encuentra Archivo.\n";}
    cout<<endl;
    system("pause");
}

void eliminarVehiculo(){
    vehiculo obj;
    int id;
    cout<<"Id Del Auto A Eliminar: ";
    cin>>id;
    if(buscarIDvehiculo(id)==-1){
        cout<<"Ese Id No Esta En El Archivo.\n";
        system("pause");
        return ;}
    obj.leerDiscoVehiculo(buscarIDvehiculo(id));
    if(!obj.getEstado()){
        cout<<"Ese Id No Esta En El Archivo.\n";
        system("pause");
        return ;}
    obj.setEstado(false);
    if(obj.modificarDiscoVehiculo(buscarIDvehiculo(id)))cout<<"Se Modifico."
    else cout<<"No Se Pudo Modificar.";
    cout<<endl;
    system("pause");
}

#endif // VEHICULO_H_INCLUDED
