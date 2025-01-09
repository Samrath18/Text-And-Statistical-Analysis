/* Lab5 Part1 : analysis of text */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main() {
  char text[MAX], c;
  int i;
  int lowercase, uppercase, digits, other;
  int length;
  bool flag;

  puts("Type some text (then ENTER):");

  /* Save typed characters in text[]: */

  for (i = 0; i < MAX; i++) {
    text[i] = getchar();
    if (text[i] == '\n') break;
  }
  length = i;  // Actual length of input string

  // In-place reversal
  int n = i;
  char rarr[n];
  for (int i = 0; i < length; i++) {
    rarr[i] = text[length - i - 1];
  }

  // Print the reversed array
  for (i = 0; i < length; i++) {
    if (text[i] != rarr[i]) {
      flag = false;
      printf("Your input in reverse is: ");
      for (int i = 0; i < length; i++) {
        printf("%c", rarr[i]);
      }
      break;
    } else {
      flag = true;
    }

    if (flag == true) {
      printf("A palindrome has been found!!!!! Your input in reverse is: ");
      for (int i = 0; i < length; i++) {
        printf("%c", rarr[i]);
      }
      break;
    }
  }
}
