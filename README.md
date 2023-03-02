# MINISHELL

## Table of Contents

1. [Instalation](#instalation)
2. [Errors](#errors)

## Instalation 

```bash
git clone https://github.com/eliaszanotti/minishell.git
```

To install minishell you just have to clone the project and run the following command:

```c
make
```

## Errors

**[ERROR:2]** Command not found

**[ERROR:3]** Parse error (quote not closed)

**[ERROR:4]** Parse error on pipe

**[ERROR:5]** Syntax error on redirect

**[ERROR:6]** Parse error at end of command

**[ERROR:10]** Failed to create fork

**[ERROR:11]** Failed to pipe fd

**[ERROR:12]** Failed to execute command

**[ERROR:13]** Failed to duplicate fd (dup2 error)

**[ERROR:14]** Can't open file

**[ERROR:15]** Can't create file

**[ERROR:20]** No such file or directory

**[ERROR:99]** Malloc cannot be created

## Bonnes pratiques

Toujours nommer les fonctions avec comme prefix ft (ex: ft\_function, ft\_print)

Bien penser a creer une branche pour chaque features creee 

Trier les protypes de fonctions par ordre alphabetique

Commenter //TODO pour les features a mettre en place
