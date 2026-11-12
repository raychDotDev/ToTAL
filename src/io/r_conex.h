// Source - https://codereview.stackexchange.com/q/294653
// Posted by FLAK-ZOSO, modified by community. See post 'Timeline' for change
// history Retrieved 2026-11-12, License - CC BY-SA 4.0
#include <stdio.h>
#ifdef _WIN32
#include <mmsystem.h>
#include <windows.h>
// #pragma comment(lib,"winmm.lib")
#include <conio.h>

void flushInput() {
    // Flush the input buffer (discard data not read yet)
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    FlushConsoleInputBuffer(hInput);
}
#elif __linux__
#include <termios.h>
#include <unistd.h>

char getch(void) {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    // printf("%c\n", buf);
    return buf;
}

void flushInput() {
    // Flush stdin (discard data not read yet)
    tcflush(STDIN_FILENO, TCIFLUSH);
}
#endif

#ifndef R_CONEX_H
#define R_CONEX_H
// MIT License
//
// Copyright (c) 2026 Daniil Potapov
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
typedef struct RCONColor {
    int r, g, b;
} RCONColor;

#define RCON_WHITE (RCONColor){.r = 255, .g = 255, .b = 255}
#define RCON_GRAY (RCONColor){.r = 127, .g = 127, .b = 127}
#define RCON_BLACK (RCONColor){.r = 0, .g = 0, .b = 0}
#define RCON_RED (RCONColor){.r = 255, .g = 0, .b = 0}
#define RCON_GREEN (RCONColor){.r = 0, .g = 255, .b = 0}
#define RCON_BLUE (RCONColor){.r = 0, .g = 0, .b = 255}
#define RCON_YELLOW (RCONColor){.r = 255, .g = 255, .b = 0}
#define RCON_MAGENTA (RCONColor){.r = 255, .g = 0, .b = 255}
#define RCON_CYAN (RCONColor){.r = 0, .g = 255, .b = 255}

#ifdef _WIN32
#define RCON_KEY_ENTER 13
#elif __linux__
#define RCON_KEY_ENTER 10
#endif
#define RCON_KEY_ESCAPE 27
#define RCON_KEY_SPACE 32
#define RCON_KEY_TAB 9
#define RCON_KEY_BACKSPACE 8
#define RCON_KEY_DELETE 127
#define RCON_KEY_LEFT -10
#define RCON_KEY_RIGHT -11
#define RCON_KEY_UP -12
#define RCON_KEY_DOWN -13
#define RCON_KEY_A (65 + 32)
#define RCON_KEY_B (66 + 32)
#define RCON_KEY_C (67 + 32)
#define RCON_KEY_D (68 + 32)
#define RCON_KEY_E (69 + 32)
#define RCON_KEY_F (70 + 32)
#define RCON_KEY_G (71 + 32)
#define RCON_KEY_H (72 + 32)
#define RCON_KEY_I (73 + 32)
#define RCON_KEY_J (74 + 32)
#define RCON_KEY_K (75 + 32)
#define RCON_KEY_L (76 + 32)
#define RCON_KEY_M (77 + 32)
#define RCON_KEY_N (78 + 32)
#define RCON_KEY_O (79 + 32)
#define RCON_KEY_P (80 + 32)
#define RCON_KEY_Q (81 + 32)
#define RCON_KEY_R (82 + 32)
#define RCON_KEY_S (83 + 32)
#define RCON_KEY_T (84 + 32)
#define RCON_KEY_U (85 + 32)
#define RCON_KEY_V (86 + 32)
#define RCON_KEY_W (87 + 32)
#define RCON_KEY_X (88 + 32)
#define RCON_KEY_Y (89 + 32)
#define RCON_KEY_Z (90 + 32)
#define RCON_KEY_AU 65
#define RCON_KEY_BU 66
#define RCON_KEY_CU 67
#define RCON_KEY_DU 68
#define RCON_KEY_EU 69
#define RCON_KEY_FU 70
#define RCON_KEY_GU 71
#define RCON_KEY_HU 72
#define RCON_KEY_IU 73
#define RCON_KEY_JU 74
#define RCON_KEY_KU 75
#define RCON_KEY_LU 76
#define RCON_KEY_MU 77
#define RCON_KEY_NU 78
#define RCON_KEY_OU 79
#define RCON_KEY_PU 80
#define RCON_KEY_QU 81
#define RCON_KEY_RU 82
#define RCON_KEY_SU 83
#define RCON_KEY_TU 84
#define RCON_KEY_UU 85
#define RCON_KEY_VU 86
#define RCON_KEY_WU 87
#define RCON_KEY_XU 88
#define RCON_KEY_YU 89
#define RCON_KEY_ZU 90
#define RCON_KEY_0 48
#define RCON_KEY_1 49
#define RCON_KEY_2 50
#define RCON_KEY_3 51
#define RCON_KEY_4 52
#define RCON_KEY_5 53
#define RCON_KEY_6 54
#define RCON_KEY_7 55
#define RCON_KEY_8 56
#define RCON_KEY_9 57
#define RCON_KEY_F1 112
#define RCON_KEY_F2 113
#define RCON_KEY_F3 114
#define RCON_KEY_F4 115
#define RCON_KEY_F5 116
#define RCON_KEY_F6 117
#define RCON_KEY_F7 118
#define RCON_KEY_F8 119
#define RCON_KEY_F9 120
#define RCON_KEY_F10 121
#define RCON_KEY_F11 122
#define RCON_KEY_F12 123

