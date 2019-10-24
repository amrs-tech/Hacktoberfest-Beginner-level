# This program displays text at a delayed speed in the terminal

import time
import sys
from random import randrange

def introduction(*args):

    text = "\n Hello Neo, this is Morpheus."

    for c in text:
        sys.stdout.write(c)
        sys.stdout.flush()
        seconds = "0." + str(randrange(1, 4, 1))
        seconds = float(seconds)
        time.sleep(seconds)

introduction()
