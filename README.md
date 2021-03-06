# CD Player

Dependencies: `none`  
Includes: `player.h` `basic_player.h`


## How to Build

```sh
$ sudo ./mk.sh
#snip
$ ls /home/lib
libplayer.a
$ ls /home/include
player.h ...
```


## Design

```plantuml
@startuml

class Player << (I, yellow) interface >> {
    + Play()
    + Stop()
}
namespace PLAYER {
    class Basic << (S, orange) >> {
        - State[]
        + constructor()
        + destructor()
    }
}

class State << (I, yellow) interface >> {
    - Play()
    - Stop()
}
namespace STATE {
    class Idle << (S, orange) >> {
        - constructor()
        - destructor()
    }
    class Play << (S, orange) >> {
        - constructor()
        - destructor()
    }
    class Pause << (S, orange) >> {
        - constructor()
        - destructor()
    }
}

Player <|. PLAYER : <<implements>>
PLAYER --> State
State <|. STATE : <<implements>>

@enduml
```

```plantuml
@startuml

[*] -> Idle

Idle --> Play : Play
Idle --> Idle : Stop

Play --> Pause : Play
Play --> Idle : Stop

Pause --> Play : Play
Pause --> Idle : Stop

@enduml
```


## Usage

```c
#include <basic_player.h>
#include <player.h>

int main( void )
{
    Player *pPlayer = __new__BasicPlayer();

    pPlayer->Play( pPlayer ); // play
    pPlayer->Play( pPlayer ); // pause
    pPlayer->Stop( pPlayer ); // idle

    pPlayer = __del__BasicPlayer( pPlayer );
    return 0;
}
```