// Sets values of window size in X and Y respectfully.
void RCONGetWindowSize(int *x, int *y);

// Returns pressed character key.
// Compare with RCON_KEY_### to check specific key.
int RCONReadKey();

// Hides cursor.
void RCONHideCursor();

// Shows cursor.
void RCONShowCursor();

// Saves cursor position. Can be restored with RCONRestoreCursor.
void RCONSaveCursor();

// Restores cursor position saved by RCONSaveCursor.
void RCONRestoreCursor();

// Sets values of cursor position in X and Y respectfully.
void RCONGetCursorPosition(int *x, int *y);

// Starts underline mode for printing text.
void RCONStartUnderline();

// Stops underline mode for printing text.
void RCONEndUnderline();

// Starts bold mode for printing text.
void RCONStartBold();

// Stops bold mode for printing text.
void RCONEndBold();

// Sets foreground color as RGB.
void RCONForegroundColor(RCONColor color);

// Sets background color as RGB.
void RCONBackgroundColor(RCONColor color);

// Resets all style modes to default.
// Such as: Bold, Underline and FG/BG color changes.
void RCONResetStyles();

// Saves screen. Can be restored with RCONSaveScreen.
void RCONSaveScreen();

// Restores screen saved by RCONSaveScreen.
void RCONRestoreScreen();

// Clears screen.
void RCONClearScreen();

// Sets cursor position to X and Y respectfully.
void RCONSetCursorPosition(int x, int y);

// Sets cursor position to [0,0].
void RCONCursorHome();

// To confirm choice user needs to press RETURN.
// Returns index of choice.
// Example:
//  // if title is NULL, no title will be displayed
//  char *title = "What fruit do you prefer?";
//  char *choices[] = {"Apple", "Banana", "Watermelon"};
//  int choicesCount = sizeof(choices) / sizeof(choices[0]);
//  int result = RCONPrompt(title, choices, choicesCount, RCON_WHITE, RCON_GRAY,
//  RCON_WHITE);
//
//  if (result == 2) {
//  	printf("Watermelon is a berry, silly ;)\\n");
//  } else {
//  	printf("Good choice!\n");
//  }
int RCONPrompt(char *title, char **choices, int choicesCount,
               RCONColor activeCol, RCONColor idleCol, RCONColor titleCol);

