# Template

+ Dependencies: none
+ Includes: `template.h`


## How to build

```
$ git clone http://xxx/template.git
$ cd template
$ sudo ./mk.sh
#snip
$ ls /home/lib
libtemplate.a
$ ls /home/include
template.h
```


## How to run a test

```
$ ./test/run.sh
```

---


## Design

```plantuml
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
        + constructor()
        + destructor()
    }
    class Play << (S, orange) >> {
        + constructor()
        + destructor()
    }
    class Pause << (S, orange) >> {
        + constructor()
        + destructor()
    }
}


Player <|. PLAYER : <<implements>>
PLAYER --> State
State <|. STATE : <<implements>>
```


## Usage

```c
#include <basic_player.h>
#include <player.h>

int main( void )
{
    // create instance
    Player *pPlayer = __new__BasicPlayer();

    // play
    pPlayer->Play( pPlayer );

    // snip

    // stop
    pPlayer->Stop( pPlayer );

    // destroy instance
    pPlayer = __del__BasicPlayer( pPlayer );

    return 0;
}
```
