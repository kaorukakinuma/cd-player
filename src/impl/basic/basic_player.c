/*
 * MIT License
 *
 * Copyright (c) 2020 Kaoru Kakinuma
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdbool.h>
#include <stddef.h>

#include "idle_player_state.h"
#include "pause_player_state.h"
#include "play_player_state.h"
#include "player_state.h"

#include "basic_player.h"
#include "player.h"

typedef struct {
    Player         base;
    bool           created;
    StateCode      currentState;
    PlayerState   *apState[STATE_NUM];
} BasicPlayer;

/* ------------------------------------------------------------------------- */

static PlayerErcd Play( Player *pSuper )
{
    BasicPlayer *pSelf = (BasicPlayer *)pSuper;
    PlayerState *pState = pSelf->apState[pSelf->currentState];
    return pState->Play( pState, &pSelf->currentState );
}

static PlayerErcd Stop( Player *pSuper )
{
    BasicPlayer *pSelf = (BasicPlayer *)pSuper;
    PlayerState *pState = pSelf->apState[pSelf->currentState];
    return pState->Stop( pState, &pSelf->currentState );
}

static const Player sBase = {
    .Play = Play,
    .Stop = Stop,
};

/* ------------------------------------------------------------------------- */

Player * __new__BasicPlayer( void )
{
    /* create instance */
    static BasicPlayer sSelf = { .created = false };
    if ( sSelf.created ) return NULL;

    /* initialize instance */
    sSelf.base         = sBase;
    sSelf.created      = true;
    sSelf.currentState = STATE_IDLE;
    sSelf.apState[STATE_IDLE]  = __new__IdlePlayerState();
    sSelf.apState[STATE_PLAY]  = __new__PlayPlayerState();
    sSelf.apState[STATE_PAUSE] = __new__PausePlayerState();

    return (Player *)&sSelf;
}

Player * __del__BasicPlayer( Player *pSelf )
{
    if ( pSelf == NULL ) return NULL;
    pSelf->Stop( pSelf );

    BasicPlayer *pSub = (BasicPlayer *)pSelf;
    pSub->created = false;

    pSub->apState[STATE_IDLE] =
        __del__IdlePlayerState( pSub->apState[STATE_IDLE] );
    pSub->apState[STATE_PLAY] =
        __del__PlayPlayerState( pSub->apState[STATE_PLAY] );
    pSub->apState[STATE_PAUSE] =
        __del__PausePlayerState( pSub->apState[STATE_PAUSE] );

    return NULL;
}
