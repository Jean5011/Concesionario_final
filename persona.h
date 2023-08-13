#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

class Persona{
protected:
    char Nombre[40];        char Direccion[40];    int telefono;
    char Apellido[40];      char Localidad[40];    int Dni;
    Fecha F_nacimiento;

public:

    void setNombre      (const char *n)     {strcpy(Nombre,n);}
    void setApellido    (const char *n)     {strcpy(Apellido,n);}
    void setDireccion   (const char *n)     {strcpy(Direccion,n);}
    void setlocalidad   (const char *n)     {strcpy(Localidad,n);}
    void setTelefono    (int n)             {telefono=n;}
    void setDni         (int n)             {Dni=n;}
    void setFecha_nacimiento(Fecha n)       {F_nacimiento=n;}
    char *GetNombre             (){return Nombre;}
    const char *GetApellido     (){return Apellido;}
    const char *GetDireccion    (){return Direccion;}
    const char *GetLocalidad    (){return Localidad;}
    int getTelefono             (){return telefono;}
    int getDni                  (){return Dni;}
    Fecha getFecha_nacimiento   (){return F_nacimiento;}

    void CargarPersona();
    void MostrarPersona();      };

///********************************************************

void Persona::CargarPersona(){
    Fecha f;
    cout<<"Ingresar Nombre: ";      cin>>Nombre;
    cout<<"Ingresar Apellido: ";    cin>>Apellido;
    cout<<"Ingrese Dni: ";          cin>>Dni;
    cout<<"Ingrese fecha de nacimiento:\n";
    do{
    F_nacimiento.Cargar();
    }while( !ValidacionEdad(F_nacimiento) );
    cout<<"Ingresar Direccion: ";   cin>>Direccion;
    cout<<"Ingresar Localidad: ";   cin>>Localidad;
    cout<<"Ingresar Telefono: ";    cin>>telefono;
    }

void Persona::MostrarPersona(){
    cout<<"Nombre y Apellido: "<<Nombre<<" "<<Apellido<<endl;
    cout<<"Direccion: "<<Direccion<<endl;
    cout<<"Localidad: "<<Localidad<<endl;
    cout<<"Dni: "<<Dni<<endl;
    cout<<"Fecha de Nacimiento: ";
    F_nacimiento.Mostrar();
    cout<<"Telefono: "<<telefono<<endl;
    }

#endif // PERSONA_H_INCLUDED
