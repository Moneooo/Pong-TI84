# ----------------------------
# Makefile Options
# ----------------------------

NAME = Pong
ICON = icon.png
DESCRIPTION = "Pong for the ti-84 plus CE - made by Paul"
COMPRESSED = YES
COMPRESSED_MODE = zx7

HAS_PRINTF = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
