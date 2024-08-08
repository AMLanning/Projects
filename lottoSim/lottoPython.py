import random
import sys

if(len(sys.argv) == 1):
  print("You must provide a random seed to use this generator")
  exit()

random.seed(int(sys.argv[1], 10))

#Drawing 5 white Balls
whitePool = list(range(1,71))
whiteBalls = random.sample(whitePool, 5)
whiteBalls.sort()
for i in whiteBalls:
    print(i, end=" ")
print("", end="| ")

#Drawing the single yellow ball
print(random.randint(1,25))
