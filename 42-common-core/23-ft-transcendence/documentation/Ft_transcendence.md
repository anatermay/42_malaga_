
## Mandatory Part
#### README.md 
- README.md file
	- comprehensive README.md file.
#### General requirements
-  The project must be a web application, and requires a frontend, backend, and a database.
-  Git must be used with clear and meaningful commit messages. The repository must show: 
	- Commits from all team members. 
	- Clear commit messages describing the changes. 
	- Proper work distribution across the team
- Deployment must use a containerisation solution (Docker, Podman, or equiva- lent) and run with a single command.
- No warnings or errors should appear in the browser console.
- The project must include accessible Privacy Policy and Terms of Service pages with relevant content.
	- GDPA rules should apply
	- Privacy Policy and Terms of Service: These pages will be verified during evaluation. They must: 
		- Be easily accessible from the application (e.g., footer links). GDPA dictates within 2 clicks
		- Contain relevant and appropriate content for your project.
		- Not be placeholder or empty pages.
	- Missing or inadequate Privacy Policy/Terms of Service pages will result in project rejection
- Multi-user Support (Mandatory): Your website must support multiple users simultaneously. This is a core requirement of the project. Users should be able to interact with the application at the same time without conflicts or performance issues. This includes:
	- Multiple users can be logged in and active at the same time. 
	- Concurrent actions by different users are handled properly. 
	- Real-time updates are reflected across all connected users when applicable. 
	- No data corruption or race conditions occur with simultaneous user actions.
#### Technical requirements
-  A frontend that is clear, responsive, and accessible across all devices. 
- Use a CSS framework or styling solution of your choice (e.g., Tailwind CSS, Bootstrap, Material-UI, Styled Components, etc.).
- Store credentials (API keys, environment variables, etc.) in a local .env file that is ignored by Git, and provide an .env.example file.
- The database must have a clear schema and well-defined relations.
- Your application must have a basic user management system. Users must be able to sign up and log in securely:
	- At minimum: email and password authentication with proper security (hashed passwords, salted, etc.). 
	- Additional authentication methods (OAuth, 2FA, etc.) can be implemented via modules.
- All forms and user inputs must be properly validated in both the frontend and backend.
- For the backend, HTTPS must be used everywhere

> What is a Framework? For this project, a framework is defined as a comprehensive tool that provides: • A structured architecture and conventions for organising code. • Built-in features for common tasks (routing, state management, etc.). • A complete ecosystem of tools and libraries. Examples: • Frontend frameworks: React, Vue, Angular, Svelte, Next.js (these are frameworks). • Backend frameworks: Express, Fastify, NestJS, Django, Flask, Ruby on Rails. • Not frameworks: jQuery (library), Lodash (utility library), Axios (HTTP client). Note: React is considered a framework in this context due to its ecosystem and architectural patterns, even though it is technically a library.

## Modules
You will need to earn 14 points in total to complete your project. Each major module is worth 2 points, and each minor module is worth 1 point.

### Gaming and user experience (8 Points)
#### Major 1 - Game
Implement a complete web-based game where users can play against each other. 
- The game can be real-time multiplayer (e.g., Pong, Chess, Tic-Tac-Toe, Card games, etc.).  TopTrunks Game!!!
- Players must be able to play live matches.
- The game must have clear rules and win/loss conditions.
- The game can be 2D or 3D. (2D)
#### Major 2 - Remote players
Remote players — Enable two players on separate computers to play the same game in real-time. 
- Handle network latency and disconnections gracefully. (have 30s countdown before abandon game)
- Provide a smooth user experience for remote gameplay.
- Implement reconnection logic. (has to reconnect within 30 sec)
#### Major 3 - Multiplayer
Multiplayer game (more than two players). 
- Support for three or more players simultaneously.
- Fair gameplay mechanics for all participants.
- Proper synchronisation across all clients

#### Minor 1 - Game customisation
Game customisation options.
 - Power-ups, attacks, or special abilities.
 - Different maps or themes.
	 - Player can select Custom Deck (coalitions) or playmat backgroung
 - Customisable game settings.
	 - default (all cards must be won)
	 - Round based (best of n rounds)
	 - First to Win n rounds
 - Default options must be available.
#### Minor 2 - Gamification system 
A gamification system to reward users for their actions.
- Implement at least 3 of the following: achievements, badges, leaderboards, XP/level system, daily challenges, rewards
	- XP/Level, Rewards (decks & Customisation), Achievements
- System must be persistent (stored in database)
- Visual feedback for users (notifications, progress bars, etc.)
- Clear rules and progression mechanics


### Web ( 4 Points)
#### Major - Framework Front & Backend
Use a framework for both the frontend and backend. 
- Use a frontend framework (React, Vue, Angular, Svelte, etc.).
- Use a backend framework (Express, NestJS, Django, Flask, Ruby on Rails, etc.).
- Full-stack frameworks (Next.js, Nuxt.js, SvelteKit) count as both if you use both their frontend and backend capabilities
#### Minor - Custom-made design system
Custom-made design system with reusable components, including a proper color palette, typography, and icons (minimum: 10 reusable components).

#### Minor - Search system (search your cards?)
Implement advanced search functionality with filters, sorting, and pagination

#### Major 3 - API (OHH MAYBE NO)
A public API to interact with the database with a secured API key, rate limiting, documentation, and at least 5 endpoints: 
- GET /api/{something} 
- POST /api/{something} 
- PUT /api/{something} 
- DELETE /api/{something}

### Accessibility and Internationalisation ( 1 - 2 Points)
#### Minor - Language (Spanish, English, German)
Support for multiple languages (at least 3 languages).
- Implement i18n (internationalization) system. 
- At least 3 complete language translations. 
- Language switcher in the UI. 
- All user-facing text must be translatable.

#### Minor - Additional browser support
Support for additional browsers.
- Full compatibility with at least 2 additional browsers (Firefox, Safari, Edge, etc.).
- Test and fix all features in each browser.
- Document any browser-specific limitations.
- Consistent UI/UX across all supported browsers.
### User Management (2 - 4 Points)
#### Minor - Game stats & History
Game statistics and match history (requires a game module).
- Track user game statistics (wins, losses, ranking, level, etc.).
- Display match history (1v1 games, dates, results, opponents).
- Show achievements and progression. 
- Leaderboard integration
#### Minor - 2.0 Auth (Have to be in 42 to play??)
Implement remote authentication with OAuth 2.0 (Google, GitHub, 42, etc.).
#### Minor - 2FA
Implement a complete 2FA (Two-Factor Authentication) system for the users
#### Minor - Activity & Analytics (maybe)
User activity analytics and insights dashboard.

### AI (2 Points)
#### Major - AI opponent
Introduce an AI Opponent for games.
- The AI must be challenging and able to win occasionally. 
- The AI should simulate human-like behaviour (not perfect play).
- If you implement game customisation options, the AI must be able to use them. 
	- Can choose deck / play mat  Background
- You must be able to explain your AI implementation during evaluation.
### Devops ()

### Data and Analytics (1 Point)
#### Minor 1 - GDPR features
GDPR compliance features.
- Allow users to request their data.
- Data deletion with confirmation. 
- Export user data in a readable format.
- Confirmation emails for data operations


