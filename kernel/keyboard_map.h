#pragma once

class MAPKeB
{
    public:
        static char conv(char keycode)
        {
            switch (keycode)
            {
            case 0x1E: return 'a'; break;
            case 0x30: return 'b'; break;
            case 0x2E: return 'c'; break;
            case 0x20: return 'd'; break;
            case 0x12: return 'e'; break;
            case 0x21: return 'f'; break;
            case 0x22: return 'g'; break;
            case 0x23: return 'h'; break;
            case 0x17: return 'i'; break;
            case 0x24: return 'j'; break;
            case 0x25: return 'k'; break;
            case 0x26: return 'l'; break;
            case 0x32: return 'm'; break;
            case 0x31: return 'n'; break;
            case 0x18: return 'o'; break;
            case 0x19: return 'p'; break;
            case 0x10: return 'q'; break;
            case 0x13: return 'r'; break;
            case 0x1F: return 's'; break;
            case 0x14: return 't'; break;
            case 0x16: return 'u'; break;
            case 0x2F: return 'v'; break;
            case 0x11: return 'w'; break;
            case 0x2D: return 'x'; break;
            case 0x15: return 'y'; break;
            case 0x2C: return 'z'; break;
            default:
                return ' '; break;

            
            };
        }
};