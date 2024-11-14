#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>

#define ESC "\033"
#define NORMALTEXT "[0m"
#define BOLDTEXT "[1m"
#define BLINKTEXT "[5m"
#define SHOWCURSOR "[?25h"
#define HIDECURSOR "[?25l"
#define CLEARSCREEN "[2J"
#define BOX_ENABLE "(0"
#define BOX_DISABLE "(B"
#define BOX_VLINE 0x78
#define BOX_HLINE 0x71
#define BOX_UPLEFT 0x6C
#define BOX_UPRIGHT 0x6B
#define BOX_DWNLEFT 0x6D
#define BOX_DWNRIGHT 0x6A
#define BOX_TLEFT 0X74
#define BOX_TRIGHT 0X75
#define BOX_TUP 0X77
#define BOX_TDOWN 0X76

#define MINX 0
#define MINY 0
#define MAXX 50
#define MAXY 30

#define FORCA_X 10
#define FORCA_Y 5
#define GANHAR_TROFEU_X 30
#define GANHAR_TROFEU_Y 10
#define PERDER_CAVEIRA_X 20
#define PERDER_CAVEIRA_Y 10

#define MAX_JOGADOR 10
#define MAX_TENTATIVAS 6

typedef enum {
  BLACK, RED, GREEN, BROWN, BLUE, MAGENTA, CYAN, LIGHTGRAY,
  DARKGRAY, LIGHTRED, LIGHTGREEN, YELLOW, LIGHTBLUE, LIGHTMAGENTA,
  LIGHTCYAN, WHITE
} screenColor;

static inline void screenShowCursor() { printf("%s%s", ESC, SHOWCURSOR); }
static inline void screenClear() { screenShowCursor(); printf("%s%s", ESC, CLEARSCREEN); }
static inline void screenSetNormal() { printf("%s%s", ESC, NORMALTEXT); }
static inline void screenSetBold() { printf("%s%s", ESC, BOLDTEXT); }
static inline void screenSetBlink() { printf("%s%s", ESC, BLINKTEXT); }
static inline void screenBoxEnable() { printf("%s%s", ESC, BOX_ENABLE); }

void screenHomeCursor(void);
void screenGotoxy(int x, int y);
void screenBoxDisable(void);
void screenUpdate(int erros);  
void screenInit(int drawBorders);
void screenDestroy();
void screenSetColor(screenColor fg, screenColor bg);
void screenTrofeu();
void screenCaveira();
void screenForca();

#define BOX_CROSS '+'

#endif 

