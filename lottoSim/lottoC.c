#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomSampleFromArr(int* arrToSample, int end, int numSamples, int* samples);
void bubbleSort(int* arr, int arrLength);

int main(int argc, char *argv[]) {

  //Checking if the user submitted a random seed:
  if(argc < 2) {
    printf("You must provide a random seed!\n");
    return 0;
  }
 
  //Initializing the random seed:
  int seedNumber = atoi(argv[1]);
  srand(seedNumber);

  //Select 5 white balls, without replacement
    //Setting up the pool of white balls
    int whiteBalls[70];
    for (int i = 1; i < 71; i++) { //whiteBalls contains 1 - 70, in indices 0-69
      whiteBalls[i - 1] = i;
    }
  
    //Selecting 5 balls from the pool
    int sampledBalls[5];

	  randomSampleFromArr(whiteBalls, 70, 5, sampledBalls);

    //Here is where the balls should be sorted in ascending order
    bubbleSort(sampledBalls, 5);

    //Printing the white balls selected
    printf("%i %i %i %i %i | ", sampledBalls[0], sampledBalls[1], sampledBalls[2], sampledBalls[3], sampledBalls[4]);


  //Select 1 yellow ball
  int yellowBall = (rand() % 25) + 1;
  printf("%i\n", yellowBall);

  return 0;
}

//Precondition: calling function sets random seed
void randomSampleFromArr(int* arrToSample, int end, int numSamples, int* samples) {

  //Selecting the random number from the array
  int randInt = (rand() % end);
  int sample = arrToSample[randInt];

  //Debug Printing
  //printf("%i\n", sample);

  //Recording the sample selected
  samples[numSamples] = sample;

  //Removing the value selected from the sample
  arrToSample[randInt] = end - 1; //This replaces whatever was selected with the last value. The next call will have an endpoint one position sooner, so the endpoint is effectively snipped off
                                              //This works even if the selected value was the endpoint, it'll just be ignored from here forward.

  //Calling the function again, recursively (if there are still more samples to be selected)
  if(numSamples == 0) {
    return;
  }

  randomSampleFromArr(arrToSample, end - 1, numSamples - 1, samples);

  return;

}

void bubbleSort(int* arr, int arrLength) {
  //Standard Bubble sort algorithm, using XOR swapping.
  for(int a = 0; a < (arrLength - 1); a++) { //For each position in the array
    for(int b = 0; b < (arrLength - 1); b++) {  //Give that position its own loop to bubble that position up to the right side, grabbing a different number if it is bigger.
      if(arr[b] > arr[b+1] ) { //If they need swapped, swap them using the XOR swap
        arr[b] = arr[b+1] ^ arr[b];
        arr[b+1] = arr[b] ^ arr[b+1];
        arr[b] = arr[b+1] ^ arr[b];
      }
    }
  }
}

