echo "creating an executable to run TESTIF.c object"
gcc -g -Wall -Wa,--execstack -o TESTIF ../../geracod.c TESTIF.c
./TESTIF
rm TESTIF
