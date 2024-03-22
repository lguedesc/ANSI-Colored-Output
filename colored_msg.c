/* =====================================================================
    This file contains all the functions related to the formatting of
    pop-up messages in the program
  ====================================================================== */

#include <stdarg.h>
#include <stdio.h>
#include "colored_msg.h"

/* Generic function that applies styles and colors */

void styled_print(char *msg, char *style, ...) {
    va_list args;
    va_start(args, style);
    printf("%s", style);
    vprintf(msg, args);
    printf(RESET_STYLE);
    va_end(args);

}

/* Colored text mesages */

void print_black(char *msg, ...) {
    printf(T_BLACK);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_yellow(char *msg, ...) {
    printf(T_YELLOW);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_green(char *msg, ...) {
    printf(T_GREEN);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_red(char *msg, ...) {
    printf(T_RED);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_blue(char *msg, ...) {
    printf(T_BLUE);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_magenta(char *msg, ...) {
    printf(T_MAGENTA);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_cyan(char *msg, ...) {
    printf(T_CYAN);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_white(char *msg, ...) {
    printf(T_WHITE);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lblack(char *msg, ...) {
    printf(T_LBLACK);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lyellow(char *msg, ...) {
    printf(T_LYELLOW);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lgreen(char *msg, ...) {
    printf(T_LGREEN);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lred(char *msg, ...) {
    printf(T_LRED);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lblue(char *msg, ...) {
    printf(T_LBLUE);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lmagenta(char *msg, ...) {
    printf(T_LMAGENTA);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lcyan(char *msg, ...) {
    printf(T_LCYAN);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_lwhite(char *msg, ...) {
    printf(T_LWHITE);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

