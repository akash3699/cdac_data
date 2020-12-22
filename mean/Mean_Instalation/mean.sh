#!/bin/bash


if [ $EUID -ne 0 ]
then
        echo "Please execute this script as root --- sudo"
        exit 1
fi

echo "You are authorized to run this script now ..."


tar -xvf ~/node_modules.tar.xz -C /usr/local/lib
if [ $? -ne 0 ]
then
        echo "***********************************************************************"
        echo "Extracting node modules failed."
        echo "***********************************************************************"
        exit
fi

if [ -d /usr/local/lib/node_modules ]
then

ln -s /usr/local/lib/node_modules/@angular/cli/bin/ng /usr/local/bin/
if [ $? -ne 0 ]
then
        echo "***********************************************************************"
        echo "Link creation - ng  failed."
        echo "***********************************************************************"
        exit
fi
chmod +x /usr/local/lib/node_modules/@angular/cli/bin/ng

ln -s /usr/local/lib/node_modules/nodemon/bin/nodemon.js /usr/local/bin/nodemon
if [ $? -ne 0 ]
then
        echo "***********************************************************************"
        echo "Link creation - nodemon.js  failed."
        echo "***********************************************************************"
        exit
fi
chmod +x /usr/local/lib/node_modules/nodemon/bin/nodemon.js

ln -s /usr/local/lib/node_modules/typescript/bin/tsc /usr/local/bin/
if [ $? -ne 0 ]
then
        echo "***********************************************************************"
        echo "Link creation - tsc  failed."
        echo "***********************************************************************"
        exit
fi
chmod +x /usr/local/lib/node_modules/typescript/bin/tsc

ln -s /usr/local/lib/node_modules/typescript/bin/tsserver /usr/local/bin/
if [ $? -ne 0 ]
then
        echo "***********************************************************************"
        echo "Link creation - tsserver  failed."
        echo "***********************************************************************"
        exit
fi
chmod +x /usr/local/lib/node_modules/typescript/bin/tsserver

else
	echo "first copy node modules into /usr/local/lib directory..."
fi



