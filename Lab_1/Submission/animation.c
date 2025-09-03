#include "types.h"
#include "user.h"

void clear_screen() {
    printf(1, "\033[?25l");
    printf(1, "\033[2J\033[H");
}

void print_frame1() {
    printf(1, "╔════╤╤╤╤════╗\n");
    printf(1, "║    │││ \\   ║\n");
    printf(1, "║    │││  O  ║\n");
    printf(1, "║    OOO     ║\n");
}

void print_frame2() {
    printf(1, "╔════╤╤╤╤════╗\n");
    printf(1, "║    ││││    ║\n");
    printf(1, "║    ││││    ║\n");
    printf(1, "║    OOOO    ║\n");
}

void print_frame3() {
    printf(1, "╔════╤╤╤╤════╗\n");
    printf(1, "║   / │││    ║\n");
    printf(1, "║  O  │││    ║\n");
    printf(1, "║     OOO    ║\n");
}

void print_frame4() {
    printf(1, "╔════╤╤╤╤════╗\n");
    printf(1, "║    ││││    ║\n");
    printf(1, "║    ││││    ║\n");
    printf(1, "║    OOOO    ║\n");
}

int main(void) {
    int ticks=30;
    while (1) {
 
        clear_screen();
        print_frame1();
        sleep(ticks);

        clear_screen();
        print_frame2();
        sleep(ticks);

        clear_screen();
        print_frame3();
        sleep(ticks);

        clear_screen();
        print_frame4();
        sleep(ticks);
    }

    exit();
}

