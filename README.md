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
	alt="Ubuntu"
	height="20"/>
<img
	src="https://upload.wikimedia.org/wikipedia/commons/4/4a/Debian-OpenLogo.svg"
	alt="Debian"
	height="20"/>
<img
	src="https://upload.wikimedia.org/wikipedia/fr/3/3b/Raspberry_Pi_logo.svg"
	alt="Rasp OS"
	height="20"/>

Télécharger l'archive `Aster.ia.ds.deb` de la dernière release, puis :
```bash
unzip Aster.ia.ds.deb.zip
sudo apt install "<chemin/vers/le/fichier/.deb/extrait>"
```
_Tous les systèmes qui héritent de debian supportent cette installation, liste complète [ici](https://upload.wikimedia.org/wikipedia/commons/1/1b/Linux_Distribution_Timeline.svg)._

Pour lancer le jeu : `Aster.ia.ds` 

### Autre OS Linux

<img
	src="https://upload.wikimedia.org/wikipedia/commons/7/74/Arch_Linux_logo.svg"
	alt="Arch Linux"
	height="20"/>

Demander à `contact@projetcohesion` ou créer une issue sur ce repository pour obtenir une version compatible.

### Windows
Une version windows 10 et 11 est prévue dans le futur, soyez patient.

Aucune version n'est prévue pour les OS dépréciés comme Windows 7 et versions antérieures.

Pour Windows 8, une version du jeu sera proposée si d'ici là l'OS n'est pas déprécié.

### MacOS
Pour l'instant aucune version mac n'est prévue.

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
 - [ ] Reprise du projet par `PC[i]` en interne pour corriger quelques problèmes
 - [ ] Reprise du projet par les étudiants pour :
   - [ ] Multijoueur
   - [ ] Interface d'e création d'IA
   - [ ] Discord Rich Presence
 - [ ] Première pré-release réservée aux membres de PC[i] et aux étudiants ayant contribués (aux environs de Juillet 2022)
 - [ ] Déploiement de la première release (Première date de sortie espérée aux environs de début Aout 2022)

Pour suivre l'avancer du projet dans les détails : [Roadmap en ligne d'Aster.ia.ds](https://pci.leria-etud.univ-angers.fr/aster.ia.ds/dev/).

## Contribuer

N'hésitez surtout pas à venir participer à ce projet, toutes les informations sont disponibles [ici](CONTRIBUTING.md)

## Une question ❓

N'hésite pas à envoyer un mail à contact@projetcohesion.info

Ou [à venir nous voir](https://projetcohesion.info/a-propos/#bureau) dans le rez-de-chaussé du batiment H de l'UA. ( [GMap](https://www.google.com/maps/place/Facult%C3%A9+des+Sciences,+2+Bd+de+Lavoisier,+49000+Angers/@47.4805015,-0.6000928,17z/data=!3m1!4b1!4m5!3m4!1s0x48087f1bc2f35b47:0xe3ea8379948a1e65!8m2!3d47.4805015!4d-0.6000928) , [Plan du site](https://math.univ-angers.fr/wp-content/uploads/2018/08/plancampus.gif))


