# bataille_navale en C
Battleship game

## Description
Le jeu de bataille navale est un jeu de stratégie classique où deux adversaires essaient de couler les navires de l'autre en devinant leurs emplacements sur une grille. Ce projet implémente une version simple de la bataille navale en langage C, où un joueur affronte l'ordinateur. Le joueur doit entrer des coordonnées pour attaquer les navires cachés de l'ordinateur, et l'ordinateur attaque à son tour aléatoirement.

Le projet comprend plusieurs fonctionnalités intéressantes, telles que la sélection du niveau de difficulté, une gestion simple des attaques, et des conditions de victoire/défaite.

## Fonctionnalités
* Grille de jeu 6x6 : Le jeu se déroule sur une grille de 6x6, où les navires sont placés aléatoirement.
* Attaque tour par tour : Le joueur et l'ordinateur jouent tour à tour. Le joueur entre les coordonnées d'attaque, et l'ordinateur attaque aléatoirement une position de la grille du joueur.
* Victoire et défaite : Le jeu se termine lorsqu'un joueur touche tous les navires de son adversaire.
* Niveaux de difficulté :  
  `* Facile : 10 tours maximum pour chaque joueur`  
  `* Moyen : 7 tours maximum`   
  `*Difficile : 5 tours maximum `  
* Indicateurs visuels :   
    `* ~ :  Eau (zone non touchée) `  
    `* X : Navire touché `  
    `* O : Coup manqué `  


# Installation et utilisation
## Prérequis
* Un compilateur C comme GCC ou Clang.
* Un terminal (sous Linux ou Mac) ou un outil de ligne de commande (CMD ou PowerShell sous Windows).

# Utilisation du programme
1. Lorsque vous lancez le programme, on vous demande de choisir un niveau de difficulté :

* 1 : Facile (10 tours)
* 2 : Moyen (7 tours)
* 3 : Difficile (5 tours)
Entrez le numéro correspondant au niveau de difficulté souhaité.
2. Ensuite, le jeu commence avec une grille de 6x6. À chaque tour :

* Le joueur entre les coordonnées d'attaque (par exemple 2 3).
* L'ordinateur attaque automatiquement une position aléatoire sur la grille du joueur.

3. Objectif : Trouvez et coulez tous les navires de l'ordinateur avant qu'il ne coule les vôtres.

## Améliorations futures possibles
* Ajouter plusieurs types de navires avec des tailles différentes.
* Implémenter un mode multijoueur.
* Ajouter une interface graphique pour améliorer l'expérience utilisateur.
* Permettre au joueur de choisir où placer ses navires.

## Contributions
Les contributions sont les bienvenues ! Si vous avez des suggestions ou des corrections, n'hésitez pas à soumettre un pull request ou à ouvrir une issue sur GitHub.
