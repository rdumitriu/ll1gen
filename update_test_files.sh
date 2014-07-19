#!/bin/sh

BLDD=../ll1gen-build
INSTD=$BLDD/ll1gen-home
TMPD=$INSTD/tmp

if [ ! -d $BLDD ]
then
  mkdir $BLDD
  cmake $BLDD
fi

rm -rf $TMPD

cwd=`pwd`
cd $BLDD
make
make install
cd $cwd

mkdir $TMPD

$INSTD/bin/ll1gen -h $INSTD -f doc/test1.txt -d $TMPD
$INSTD/bin/ll1gen -h $INSTD -f doc/test2.txt -d $TMPD

echo Copying hellobean ...
cp $TMPD/hellobean.hpp test/
cp $TMPD/test2simple.hpp test/
cp $TMPD/test2multi.hpp test/
