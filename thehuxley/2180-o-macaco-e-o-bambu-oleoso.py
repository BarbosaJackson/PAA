def define_strength(steps):
	qtd_steps = len(steps)
	if(qtd_steps == 1):
		return steps[0]
	elif(qtd_steps == 2):
		if(steps[0] != steps[1] - steps[0]):
			return max(steps[0], steps[1] - steps[0])
		else:
			return steps[0] + 1
	else:
		final_strength = 2
		while True:
			strength = final_strength
			flag = False
			previous = 0
			for i in range(0, qtd_steps):
				if(strength < steps[i] - previous):
					flag = False
					break
				else:
					flag = True
				if(strength == steps[i] - previous):
					strength -= 1
				previous = steps[i]
			if(flag):
				return final_strength
			final_strength += 1
def main() :
	n_cases = int(input())
	count_case = 1
	while count_case <= n_cases :
		n_steps = int(input())
		steps = input().split()
		for i in range(0, n_steps):
			steps[i] = int(steps[i])
		print("Case {}: {}".format(count_case, define_strength(steps)))
		count_case += 1
main()