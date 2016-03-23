#!/bin/sh
# UEFI原理与编程 gcc script for use g++
iscpp=0
for i in "$@" ; do
  if [ "-" != "${i:0:1}" ] ; then
    if [ "cpp" = "${i##*.}" ]; then
      iscpp=1
    fi
  fi
done

if [ $iscpp = 0 ]; then
  echo gcc
  /usr/bin/gcc $@
else
  echo g++
  /usr/bin/g++ $@
fi

