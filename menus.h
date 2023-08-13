#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void barra(){
    rlutil::setColor(3); /* http://tapiov.net/rlutil/docs/HTML/files/docs/ColorCodes-txt.html#Color_Codes */
    for(int i=0;i<=35;i++){cout<<char(219);}
    rlutil::setColor(15);
}

int suma(int &y,int barra,int ir){
    rlutil::locate(39,7 + y);
    y=y+2;
    if( y==barra || y>ir) y=ir;
    return y;
}

int resta(int &y,int barra,int ir){
    rlutil::locate(39,7 + y);
    y=y-2;
    if( y==barra ) y=ir;
    if(y<0)y=0;
    return y;
}

void ajuste1(int &y){
    rlutil::setColor(10);
    rlutil::locate(40,7+y);}

void ajuste2(int &y){
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::locate(39,7 + y);
}

int returns(int cantOps,int y){
    system("cls");
    if( y==cantOps )return 0;
    return y=y/2+1;
}


int menuPrincipal(){
    int y=0;
    system("cls");

    while(true){
        rlutil::locate(40,3);   cout<<"MENU PRINCIPAL";
        rlutil::locate(30,5);   barra();
        rlutil::locate(40,7);   cout<<"1. Vehiculo";
        rlutil::locate(40,9);   cout<<"2. Vendedor";
        rlutil::locate(40,11);  cout<<"3. Cliente";
        rlutil::locate(40,13);  cout<<"4. Ventas";
        rlutil::locate(40,15);  cout<<"5. Cuota";
        rlutil::locate(40,17);  cout<<"6. Configuracion";
        rlutil::locate(40,19);  cout<<"7. Reportes";
        rlutil::locate(30,21);  barra();
        rlutil::locate(40,23);  cout<<"0. Salir";
        ajuste1(y);
        switch(y){
        case 0:     cout<<"1. Vehiculo";        break;
        case 2:     cout<<"2. Vendedor";        break;
        case 4:     cout<<"3. Cliente";         break;
        case 6:     cout<<"4. Ventas";          break;
        case 8:     cout<<"5. Cuota";           break;
        case 10:    cout<<"6. Configuracion";   break;
        case 12:    cout<<"7. Reportes";        break;
        case 16:    cout<<"0. Salir";           break;
        }
        ajuste2(y);
        switch(rlutil::getkey()){
        case 14:    resta(y,14,12);         break;
        case 15:    suma(y,14,16);          break;
        case 1:     return returns(16,y);   break;}}}

int menuVehiculo(){
    int y=0;
    system("cls");
    while(true){
        rlutil::locate(40,3);   cout<<"MENU VEHICULO";
        rlutil::locate(30,5);   barra();
        rlutil::locate(40,7);   cout<<"1. Cargar Vehiculo";
        rlutil::locate(40,9);   cout<<"2. Mostrar Vehiculos";
        rlutil::locate(40,11);  cout<<"3. Mostrar por ID";
        rlutil::locate(40,13);  cout<<"4. Eliminar Vehiculo";
        rlutil::locate(30,15);  barra();
        rlutil::locate(40,17);  cout<<"0. Salir del Menu";
        ajuste1(y);
        switch(y){
        case 0:     cout<<"1. Cargar Vehiculo";     break;
        case 2:     cout<<"2. Mostrar Vehiculos";   break;
        case 4:     cout<<"3. Mostrar por ID";      break;
        case 6:     cout<<"4. Eliminar Vehiculo";   break;
        case 10:    cout<<"0. Salir del Menu";      break;
        }
        ajuste2(y);
        switch(rlutil::getkey()){
        case 14:    resta(y,8,6);         break;
        case 15:    suma(y,8,10);          break;
        case 1:     return returns(10,y);   break;   }}}

