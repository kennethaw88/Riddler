# 22 April 2022
# start at level 0
# for each level x=0-4, there is a (100-20x) % chance of moving up one level,
# else fall one level. How many moves to get to level 5?

import random

def move(level, max_level):
  return random.randint(1, max_level) > level

def main():

  N_trials = int(1e5)
  avg_moves = 0
  current_level = 0
  max_level = 5
  moves_counter = 0

  for n in range(0, N_trials):
    current_level = 0
    moves_counter = 0

    while current_level != max_level:
      moves_counter += 1
      if move(current_level, max_level):
        current_level += 1
      else:
        current_level -= 1

    avg_moves += moves_counter

  avg_moves /= N_trials
  print("\nWith a max level of ", max_level, ", it takes an average of ",
        round(avg_moves, 2), " moves.\n")

main()
