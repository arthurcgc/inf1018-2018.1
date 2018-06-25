echo "creating an executable to run TESTSUB.c object"
gcc -g -Wall -Wa,--execstack -o TESTSUB ../../geracod.c TESTSUB.c
./TESTSUB
rm TESTSUB
