#include "Crewmates.h"
#include "Game.h"

bool redSus() {
  Crewmates crewmates;
  Game game;

  const CrewMate* red;
  for (int i = 0; i < crewmates.getAmount(); i++) {
    if (crewmates.getCrewMate(i).getColor() == "RED") {
      red = crewmates.getCrewMate(i);
    }
  }

  if (!red) {
    std::cout << "red no in game :c" << endl;
    return false;
  }

  int susAmount = crewmates::GetSus(red);
  if (susAmount >= 1) {
    void voteFunction(int votes, bool result) {
      for (int i = 0; i < crewmates.getAmount(); i++) {
        const crewmate* selected = crewmates.getCrewMate(i);
        if (&selected.canVote() && &selected.getColor() != crewmates.getColor("RED")) {
          selected.vote("IMPOSTER");
          game::TypeInChat(selected, "IMPOSTER");
          votes++;
        }
      }

      if (votes >= game.getMinimumVotesRequired()) {
        result = true;
      }
    }

    game::CallNewVote(0, false, voteFunction());

    return true;
  } else {
    return false;
  }
}
