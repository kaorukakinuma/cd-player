/*
 *    file:             player.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-01
 *    author:           kaoru kakinuma
 */
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "player_types.h"
struct Player {
    PlayerErr (*Play)( Player *pSelf );
    PlayerErr (*Stop)( Player *pSelf );
};

#endif /* _PLAYER_H_ */
