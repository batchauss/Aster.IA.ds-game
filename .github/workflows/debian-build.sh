# Conf
CONF_ARCHITECTURE="amd64"
CONF_APP_NAME="Asteriads"
CONF_VERSION="0.0.3"
CONF_REVISION="1"

# Calc
DEST_FOLDER="${CONF_APP_NAME}_${CONF_VERSION}-${CONF_REVISION}_${CONF_ARCHITECTURE}"

# Build package
mkdir $DEST_FOLDER
mkdir -p $DEST_FOLDER/usr/bin/
cp "Aster.IA.ds" $DEST_FOLDER/usr/bin/
mkdir $DEST_FOLDER/DEBIAN/
touch $DEST_FOLDER/DEBIAN/control

echo "
Package: $CONF_APP_NAME
Version: $CONF_VERSION
Architecture: $CONF_ARCHITECTURE
Maintainer: Mathieu TOULON <contact@projetcohesion.info>
Description: A game devellop for and by student of the University of Angers at PC[i]
 Still in dev be carefull
" > $DEST_FOLDER/DEBIAN/control

dpkg-deb --build --root-owner-group $DEST_FOLDER

rm $DEST_FOLDER -rf

echo -e "\033[107;30m Package $DEST_FOLDER.deb generated succesfuly ! \033[0m"