/*
 *    file:             play_player_state.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-01
 *    author:           kaoru kakinuma
 */
#ifndef _PLAY_PLAYER_STATE_H_
#define _PLAY_PLAYER_STATE_H_

#include "player_types.h"
PlayerState * __new__PlayPlayerState( void );
PlayerState * __del__PlayPlayerState( PlayerState *pSelf );

#endif /* _PLAY_PLAYER_STATE_H_ */
