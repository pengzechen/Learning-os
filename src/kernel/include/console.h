#ifndef CONSOLE_H
#define CONSOLE_H
#include <comm/types.h>


#define CONSOLE_DISP_ADDR   0Xb8000
#define CONSOLE_DISP_END    (0XB8000 + 32*1024)
#define CONSOLE_ROW_MAX     25
#define CONSOLE_COL_MAX     80


typedef enum _color_t {
    COLOR_Black			= 0,
    COLOR_Blue			= 1,
    COLOR_Green			= 2,
    COLOR_Cyan			= 3,
    COLOR_Red			= 4,
    COLOR_Magenta		= 5,
    COLOR_Brown			= 6,
    COLOR_Gray			= 7,
    COLOR_Dark_Gray 	= 8,
    COLOR_Light_Blue	= 9,
    COLOR_Light_Green	= 10,
    COLOR_Light_Cyan	= 11,
    COLOR_Light_Red		= 12,
    COLOR_Light_Magenta	= 13,
    COLOR_Yellow		= 14,
    COLOR_White			= 15
}color_t;


typedef union _disp_char_t {
    struct {
        char c;
        char foreground : 4;
        char background : 3;
    };
    uint16_t v;

}disp_char_t;

typedef struct _console_t {
    disp_char_t * disp_base;
    int display_rows, display_cols;
    int cursor_row, cursor_col;
    color_t foreground, background;
}console_t;

int  console_init();
int  console_write(int console, char* data, int size);
void console_close(int console);

#endif  // CONSOLE_H