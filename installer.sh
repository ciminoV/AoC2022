aclocal # generate m4-files
autoconf # generate configure.ac

automake -a -c # generate missing files
./configure # run generate local configure

make
