/*
 *    file:             player.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-03
 *    author:           kaoru kakinuma
 */
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "player_types.h"
struct Player {
    PlayerErcd (*Play)( Player *pSelf );
    PlayerErcd (*Stop)( Player *pSelf );
};

#endif /* _PLAYER_H_ */
