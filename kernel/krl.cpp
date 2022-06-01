#include "vga_driver.h"
#include "keyboard_driver.h"

/*
    TODO: 
        vga driver (vga_engine.h) (3D)
        keyboard driver - clickables
        audio driver
*/

extern "C" int main()
{
    VGA::init_vga();

    
    VGA::几帳書く("sak ale dobre", VGA_LIGHT_RED, VGA_BLACK);
    VGA::新しい_ライン();
    VGA::几帳書く("ced hej", VGA_LIGHT_RED, VGA_BLACK);

	

    return 0;
}


