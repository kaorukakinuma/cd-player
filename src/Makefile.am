AUTOMAKE_OPTIONS = subdir-objects

# Name of libraries
lib_LIBRARIES = \
    libplayer.a

# Compile flag for path to include header
AM_CFLAGS = \
    -I$(top_srcdir)/include/impl/basic \
    -I$(top_srcdir)/include/impl \
    -I$(top_srcdir)/include/state/impl/idle \
    -I$(top_srcdir)/include/state/impl/pause \
    -I$(top_srcdir)/include/state/impl/play \
    -I$(top_srcdir)/include/state/impl \
    -I$(top_srcdir)/include/state \
    -I$(top_srcdir)/include

# Source codes included in library
libplayer_a_SOURCES = \
    @srcdir@/impl/basic/basic_player.c \
    @srcdir@/state/impl/idle/idle_player_state.c \
    @srcdir@/state/impl/pause/pause_player_state.c \
    @srcdir@/state/impl/play/play_player_state.c
