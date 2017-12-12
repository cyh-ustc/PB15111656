

class block(object):
	def __init__(self, name, children, defs, uses):
		self.name = name
		self.children = children
		self.defs = set(defs)
		self.uses = set(uses)
		self.IN = set()
		self.OUT = set()

exit = block("exit", [], [], [])

B1 = block("B1", [], ['a','b'], [])
B2 = block("B2", [], ['c','d'], ['a','b'])
B3 = block("B3", [], ['d'], ['b','d'])
B4 = block("B4", [B3], ['d','e'], ['a','b','e'])
B5 = block("B5", [], ['b','e'], ['a','b','c'])
B6 = block("B6", [exit], ['a','b'], ['b','d'])


B1.children = [B2]
B2.children = [B3, B5]
B3.children = [B4, B5]
B5.children = [B2, B6]



Bs = [B1, B2, B3, B4, B5, B6]
Bs.reverse()
change = True
while change:
	change = False
	for B in Bs:
	
		tmp2 = set()
		for i in B.children:
			tmp2 |= i.IN
		if B.OUT <> tmp2:
			B.OUT = tmp2
			change = True
			
		tmp = B.uses | (B.OUT - B.defs)
		if B.IN <> tmp:
			B.IN = tmp
			change = True
	Bs.reverse()
	for i in Bs:
		print i.name, i.IN, i.OUT
	Bs.reverse()
	raw_input('...')