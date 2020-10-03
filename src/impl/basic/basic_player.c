/*
 *    file:             basic_player.c
 *    creation date:    2020-09-30
 *    last update:      2020-10-03
 *    author:           kaoru kakinuma
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
