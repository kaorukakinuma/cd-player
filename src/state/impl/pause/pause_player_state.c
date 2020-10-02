/*
 *    file:             pause_player_state.c
 *    creation date:    2020-10-02
 *    last update:      2020-10-02
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

static PlayerErr Play( PlayerState *pSuper )
{
    PausePlayerState *pSelf = (PausePlayerState *)pSuper;
    (void)pSelf;
    printf( "Play.\n" );
    return PLAYER_E_OK;
}

static PlayerErr Stop( PlayerState *pSuper )
{
    PausePlayerState *pSelf = (PausePlayerState *)pSuper;
    (void)pSelf;
    printf( "Idle.\n" );
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
