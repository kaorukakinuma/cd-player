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
#include <stdio.h>

#include "pause_player_state.h"
#include "player_state.h"

typedef struct {
    PlayerState    base;
    bool           created;
} PausePlayerState;

/* ------------------------------------------------------------------------- */

static PlayerErcd Play( PlayerState *pSuper, StateCode *pState )
{
    PausePlayerState *pSelf = (PausePlayerState *)pSuper;
    (void)pSelf;
    printf( "Play.\n" );
    *pState = STATE_PLAY;
    return PLAYER_E_OK;
}

static PlayerErcd Stop( PlayerState *pSuper, StateCode *pState )
{
    PausePlayerState *pSelf = (PausePlayerState *)pSuper;
    (void)pSelf;
    printf( "Idle.\n" );
    *pState = STATE_IDLE;
    return PLAYER_E_OK;
}

static const PlayerState sBase = {
    .Play = Play,
    .Stop = Stop,
};

/* ------------------------------------------------------------------------- */

PlayerState * __new__PausePlayerState( void )
{
    /* create instance */
    static PausePlayerState sSelf = { .created = false };
    if ( sSelf.created ) return NULL;

    /* initialize instance */
    sSelf.base    = sBase;
    sSelf.created = true;

    return (PlayerState *)&sSelf;
}

PlayerState * __del__PausePlayerState( PlayerState *pSelf )
{
    if ( pSelf == NULL ) return NULL;
    ((PausePlayerState *)pSelf)->created = false;
    return NULL;
}
