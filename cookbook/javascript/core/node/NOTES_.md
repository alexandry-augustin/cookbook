---
title: Node.js
author: 
date: 
url: 
---

[[wiki]](https://en.wikipedia.org/wiki/Node.js) [[github]](https://github.com/nodejs/node)

# Installation

```bash
sudo apt-get install nodejs
sudo dnf install nodejs
```

# Usage

```bash
node [file.js]
```

# Flags

- `-v`: version
- `-e, --eval string`: 
- `-p, --print string`: same as `-e` but prints the result
- `-i, --interactive`: interactive

# REPL

`node`

`.help`:

`.break`: Sometimes you get stuck, this gets you out

`.clear`: Alias for .break

`.editor`: Enter editor mode

`.load`: Load JS from a file into the REPL session

`.save`: Save all evaluated commands in this REPL session to a file

`.exit`: Exit the REPL