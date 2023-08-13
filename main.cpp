#include <iostream>
#include<ctime>

using namespace std;

#include "rlutil.h"
#include "fecha.h"
#include "persona.h"
#include "menus.h"
#include "vehiculo.h"
#include "vendedor.h"
#include "cliente.h"
#include "venta.h"
#include "cuota.h"
#include "configuracion.h"
#include "reporte_Tomi.h"
#include "reporte_Ruben.h"
#include "reporte_Jean.h"

int main(){
    /*
setlocale(LC_ALL,"spanish"); ///ESTA COSA NO DEJA FUNCIONAR CORRECTAMENTE EL RLUTIL
*/

rlutil::setBackgroundColor(0);
rlutil::setColor(15);
bool n;

while(true){
    switch(menuPrincipal()){

        case 1:     ///VEHICULO
            n=true;
            while(n==true){

            switch(menuVehiculo()){
                case 1:     cargarVehiculo();       break;
                case 2:     mostrarVehiculos();     break;
                case 3:     mostrarVehiculo();      break;
                case 4:     eliminarVehiculo();     break;
                case 0:     n=false;                break;
                }}break;

        case 2:     ///VENDEDOR
            n=true;
            while(n==true){

            switch(menuVendedor()){
                case 1:     cargarVendedor();       break;
                case 2:     mostrarVendedor();      break;
                case 3:     mostrarXIDVendedor();   break;
                case 4:     cambiarEstadoVendedor();break;
                case 0:     n=false;                break;
                }}break;

        case 3:     ///CLIENTE
            n=true;
            while(n==true){

            switch(menuCliente()){
                case 1:     CargarCliente();        break;
                case 2:     MostrarCliente();       break;
                case 3:     MostrarXIDCliente();    break;
                case 4:     EliminarCliente();      break;
                case 0:     n=false;                break;
                }}break;

        case 4:     ///VENTA
            n=true;
            while(n==true){

            switch(menuVenta()){
                case 1:     cargarVenta();          break;
                case 2:     mostrarVenta();        break;
                case 3:     mostrarXIDVentas();         break;
                case 4:     eliminarVenta();        break;
                case 0:     n=false;                break;
                }}break;

        case 5:     ///CUOTA
            n=true;
            while(n==true){

            switch(menuCuota()){
                case 1:     cargarCuota();          break;
                case 2:     mostrarCuotas();        break;
                case 3:     MostarXId();            break;
                case 4:     MostrarXcuota();        break;
                case 0:     n=false;                break;
                }}break;

        case 6:     ///CONFIGURACION
            n=true;
            while(n==true){

            switch(menuConfiguracion()){
                case 1:      Copia_segurida_vehiculo();                break;
                case 2:      Copia_segurida_vendedor();                break;
                case 3:      Copia_segurida_cliente();                 break;
                case 4:      Copia_segurida_venta();                   break;
                case 5:      Copia_segurida_cuota();                   break;
                case 6:            vehiculo_bkp();                     break;
                case 7:            vendedor_bkp();                     break;
                case 8:             cliente_bkp();                     break;
                case 9:               venta_bkp();                     break;
                case 10:              cuota_bkp();                     break;
                case 11:              Datos_inicio();                  break;
                case 0:                    n=false;                    break;
                }}break;

        case 7:     ///REPORTES
            n=true;
            while(n==true){

            switch(menuReportes()){
                case 1:     TomiMostrarXPromedio();         break;
                case 2:     TomiVehiculosComprados();       break;
                case 3:     facturacion();                  break;
                case 4:     PagoTotal();                    break;
                case 5:     CompraCliente();                break;
                case 6:     listarVendedoresXAlfa();        break;
                case 0:     n=false;                        break;
                }}break;

        case 0:    return 0;   break;   }}}
