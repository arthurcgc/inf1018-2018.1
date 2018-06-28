echo "creating an executable to run TESTJUMP.c object"
gcc -g -Wall -Wa,--execstack -o TESTJUMP ../../geracod.c TESTJUMP.c
./TESTJUMP
rm TESTJUMP
