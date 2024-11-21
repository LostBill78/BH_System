/* ***************************************************
 *			BH_SYSTEMS Operating System
 *************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <terminal.h>
#include <keyboard.h>
#include <kernel.h>
#include <string.h>

bool ready_to_run = false;

void kernel_main()
{
    terminal_initialize();
    terminal_writestring("New build system for BH_Systems OS\n");
    init_keyboard();
    
    test_tty();
    ready_to_run = true;
    while(ready_to_run)
    {
        // Should not return to assembly code.
    }
}

void user_commands(const char *data)
{
    if (strcmp(data, "end"))
    {
        terminal_writestring("System shutting down!");
        ready_to_run = false;
    }
}

void test_tty()
{
    for (uint16_t i = 0; i < 27; i++)
    {
        terminal_writestring("Next line.\n");
    }
    terminal_writestring("This should always be the last line. It is always on the bottom.");
}