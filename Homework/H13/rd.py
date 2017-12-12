class block(object):
	def __init__(self, name, parent, gen, kill):
		self.name = name
		self.parent = parent
		self.gen = set(gen)
		self.kill = set(kill)
		self.IN = set()
		self.OUT = set()

entry = block("entry", [], [], [])
B1 = block("B1", [entry], [1,2], [8,10,11])
B2 = block("B2", [], [3,4], [5,6])
B3 = block("B3", [], [5], [4,6])
B4 = block("B4", [B3], [6,7], [4,5,9])
B5 = block("B5", [B2, B3], [8,9], [2,7,11])
B6 = block("B6", [B5], [10,11], [1,2,8])

B2.parent = [B1, B5]
B3.parent = [B2, B4]

Bs = [B1, B2, B3, B4, B5, B6]

change = True
while change:
	change = False
	for B in Bs:
		tmp = set()
		for i in B.parent:
			tmp |= i.OUT
		if B.IN <> tmp:
			B.IN = tmp
			change = True
		#print B.name,B.IN - set(B.kill)
		
		tmp2 = set(B.gen) | (B.IN - set(B.kill))
		#print tmp2
		if B.OUT <> tmp2:
			B.OUT = tmp2
			change = True
	for i in Bs:
		print i.name, i.IN, i.OUT
	raw_input('...')