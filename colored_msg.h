#ifndef COLORED_MSG_H
#define COLORED_MSG_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* Text styles */
#define RESET_STYLE   "\x1b[0m"
#define BOLD          "\x1b[1m"
#define ITALIC        "\x1b[3m"
#define UNDERLINE     "\x1b[4m"

/* Text colors */
#define T_BLACK       "\x1b[30m"
#define T_RED         "\x1b[31m"
#define T_GREEN       "\x1b[32m"
#define T_YELLOW      "\x1b[33m"
#define T_BLUE        "\x1b[34m"
#define T_MAGENTA     "\x1b[35m"
#define T_CYAN        "\x1b[36m"
#define T_WHITE       "\x1b[37m"

/* Text brigth colors */
#define T_LBLACK       "\x1b[90m"
#define T_LRED         "\x1b[91m"
#define T_LGREEN       "\x1b[92m"
#define T_LYELLOW      "\x1b[93m"
#define T_LBLUE        "\x1b[94m"
#define T_LMAGENTA     "\x1b[95m"
#define T_LCYAN        "\x1b[96m"
#define T_LWHITE       "\x1b[97m"

/* Background colors */
#define BG_BLACK       "\x1b[40m"
#define BG_RED         "\x1b[41m"
#define BG_GREEN       "\x1b[42m"
#define BG_YELLOW      "\x1b[43m"
#define BG_BLUE        "\x1b[44m"
#define BG_MAGENTA     "\x1b[45m"
#define BG_CYAN        "\x1b[46m"
#define BG_WHITE       "\x1b[47m"

/* Background bright colors */
#define BG_LBLACK       "\x1b[100m"
#define BG_LRED         "\x1b[101m"
#define BG_LGREEN       "\x1b[102m"
#define BG_LYELLOW      "\x1b[103m"
#define BG_LBLUE        "\x1b[104m"
#define BG_LMAGENTA     "\x1b[105m"
#define BG_LCYAN        "\x1b[106m"
#define BG_LWHITE       "\x1b[107m"

void styled_print(char *msg, char *style, ...);

/* Generic Messagens */
void print_black(char *msg, ...);
void print_yellow(char *msg, ...);
void print_green(char *msg, ...);
void print_red(char *msg, ...);
void print_blue(char *msg, ...);
void print_magenta(char *msg, ...);
void print_cyan(char *msg, ...);
void print_white(char *msg, ...);
void print_lblack(char *msg, ...);
void print_lyellow(char *msg, ...);
void print_lgreen(char *msg, ...);
void print_lred(char *msg, ...);
void print_lblue(char *msg, ...);
void print_lmagenta(char *msg, ...);
void print_lcyan(char *msg, ...);
void print_lwhite(char *msg, ...);

/* Specific Messages */

void print_success(char *msg, ...);
void print_warning(char *msg, ...);
void print_error(char *msg, ...);
void print_debug(char *msg, ...);
void print_directory(char *msg, ...);

#endif
