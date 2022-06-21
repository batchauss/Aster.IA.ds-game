#!/bin/bash

###
### Configuration
###

# Load configuration
source ../project.toml

# Dynamic configuration
CONF_ARCHITECTURE="$(dpkg --print-architecture)"
DEST_FOLDER="${PROJECT_NAME}_${PROJECT_VERSION}-${PROJECT_REVISION}_${CONF_ARCHITECTURE}"



###
### Build
###

# Setup binary
mkdir $DEST_FOLDER
mkdir -p $DEST_FOLDER/usr/bin/
cp $PROJECT_NAME $DEST_FOLDER/usr/bin/

# Setup info files
mkdir $DEST_FOLDER/debian/
touch $DEST_FOLDER/debian/control
echo "
Source: $PROJECT_NAME
Package: $PROJECT_NAME
Version: $PROJECT_VERSION
Architecture: $CONF_ARCHITECTURE
Maintainer: Mathieu TOULON <contact@projetcohesion.info>
Description: A game devellop for and by student of the University of Angers at PC[i]
 Still in dev be carefull
" > $DEST_FOLDER/debian/control

cd $DEST_FOLDER

dpkg-shlibdeps -O $PROJECT_NAME | sed -e "s/^shlibs:Depends=/Depends:/g" >> $DEST_FOLDER/debian/control

cd ..

cat $DEST_FOLDER/DEBIAN/control

mv $DEST_FOLDER/debian $DEST_FOLDER/DEBIAN

# Setup assets
mkdir -p $DEST_FOLDER/usr/share/Aster.ia.ds/
cp -r models $DEST_FOLDER/usr/share/Aster.ia.ds/
cp -r settings $DEST_FOLDER/usr/share/Aster.ia.ds/
cp -r scores $DEST_FOLDER/usr/share/Aster.ia.ds/
cp -r pic $DEST_FOLDER/usr/share/Aster.ia.ds/

# Generate .deb
dpkg-deb --build --root-owner-group $DEST_FOLDER

# Remove temp folder
rm $DEST_FOLDER -rf

# Print
echo -e "\033[107;30m Package $DEST_FOLDER.deb generated succesfuly ! \033[0m"