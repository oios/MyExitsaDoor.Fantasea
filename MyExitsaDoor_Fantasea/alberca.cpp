
#include<iostream>  
#include<string>   
#include<locale.h>
#include<vector>
//Modulo - ENCAPSULADO
/*
ENCAPSULAMOS PARA PODER COMPRENDER EL FENOMENO (al programa/el problema)POR PARTES

*PARA NO REPETIRSE 
*NOMBRE SIGNIFICANTE
*PARA REUSO!(lo mismo que el punto 1)
*PARA TENER !!!COSAS!!! SIMILARES EN UN MISMO LUGAR = 
|||||||||||||||||||||||||FAMILIA||||||||||||||||||||||||||||||||||||||||||||
TIPOS
     = INT,STRING , CHAR, DOUBLE, FLOAT,BOOL ,unsigned int , signed int

                           /\
                           |
                           |
                          \/

||||||||||||||||||||||||||FAMILIA|||||||||||||||||||||||||||||||||||||||||||
CONTENEDORES

    ARRASYS MATRICES, VECTOR , TUPLAS,LISTAS, SETS,MAPAS , DICTIONARIOS


||||||||||||||||||||||||||||||||||||||||||||||||||||

g++ alberca.cpp -o gold

*/

//imprimir
void DI()
{
    std::cout<<'\n';
}

template<typename sayit,typename... say>
void DI(sayit dije,say... algo)
{
    std::cout<<dije;
    DI(algo...);
}
using namespace std;
namespace HAWAII
{
void CASA(int VISITA )//input = lo desconocido o lo que cambia constantemente
{

    if(VISITA > 1 && VISITA <= 4){
        std::cout<<"he";
    }
    if(VISITA > 4 && VISITA <= 6){
            std::cout<<"tomate";
    }

}
}
const int tamañomatriz=10;
string no[tamañomatriz]={"¿Estás seguro de tu respuesta?",
             "¿Te arrepientes de algo?", 
             "¿Te gustaría hablar con alguien al respecto?",
              "¿Te sientes cómodo con tu decisión?",
               "¿Crees que podrías haber hecho algo diferente?",
                "¿Estás dispuesto a escuchar otras opiniones?", 
                "¿Te preocupa lo que piensen los demás?",
                 "¿Esperas que cambie algo en el futuro?", 
                 "¿Tienes algún plan alternativo?", 
                 "¿Quieres que te ayude con algo más?"};

string si[tamañomatriz]={"¿Estás feliz con tu respuesta? s/n", 
"¿Te costó mucho trabajo llegar a ella? s/n",
 "¿Qué te motivó a hacerlo? s/n",
  "¿Qué beneficios tiene tu decisión? s/n", 
  "¿Has compartido tu respuesta con alguien más? s/n",
   "¿Crees que tu respuesta es la mejor opción? s/n",
    "¿Te gustaría saber más sobre el tema? s/n",
     "¿Qué te gustaría hacer ahora? s/n",
      "¿Tienes algún consejo para otras personas que enfrentan la misma situación? s/n",
       "¿Quieres que te felicite por tu respuesta? s/n"};

/*CONTENEDORES*/
int a = 0; //variable
int aa(int a){return a;};//FUNCION
int aaa[2][100]={}; //array
/**/
vector<int>usuariosdeFACEBOOK={1,2,3,4,5,6};

void SipoNop(char &respuesta,int &con)
{
    if(respuesta == 'n'){
        DI(no[con]);
    }
    if(respuesta == 's'){
        DI(si[con]);
    }else if(respuesta != 'n' && respuesta != 's'){
        DI("NO TE ENTIENDO!");
    }

}
int main()
{
    int cont=0;//principio de la programacion de maquinas de estado finito
    char tu;
    setlocale(LC_CTYPE,"Spanish");
    DI("quiéres un helado?... s/n");

  

    while(std::cin>>tu){//GAME LOOP  //VOID LOOP
      
        cont++;//CONTADOR GRAN PRINCIPIO EN LA PROGRAMACION
        if(cont >= tamañomatriz){cont = 0;}//LIMITADOR
    
        SipoNop(tu,cont);
        // DI(cont);

    }

    
  

    return 0;
}