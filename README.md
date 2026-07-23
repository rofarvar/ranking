# ranking
A ranking system for international sports. 

Here's a simple C-based international sports ranking, based on the FIFA calculation formula but also includes built-in chess elo and a simple simulation method in the simulate.h library. 
It has a lot of files. I'm sorry.

# Get started

Download the source code or clone the repo. 
Individually compile the match.c, rank.c, and optionally simulator.c and advancedsimulator.c. I recommend the executable names match, rank, sim, and advancedsim respectively for each file, as that's how I'll refer to them here.
* Compilation is not actually necessary as the entire repo comes with the compilated files. However, if you change things like the simulator engine it's highly likely you'll have to recompile.

To load a match:
./match winningTeam losingTeam matchType drawOrNot

example: ./match Brazil Norway round regular
draw example: ./match Spain Cape_Verde group draw
penalties example: ./match Switzerland Colombia round penalties

Types of matches: 
Friendly outside main season: outFriendly
Normal friendly: friendly
League-style group match: championsGroup
World Cup qualifier: qualifier
Round of 32/16/whatever: round
Quarterfinals: quarter
Semifinals, third-place match and finals: finals

Of course you may always edit those as you wish.

To put all teams in the same, allteams plain text file with their respective elos: 
./rank

To simulate a match:
./sim teamA teamB
example: ./sim Brazil Norway
advancedsim example: ./advancedsim Brazil Norway

Want to change the elo math? From the simulate.h library you will find two other functions that you can substitute in for simulate() in the match.c file!

Need help? 
./help
Or refer to this readme. 

Is your team not here? Fork it. That's why this is released with the MIT license. 
This is very simple code, and it was a daylong project for me. However, it does work but if anyone wants to improve it and build onto it, please do!

NO AI was used making this apart from initializing all of the 211 plain text files with a 0 for elo

