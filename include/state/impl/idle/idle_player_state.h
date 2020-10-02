/*
 *    file:             idle_player_state.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-01
 *    author:           kaoru kakinuma
 */
#ifndef _IDLE_PLAYER_STATE_H_
#define _IDLE_PLAYER_STATE_H_

#include "player_types.h"
PlayerState * __new__IdlePlayerState( void );
PlayerState * __del__IdlePlayerState( PlayerState *pSelf );

#endif /* _IDLE_PLAYER_STATE_H_ */
