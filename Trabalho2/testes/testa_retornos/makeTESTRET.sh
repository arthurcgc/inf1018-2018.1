echo "creating an executable to run TESTRET.c object"
gcc -g -Wall -Wa,--execstack -o TESTRET ../geracod.c TESTRET.c
./TESTRET
