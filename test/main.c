#include <basic_player.h>
#include <player.h>

int main( void )
{
    Player *pPlayer = __new__BasicPlayer();

    pPlayer->Play( pPlayer );
    pPlayer->Play( pPlayer );
    pPlayer->Stop( pPlayer );

    pPlayer = __del__BasicPlayer( pPlayer );
    return 0;
}
