#!/usr/bin/env python3
def nfa(state, string):
	if not string:
		return
	if state == 0:
		nfa(1, string)
		nfa(3, string)
		return
	elif state == 1:
		if string[0] == 'a':
			nfa(2, string)
			return
		elif string[0] == 'b':
			return
		else:
			nfa(0, string[1:])
			return
	elif state == 3:
		if string[0] == 'b':
			nfa(4, string)
			return
		else:
			return
	elif state == 2:
		for i in range(len(string)):
			if string[i] != 'a':
				break
		if string[-1] == 'a' and i== len(string)-1:
			print(string)
			return
		print(string[:i])
		nfa(0, string[i:])
		return
	elif state == 4:
		for i in range(len(string)):
			if string[i] != 'b':
				break
		if string[-1] == 'b' and i== len(string)-1:
			print(string)
			return
		print(string[:i])
		nfa(0, string[i:])
		return
if __name__ == '__main__':
	while True:
		try:
			nfa(0, input('>'))
		except EOFError:
			exit()

