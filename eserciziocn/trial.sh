#!/bin/bash
# Store menu options selected by the user
INPUT=/tmp/menu.sh.$$

# Storage file for displaying cal and date command output
OUTPUT=/tmp/output.sh.$$

# get text editor or fall back to vi_editor
vi_editor=${EDITOR-vi}

# trap and delete temp files
trap "rm $OUTPUT; rm $INPUT; exit" SIGHUP SIGINT SI

# 
function display_output(){
	local h=${1-10}			# box height default 10
	local w=${2-41} 		# box width default 41
	local t=${3-Output} 	# box title 
	dialog --backtitle "non sono bello ma patcho - Laboratorio di Calcolo Numerico" --title "${t}" --clear --msgbox "$(<$OUTPUT)" ${h} ${w}
}

function display_ex1a(){
	./bin/es1a.out > ${OUTPUT}
	display_output 6 50 "Esercizio 1a"
}

function display_ex1b(){
	./bin/es1b.out > ${OUTPUT}
	display_output 50 50 "Esercizio 1b"
}

function display_ex1c(){
	./bin/es1c.out > ${OUTPUT}
	display_output 50 50 "Esercizio 1c"
}

function display_ex2(){
	echo "Il programma seguente non prevede l'interfaccia corrente, ci scusiamo per il disagio" > ${OUTPUT}
	display_output 6 100 "Attenzione" ${OUTPUT}
	clear
	./bin/es2.out
}

while true
do

### display main menu ###
dialog --clear --backtitle "non sono bello ma patcho - Laboratorio di Calcolo Numerico" \
--title "[ M A I N - M E N U ]" \
--menu "You can use the UP/DOWN arrow keys, the first \n\
letter of the choice as a hot key, or the \n\
number keys 1-9 to choose an option.\n\
Choose the TASK" 25 50 14 \
ex1a " Display exercise 1a" \
ex1b " Display exercise 1b" \
ex1c " Display exercise 1c" \
ex2 "Displays exercise 2" \
ex3 "Display exercise 3" \
Exit "Exit to the shell" 2>"${INPUT}"

menuitem=$(<"${INPUT}")


# make decsion 
case $menuitem in
	ex1a) display_ex1a;;
	ex1b) display_ex1b;;
	ex1c) display_ex1c;;
	ex2) display_ex2;;
	ex3) pluma;;
	Exit) echo "grazie per aver scelto non sono bello ma patcho" > ${OUTPUT} ; display_output 5 51 "bye"; break;;
esac

done
clear
# if temp files found, delete em
[ -f ${OUTPUT} ] && rm ${OUTPUT}
[ -f ${INPUT} ] && rm ${INPUT}
