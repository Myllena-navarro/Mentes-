#include "keyboard.h"
#include <termios.h>
#include <unistd.h>

int keyhit(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  
    if (ch != EOF) {
        ungetc(ch, stdin);  
        return 1; 
    }
    return 0; 
}

char get_input(void) {
    char ch = getchar(); 
    return ch;
}
