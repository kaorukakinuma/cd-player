/*
 *    file:             play_player_state.c
 *    creation date:    2020-10-02
 *    last update:      2020-10-02
 *    author:           kaoru kakinuma
 */
#include <stdbool.h>
#include <stdio.h>

#include "play_player_state.h"
#include "player_state.h"

typedef struct {
    PlayerState base;
    bool        created;
} PlayPlayerState;

/* ------------------------------------------------------------------------- */

static PlayerErr Play( PlayerState *pSuper )
{
    PlayPlayerState *pSelf = (PlayPlayerState *)pSuper;
    (void)pSelf;
    printf( "Pause.\n" );
    return PLAYER_E_OK;
}

static PlayerErr Stop( PlayerState *pSuper )
{
    PlayPlayerState *pSelf = (PlayPlayerState *)pSuper;
    (void)pSelf;
    printf( "Idle.\n" );
    return PLAYER_E_OK;
}

static const PlayerState sBase = {
    .Play = Play,
    .Stop = Stop,
};

/* ------------------------------------------------------------------------- */

PlayerState * __new__PlayPlayerState( void )
{
    /* create instance */
    static PlayPlayerState sSelf = { .created = false };
    if ( sSelf.created ) return NULL;

    /* initialize instance */
    sSelf.base           = sBase;
    sSelf.created        = true;

    return (PlayerState *)&sSelf;
}

PlayerState * __del__PlayPlayerState( PlayerState *pSelf )
{
    if ( pSelf == NULL ) return NULL;
    ((PlayPlayerState *)pSelf)->created = false;
    return NULL;
}
