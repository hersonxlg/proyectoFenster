target("JuegoFenster")
    set_kind("binary")
    
    -- Le decimos dónde está nuestro fenster.h
    add_includedirs("include")
    
    -- Le decimos dónde está nuestro código
    add_files("src/*.c")
    
    set_languages("c11")

    -- MÁGICO: Si estamos en Windows, conectamos las librerías nativas del sistema
    if is_plat("windows", "mingw") then
        add_syslinks("user32", "gdi32")
    
    -- (Opcional) Por si algún día lo pasas a Linux o Mac
    elseif is_plat("linux") then
        add_syslinks("X11", "asound")
    elseif is_plat("macosx") then
        add_frameworks("Cocoa", "AudioToolbox")
    end
