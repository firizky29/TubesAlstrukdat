/**
Filename: pcolor_driver.c (driver of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include <pcolor.h>

int main() {
    print_red_char('R');
    print_green_char('G');
    print_magenta_char('M');
    print_cyan_char('C');
    print_yellow_char('Y');
    print_blue_char('B');
    printf("\n");
    return 0;
}
