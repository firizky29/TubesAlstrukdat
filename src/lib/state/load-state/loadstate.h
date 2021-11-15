#ifndef LOADSTATE_H
#define LOADSTATE_H

#include <wordmachine.h>

boolean isLoadAvailable();
/* check if there are saved files able to be loaded */
void load();
/* load saved file (initialize from saved file) */

#endif