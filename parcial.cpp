#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<windows.h>
using namespace std;

int menu(){
int x;
   	system("cls");

			 cout<<"Bienvenido"<<endl;
			 cout<<" 1. Ingresar nombre : "<<endl;
			cout<<" 2. Verificar Empleados : "<<endl;
			cout<<" 3. Buscar Empleados : "<<endl;	
				cout<<" 4.Modificar Datos : "<<endl;
				cout<<" 5. Eliminar Registro : "<<endl;
				cout<<" 6. Salir"<<endl;
				cout<<"opcion "<<endl;
			   cin>>x;
		
	
	return x;
}
bool verifica(string cod){
	ifstream leer ("persona.txt",  ios::in);
	string Nom;
   	string Ape;
   	string Cod;
   	string Pues;
   	string Suel;
   	string Bon;
   	leer>>Nom;
   	while(!leer.eof()){
   		leer>>Ape;
   		leer>>Cod;
   		leer>>Pues;
   		leer>>Suel;
   		leer>>Bon;
   		if(Cod == cod){
   			leer.close();
   			return false;
   			
   			
		   }
   		leer>>Nom;
	   }
	   leer.close();
	   return true;
}

void agregar (ofstream &es){
   	system("cls");
   	string Nom;
   	string Ape;
   	string Cod;
   	string Pues;
   	string Suel;
   	string Bon;
   	string sueltotal;
   	es.open("Persona.txt", ios::out | ios::app);
   	if(verifica(Cod))
   	
   	if(es.fail()){
   		cout<<"No se pudo abrir";
   		exit(1);
	   }
   	cout<<"Nombre "<<endl;
   cin>>Nom;
	cout<<"Apellido "<<endl;;
   cin>> Ape;
   cout<<"Codigo "<<endl;
   cin>>Cod;
   cout<<"Puesto "<<endl;
   cin>>Pues;
   cout<<"Sueldo "<<endl;
   cin>>Suel;
   cout<<"Bonificacion "<<endl;
   cin>>Bon;
      cout<<"sueldo total"<<endl;

   sueltotal = Suel + Bon;
   es<<Nom<<" "<<Ape<<"   "<<Cod<<"   "<<Pues<<"     "<<Suel<<"  "<<Bon<<"  "<<sueltotal <<endl;
   es.close();
}
void VerRegistro(ifstream &lec){
	system("cls");
	string nom;
	string ape;
	string cod;
	string pues;
	string suel;
	string bon;
	lec.open("persona.txt",ios :: in); 
	if(lec.is_open()){
	
	cout<<"------Empleados Registrados----- "<<endl;
	lec>>nom;
	while(!lec.eof()){
		lec>>ape;
		lec>>cod;
		lec>>pues;
		lec>>suel;
		lec>>bon;
		cout<<"Nombre ----------: "<<nom<<endl;
		cout<<"Apellido ----------: "<<ape<<endl;
		cout<<"Codigo ----------: "<<cod<<endl;
		cout<<"Puesto ----------: "<<pues<<endl;
		cout<<"Sueldo ----------: "<<suel<<endl; 
		cout<<"Bonificacion ----------: "<<bon<<endl;
		cout<<"-------------------------: "<<endl;
		cout<<"Empleados registrados------------------------- "<<endl<<endl;

		lec>>nom;
		}
	lec.close();
	}else 
	cout<<"Error";
	system("pause");
	
}

   		void  buscarpersona(ifstream &lec){
   			system ("pause");
   			lec.open("persona.txt", ios :: in);
   			string nom,ape,cod,pues,suel,bon,codaux;
   			bool encontrado = false;
   			
   			
   			cout<<"Ingresar el codigo : ";
   			cin>>codaux;
   			lec>>nom;
   			while(!lec.eof() && ! encontrado){
   				   			lec>>ape;
   				   			lec>>cod;
   				   			lec>>pues;
   				   			lec>>suel;
   				   			lec>>bon;
   				   			if(cod==codaux){
		   	cout<<"Nombre ----------: "<<nom<<endl;
			cout<<"Apellido ----------: "<<ape<<endl;
			cout<<"Codigo ----------: "<<cod<<endl;
			cout<<"Puesto ----------: "<<pues<<endl;
			cout<<"Sueldo ----------: "<<suel<<endl;
			cout<<"Bonificacion ----------: "<<bon<<endl;
			cout<<"-------------------------: "<<endl;
			cout<<"Emleados registrados------------------------- "<<endl<<endl;
   			encontrado == true;
								  }
   				   			lec>>nom;
			   }
			       lec.close();
			        if(!encontrado)
    cout<<"Datos no encontrados"<<endl;
    system("pause");
	}
	
	   	void	modificar(ifstream &lec){
	   			system("cls");
	string nom;
	string ape;
	string cod;
	string pues;
	string suel;
	string bon;
	string codaux;
	string nomaux;
	lec.open("persona.txt", ios :: in);
	ofstream aux ("auxiliar.txt", ios :: out );
	if(lec.is_open()){
		cout<<"codigo ";
		cin>>codaux;
		lec>>nom;
		while(!lec.eof()){
			lec>>ape;
			lec>>cod;
			lec>>pues;
			lec>>suel;
			lec>>bon;
			if(cod == codaux){
				cout<<"Digite la actualizacion : ";
				cin>>nomaux;
				aux<<nomaux<<""<<ape<<""<<cod<<""<<pues<<""<<suel<<""<<bon<<endl;
			}else{
			aux<<nom<<""<<ape<<""<<cod<<""<<pues<<""<<suel<<""<<bon<<endl;
			}
					lec>>nom;
		}
		lec.close();
		aux.close();
	}else 
	cout<<"Error"<<endl;
	remove("persona.txt");
	rename("auxiliar.txt", "persona.txt");
	   		
	   		
		   }

   void eliminar(ifstream &lec){
   			system("cls");
	string nom;
	string ape;
	string cod;
	string pues;
	string suel;
	string bon;
	string codaux;
	string nomaux;
	lec.open("persona.txt", ios :: in);
	ofstream aux ("auxiliar.txt", ios :: out );
	if(lec.is_open()){
		cout<<"codigo ";
		cin>>codaux;
		lec>>nom;
		while(!lec.eof()){
			lec>>ape;
			lec>>cod;
			lec>>pues;
			lec>>suel;
			lec>>bon;
			if(cod == codaux){
				cout<<"Eliminado ok ** : ";
				Sleep(1500);
				
			}else{
			aux<<nom<<""<<ape<<""<<cod<<""<<pues<<""<<suel<<""<<bon<<endl;
			}
					lec>>nom;
		}
		lec.close();
		aux.close();
	}else 
	cout<<"Error"<<endl;
	remove("persona.txt");
	rename("auxiliar.txt", "persona.txt");
   }

    

  int main(){
	ofstream Esc;
	int op;
	ifstream lec;
   do{
   	system("cls");
   	
   	op = menu (); 
   	switch(op){
   		case  1:
   			agregar (Esc);
   			
   			break;
   			case 2: 
   			VerRegistro(lec);
   			break;
   			case 3: 
   			buscarpersona(lec);	
   		break;
   		case 4: 
   		modificar(lec);
   		break;
   		case 5: 
   		eliminar(lec);
   		break;
	   }
   	
   }while( op != 9);
	
	 
	return 0;
}
