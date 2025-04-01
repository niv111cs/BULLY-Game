
# Bully & Dov – A Grid-Based Chase Simulation in C

This project is a console-based game written in **C**, simulating a strategic chase between two characters on a 100x100 grid-based board. The player controls **Bully ('B')**, whose goal is to collect all accessible points ('.') on the board while avoiding being caught by **Dov ('D')**, who automatically chases Bully each turn.

### How It Works

- The game begins with an empty grid surrounded by safety walls (`*`), and the user can define additional custom walls.
- The user sets initial positions for both Bully and Dov.
- On each turn:
  - The player chooses a direction for Bully to move (right, left, up, down).
  - Dov automatically moves one step diagonally or straight toward Bully.
- Every time Bully steps on a point (`.`), the score decreases.
- The game ends when either:
  - Bully steps on all available points → **Bully wins**.
  - Dov catches Bully (both occupy the same cell) → **Bully loses**.

### Technical Highlights

- Written entirely in standard **C (ANSI C)**.
- Implements:
  - Manual wall placement.
  - Grid visualization in the console.
  - Simulated character movement and path-tracking.
  - Real-time input/output using `scanf` and `printf`.
  - Structured modular functions with clear documentation.

### Educational Value

This project demonstrates:
- Use of 2D arrays to model environments.
- Real-time interaction in terminal applications.
- Low-level memory manipulation and pointer usage.
- Implementation of basic AI-like behavior (Dov’s movement logic).

It's a simple, logic-driven game showcasing structured C programming with a creative and interactive twist.
