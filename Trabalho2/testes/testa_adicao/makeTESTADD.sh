echo "creating an executable to run TESTADD.c object"
gcc -g -Wall -Wa,--execstack -o TESTADD ../geracod.c TESTADD.c
./TESTADD
