#pragma once

#include <stdint.h>

class math {

    public:
        static uint16_t map(
            uint16_t a0, uint16_t a1, 
            uint16_t b0, uint16_t b1, 
            uint16_t a
        )
        {
            return b0 + (b1 - b0) * ((a-a0)/(a1-a0));
        }
};

