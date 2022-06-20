<div align="center">
	<h1> Aster.ia.ds </h1>

<p align="center">
	Jeu-vidéo - Interface graphique - IA - Rendu 3D
</p>

![Debian based build](https://github.com/pci-ua/Aster.ia.ds/actions/workflows/debian-build.yml/badge.svg)

<h2 size="1" margin="0"><h6>⠀</h6></h2>
	
</div>
Basé sur le jeu des années 80 [Asteroids](https://fr.wikipedia.org/wiki/Asteroids),
Aster.ia.ds est un remake de ce dernier avec des technologies vues en cours.

Votre objectif sera de réaliser un jeu multijoueur en 3D. Une liste d'objectifs initiaux seront fournis puis des fonctionnalités seront demandées en fonction du besoin et de l'avancement du projet, par le client.

Le but de ce stage est de fournir un contenu de base que l'association [PC[i]](https://projetcohesion.info) pourra enrichir avec quelques fonctionnalités supplémentaires telle que l'aspect multijoueur ou la gestion des IA, des cosmétiques etc. Pour ensuite déployer ce projet et permettre à tout étudiant de jouer ou de créer son IA sur le jeu.

## Table des matières
1. [Compilation et exécution](#compilation-et-exécution)
2. [Pourquoi nous ? 🤔](#pourquoi-nous--)
3. [Technologies](#technologies)
4. [Méthodologie](#méthodologie)
5. [Étapes](#étapes)
6. [Contenu attendu](#contenu-attendu)
7. [Contenu suplémentaire](#contenu-suplémentaire)
8. [Une question ❓](#une-question-)

## Compilation et exécution

Afin de pouvoir lancer le jeu il faut se rendre dans le
dossier Projet puis effectuer les commandes "qmake",
ensuite "make" puis lancer l'exécutable "./Aster.IA.ds" 

## Pourquoi nous ? 🤔

 Un projet avec une réelle application derrière, et orienté jeux-vidéo.
 Qui met en application tes cours. Encadré par des étudiants.
 Avec une certaine liberté dans les choix.

## Technologies

 - c++
 - Qt
 - OpenGL / GLU / GLUT
 - git

Les étudiants pourront utiliser des technologies supplémentaires en fonction de leurs envies, de leurs cohérences avec le projet ainsi que de l'expertise de leur tuteur.

## Méthodologie

Le stage se déroulera avec une méthode agile dont la durée des sprints et leurs contenus varieront en fonction de l'avancement du projet. 

## Étapes

 - Création, préparation et maturation par [PC[i]](https://projetcohesion.info)
 - Dépôt du projet auprès des enseignants qui gèrent la L3 à l'Université d'Angers
 - **Développement initial par des étudiants en L3 dans le cadre de leur stage de fin d'année,il sera encadré par l'association [PC[i]](https://projetcohesion.info)** (8 semaines minimum)
 - Reprise du projet par PC[i] en interne pour rajouter des fonctionnalités manquantes et préparer le déploiement
 - Première pré-release réservée aux membres de PC[i] et aux étudiants ayant contribués (aux environs de Juillet 2022)
 - Déploiement de la première release (Première date de sortie espérée aux environs de début Aout 2022)
 
## Contenu attendu

  - Une interface graphique comportant :
    - Un menu
    - Le jeu en 3D :
		- astéroïdes
		- adversaires
		- une interface utilisateur avec différentes informations (ex: vitesse, vie,...)
    - Une fenêtre de résultat
  - Des éléments viendront à être rajoutés par le client au fur et à mesure.
  - Un code qui compile sans erreur.

## Contenu suplémentaire

Voici quelques pistes de ce qui pourraient être demandé une fois la première partie achevée.

#### 🎮 Axe Jeu Vidéo :
*Si vous avez fait SI et/ou DIGA, cette partie peut vous intéresser*

 - Résultat :
 	La fenêtre de résultat de base ne doit rendre qu'un classement des joueurs et si l'on a perdu ou gagné
 	mais pourquoi ne pas pousser plus loin l'interface et ajouter un graphique de l'évolution des scores des joueurs dans la partie	ou toutes autres données du jeu qui seraient pertinentes.


 - Paramètre et option :
 	Un système de configuration de paramètre telle que la qualité de rendu, sans éditer le code ou un fichier de configuration
	directement dans l'interface serait un énorme atout au jeu.
   
   
#### 🧠 Axe Intelligence artificiel :
*Si vous avez fait IPSI et/ou TDPy, cette partie peut vous intéresser*

Les ennemis sont pour l'instant des scripts de base,
mais il serait intérressant d'implémenter les algo d'IA que vous avez pu apprendre durant votre cursus.

Et peut-être, réaliser plusieurs IA avec plusieurs méthodes pour les comparer ou faire différentes difficultés.
À vous de voir ce que vous pouvez et voulez faire.

## Une question ❓

N'hésite pas à envoyer un mail à contact@projetcohesion.info

Ou [à venir nous voir](https://projetcohesion.info/a-propos/#bureau) on est souvent dans le batiment H (H001/2/3/7)


<hr/>
*[IPSI]: Initiation à la Programmation de Systèmes Intelligents <br/>
*[TDPy]: Traitement de données en Python <br/>
*[SI]: Synthèse d’images <br/>
*[DIGA]:  Développement d’Interfaces Graphiques Avancées <br/>
