#include "fenster.h"

int main() {
    // Definimos el ancho y alto
    const int W = 800;
    const int H = 800;
    
    // Creamos un arreglo de píxeles (nuestro lienzo)
    uint32_t buf[W * H];

    
    // Inicializamos la estructura de Fenster
    struct fenster f = { 
        .title = "Mi primer Fenster con XMake", 
        .width = W, 
        .height = H, 
        .buf = buf 
    };
    
    fenster_open(&f);
    
    uint32_t color = 0x000000; // Empezamos en negro
    
    // Bucle principal: fenster_loop devuelve 0 mientras no cerremos la ventana
    while (fenster_loop(&f) == 0) {
        // Pintamos todos los píxeles del lienzo
        for (int i = 0; i < W * H; i++) {
            buf[i] = color;
        }
        
        color += 0x000005; // Aclaramos el color un poco en cada frame
        
        fenster_sleep(16); // Pausamos ~16ms para ir a 60 FPS
    }
    
    fenster_close(&f);
    return 0;
}
