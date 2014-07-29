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
$INSTD/bin/ll1gen -h $INSTD -f doc/test3.txt -d $TMPD
mkdir $TMPD/ex0 2>/dev/null
$INSTD/bin/ll1gen -h $INSTD -f doc/std_test0.txt -d $TMPD/ex0
mkdir $TMPD/ex1 2>/dev/null
$INSTD/bin/ll1gen -h $INSTD -f doc/std_test1.txt -d $TMPD/ex1
mkdir $TMPD/ex2 2>/dev/null
$INSTD/bin/ll1gen -h $INSTD -f doc/std_test2.txt -d $TMPD/ex2

echo Copying hellobean ...
cp $TMPD/hellobean.hpp test/
echo Copying test2simple and test2multi ...
cp $TMPD/test2simple.hpp test/
cp $TMPD/test2multi.hpp test/
echo Copying testperson and testnevecs
cp $TMPD/testperson.hpp test/
cp $TMPD/testnevecs.hpp test/
echo Copying gamer files -Standard test 0-
cp $TMPD/ex0/score.hpp $TMPD/ex0/weapon.hpp $TMPD/ex0/gamer*.hpp test/ex0/
echo Copying glossary files -Standard test 1-
cp $TMPD/ex1/glossary*.hpp test/ex1/
echo Copying menu files -Standard test 2-
cp $TMPD/ex2/menu*.hpp test/ex2/

echo Done.
