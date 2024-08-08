import java.util.Random;
import java.util.ArrayList;
import java.util.stream.IntStream;
import java.util.stream.Collectors;
import java.util.Iterator;
import java.util.Collections;

class lottoSim
{
public static void main(String []args) {
 
  //Checking if a random seed was provided, quitting if it was not
  if(args.length == 0) {
    System.out.println("You must provide a random seed!");
    return;
  }
 
  //Creating the random number generator;
  Random rand = new Random(Long.parseLong(args[0], 10));

  //Creating a pool of white balls
  ArrayList whiteBalls = new ArrayList(IntStream.rangeClosed(0,70).boxed().toList());
  Collections.shuffle(whiteBalls, rand);
  ArrayList selectedWhiteBalls = new ArrayList(5);

  //Picking the white balls
  for (int i = 0; i < 5; i++) {
    selectedWhiteBalls.add(whiteBalls.get(i));
  }

  //Sorting the white balls
  Collections.sort(selectedWhiteBalls);

  //Printing the white balls
  for(int i = 0; i < 5; i++) {
  System.out.print(selectedWhiteBalls.get(i) + " ");
  }
  System.out.print("| ");

  //Pick a single yellow ball
  int firstRand = rand.nextInt(25) + 1;
  System.out.println(firstRand);

  return;
  }
}