#include <stdio.h>

int RCONReadKey() {
    int temp = getch();
    int *key = &temp;
    if (*key == 224 || *key == 27) {
        int mod = getch();
        if (*key == 27 && mod == 91) {
            switch (getch()) {
            case 72:
            case 65:
                *key = RCON_KEY_UP;
                break;
            case 77:
            case 67:
                *key = RCON_KEY_RIGHT;
                break;
            case 75:
            case 68:
                *key = RCON_KEY_LEFT;
                break;
            case 80:
            case 66:
                *key = RCON_KEY_DOWN;
                break;
            }
        }
    }
    return *key;
}
void RCONGetWindowSize(int *x, int *y) {
    RCONSaveScreen();
    RCONSaveCursor();
    RCONSetCursorPosition(9999, 9999);
    RCONGetCursorPosition(x, y);
    RCONRestoreScreen();
    RCONRestoreCursor();
}
void RCONHideCursor() { printf("\e[?25l"); }
void RCONRestoreScreen() { printf("\e[47l"); }
void RCONSaveScreen() { printf("\e[47h"); }
void RCONShowCursor() { printf("\e[?25h"); }
void RCONSaveCursor() { printf("\e[s"); }
void RCONRestoreCursor() { printf("\e[u"); }
void RCONGetCursorPosition(int *x, int *y) {
    char in[128];
    printf("\e[6n");
    char ch = ' ';
    // we are getting the cursor pos in format \e[x;yR
    for (int i = 0; (ch = getch()) != 'R'; i++) {
        in[i] = ch;
    }
    sscanf(in, "\e[%d;%dR", y, x);
}
void RCONStartUnderline() { fprintf(stdout, "\e[4m"); }

void RCONEndUnderline() { fprintf(stdout, "\e[24m"); }

void RCONStartBold() { printf("\e[1m"); }

void RCONEndBold() { printf("\e[22m"); }

void RCONForegroundColor(RCONColor color) {
    printf("\e[38;2;%d;%d;%dm", color.r, color.g, color.b);
}

void RCONBackgroundColor(RCONColor color) {
    printf("\e[48;2;%d;%d;%dm", color.r, color.g, color.b);
}

void RCONResetStyles() { printf("\e[0m"); }

void RCONClearScreen() { printf("\033[H\033[J"); }

void RCONSetCursorPosition(int x, int y) { printf("\033[%d;%dH", y, x); }

void RCONCursorHome() { printf("\033[H"); }

int RCONPrompt(char *title, char **choices, int choicesCount,
               RCONColor activeCol, RCONColor idleCol, RCONColor titleCol) {
    int choosed = 0;
    int currentChoice = 0;
    RCONResetStyles();
    RCONHideCursor();
    while (!choosed) {
        if (title != NULL) {
            RCONForegroundColor(titleCol);
            printf("%s\n", title);
        }

        for (int i = 0; i < choicesCount; i++) {
            RCONForegroundColor(idleCol);
            if (currentChoice == i) {
                RCONForegroundColor(activeCol);
                RCONStartUnderline();
                printf("> ");
                printf("%s\n", choices[i]);
                RCONEndUnderline();
            } else {
                printf("%s\n", choices[i]);
            }
            RCONResetStyles();
        }

        int key;
        while (!(key = RCONReadKey())) {
        }
        if (key == RCON_KEY_SPACE || key == RCON_KEY_ENTER) {
            choosed = !choosed;
        } else if (key == RCON_KEY_DOWN) {
            currentChoice++;
        } else if (key == RCON_KEY_UP) {
            currentChoice--;
        }
        currentChoice =
            ((currentChoice % choicesCount) + choicesCount) % choicesCount;
        for (int i = choicesCount + (title == NULL ? 0 : 1); i > 0; i--) {
            printf("\033[A\33[2K");
        }
    }
    RCONShowCursor();
    return currentChoice;
}
#endif
