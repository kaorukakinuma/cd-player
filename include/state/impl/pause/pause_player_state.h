/*
 *    file:             pause_player_state.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-01
 *    author:           kaoru kakinuma
 */
#ifndef _PAUSE_PLAYER_STATE_H_
#define _PAUSE_PLAYER_STATE_H_

#include "player_types.h"
PlayerState * __new__PausePlayerState( void );
PlayerState * __del__PausePlayerState( PlayerState *pSelf );

#endif /* _PAUSE_PLAYER_STATE_H_ */
