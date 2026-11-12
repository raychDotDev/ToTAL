#pragma once

#define ANSI_CURSOR_SAVE "\e[s"
#define ANSI_CURSOR_RESTORE "\e[u"
#define ANSI_CURSOR_HIDE "\e[?25l"
#define ANSI_CURSOR_SHOW "\e[?25h"
#define ANSI_CURSOR_HOME "\e[H"

#define ANSI_CURSOR_MOVE_UP "\e[M"

const char* ANSI_CURSOR_SET(int x, int y);

#define ANSI_ERASE_TO_END "\e[0J"
#define ANSI_ERASE_TO_BEGIN "\e[1J"
#define ANSI_ERASE_LINE "\e[2K"
#define ANSI_ERASE_SCREEN "\e[2J"

const char *ANSI_COLOR_FG(unsigned char r, unsigned char g, unsigned char b);
const char *ANSI_COLOR_BG(unsigned char r, unsigned char g, unsigned char b);

#define ANSI_SCREEN_SAVE "\e[?47h"
#define ANSI_SCREEN_RESTORE "\e[?47l"

#define ANSI_STYLE_RESET "\e[0m"
#define ANSI_STYLE_BOLD "\e[1m"
#define ANSI_STYLE_DIM "\e[2m"
#define ANSI_STYLE_ITALIC "\e[3m"
#define ANSI_STYLE_UNDERLINE "\e[4m"
#define ANSI_STYLE_BLINK "\e[5m"
#define ANSI_STYLE_STRIKETHROUGH "\e[9m"
