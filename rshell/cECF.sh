#!/bin/bash

echo $1

if [ "$#" == 0 ];then
	echo "ERROR: you didnt enter a class name"
	echo "usage: ./scriptname.sh <Myclass_name>"
else
	touch $1.cc
	touch $1.hh

	echo "#ifndef $1_hh">>$1.hh
	echo "#define $1_hh">>$1.hh
	echo "">>$1.hh
	echo "class $1">>$1.hh
	echo "{">>$1.hh
	echo "">>$1.hh
	echo "public:">>$1.hh
	echo "	$1();">>$1.hh
	echo "	~$1();">>$1.hh
	echo "">>$1.hh
	echo "private:">>$1.hh
	echo "">>$1.hh
	echo "">>$1.hh
	echo "};">>$1.hh
	echo "#endif">>$1.hh

	
	echo "#include \"$1.hh\"">>$1.cc
	echo "">>$1.cc
	echo "$1::$1()">>$1.cc
	echo "{}">>$1.cc
	echo "">>$1.cc
	echo "$1::~$1()">>$1.cc
	echo "{}">>$1.cc

fi
