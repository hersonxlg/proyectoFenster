#include "fenster.h"

// 1. Usamos #define para crear constantes reales en C
#define W 320
#define H 240

int main() {
    // 2. Ahora el compilador sabe exactamente que esto es buf[76800]
    uint32_t buf[W * H];
    
    struct fenster f = { 
        .title = "Mi primer Fenster con XMake", 
        .width = W, 
        .height = H, 
        .buf = buf 
    };
    
    fenster_open(&f);
    
    uint32_t color = 0x000000;
    
    while (fenster_loop(&f) == 0) {
        for (int i = 0; i < W * H; i++) {
            buf[i] = color;
        }
        
        color += 0x000005;
        fenster_sleep(16);
    }
    
    fenster_close(&f);
    return 0;
}
