#include <stdio.h>
#include <stdlib.h>

int getNthFibonacciIterative(int nthNum) {
   int prevPrevNum;
   int prevNum = 0;
   int curNum = 1;

   for (int i = 1; i < nthNum; i ++) {
      prevPrevNum = prevNum;
      prevNum = curNum;
      curNum = prevPrevNum + prevNum;
   }
   return curNum;
}

int getNthFibonacciRecursive(int nthNum) {
   // base case
   if (nthNum == 0) {
      return 0;
   } else if (nthNum == 1) {
      return 1;
   }

   // recursive case
   return getNthFibonacciRecursive(nthNum - 1) + getNthFibonacciRecursive(nthNum - 2);
}

int main(int argc, char *argv[]) {
   int num1 = atoi(argv[1]);
   char* method = argv[2];
   char* fileName = argv[3];

   int num2 = 0;

   FILE *f = fopen(fileName, "r");

   fscanf(f, "%d", &num2);
   fclose(f);

   int result;

   // nth number is 1 indexed.
   if (*method == 'r') {
      result = getNthFibonacciRecursive(num1 + num2 - 1);
   } else if (*method == 'i') {
      result = getNthFibonacciIterative(num1 + num2 - 1);
   }

   printf("%d", result);

   return 0;
}
