/*
 *    file:             player_state.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-01
 *    author:           kaoru kakinuma
 */
#ifndef _PLAYER_STATE_H_
#define _PLAYER_STATE_H_

#include "player_types.h"
struct PlayerState {
    PlayerErr (*Play)( PlayerState *pSelf );
    PlayerErr (*Stop)( PlayerState *pSelf );
};

#endif /* _PLAYER_STATE_H_ */
