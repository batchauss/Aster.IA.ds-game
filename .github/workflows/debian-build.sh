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
echo \
"Source: $PROJECT_NAME
Maintainer: Mathieu TOULON <contact@projetcohesion.info>
Version: $PROJECT_VERSION
Architecture: $CONF_ARCHITECTURE
Package: $PROJECT_NAME
Description: A game devellop for and by student of the University of Angers at PC[i]
 Still in dev be carefull" \
> $DEST_FOLDER/debian/control

cd $DEST_FOLDER

dpkg-shlibdeps -O usr/bin/$PROJECT_NAME 2> /dev/null | sed -e "s/^shlibs:Depends=/Depends:/g" >> debian/control

mv debian DEBIAN

cd ..


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
