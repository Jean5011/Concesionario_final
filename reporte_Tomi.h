#ifndef REPORTE_TOMI_H_INCLUDED
#define REPORTE_TOMI_H_INCLUDED


///-----------------------------------------------------------------------
/*
                            PRIMER REPORTE
*/
///-----------------------------------------------------------------------


void TomiMostrarXPromedio(){
    /***
    Suma Los Precios De Todos Los Vehículos Y Luego Obtiene Un Promedio De Cuanto
    Vale Cada Vehículo, Y Luego En Un Vector Dinámico Guarda Y Muestra Los Que Esten
    Por Debajo De Ese Promedio

    ***/

    vehiculo obj;
    int pos=0,ultimo=0;
    float promedio=0.00;
    while(obj.leerDiscoVehiculo(pos)){
        promedio=promedio+obj.getPrecio();
        pos++;
    }
    promedio=promedio/pos;
    vehiculo *vec;
    vec = new vehiculo[pos];
    for(int y=0;y<=pos;y++){ vec[y].setPrecio(0); }
    pos=0;
    while(obj.leerDiscoVehiculo(pos++)){

        if(obj.getPrecio()<promedio){
            vec[ultimo].setId       (obj.getID());
            vec[ultimo].setTipo     (obj.getTipo());
            vec[ultimo].setModelo   (obj.getModelo());
            vec[ultimo].setNombre   (obj.getNombre());
            vec[ultimo].setMarca    (obj.getMarca());
            vec[ultimo].setPrecio   (obj.getPrecio());
            vec[ultimo].setEstado   (obj.getEstado());
            ultimo++;
        }
    }
    barraVeh();
    for(int h=0;h<=ultimo;h++){
        if(vec[h].getPrecio()>0){
            vec[h].mostrarVehiculo(h+2);
            cout<<endl;
        }
    }
    delete []vec;
    system("pause");
}


///-----------------------------------------------------------------------
/*
                            SEGUNDO REPORTE
*/
///-----------------------------------------------------------------------
    /***
    Guarda En Un Archivo Con Las Propiedades Nombre Del Vehículo, Marca, Modelo
    Y Cuantos Vehículos Se Vendieron Y Los Muestra Por Pantalla
    ***/

class VehiculosVendidos{
private:

    char nombre[40];    int modelo;
    char marca[40];     int cantidad;

public:

    void setNombre      (const char *n){strcpy( nombre,n);} char *getNombre(){return nombre;}
    void setMarca       (const char *n){strcpy( marca ,n);} char *getMarca (){return marca;}
    void setModelo      (int n){modelo=n;}                  int getModelo  (){return modelo;}
    void setCantidad    (int n){cantidad=n;}                int getCantidad(){return cantidad;}

    void CargarVe(vehiculo &aux,int n){
        strcpy(nombre,aux.getNombre() );
        strcpy(marca, aux.getMarca() );
        modelo = aux.getModelo();
        cantidad = n;}

    void mostrar(int pos){
        rlutil::locate(1,pos);    cout<<nombre;
        rlutil::locate(10,pos);   cout<<marca;
        rlutil::locate(20,pos);   cout<<modelo;
        rlutil::locate(30,pos);   cout<<cantidad;}

///-----------------------------------------------------------------------
/*
                                    DISCO
*/
///-----------------------------------------------------------------------

bool leerDisco(int pos){
    FILE *p=fopen("vehiculosvendidos.dat","rb");
    if(p==NULL&&pos>0){
        cout << "No pudo abrir el archivo.\n";
        return false;}
    fseek(p,pos*sizeof (VehiculosVendidos),0);
    bool leyo=fread(this,sizeof(VehiculosVendidos),1,p);
    fclose(p);
    return leyo;
}

bool grabarDisco(){
    FILE *p=fopen("vehiculosvendidos.dat", "ab");
    if(p==NULL){
        cout << "No pudo abrir el archivo.\n";
        return false;}
    bool escribio=fwrite(this,sizeof(VehiculosVendidos),1,p);
    fclose(p);
    return escribio;
}

///-----------------------------------------------------------------------
/*
                                    DISCO
*/
///-----------------------------------------------------------------------

};
void TomiVehiculosComprados(){
    vehiculo veh;
    VehiculosVendidos obj;
    Venta ven;
    int pos=0 , contV=0, poss=0;
    while(veh.leerDiscoVehiculo(pos++)){
        poss=0;
        contV=0;
        while(ven.leerDiscoVenta(poss++)){
            if(veh.getID() == ven.getVehiculo()  )contV++;
        }
        if(contV >0){
        obj.CargarVe(veh,contV);
        obj.grabarDisco();
        }
    }
    pos=0;

    rlutil::locate(0,1);cout<<"Nombre";
    rlutil::locate(10,1);cout<<"Marca";
    rlutil::locate(20,1);cout<<"Modelo";
    rlutil::locate(30,1);cout<<"cantidad";


    while(obj.leerDisco(pos++)){
        obj.mostrar(pos+1);
        cout<<endl;
    }
    system("pause");
}

#endif // REPORTE_TOMI_H_INCLUDED