int menuVendedor(){
    int y=0;
    system("cls");
    while(true){
        rlutil::locate(40,3);   cout<<"MENU VENDEDOR";
        rlutil::locate(30,5);   barra();
        rlutil::locate(40,7);   cout<<"1. Cargar Vendedor";
        rlutil::locate(40,9);   cout<<"2. Mostrar Vendedores";
        rlutil::locate(40,11);   cout<<"3. Mostrar por ID";
        rlutil::locate(40,13);   cout<<"4. Eliminar Vendedor ";
        rlutil::locate(30,15);   barra();
        rlutil::locate(40,17);   cout<<"0. Salir del Menu";
        ajuste1(y);
        switch(y){
        case 0:     cout<<"1. Cargar Vendedor";     break;
        case 2:     cout<<"2. Mostrar Vendedores";    break;
        case 4:     cout<<"3. Mostrar por ID";      break;
        case 6:     cout<<"4. Eliminar Vendedor";   break;
        case 10:    cout<<"0. Salir del Menu";      break;
        }
        ajuste2(y);
        switch(rlutil::getkey()){
        case 14:    resta(y,8,6);         break;
        case 15:    suma(y,8,10);          break;
        case 1:     return returns(10,y);   break;}}}

int menuCliente(){
    int y=0;
    system("cls");
    while(true){
        rlutil::locate(40,3);   cout<<"MENU CLIENTE";
        rlutil::locate(30,5);   barra();
        rlutil::locate(40,7);   cout<<"1. Cargar Cliente";
        rlutil::locate(40,9);   cout<<"2. Mostrar Clientes";
        rlutil::locate(40,11);  cout<<"3. Mostrar por ID";
        rlutil::locate(40,13);  cout<<"4. Eliminar Cliente";
        rlutil::locate(30,15);  barra();
        rlutil::locate(40,17);  cout<<"0. Salir del Menu";
        ajuste1(y);
        switch(y){
        case 0:     cout<<"1. Cargar Cliente";     break;
        case 2:     cout<<"2. Mostrar Clientes";    break;
        case 4:     cout<<"3. Mostrar por ID";      break;
        case 6:     cout<<"4. Eliminar Cliente";   break;
        case 10:    cout<<"0. Salir del Menu";      break;
        }
        ajuste2(y);
        switch(rlutil::getkey()){
        case 14:    resta(y,8,6);           break;
        case 15:    suma(y,8,10);           break;
        case 1:     return returns(10,y);   break;}}}

int menuVenta(){
    int y=0;
    system("cls");
    while(true){
        rlutil::locate(40,3);  cout<<"MENU VENTA";
        rlutil::locate(30,5);  barra();
        rlutil::locate(40,7);  cout<<"1. Cargar Venta";
        rlutil::locate(40,9);  cout<<"2. Mostrar Ventas";
        rlutil::locate(40,11);  cout<<"3. Mostrar por ID";
        rlutil::locate(40,13);  cout<<"4. Eliminar Venta";
        rlutil::locate(30,15);  barra();
        rlutil::locate(40,17);  cout<<"0. Salir del Menu";
        ajuste1(y);
        switch(y){
        case 0:     cout<<"1. Cargar Venta";    break;
        case 2:     cout<<"2. Mostrar Ventas";  break;
        case 4:     cout<<"3. Mostrar por ID";  break;
        case 6:     cout<<"4. Eliminar Venta";  break;
        case 10:    cout<<"0. Salir del Menu";  break;
        }
        ajuste2(y);
        switch(rlutil::getkey()){
        case 14:    resta(y,8,6);           break;
        case 15:    suma(y,8,10);           break;
        case 1:     return returns(10,y);   break;}
    }
}

int menuCuota(){
    int y=0;
    system("cls");
    while(true){
        rlutil::locate(40,3);    cout<<"MENU COUTA";
        rlutil::locate(30,5);    barra();
        rlutil::locate(40,7);    cout<<"1. Cargar Cuota";
        rlutil::locate(40,9);    cout<<"2. Mostrar todas las Cuotas";
        rlutil::locate(40,11);   cout<<"3. Mostrar por ID";
        rlutil::locate(40,13);   cout<<"4. Mostrar Cuotas ESPECIALES";
        rlutil::locate(30,15);   barra();
        rlutil::locate(40,17);   cout<<"0. Salir del Menu";
        ajuste1(y);
        switch(y){
        case 0:     cout<<"1. Cargar Cuota";             break;
        case 2:     cout<<"2. Mostrar todas las Cuotas";  break;
        case 4:     cout<<"3. Mostrar por ID";            break;
        case 6:     cout<<"4. Mostrar Cuotas ESPECIALES";  break;
        case 10:    cout<<"0. Salir del Menu";            break;
        }
        ajuste2(y);
        switch(rlutil::getkey()){
        case 14:    resta(y,8,6);           break;
        case 15:    suma(y,8,10);           break;
        case 1:     return returns(10,y);   break;}}}

