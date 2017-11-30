#!/bin/bash

set -e

readonly FILE_MATRICE='file_matrice'
readonly FILE_VETTORE='file_vettore'
readonly BINDIR='bin'


rm -f -v ${FILE_MATRICE}
rm -f -v ${FILE_VETTORE}
printf "\nEseguo il Makefile!\n\n" ; 

make
echo "                                                     ____  ____   ___   ___            ____   __ __                                 ";
echo "                                                    |    \|    \ /   \ |   \          |    \ |  |  |                                ";
echo "                                                    |  o  )  D  )     ||    \         |  o  )|  |  |                                ";
echo "                                                    |   _/|    /|  O  ||  D  |        |     ||  ~  |                                ";
echo "                                                    |  |  |    \|     ||     | __     |  O  ||___, |                                ";
echo "                                                    |  |  |  .  \     ||     ||  |    |     ||     |                                ";
echo "                                                    |__|  |__|\_|\___/ |_____||__|    |_____||____/                                 ";
echo "                                                                                                                                    ";
echo "                                     ____    ___   ____        _____  ___   ____    ___       ____     ___  _      _       ___      ";
echo "                                    |    \  /   \ |    \      / ___/ /   \ |    \  /   \     |    \   /  _]| |    | |     /   \     ";
echo "                                    |  _  ||     ||  _  |    (   \_ |     ||  _  ||     |    |  o  ) /  [_ | |    | |    |     |    ";
echo "                                    |  |  ||  O  ||  |  |     \__  ||  O  ||  |  ||  O  |    |     ||    _]| |___ | |___ |  O  |    ";
echo "                                    |  |  ||     ||  |  |     /  \ ||     ||  |  ||     |    |  O  ||   [_ |     ||     ||     |    ";
echo "                                    |  |  ||     ||  |  |     \    ||     ||  |  ||     |    |     ||     ||     ||     ||     |    ";
echo "                                    |__|__| \___/ |__|__|      \___| \___/ |__|__| \___/     |_____||_____||_____||_____| \___/     ";
echo "                                                                                                                                    ";
echo "                                                 ___ ___   ____      ____   ____  ______   __  __ __   ___                          ";
echo "                                                |   |   | /    |    |    \ /    ||      | /  ]|  |  | /   \                         ";
echo "                                                | _   _ ||  o  |    |  o  )  o  ||      |/  / |  |  ||     |                        ";
echo "                                                |  \_/  ||     |    |   _/|     ||_|  |_/  /  |  _  ||  O  |                        ";
echo "                                                |   |   ||  _  |    |  |  |  _  |  |  |/   \_ |  |  ||     |                        ";
echo "                                                |   |   ||  |  |    |  |  |  |  |  |  |\     ||  |  ||     |                        ";
echo "                                                |___|___||__|__|    |__|  |__|__|  |__| \____||__|__| \___/                         ";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";
echo "                                                                                    Andrea Straforini  Andrea Storace  Elisa Zazzera";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";
echo "                                                                                                                                    ";

${BINDIR}/main.out
