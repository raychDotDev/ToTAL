#include "ansiescape.h"
#include <raylib.h>

const char *ANSI_CURSOR_SET(int x, int y) {
    return TextFormat("\e[%d;%dH", y, x);
}

const char *ANSI_COLOR_FG(unsigned char r, unsigned char g, unsigned char b) {
    return TextFormat("\e[38;2;%d;%d;%dm", r, g, b);
}
const char *ANSI_COLOR_BG(unsigned char r, unsigned char g, unsigned char b) {
    return TextFormat("\e[48;2;%d;%d;%dm", r, g, b);
}
