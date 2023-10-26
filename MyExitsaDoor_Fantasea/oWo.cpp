#include<iostream>//input/output stream=corriente continua
#include<string>//url ,scripts, otros programas , paginas, un servidor, ip :para poder escribit algo mas largo que un caracter 0 
#include<vector>//contenedor = vector tiene un tamaño indefindo

#include<chrono>//TIEMPO  //SAMPLE RATE == ffps
#include<thread> //PARALELISMO Y CONCURRENCIA == DISTRIBUIR LAS TAREAS A DISTINTAS PARTES DE TU COMPU


#include<random>//numeros aleatorios

std::vector<int> hola {1,2,3};
using namespace std::chrono_literals;
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


void cada3()
{
    float hol = 9.999f;
    static_cast<int>(hol);
    std::mt19937_64 rana(static_cast<unsigned long>(std::time(nullptr)));
    std::uniform_int_distribution<int>r(1,10);
    int he = r(rana);
   while(true) 
   {

    DI("ya pasaron 3 segundos...",he);
    std::this_thread::sleep_for(3s);
   }
 
}




//MAIN thread
int main()
{
 /*std::vector<int>han{2,3,55,6};
for(auto la : han){
    DI(la);

}
    for(auto jeje = han.begin(); jeje != han.end();){
        jeje = han.erase(jeje);
    }
    for(auto ahora : han){

    DI(ahora);
    DI("nop");
    }
    DI("nop");


    for(;;){

    }*/   
    
    std::thread que(cada3);

    que.join();
    return 0;
}
