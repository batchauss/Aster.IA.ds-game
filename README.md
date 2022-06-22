<div align="center">
	<h1> Aster.ia.ds </h1>

<p align="center">
	Jeu-vidéo - Interface graphique - IA - Rendu 3D
</p>

[![Debian based build](https://github.com/pci-ua/Aster.ia.ds/actions/workflows/debian-build.yml/badge.svg?branch=main)](https://github.com/pci-ua/Aster.ia.ds/actions/workflows/debian-build.yml)

<h2 size="1" margin="0"><h6>⠀</h6></h2>
	
</div>

Basé sur le jeu des années 80 
[Asteroids](https://fr.wikipedia.org/wiki/Asteroids) ,
Aster.ia.ds est un remake de ce dernier fait par des étudiants pour des étudiants, avec de multiples ajouts :

 - Un système d'IA, pour créer et testé son IA.
 - Un jeu en 3D, avec un moteur graphique custom, utilisant OpenGL
 - Un multijoueur pour joué 
Votre objectif sera de réaliser un jeu multicontre et avec d'autres joueurs.

## Table des matières
 - [⚙️ Installation ⚙️](#installation)
 - [📄 Spécifications 📄](#spécifications)
 - [💪 Contribuer 💪](#contribuer)
 - [🛣️ Roadmap 🛣️](#roadmap)
 - [Une question ❓](#une-question-)

## Installation


### Debian, Ubuntu, _et similaire_ 

<img
	src="https://upload.wikimedia.org/wikipedia/commons/9/9e/UbuntuCoF.svg"
	height="20"/>
<img
	src="https://upload.wikimedia.org/wikipedia/commons/4/4a/Debian-OpenLogo.svg"
	height="20"/>
<img
	src="https://upload.wikimedia.org/wikipedia/fr/3/3b/Raspberry_Pi_logo.svg"
	height="20"/>

Télécharger l'archive `Aster.ia.ds.deb` de la dernière release, puis :
```bash
unzip Aster.ia.ds.deb.zip
sudo apt install "<chemin/vers/le/fichier/.deb/extrait>"
```
_Tous les systèmes qui hérite de debian supporte cette installation, liste complète [ici](https://upload.wikimedia.org/wikipedia/commons/1/1b/Linux_Distribution_Timeline.svg)._

Pour lancer le jeu : `Aster.ia.ds` 

### Autre OS Linux
Demander à `contact@projetcohesion` ou créer une issue sur ce repository pour obtenir une version compatible.

### Windows
Une version windows 10 et 11 est prévu dans le futur, soyez patient.

Aucune version n'est prévue pour les OS déprécié comme Windows 7 et antérrieur.

Pour Windows 8, une version du jeu sera proposé si d'ici là l'OS n'est pas déprécié.

### MacOS
Pour l'instant aucune version mac n'est prévu.

## Spécifications

### Technologies

 - c++
 - Qt
 - OpenGL / GLU / GLUT
 - git

## Roadmap

 - [x] Création, préparation et maturation par [PC[i]](https://projetcohesion.info)
 - [x] Discussion avec des enseignants de la L3 informatique de l'[UA](https://www.univ-angers.fr), pour l'organisation d'un stage sur le sujet.
 - [x] Développement initial par des étudiants en L3 dans le cadre de leurs stages de fin d'année,il sera encadré par l'association [PC[i]](https://projetcohesion.info) et durera 8 semaines.
 - [ ] Reprise du projet par `PC[i]` en interne pour rajouter des fonctionnalités manquantes et préparer le déploiement
 - [ ] Première pré-release réservée aux membres de PC[i] et aux étudiants ayant contribués (aux environs de Juillet 2022)
 - [ ] Déploiement de la première release (Première date de sortie espérée aux environs de début Aout 2022)

## Contribuer

N'hésitez surtout pas à venir participer à ce projet, toutes les informations sont disponibles [ici](CONTRIBUTING.md)

## Une question ❓

N'hésite pas à envoyer un mail à contact@projetcohesion.info

Ou [à venir nous voir](https://projetcohesion.info/a-propos/#bureau) on est souvent dans le batiment H (H001/2/3/7)


Le but de ce stage est de fournir un contenu de base que l'association [PC[i]](https://projetcohesion.info) pourra enrichir avec quelques fonctionnalités supplémentaires telle que l'aspect multijoueur ou la gestion des IA, des cosmétiques etc. Pour ensuite déployer ce projet et permettre à tout étudiant de jouer ou de créer son IA sur le jeu.


<hr/>
*[IPSI]: Initiation à la Programmation de Systèmes Intelligents <br/>
*[TDPy]: Traitement de données en Python <br/>
*[SI]: Synthèse d’images <br/>
*[DIGA]:  Développement d’Interfaces Graphiques Avancées <br/>
