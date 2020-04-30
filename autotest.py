import random
import time
import os

def check_line(line):
	mass = line.split(' ')
	mass = mass[:-1]
	length = len(mass)
	if length > 1:
		for i in range(0, length - 1):
			if int(mass[i]) > int(mass[i + 1]):
				return 0
	return 1

col_test = random.randint(100, 1000)
os.system("echo '' > autotest")

time_all = 0
for i in range(col_test):
	length = random.randint(1, 20)
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

	time_start = time.time()
	os.system(f'./prog {line} >> autotest')
	time_end = time.time()
	
	time_all += (time_end-time_start)

f = open('autotest', 'r')
error = 0
for line in f:
	if line != '\n':
		if check_line(line) == 0:
			print('error in test')
			print(line)
			error += 1
if error == 0:
	print(f'Все {col_test} тестов пройдены за {round(time_all, 5)} секунд')
	print(f'В среднем по {round((time_all / col_test), 5)} секунды на тест')
