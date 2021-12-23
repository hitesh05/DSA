import numpy as np

for i in range(100000):
	if np.random.choice([True, False], p=[0.8, 0.2]):
		print(f"push {np.random.randint(100)} {np.random.randint(100)}")
	else:
		print(f"pop")
print("exit")
