#include <stdio.h>
#include <stdlib.h>

int getNthFibonacciIterative(int seq) {
   // base
   if (seq == 1) {
      return 0;
   } else if (seq == 2) {
      return 1;
   }

   // iterative
   int prevNum = 0;
   int curNum = 1;

   // iterate (seq - 2) times since we already covered seq1 and seq2
   for (int i = 0; i < seq - 2; i ++) {
      int nxtNum = prevNum + curNum;
      prevNum = curNum;
      curNum = nxtNum;
   }
   return curNum;
}

int getNthFibonacciRecursive(int seq) {
   // base case
   if (seq == 1) {
      return 0;
   } else if (seq == 2) {
      return 1;
   }

   // recursive case
   return getNthFibonacciRecursive(seq - 1) + getNthFibonacciRecursive(seq - 2);
}

int main(int argc, char *argv[]) {
   int num1;
   sscanf(argv[1], "%d", &num1);
   char* method = argv[2];
   char* fileName = argv[3];

   int num2 = 0;

   FILE *f = fopen(fileName, "r");

   fscanf(f, "%d", &num2);
   fclose(f);

   int result;

   // nth number starts from 1 not 0
   if (*method == 'r') {
      result = getNthFibonacciRecursive(num1 + num2);
   } else if (*method == 'i') {
      result = getNthFibonacciIterative(num1 + num2);
   }

   printf("%d", result);

   return 0;
}
