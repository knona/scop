#!/bin/bash

# Install glfw version 3.3.2

set -e

function clean_before_exit {
	rm -rf $current_directory/libs/glfw
	rm -rf $current_directory/.tmp
}

trap clean_before_exit EXIT

current_directory=$(pwd)
glad_dir=$current_directory/libs/glfw
mkdir -p $glad_dir

cache=$(pwd)/.cache

mkdir -p $cache

glfw_archive=$cache/glfw.zip
glfw_dl_url=https://github.com/glfw/glfw/releases/download/3.3.2/glfw-3.3.2.zip

if [ ! -f "$glfw_archive" ]
then
	curl -o $glfw_archive -L $glfw_dl_url
fi

mkdir .tmp
cd .tmp

unzip -qq $glfw_archive

cd glfw-3.3.2

mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=$glad_dir -DGLFW_BUILD_DOCS=no -DGLFW_BUILD_EXAMPLES=no -DGLFW_BUILD_TESTS=no -DBUILD_SHARED_LIBS=yes ..
make install

cd ../../..
rm -rf .tmp

trap - EXIT
