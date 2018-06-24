echo "creating an executable to run TESTATR.c object"
gcc -g -Wall -Wa,--execstack -o TESTATR ../geracod.c TESTATR.c
./TESTATR
