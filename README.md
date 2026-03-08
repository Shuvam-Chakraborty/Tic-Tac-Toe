# ❌ Tic Tac Toe

A 2-player terminal-based Tic Tac Toe game built in **C**, developed with Dev-C++ on Windows.

---

## 🎮 Features

- 2-player local multiplayer with custom names
- Animated welcome screen with loading delay
- Live 3×3 board redrawn each turn
- Win/draw detection across all rows, columns, and diagonals
- Color-coded result screen + `.wav` sound effects on win/draw
- Invalid move handling without losing a turn

---

## 🕹️ Controls

```
Board positions:
 1 | 2 | 3
 4 | 5 | 6
 7 | 8 | 9
```
Each player types a number (1–9) to place their mark. Player 1 → `X`, Player 2 → `O`.

---

## 🗂️ Files

| File | Description |
|------|-------------|
| `Tic Tac Toe Game 3 by 3.c` | Main source file |
| `Tic Tac Toe Game.dev` | Dev-C++ project file |
| `Makefile.win` | Build configuration |

---

## 🔧 Build & Run

Open `Tic Tac Toe Game.dev` in **Dev-C++ 5.11** and press **F11**, or build via:

```bash
mingw32-make -f Makefile.win
```

> ⚠️ **Windows only** — requires `winmm.lib` for sound and `<conio.h>` / `<windows.h>`. Update the `.wav` paths in the source before building.
