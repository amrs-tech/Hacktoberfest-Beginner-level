import random

avail=[1,2,3,4,5,6,7,8,9]
ttt = [' ',' ',' ',' ',' ',' ',' ',' ',' ']
def out():
	print(ttt[0],ttt[1],ttt[2],sep=" | ")
	print("----------")
	print(ttt[3],ttt[4],ttt[5],sep=" | ")
	print("----------")
	print(ttt[6],ttt[7],ttt[8],sep=" | ")
	print("\n")
def mark(choice, a):
	ttt[choice - 1] = a
	i = avail.index(choice)
	avail.pop(i)
	out()
def player():
	print("Its Your turn!")
	choice = int(input("Enter your positon: "))
	if not choice in avail:
		print("Sorry, position is not available")
		player()
	else:
		mark(choice, "X")
		computer()
def computer():
	choice = random.choice(avail)
	mark(choice, "O")
	player()
def start():
	n = random.random()
	if n < 0.5:
		print("You start!")
		player()
	else:
		computer()
start()
