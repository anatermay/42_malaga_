---
date: 2025-12-13
tags:
  - Game-UX
  - MainFeature
Module: Game
---
## Description
Default game has 30 cards and runs with 2 players

## Related Topics
- Remote players
- Multiplayer
- Customisation
- Gamification
## To Do List
- [ ] Create random deck at start
	- [ ] Base the Deck card choice based on Level Select
		- [ ] This can relate to Campus Deck choice as well
- [ ] Create Card statistics (3 - 6)
	- [ ] if we do (# GET /v2/campus/:campus_id/users) we get all the users of a specific campus 
		- this gives us less info:
			- login / name
			- Photo
			- Correction points
			- Pool year and month
			- Wallet 
			- These stats are minimal viable product 
	- [ ] Level -> Highest wins
	- [ ] # of Achievements -> Highest wins
	- [ ] Time started 42 -> lowest wins
	- [ ] # of Correction points -> Highest wins
	- [ ] Wallet -> Highest wins
- [ ] Game Logic
	- [ ] Select a dealer (If a game is hosted its the host)
		- [ ] start left of dealer
	- [ ] Player select card attribute
		- [ ] all players reveal cards after selection (with stat highlighted)
		- [ ] Based on stat of all cards decide who won the round
			- [ ] In case of Draw place cards in the center pile
			- [ ] Last player to choose gets to select a category from their next card
		- [ ] Winner of rounds adds the won cards to the bottom of their deck
			- [ ] if previous round was a draw this includes the cards in the middle of the table
	- [ ] If a player has no cards left they are out of the game (can spectate on 3 or > player)
	- [ ] If a player has all cards they win the
## Issues & concerns
- List issues or concerns that we need to handle 

## Code Snippets
Add core code or example code here (Change this to name or function)

```


```

## Log
- Please write a log of what changes where done (same as git commits)

