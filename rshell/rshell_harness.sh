#!/bin/bash

echo "------Testing AND------"
ls && ps
a && ps
sleep 5
ls && b
ls && b && a
sleep 5
ls && b && ps
a && b && ps
sleep 5
a && b && c
a && ls && b

echo "_________End And______"

sleep 5

echo "-------Testing Semi-Colon-----"
ls;ps
a;ps
sleep 5
ls;b
ls;ps;a
sleep 5
a;b;c
echo"____________End Semi-Colon____"

echo
echo "---------Testing OR -------"
ls || a
a || ls
sleep 5
a || b
a | b || ls
echo "_________End OR __________"
sleep 5

echo
echo "---------Testint MIXED Commands___"
ls || ps && echo hello
a || ps && echo hello
sleep 5
ls || b && echo hello
ls && ps || echo hello
sleep 5
a && ps || ps echo hello
ls && b || echo hello
sleep 5
ls; ps && ls; a || b; ls || ps && echo hello
a;b;ls;a || ps && ls;
sleep 5
echo "__________End Mixed Conmmands___"


