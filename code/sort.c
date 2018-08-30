/**
 * Source name     : sort.c
 * Executable name : sort 
 * Version         : 1.0
 * Created date    : 01/19/2017
 * Author          : I-Ting Angelina Lee and <Your name>
 * Description     : A program that, given an input <n>, 
 *                   generate an array of length n with random values
 *                   and sort the values using bubble sort 
 **/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/** 
 * Input: a string (an array of chars that is '\0' terminated).
 *
 * This function takes the string and converts it into an int
 *  using strtol library function.  It reports an error and 
 *  exits the program if an error is encountered.
 **/
static int parse_input(char *input) {
    errno = 0;
    int ret = strtol(input, NULL, 10); 
    if(errno != 0) {
        perror("Failed to parse input");
        exit(0);
    }
    if(ret == 0) {
        fprintf(stderr, "%s is not a valid input.\n", input);
        exit(0);
    }
    return ret;
}

/**
 * Input: an empty array of length n
 * 
 * This function generates random inputs within the range 
 * of [0, n) to fill the array. 
 **/
static void generate_input(int *array, int n) {
    int i = 0;
    for(i=0; i < n; i++) {
        array[i] = rand() % n;
    }
}

/**
 * Input: array of length n containing random values
 * 
 * This function sorts the input array so that at the 
 * end of the function execution, the array contains values
 * in increasing order.
 **/
static void sort_input(int *array,  int n) {
    
    // It's your job to implement this simple bubble sort routine
}

/**
 * Input: arary of length n
 * This function checks to see if the array is sorted.
 * If so, return TRUE; otherwise return FALSE.
 **/
static int check_array_sorted(int *array, int n) {
    int pass = TRUE;
    int i = 0;

    for(i=0; i < (n-1); i++) {
        if(array[i] > array[i+1]) {
            pass = FALSE; 
            break;
        }
    }
    return pass;
}

int main(int argc, char *argv[]) {
    
    if(argc < 2) {
        fprintf(stderr, "Usage: ./sort <n>\n");
        exit(0);
    } 
    errno = 0;

    int n = parse_input(argv[1]);
    int array[n];
    int pass = FALSE;

    generate_input(array, n);
    sort_input(array, n);
    pass = check_array_sorted(array, n);

    if(pass) {
        printf("%d elements sorted successfully.\n", n);
    } else {
        fprintf(stderr, "Sorting failed.\n\n");
    }

    return 0;
}

