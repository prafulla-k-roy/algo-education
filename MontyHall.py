# Monty Hall problem in python

# The Monty Hall Problem is like this:

# 1.The show has three doors. A prize like a car or vacation is behind a door, and the other two doors hide a worthless prize called a Zonk; in most discussions of the problem, the Zonk is a goat.
# 2.The competitor chooses a door. We’ll assume that the entrant has no internal knowledge of which gate is holding the prize, so the entrant will simply make a random choice.
# 3.Smiling host Monty Hall opens one of the other doors, always choosing the one that shows a goat, and always offers the contestant a chance to change their choice for the remaining unopened door.
# 4.The competitor chooses to change the gate or chooses to stick to the first choice.

import random
from random import seed, randint
import numpy

def game(winningdoor, selecteddoor, change=False):
    assert winningdoor < 3
    assert winningdoor >= 0

    # Presenter removes the first door that was not selected neither winning
    removeddoor = next(i for i in range(3) if i != selecteddoor and i != winningdoor)

    # Player decides to change its choice
    if change:
        selecteddoor = next(i for i in range(3) if i != selecteddoor and i != removeddoor)

    # We suppose the player never wants to change its initial choice.
    return selecteddoor == winningdoor


if __name__ == '__main__':
    playerdoors = numpy.random.random_integers(0,2, (1000 * 1000 * 1,))

    winningdoors = [d for d in playerdoors if game(1, d)]
    print("Winning percentage without changing choice: ", len(winningdoors) / len(playerdoors))

    winningdoors = [d for d in playerdoors if game(1, d, change=True)]
    print("Winning percentage while changing choice: ", len(winningdoors) / len(playerdoors))
