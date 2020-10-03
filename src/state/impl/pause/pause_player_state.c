/*
 *    file:             pause_player_state.c
 *    creation date:    2020-10-02
 *    last update:      2020-10-03
 *    author:           kaoru kakinuma
 */
#include <stdbool.h>
#include <stdio.h>

#include "pause_player_state.h"
#include "player_state.h"

typedef struct {
    PlayerState base;
    bool        created;
} PausePlayerState;

/* ------------------------------------------------------------------------- */

static PlayerErr Play( PlayerState *pSuper, StateCode *pState )
{
    PausePlayerState *pSelf = (PausePlayerState *)pSuper;
    (void)pSelf;
    printf( "Play.\n" );
    *pState = STATE_PLAY;
    return PLAYER_E_OK;
}

static PlayerErr Stop( PlayerState *pSuper, StateCode *pState )
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
    sSelf.base           = sBase;
    sSelf.created        = true;

    return (PlayerState *)&sSelf;
}

PlayerState * __del__PausePlayerState( PlayerState *pSelf )
{
    if ( pSelf == NULL ) return NULL;
    ((PausePlayerState *)pSelf)->created = false;
    return NULL;
}
