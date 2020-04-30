import random
import os

col_test = 1

for i in range(col_test):
	# length = random.randint(1, 20)
	length = 50
	seed = []
	i = 0
	while i < length:
		k = random.randint(-100, 100)
		if k not in seed:
			seed.append(k)
			i += 1
	line = ''
	for i in seed:
		line += str(i) + ' '
	os.system(f'./prog {line}')