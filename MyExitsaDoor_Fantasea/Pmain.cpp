#ifndef UNICODE
#define UNICODE
#endif
#include<Windows.h>
#include"windowsx.h"
#include<gdiplus.h>
#include"C:\\Users\\sicar\\3D Objects\\FIEEELD\\SERIOUS MODE 2023\\PUCKETTE\\casa\\libz\\FreeImage\\include\\FreeImage.h"
//#include"Functrollia"
#include<algorithm>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<tuple>
#include<array>
#include<random>
#include<chrono>
#include<ctime>
#include<thread>
#include<memory>


//GLOBALES
HWND g;
BOOL siguelEnlaThread=true;
   
HINSTANCE hIna;
HWND hwnd;
//std::vector<HWND>ventanass;
constexpr int MAX_WINDOWS = 300;
HWND Binbows[MAX_WINDOWS];
// Declare cenX and cenY as global variables
int cenX[MAX_WINDOWS];
int cenY[MAX_WINDOWS];
int numWindows = 0;
HBITMAP g_hBitmap = nullptr;
//tamaño de VENTANA
int ventanaWidth = 300;
int ventanaHigh = 300;
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


class Ventanador
{
    public:
    WNDCLASSW ventaClass;
    
    Ventanador(){}

    HWND creaVentana
        (HINSTANCE hIns,WNDPROC Waction,
        LPCWSTR name_Class,LPCWSTR name_Ventana,
        int alto, int ancho,int xpos, int ypos)
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

class MsgCreator
{
    public:
    MsgCreator(){}

int mensajelala(){
        int mensajEx=MessageBoxW(
    nullptr,
    L"that is life.",
    L"xD",
    MB_YESNOCANCEL);

return mensajEx;
}


};

void MessagThrd()
{
    MsgCreator fff;
 

        int result = fff.mensajelala();
        // Do something with the result if needed
        // ...
    
}


void MENSA_G()
{
    
   /* std::vector<int>trollmes;
    MsgCreator fff;
    int msgContados=0;
    int mostrados=0;

    while(true){
      int reso=fff.mensajelala(); // mostrados=fff.mensajelala();
    for(int tt=0;tt<100;++tt){ trollmes.push_back(reso);}
   */
  
  std::vector<std::thread> messageThreads;
//crea el numero de mensajes que quieras crear
//buen lugar para poesia generativa
  
    for (int i = 0; i < 50; ++i)   {
        messageThreads.emplace_back(MessagThrd);
        std::this_thread::sleep_for(15s); // Sleep for some time between message box creations
    }

    for (auto& thread : messageThreads)
    {
        thread.join(); // Wait for all threads to finish
    }
  // std::this_thread::sleep_for(3s); 
    
   
}
//IMAGEN BUROCRACIA
bool CheckFilePermission
    (const wchar_t* filePath) 
    {
    DWORD fileAttributes = GetFileAttributes(filePath);
    if (fileAttributes == INVALID_FILE_ATTRIBUTES) {
        // Failed to get file attributes, handle the error
        DWORD errorCode = GetLastError();
        DI("Error getting file attributes. Error code: " + std::to_string(errorCode));
        return false;
    }

    // Check if the file is read-only
    if (fileAttributes & FILE_ATTRIBUTE_READONLY) {
        DI("ARCHIVO DE LECTURA SOLAMENTa.");
        return false;
    }

    // Check if the file is a directory
    if (fileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        DI("NO ES ARCHIVO ES DIRECTORIO.");
        return false;
    }

    // File has read permissions
    return true;
}
//IMAGEN LOADER PARA WINAPI BITMAPS; OCUPALO SI TE SIRVE
void CARGA_IMAGEN() 
{
    const wchar_t* FOTO = L"c:\\Users\\sicar\\3D Objects\\FIEEELD\\SERIOUS MODE 2023\\PUCKETTE\\casa\\cato.bmp"; 
    DI("Obteniendo...");
    if(!CheckFilePermission(FOTO))
    {
         
    return;
        return;
    }
    g_hBitmap = (HBITMAP)LoadImage(NULL,FOTO,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
     if (g_hBitmap == NULL) {
        DWORD errorCode = GetLastError();
        DI("fallo la carga de imagen xc. Error code: " + std::to_string(errorCode));
    } 
}

//numero aleatoreo RANDOM RANGE =  RANDGE
int RANDGE
    (int minn, int maxx,int distancia)
{
    static std::mt19937_64 sujetoo(static_cast<unsigned int>(std::time(nullptr)));//randomGenerador
    std::uniform_int_distribution<int> scalo(minn, maxx);//limita lo random
    static  int oldrand = scalo(sujetoo); // primer random
    static int permutaDist=distancia;//distancia entre numeros aleatorios
    int randyio;

    do
    {
        randyio = scalo(sujetoo);
    } while (std::abs(randyio - oldrand) < permutaDist); // 

    oldrand = randyio;
    return randyio;
}

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
    (HWND hwnd, int &posX, int &posY, int rangotango, int cenX, int cenY, int raddi)
{
    static int daa;
    static int oldva = 0;
    //RANDOM PATH
    daa = RANDGE(0, rangotango, 180);
    //creamos un punto para que se posicione sobre un rectangulo
    POINT poscursed;
    GetCursorPos(&poscursed);
    ScreenToClient(hwnd, &poscursed);

    RECT ventaRect;
    GetClientRect(hwnd, &ventaRect);
    int ah, viejoo;
    if (PtInRect(&ventaRect, poscursed))
    {
       // DI("M.use XoX!");

        // Calculate a new position for the window along the circle
        float angg = atan2(poscursed.y - cenY, poscursed.x - cenX);
        posX = cenX + raddi * cos(angg);
        posY = cenY + raddi * sin(angg);
       
    }
     cenX = daa;
        cenY = daa;
}


//THREAD MOVIMIENTO VENTANA
void threa_MUEVELA
    (int velocida)
{


    // Initialize the values of cenX and cenY for each window
    for (int winPop = 0; winPop < numWindows; winPop++)
    {
        cenX[winPop] = RANDGE(0,490,100);
        cenY[winPop] = RANDGE(0,400,133);
    }
    int raddi=10;
    float angg= 0.00f;
    while(siguelEnlaThread)
    {
        static int diri = 1; 
        static int Wsizee=250;
        static int TheWayYouMove=0;//SETS THE PATTERNS  
        int winX,winY,conttt=0;
        RECT venCon; 
   
   
   switch(TheWayYouMove){
     
    case 0:
    for(int winPop=0;winPop < numWindows;++winPop)
        {
            GetWindowRect(Binbows[winPop],&venCon);
         //circle stuff
            int xD = venCon.left;
            int yD = venCon.top;
            int Weed= venCon.right - venCon.left;
            int Highh= venCon.bottom - venCon.top;
       
            HMONITOR hmoni=MonitorFromWindow(Binbows[winPop],MONITOR_DEFAULTTONEAREST);
            MONITORINFO miMona={ sizeof(miMona)};
            GetMonitorInfo(hmoni,&miMona);
            
        if(yD <= 0 || (yD + Highh)>= miMona.rcMonitor.bottom)
        {
            diri *= -1;
        }
                
        //MOUSE INTERACCION
        CURSORON_SCREEN(Binbows[winPop],xD,1080);
        CURSORON_SCREEN(Binbows[winPop],yD,400);
        MoveWindow(Binbows[winPop],xD  ,yD + diri,Wsizee,Weed,false);
   
        //InvalidateRect(Binbows[winPop],NULL,true);              
   
        }
        break;
        case 1://MUEVELO EN CIRCULOS
         /*for (int winPop = 0; winPop < numWindows; winPop++)
        {
            GetWindowRect(Binbows[winPop], &venCon);

            // Use the values of cenX and cenY for the current window
            int xD = cenX[winPop] + raddi * cos(angg);
            int yD = cenY[winPop] + raddi * sin(angg);

            // Declare new variables for the x and y coordinates of the window
            int winX = venCon.left;
            int winY = venCon.top;

            // Pass in winX and winY as arguments to CURSORON_SCREEN
            CURSORON_SCREEN(Binbows[winPop], winX, winY, 1050, cenX[winPop], cenY[winPop], raddi);

            int newX = 0.9 * xD + 0.1 * winX;
            int newY = 0.7 * yD + 0.3 * winY;
            cenX[winPop] = winX;
            cenY[winPop] = winY;
            MoveWindow(Binbows[winPop], newX, newY, ventanaWidth, ventanaHigh, false);
         
        }*/
     // Move windows in circles
        break;

   }
    
     std::this_thread::sleep_for(std::chrono::microseconds(velocida));
}
}


//DIBUJA LA IMAGEN GDI PLUS
void DIBUJA
    (HDC hhddcc,int escoge, int veW,int veH){
     using namespace std::chrono_literals;
    Gdiplus::Graphics gf(hhddcc);
   /**
    * Gdiplus::Pen pen(Gdiplus::Color(255,255,0,0));
    Gdiplus::SolidBrush brr(Gdiplus::Color(255,0,255,0));
    gf.DrawLine(&pen,0,0,500,500);
    gf.FillEllipse(&brr,400,200,100,100);
  //Gdiplus::Bitmap bmmm(L"ola.png");
  //Gdiplus::Bitmap bitimaf(L"cato.bmp");
  */

    std::array<std::unique_ptr<Gdiplus::Bitmap>,3> gatoAnimation;
    gatoAnimation[0]=std::make_unique<Gdiplus::Bitmap>(L"ola.png");
    gatoAnimation[1]=std::make_unique<Gdiplus::Bitmap>(L"cato.bmp");
    gatoAnimation[2]=std::make_unique<Gdiplus::Bitmap>(L"bla.png");

    //sacar dimensiones
    int imagenAncho=gatoAnimation[escoge]->GetWidth();
    int imagenAlto=gatoAnimation[escoge]->GetHeight();
    //calcular la imagen en la ventana, escalamiento
    float wX=static_cast<float>(veW) / imagenAncho + 0.12f;
    float wY=static_cast<float>(veH) / imagenAlto + 0.05f;
    float scala=std::max(wX,wY);

     // Calculate the new image dimensions after scaling
    int newAncho = static_cast<int>(imagenAncho * scala);
    int newAlto = static_cast<int>(imagenAlto * scala);

    gf.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
    gf.SetPixelOffsetMode(Gdiplus::PixelOffsetModeHighQuality);
    gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
    Gdiplus::Matrix matrix(scala, 0.0f, 0.0f, scala, 0.0f, 0.0f); 
    gf.SetTransform(&matrix);
    // Calculate the position to center the image within the window
    int x = (veW- newAncho) / 2;
    int y = (veH - newAlto) / 2;

       
    gf.DrawImage(gatoAnimation[escoge].get(),x,y,newAncho,newAlto);
             
}
//MESSEGES PARA LAS VENTANAS PAPS
LRESULT CALLBACK VENTANEANDO
    (HWND hwnd,UINT uMsg, WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK vent
    (HWND hwnd,UINT uMsg, WPARAM wParam,LPARAM lParam);

int main(){
    //BOILERPLATE DIRIAN
    HINSTANCE hInsta;
    int nCmdShow=1;
    DI("xD");
    //GDIplus permite poner imagenes , boilerplate de inicializacion 
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR  gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken,&gdiplusStartupInput,nullptr);
    /*//cargado de imagen para winapi(Use si funciona)
    //HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, L".\\cato.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    //if (hBitmap == NULL)
   // {
    // Failed to load bitmap
        //DWORD errorCode = GetLastError();
       // DI("</3 Imagen no pudo ser cargada xc </3");
    //}else{DI(">:))");}*/
    /*//forma vieja de declaracion de ventana
    registrar la clase de la window
    const wchar_t VENTANA[] = L"ahora";
    WNDCLASS ve = { };
    ve.lpfnWndProc = VENTANEANDO;
    ve.hInstance= hInsta;
    ve.lpszClassName=VENTANA;
    RegisterClass(&ve);
    
    //crear ventana 
    //CARGA_IMAGEN(); carga de imagen pero no sirve aqui

     hwnd = CreateWindowEx(
        0,
        VENTANA,
        L"uWu",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,CW_USEDEFAULT,
        ventanaWidth,ventanaHigh,
        NULL,NULL,hInsta,NULL
    );

    if (hwnd == NULL)
    {
        return 0;
    }
 
    
    DI("c: toBien c:");//produ de ventana exitoso
  
    //ventanass.push_back(hwnd);
    ShowWindow(hwnd,nCmdShow);*/

     // cREAR VWNTANA PRINCIPAL
     Ventanador maino = { };
     hwnd=maino.creaVentana(hInsta,VENTANEANDO,L"Y",L"principalia",ventanaHigh,ventanaWidth,10,10);
     
     ShowWindow(hwnd,nCmdShow);
     Binbows[numWindows++]=hwnd;
    //ajustar velocidad de movimiento de ventana, esta en microsegundos
    
    constexpr int moodVelo[3]={2995,700,3000};
    int pickVelo=0;
    siguelEnlaThread=true;
    std::thread muevelatret(threa_MUEVELA,moodVelo[pickVelo]);
    std::thread mensajeee(MENSA_G);
    //std::thread muevelo(threa_MUEVELA,g,1000);
    //TEXTEALE
    MSG msg ={};
    while(GetMessage(&msg,NULL,0,0)>0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //activar thread
   
    siguelEnlaThread=false;
    muevelatret.join();
    mensajeee.join();
    Gdiplus::GdiplusShutdown(gdiplusToken);
    return 0;
}

Ventanador ventanas={ };
//actiones y monitoreos de la ventana misma
LRESULT CALLBACK vent
    (HWND g,UINT uMsg, WPARAM wParam,LPARAM lParam)
{
    Ventanador ventanass;
    HINSTANCE hInass;
    int raanYy=RANDGE(0,380,60);
    switch(uMsg)
    {
        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(g,&ps);
                //LA ZONA
                //FillRect(hdc,&ps.rcPaint,(HBRUSH)(COLOR_WINDOW+3));
                DIBUJA(hdc,1,ventanaHigh,ventanaWidth);
                EndPaint(g,&ps);
            }
        return 0;

        case WM_CLOSE:
         //DestroyWindow(g);
            g=ventanass.creaVentana(hInass, vent,L"heee",L"XDD", ventanaHigh, ventanaWidth,RANDGE(0,1090,60),raanYy);
            ShowWindow(g,1);
            //ventanass.push_back(g);
            Binbows[numWindows++]=g;
  
            DI(numWindows, "<-- from the other side c: ");
       
          return 0;
        break;

        case WM_DESTROY:
           // PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(g,uMsg,wParam,lParam);
}

LRESULT CALLBACK VENTANEANDO
    (HWND hwnd,UINT uMsg, WPARAM wParam,LPARAM lParam)
{
    

    PAINTSTRUCT pss;
    HDC hdco;
    int raanX=RANDGE(0,1090,60);
    int raanY=RANDGE(0,380,60);
    switch(uMsg)
    {
        case WM_PAINT:
                hdco = BeginPaint(hwnd,&pss);
                DIBUJA(hdco,2,ventanaHigh,ventanaWidth);
               /*
                //PAINTSTRUCT ps;
                //HDC hdc = BeginPaint(hwnd,&ps);
                //LA ZONA(solo pone la pantalla negra)
                //FillRect(hdc,&ps.rcPaint,(HBRUSH)(COLOR_WINDOW+3));
                /////////
                //apartar memoria pa la imagen
                //EndPaint(hwnd,&ps);*/
            
        break;

        case WM_CLOSE:
            g = ventanas.creaVentana(hIna, vent, L"he", L"XD", ventanaHigh, ventanaWidth, raanX, raanY);
          
            ShowWindow(g, 1);
            Binbows[numWindows] = g;

    // Set the initial values of cenX and cenY for the new window
            cenX[numWindows] = RANDGE(0, 1090, 40);
            cenY[numWindows] = RANDGE(0, 400, 40);

            numWindows++;
            DI("window number= ",numWindows);
            UpdateWindow(g);
           /*g=ventanas.creaVentana(hIna, vent,L"he",L"XD", ventanaHigh, ventanaWidth,raanX,raanY);
            ShowWindow(g,1);
            //ventanass.push_back(g);
            Binbows[numWindows++]=g;*/
            return 0;

        break;

        case WM_DESTROY:
        //PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}