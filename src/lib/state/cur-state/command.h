#ifndef COMMAND_H
#define COMMAND_H

#include "../../tools/mesin-kata/wordmachine.h"
#include "../../scene/map/map.h"
#include "../../component/global.h"

/* CHECK COMMAND VALIDITY */
boolean isNewGame(Word kata);
/* return true if kata is NEW_GAME and false if not */
boolean isExit(Word kata);
/* return true if kata is EXIT and false if not */
boolean isLoadGame(Word kata);
/* return true if kata is LOAD_GAME and false if not */
boolean isMove(Word kata);
/* return true if kata is MOVE and false if not */
boolean isPickUp(Word kata);
/* return true if kata is PICK_UP and false if not */
boolean isDropOff(Word kata);
/* return true if kata is DROP_OFF and false if not */
boolean isMap(Word kata);
/* return true if kata is MAP and false if not */
boolean isToDo(Word kata);
/* return true if kata is TO_DO and false if not */
boolean isInProgress(Word kata);
/* return true if kata is IN_PROGRESS and false if not */
boolean isBuy(Word kata);
/* return true if kata is BUY and false if not */
boolean isInventory(Word kata);
/* return true if kata is INVENTORY and false if not */
boolean isHelp(Word kata);
/* return true if kata is HELP and false if not */
boolean isSaveGame(Word kata);
/* return true if kata is SAVE_GAME and false if not */
boolean isReturn(Word kata);
/* return true if kata is RETURN and false if not */

/* ACTION */
void Move();
/* Mengubah curPosition, curTime*/
void Pickup();
/* Mengubah curBag, curProgress, cur..*/
void Dropoff();
void displayMap();
void displayToDoList();
void displayInProgress();
void Buy();
void displayInventory();
void displayHelp();
void Retur();


#endif