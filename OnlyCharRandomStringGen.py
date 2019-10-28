"""by Tarun M"""
import random
import string

def randNumb():
    """Generates a number number for the number of characters."""
    return random.ranrange(4,16,1);
    
def randomString(stringLength):
    """Generate a random string with the combination of lowercase and uppercase letters """

    letters = string.ascii_letters
    return ''.join(random.choice(letters) for i in range(stringLength))

if __name__ == '__main__':
  print("Random String with only characters of different lengths...")
  print ("First Random String is ", randomString(randNumb) )
  print ("Second Random String is ", randomString(randNum) )
  print ("Third Random String is ", randomString(randNum) )
  
  print("Hence verified that the strings are random in characters and length.")
 
