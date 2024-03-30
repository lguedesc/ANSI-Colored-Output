/* =====================================================================
    This file contains all the functions related to the formatting of
    pop-up messages in the program
  ====================================================================== */

#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

/* Specific Messages */

void print_success(char *msg, ...) {
    printf(T_LGREEN);
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_warning(char *msg, ...) {
    printf(T_LYELLOW);
    printf("Warning: ");
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_error(char *msg, ...) {
    printf(T_LRED);
    printf("Error: ");
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_debug(char *msg, ...) {
    printf(T_LBLUE);
    printf("Debug: ");
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf(RESET_STYLE);
}

void print_directory(char *msg, ...) {
    printf(T_LMAGENTA);
    printf("'");
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf("'");
    printf(RESET_STYLE);
}

/* Remove style */

static bool check_ANSI_start(char character, bool current_ANSI_status) {
    /* This function checks if the position of the string is the start of an ANSI escape character */
    bool inside_ANSI = current_ANSI_status;
    // Check if the character is the first character of an ANSI escape sequence  
    if (character == '\x1b' || character == '\033') {
        inside_ANSI = true;
    }
    return inside_ANSI;
}

static bool check_ANSI_end(char character, bool current_ANSI_status) {
    /* This function checks if the position of the string is the end of an ANSI escape character 
       (this function must be called after all checks for inside_ANSI variable) */
    bool inside_ANSI = current_ANSI_status;
    // Check if position is inside an ANSI escape sequence and if it is the last position of the sequence
    if ((inside_ANSI == true) && (character == 'm')) {
        inside_ANSI = false;
    }
    return inside_ANSI;
}

static size_t count_ANSI_style_bytes(char *str) {
    // Create variable to determine if the position of the string is inside a ANSI escape sequence
    bool inside_ANSI = false;
    // Create variable to count the number of bytes in memory ANSI escape sequences occupy for the str
    size_t bytes = 0;
    // Get length of the string
    size_t len = strlen(str) + 1;
    // Iterate over the string to find how many ANSI escape characters are there
    for (size_t i = 0; i < len; i++) {
        inside_ANSI = check_ANSI_start(str[i], inside_ANSI);
        if (inside_ANSI == true) {
            // Increase number of bytes by 1
            bytes++;
        }
        inside_ANSI = check_ANSI_end(str[i], inside_ANSI);
    }
    return bytes;
}

char *remove_ansi_escape_codes(char *str) {
    // Determine the number of bytes ANSI escape sequences occupy in the str
    size_t ANSI_bytes = count_ANSI_style_bytes(str);
    // Allocate enough memory for the new unformatted string
    size_t str_len = strlen(str) + 1;
    size_t new_str_len = str_len - ANSI_bytes;
    char *new_str = malloc(new_str_len);   // length of the original string + 1 for '\0' - the ANSI bytes
    // Counter to skip ANSI characters
    size_t j = 0;
    // Flag to determine if it is inside a ANSI sequence or not
    bool inside_ANSI = false;
    // Iterate over the original string to copy the characters to the new string
    for (size_t i = 0; i < str_len; i++) {
        inside_ANSI = check_ANSI_start(str[i], inside_ANSI);
        if (inside_ANSI == false) {
            // Copy the string and advance one position in the new str (j++)
            new_str[j] = str[i];
            j++;
        }
        inside_ANSI = check_ANSI_end(str[i], inside_ANSI);        
    }
    return new_str;
}
