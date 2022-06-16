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

    
    VGA::四角書く(
        VGA_LIGHT_RED, VGA_BLACK,
        20, 7, 15, 15
    );
    VGA::四角書く(
        VGA_LIGHT_RED, VGA_BLACK,
        40, 7, 15, 15
    );

    char ch = 0;
    do {

        ch = KBOARD_DRIVER::get_input_keycode();
        VGA::ピクセル書く(ch, VGA_LIGHT_RED, VGA_BLACK);

        uint32_t time = 0x02FFFFFF;
        while (1)
        {
            asm volatile("nop");
            time--;
            
            if (time <= 0)
            {
                break;
            }
        }
    } while (ch > 0);




    return 0;
}


