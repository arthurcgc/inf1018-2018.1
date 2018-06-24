echo "creating an executable to run TESTMUL.c object"
gcc -g -Wall -Wa,--execstack -o TESTMUL ../geracod.c TESTMUL.c
./TESTMUL
