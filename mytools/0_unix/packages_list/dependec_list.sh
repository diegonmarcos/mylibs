#!/bin/bash

#apt list --installed | awk '/\/installed$/ { print $1 }'
apt list --installed
apt list --installed  > installed_packages_apt.txt

pip list
pip freeze > installed_packages_pip.txt

snap list
snap list > installed_packages_snap.txt

flatpak list
flatpak list > installed_packages_flatpak.txt

apt-mark showmanual > installed_packages_apt_mark.txt