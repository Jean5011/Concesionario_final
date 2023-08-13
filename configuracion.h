#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
///******************************************************************************************************
/***COPIA DE SEGURIDAD DEL ARCHIVO***/
void Copia_segurida_vehiculo();
void Copia_segurida_vendedor();
void Copia_segurida_cliente();
void Copia_segurida_venta();
void Copia_segurida_cuota();
/***_bkp***/
void vehiculo_bkp();
void vendedor_bkp();
void cliente_bkp();
void venta_bkp();
void cuota_bkp();
/***Datos inicio**/
void Datos_inicio();
///******************************************************************************************************
///vehiculo.dat///
///vendedor.dat///
///cliente.dat///
///venta.dat///
///cuota.dat///
/***COPIA DE SEGURIDAD DEL ARCHIVO***/
void Copia_segurida_vehiculo(){
FILE *p;
p=fopen("vehiculo.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return;}
system("copy vehiculo.dat vehiculo.bkp");
fclose(p);
system("pause");
}

void Copia_segurida_vendedor(){
FILE *p;
p=fopen("vendedor.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return;}
system("copy vendedor.dat vendedor.bkp");
fclose(p);
system("pause");
}

void Copia_segurida_cliente(){
FILE *p;
p=fopen("cliente.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return;}
system("copy cliente.dat cliente.bkp");
fclose(p);
system("pause");
}

void Copia_segurida_venta(){
FILE *p;
p=fopen("venta.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return;}
system("copy venta.dat venta.bkp");
fclose(p);
system("pause");
}

void Copia_segurida_cuota(){
FILE *p;
p=fopen("cuota.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return;}
system("copy cuota.dat cuota.bkp");
fclose(p);
system("pause");
}


/***_bkp***/
void vehiculo_bkp(){
system("copy vehiculo.bkp vehiculo.dat");
system("pause");
}

void vendedor_bkp(){
system("copy vendedor.bkp vendedor.dat");
system("pause");
}

void cliente_bkp(){
system("copy cliente.bkp cliente.dat");
system("pause");
}

void venta_bkp(){
system("copy venta.bkp venta.dat");
system("pause");
}

void cuota_bkp(){
system("copy cuota.bkp cuota.dat");
system("pause");
}

/***Datos inicio**/
void Datos_inicio(){
system("copy Iniciovehiculo.dat vehiculo.dat");
system("copy Iniciovendedor.dat vendedor.dat ");
///system("copy vendedor.dat Iniciovendedor.dat ");
system("copy Iniciocliente.dat  cliente.dat");
system("copy Inicioventa.dat    venta.dat");
system("copy Iniciocuota.dat    cuota.dat");
system("pause");
}
#endif // CONFIGURACION_H_INCLUDED
