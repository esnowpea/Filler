# Filler
Writing a Filler player is a very interesting algorithmic challenge. Each turn, the active player receives the grid status and must maximize his points while trying to minimize those of the opponent by eliminating it as quickly as possible.

The meaning of the algorithm is to surround the enemy as close as possible and prevent him from making his move

## Compiling
Run `make`, an player called `esnowpea.filler` should compile directly

## Usage
To start a two-player battle, run the command:

`./filler_vm -p1 [player1] -p2 [player2] -f [map]`

Replace [player1] and [player2] with players from the players folder or ./esnowpea.filler

In place of [map] put a map from the maps folder

For example:
`./filler_vm -p1 players/carli.filler -p2 ./esnowpea.filler -f maps/map02`

A visualizer is present, but it only works on macos.
To run it, you need to pipe the output of the previous command to the `./vs` executable

For example:
`./filler_vm -p1 players/carli.filler -p2 ./esnowpea.filler -f maps/map02 | ./vs`

GOOD FIGHT!!
