#ifndef INITIALIZE_H
#define INITIALIZE_H

#endif // INITIALIZE_H

#include <ncurses.h>

static WINDOW *MainFrame;


void CreateWindow(void);

void DestroyWindow(void);

void HandleEvents(void);
