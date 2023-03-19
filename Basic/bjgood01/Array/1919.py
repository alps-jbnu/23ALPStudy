# 결국 두 문자열의 알파벳의 개수가 같아야한다
# a ~ z: 26개
word1 = input()
word2 = input()
word1_alphabet = [0 for i in range(26)]  # 첫번째 단어의 알파벳 개수 리스트
word2_alphabet = [0 for i in range(26)]  # 두번째 단어의 알파벳 개수 리스트

# ord: 문자를 유니코드 숫자로 바꿔준다
# chr: 숫자를 유니코드 문자로 바꿔준다
# 97을 빼는이유는 'a'가 97번이다
for ch in word1:
    word1_alphabet[ord(ch) - 97] += 1
for ch in word2:
    word2_alphabet[ord(ch) - 97] += 1

count = 0
# abs() -> 절대값
for i in range(26):
    count += abs(word1_alphabet[i] - word2_alphabet[i])
print(count)
