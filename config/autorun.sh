#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

if [[ -d .git || -f .git || ! -f m4/version.m4 ]]
then
  perl config/version.pl
fi

autoreconf --install --force --verbose -Wall

sed 's/"$$tst" $(AM_TESTS_FD_REDIRECT)/"$$tst" $(AM_TESTS_FD_REDIRECT) \&\& \\\n\tTRS="$$(echo $@ | sed s\/.log\/.trs\/g | xargs cat | grep "PASS")" \&\& \\\n\ttest -n "$$TRS" \&\& echo "" || exit 1;/g' Makefile.in > Makefile.out
rm -f Makefile.in
yes | mv -f Makefile.out Makefile.in
