#!/bin/sh
DSC=http://archive.ubuntu.com/ubuntu/pool/universe/g/gsl/gsl_2.8+dfsg-5.1ubuntu1.dsc
ORIG=http://archive.ubuntu.com/ubuntu/pool/universe/g/gsl/gsl_2.8+dfsg.orig.tar.gz
DEB_PATCH=http://archive.ubuntu.com/ubuntu/pool/universe/g/gsl/gsl_2.8+dfsg-5.1ubuntu1.debian.tar.xz

# DSC=http://archive.ubuntu.com/ubuntu/pool/universe/g/gsl/gsl_2.8+dfsg-5.dsc
# ORIG=http://archive.ubuntu.com/ubuntu/pool/universe/g/gsl/gsl_2.8+dfsg.orig.tar.gz
# DEB_PATCH=http://archive.ubuntu.com/ubuntu/pool/universe/g/gsl/gsl_2.8+dfsg-5.debian.tar.xz

save_path=$(pwd)
mkdir -p build/gsl_2.8
cd build/gsl_2.8

curl -O -s $DSC
curl -O -s $ORIG
curl -O -s $DEB_PATCH

cd "$save_path"
tar -cvf gsl2.8_ubuntu_src.tar -C build gsl_2.8