int menuConfiguracion(){
    int y=0;
    system("cls");
    while(true){
    rlutil::locate(40,3);    cout<<"MENU CONFIGURACION";
    rlutil::locate(30,5);    barra();
    rlutil::locate(40,7);    cout<<"1. Copia Vehiculo";
    rlutil::locate(40,9);    cout<<"2. Copia Vendedor";
    rlutil::locate(40,11);    cout<<"3. Copia Cliente";
    rlutil::locate(40,13);    cout<<"4. Copia Venta";
    rlutil::locate(40,15);    cout<<"5. Copia Cuota";
    rlutil::locate(40,17);    cout<<"6. Restaurar Vehiculo";
    rlutil::locate(40,19);    cout<<"7. Restaurar Vendedor";
    rlutil::locate(40,21);    cout<<"8. Restaurar Cliente";
    rlutil::locate(40,23);    cout<<"9. Restaurar Venta";
    rlutil::locate(40,25);    cout<<"10. Restaurar Cuota";
    rlutil::locate(40,27);    cout<<"11. Establecer Datos De Inicio";
    rlutil::locate(30,29);    barra();
    rlutil::locate(40,31);    cout<<"0. Salir del Menu";

    ajuste1(y);
    switch(y){
    case 0: cout<<"1. Copia Vehiculo";              break;
    case 2: cout<<"2. Copia Vendedor";              break;
    case 4: cout<<"3. Copia Cliente";               break;
    case 6: cout<<"4. Copia Venta";                 break;
    case 8: cout<<"5. Copia Cuota";                 break;
    case 10: cout<<"6. Restaurar Vehiculo";         break;
    case 12: cout<<"7. Restaurar Vendedor";         break;
    case 14: cout<<"8. Restaurar Cliente";          break;
    case 16: cout<<"9. Restaurar Venta";            break;
    case 18: cout<<"10. Restaurar Cuota";           break;
    case 20: cout<<"11. Establecer Datos De Inicio";break;
    case 24: cout<<"0. Salir del Menu";             break;
    }
    ajuste2(y);
    switch(rlutil::getkey()){
        case 14:    resta(y,22,20);           break;
        case 15:    suma(y,22,24);           break;
        case 1:     return returns(24,y);   break;}}}

int menuReportes(){
    int y=0;
    system("cls");
    while(true){
        rlutil::locate(40,3);     cout<<"MENU REPORTES";
        rlutil::locate(30,5);     barra();
        rlutil::locate(40,7);     cout<<"1. Mostrar Vehiculos Ya Comprados";
        rlutil::locate(40,9);    cout<<"2. Mostrar Vehiculos con precio Menor al Promedio";
        rlutil::locate(40,11);    cout<<"3. Archivo de facturacion";
        rlutil::locate(40,13);    cout<<"4. Mostrar las ventas de tipo 0";
        rlutil::locate(40,15);    cout<<"5. mostrar clientes y la cantidad de compras";
        rlutil::locate(40,17);    cout<<"6. Muestra por orden alfavetico de apellido a los vendedores";
        rlutil::locate(30,19);    barra();
        rlutil::locate(40,21);    cout<<"0. Salir del Menu";

        ajuste1(y);
        switch(y){
        case 0:     cout<<"1. Mostrar Vehiculos Ya Comprados";                            break;
        case 2:     cout<<"2. Mostrar Vehiculos con precio Menor al Promedio";            break;
        case 4:     cout<<"3. Archivo de facturacion";                                    break;
        case 6:     cout<<"4. Mostrar las ventas de tipo 0";                              break;
        case 8:    cout<<"5. mostrar clientes y la cantidad de compras";                  break;
        case 10:    cout<<"6. Muestra por orden alfavetico de apellido a los vendedores"; break;
        case 14:    cout<<"0. Salir del Menu";                                            break;
        }
        ajuste2(y);
        switch(rlutil::getkey()){
        case 14:    resta(y,12,10);           break;
        case 15:    suma(y,12,14);           break;
        case 1:     return returns(14,y);   break;}}}


#endif // MENUS_H_INCLUDED
