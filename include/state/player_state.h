/*
 *    file:             player_state.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-03
 *    author:           kaoru kakinuma
 */
#ifndef _PLAYER_STATE_H_
#define _PLAYER_STATE_H_

#include "player_types.h"

typedef enum {
    STATE_IDLE,
    STATE_PLAY,
    STATE_PAUSE,
    STATE_NUM
} StateCode;

struct PlayerState {
    PlayerErcd (*Play)( PlayerState *pSelf, StateCode *pState );
    PlayerErcd (*Stop)( PlayerState *pSelf, StateCode *pState );
};

#endif /* _PLAYER_STATE_H_ */
