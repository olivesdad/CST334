#!/bin/bash 

# Name: Andrew Shiraki
# Date: 2021-03-02
# Title: Lab1 - task
# Description: This program has 3 blocks:
# Block1: Prints out the home directory, usersname, path and current directory, then checks if the users is me. If the user is not me the program terminates
# Block2: Calculates the area of a rectangle requieres user to input "No" to proceed
# Block3: Calculates the area of a circle given radius. Requiers user to input "No" at the end to terminate

echo Executing $0 
echo $(/bin/ls | wc -l) files 
wc -l $(/bin/ls) 
echo "HOME="$HOME 
echo "USER="$USER 
echo "PATH="$PATH 
echo "PWD="$PWD 
echo "\$\$"=$$ 
user=`whoami` 
numusers=`who | wc -l` 
echo "Hi $user! There are $numusers users logged on." 
if [ $user = "shir5019" ] 
then 
	echo "Now you can proceed!" 
else 
	echo "Check who logged in!" 
	exit 1 
fi 


response="Yes"
while [ $response != "No" ]
do
	echo "Enter height of rectangle: "
	read height
	echo "Enter width of rectangle: "
	read width
	area=`expr $height \* $width`
	echo "The area of the rectangle is $area"
	echo "Would you like to repeat for another rectangle [Yes/No]?"
	read response
done

response="Yes"
while [ $response != "No" ]
do
	echo "Enter radius of circle: "
	read rad
	area=$((($rad * $rad)*31415))
	length=$(echo $area | wc -c | xargs)

	echo "The area of the circle is: ${area:0:$(($length - 5))}.${area:$(($length - 5)):4}"
	echo "Would you like to repeat for another rectangle [Yes/No]?"
	read response
done
