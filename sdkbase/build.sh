#!/bin/bash

# Assumes an ssh key was setup with ssh-keygen and uploaded
# to https://bitbucket.org/account/settings/ssh-keys/
if [ ! -d openiss ]; then
  echo "Cloning a fresh shallow copy of openiss, edetintegration branch..."
  git clone --depth 1 --branch edetintegration git@bitbucket.org:rt-mocap-vfx/openiss.git
else
  echo "Updating an existing copy of openiss, edetintegration branch..."
  pushd openiss
  git pull
  popd
fi

# Update openedet submodule
echo "Updating openedet submodule in openiss..."
pushd openiss
# TODO: Should be
# git submodule update --init --recursive openedet
# Getting ERROR: error: pathspec 'openedet' did not match any file(s) known to git
git clone --depth 1 --branch integration git@bitbucket.org:rt-mocap-vfx/openedet.git
popd

# Build the container
echo -n "Building the container... " && date
sudo docker build -f Dockerfile.openisssdkbase . -t openisssdkbase
date

# EOF
