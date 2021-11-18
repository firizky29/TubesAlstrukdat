#ifndef SAVESTATE_H
#define SAVESTATE_H

#include <wordmachine.h>
#include <stack.h>
#include <list_linked.h>

LinkedList reverseStack(Stack *s);
/* get reversed stack */

void save();
/* save current progress */

#endif