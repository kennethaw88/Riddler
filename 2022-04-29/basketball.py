# 29 April 2022 Classic Riddler
# Two teams take turns scoring 0 or 2 points with some probability.
# During a tie, the possessor has 50% chance to score.
# When ahead, the possessor has a 50-x% chance
# When behind, the possessor has a 50+x% chance
# What is x such that there is 50% chance of a tie at the end?

import random

def score(lead, edge):
    return random.random() > 0.5+lead*edge
  
N_trials = int(1e5)
N_possessions = 100
edge = 0.250
Nicks_score = 0
Naughts_score = 0
ties = 0
Nicks_wins = 0
Naughts_wins = 0
lead = 0
random.seed

for i in range(0, N_trials):
  Nicks_score = 0
  Naughts_score = 0

  for j in range(0, N_possessions):
# Nicks get first opportunity to score
    if Nicks_score > Naughts_score:
      lead = 1
    elif Nicks_score < Naughts_score:
      lead = -1
    else:
      lead = 0
    if score(lead, edge):
      Nicks_score += 1

# Naughts get second opportunity to score
    if Naughts_score > Nicks_score:
      lead = 1
    elif Naughts_score < Nicks_score:
      lead = -1
    else:
      lead = 0
    if score(lead, edge):
      Naughts_score += 1
    
  if Nicks_score > Naughts_score:
    Nicks_wins += 1
  elif Nicks_score < Naughts_score:
    Naughts_wins += 1
  else:
    ties += 1

# tally up the totals
message = (f"With {N_trials:.0e} trials and an edge of {edge}, " +
           f"ties were {ties/N_trials*100:.2f}%, " +
           f"Nicks wins were {Nicks_wins/N_trials*100:.1f}%, " +
           f"and Naughts wins were {Naughts_wins/N_trials*100:.1f}%.")
print(message)
