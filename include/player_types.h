/*
 *    file:             player_types.h
 *    creation date:    2020-10-01
 *    last update:      2020-10-03
 *    author:           kaoru kakinuma
 */
#ifndef _PLAYER_TYPES_H_
#define _PLAYER_TYPES_H_

typedef struct Player      Player;
typedef struct PlayerState PlayerState;

typedef enum {
    PLAYER_E_OK,
    PLAYER_E_OBJ,
    PLAYER_E_SYS,
} PlayerErr;

#endif /* _PLAYER_TYPES_H_ */
