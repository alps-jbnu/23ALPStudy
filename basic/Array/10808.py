s = input()
alpha = "abcdefghijklmnopqrstuvwxyz"
for i in range(len(alpha)):
    if s.count(alpha[i]):
        print(s.count(alpha[i]), end=' ')
    else:
        print('0', end=' ')
