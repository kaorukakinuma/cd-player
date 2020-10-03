/*
 *    file:             idle_player_state.c
 *    creation date:    2020-10-02
 *    last update:      2020-10-03
 *    author:           kaoru kakinuma
 */
#include <stdbool.h>
#include <stdio.h>

#include "idle_player_state.h"
#include "player_state.h"

typedef struct {
    PlayerState base;
    bool        created;
} IdlePlayerState;

/* ------------------------------------------------------------------------- */

static PlayerErcd Play( PlayerState *pSuper, StateCode *pState )
{
    IdlePlayerState *pSelf = (IdlePlayerState *)pSuper;
    (void)pSelf;
    printf( "Play.\n" );
    *pState = STATE_PLAY;
    return PLAYER_E_OK;
}

static PlayerErcd Stop( PlayerState *pSuper, StateCode *pState )
{
    IdlePlayerState *pSelf = (IdlePlayerState *)pSuper;
    (void)pSelf;
    printf( "Ignored.\n" );
    *pState = STATE_IDLE;
    return PLAYER_E_OK;
}

static const PlayerState sBase = {
    .Play = Play,
    .Stop = Stop,
};

/* ------------------------------------------------------------------------- */

PlayerState * __new__IdlePlayerState( void )
{
    /* create instance */
    static IdlePlayerState sSelf = { .created = false };
    if ( sSelf.created ) return NULL;

    /* initialize instance */
    sSelf.base           = sBase;
    sSelf.created        = true;

    return (PlayerState *)&sSelf;
}

PlayerState * __del__IdlePlayerState( PlayerState *pSelf )
{
    if ( pSelf == NULL ) return NULL;
    ((IdlePlayerState *)pSelf)->created = false;
    return NULL;
}
