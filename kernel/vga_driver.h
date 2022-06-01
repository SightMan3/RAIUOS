#pragma once

#include <stdint.h>
#include <stddef.h>



#define VGA_ADD 0xb8000
#define BUFFSIZE 2200
#define NULL 0

enum {
    VGA_BLACK = 0,
    VGA_BLUE= 1,
    VGA_GREEN = 2,
    VGA_CYAN = 3,
    VGA_RED = 4,
    VGA_MAGENTA = 5,
    VGA_BROWN = 6,
    VGA_LIGHT_GRAY = 7,
    VGA_DARK_GRAY = 8,
    VGA_LIGHT_BLUE = 9,
    VGA_LIGHT_GREEN = 10,
    VGA_LIGHT_CYAN = 11,
    VGA_LIGHT_RED = 12,
    VGA_PINK = 13,
    VGA_YELLOW = 14,
    VGA_WHITE = 15,

};

uint16_t* VGA_BUFFER;

uint32_t col = 0;

/*
    TODO:
        clear_screen()

        drawing:
            coordinates_system()
            windowing
            basic draw functions
            -- later basic 3D --

        printing:
            print_text()
            new_line()

*/



class VGA
{

    public:


        static void init_vga()
        {
            VGA_BUFFER = (uint16_t*)VGA_ADD;
        }

        /*
            16 bit video buffer elements(register ax)
            8 bits(ah) higher : 
            lower 4 bits - forec olor
            higher 4 bits - back color

            8 bits(al) lower :
            8 bits : ASCII character to print
        */
        static uint16_t vga_entry(unsigned char ch, uint8_t fore_color, uint8_t back_color) 
        {

            uint16_t ax = 0;
            uint8_t ah = 0, al = 0;

            ah = back_color;
            ah <<= 4;
            ah |= fore_color;
            ax = ah;
            ax <<= 8;
            al = ch;
            ax |= al;

            return ax;
        }

        static void ブッフェ記憶澄ます(uint16_t **buffer, uint8_t fore, uint8_t back)
        {
            uint32_t i;
            for (i = 0; i < BUFFSIZE; i++)
            {
                (*buffer)[i] = vga_entry(NULL, fore, back);
            }

            col = 0;
        }

        /*
            create calculation for counting rows 
            with rows calculate number of chars to skip for new line
        */
        static void 新しい_ライン()
        {
            if (col > 80)
            {
                col = 80 * ((uint8_t)(col / 80) + 1);
            }
            else
            {
                col = 80;
            }
			
            
        }

        // every 80 char new line
        static void 几帳書く(char *data, uint8_t fore, uint8_t back)
        {
            // VGA::vga_entry(' ', VGA_RED, VGA_RED);
            
            size_t ch = 0;
            while (data[ch])
            {
                文字書く(data[ch], fore, back);
                ch++;
            }

        }

        static void 文字書く(char ch, uint8_t fore, uint8_t back)
        {
            VGA_BUFFER[col] = vga_entry(ch, fore, back);
            col++;            
        }


        static void 文字消す()
        {
            VGA_BUFFER[col - 1] = NULL;
            col--; 
        }
       
};

