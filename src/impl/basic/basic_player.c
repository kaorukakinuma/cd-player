/*
 *    file:             basic_player.c
 *    creation date:    2020-09-30
 *    last update:      2020-10-02
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

typedef enum {
    IDLE,
    PLAY,
    PAUSE,
    STATENUM
} State;

typedef struct {
    Player         base;
    bool           created;
    State          currentState;
    PlayerState   *apState[STATENUM];
} BasicPlayer;

/* ------------------------------------------------------------------------- */

static PlayerErr Play( Player *pSuper )
{
    BasicPlayer *pSelf = (BasicPlayer *)pSuper;

    PlayerState *pState = pSelf->apState[pSelf->currentState];
    pState->Play( pState );

    switch ( pSelf->currentState )
    {
    case IDLE:  pSelf->currentState = PLAY;
                break;
    case PLAY:  pSelf->currentState = PAUSE;
                break;
    case PAUSE: pSelf->currentState = PLAY;
                break;
    default:
        break;
    }

    return PLAYER_E_OK;
}

static PlayerErr Stop( Player *pSuper )
{
    BasicPlayer *pSelf = (BasicPlayer *)pSuper;

    PlayerState *pState = pSelf->apState[pSelf->currentState];
    pState->Stop( pState );

    switch ( pSelf->currentState )
    {
    case IDLE:  pSelf->currentState = IDLE;
                break;
    case PLAY:  pSelf->currentState = IDLE;
                break;
    case PAUSE: pSelf->currentState = IDLE;
                break;
    default:
        break;
    }

    return PLAYER_E_OK;
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
    sSelf.base           = sBase;
    sSelf.created        = true;
    sSelf.currentState   = IDLE;
    sSelf.apState[IDLE]  = __new__IdlePlayerState();
    sSelf.apState[PLAY]  = __new__PlayPlayerState();
    sSelf.apState[PAUSE] = __new__PausePlayerState();

    return (Player *)&sSelf;
}

Player * __del__BasicPlayer( Player *pSelf )
{
    if ( pSelf == NULL ) return NULL;
    pSelf->Stop( pSelf );

    BasicPlayer *pSub = (BasicPlayer *)pSelf;
    pSub->created        = false;
    pSub->apState[IDLE]  = __del__IdlePlayerState(  pSub->apState[IDLE]  );
    pSub->apState[PLAY]  = __del__PlayPlayerState(  pSub->apState[PLAY]  );
    pSub->apState[PAUSE] = __del__PausePlayerState( pSub->apState[PAUSE] );

    return NULL;
}
