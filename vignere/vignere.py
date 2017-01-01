import math

def read(file):
	cipher=""
	with open(file, "r") as f:
		for line in f:
			if line!="":
				line.upper()
				cipher+=line
	return cipher

def shift(string, left):
	length=len(string)
	left+=65
	newstr=""
	for i in range(length):
		newstr+=chr((ord(string[i])-left)%26+65)
	return newstr

def decode(string, cipher, k):
	part=partition(string, k)
	decrypt=[]
	for i in range(k):
		decrypt.append(shift(part[i], cipher[i]))
	return recombine(decrypt, k)

def recombine(partitions, key):
	count=len(partitions[0])
	plaintxt=""
	for index in range(0, count):
		for i in range(0, key):
			try:
				plaintxt+=partitions[i][index]
			except IndexError:
				pass
	return plaintxt

def caesar(string, k):
	part=partition(string, k)
	prtstring=""
	low=0
	val=0
	s=0
	cipher=[]
	for j in range(k):
		prtstring=part[j]
		low=10000000
		for i in range(26):
			val=chisqr(shift(prtstring, i))
			if val<low:
				low=val
				s=i
		cipher.append(s)
	return cipher

def partition(string, k):
	count=len(string)
	part=[]
	for i in range(0, k):
		newstring=""
		for index in range(i, count, k):
			newstring+=string[index]
		part.append(newstring)
	return part

def ic(parts):
	length=len(parts)
	string=""
	strlen=0
	sumIC=0
	for i in range(length):
		string=parts[i]
		strlen=len(string)
		occur=count(string)
		for j in range(26):
			sumIC+=(occur[j]*(occur[j]-1))/(strlen*(strlen-1))
	sumIC/=length
	return sumIC*100

def key(string):
	high=0
	val=0
	k=0
	p=[]
	for i in range(1, 11):
		p=partition(string, i)
		val=ic(p)
		if(val>high):
			high=val
			k=i
	return k

def count(string):
	occur=[0]*26
	index=0
	for letter in string:
		index=ord(letter)-65
		occur[index]+=1
	return occur

def translate(cipher, k):
	string=""
	for i in range(k):
		string+=chr(cipher[i]+65)
	return string

def chisqr(string):
	sumX=0.0
	expected=0.0
	length=len(string)
	occur=count(string)
	probability=[0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 
				 0.02015, 0.06094, 0.06966, 0.00153, 0.00773, 0.04025,
				 0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
				 0.06327, 0.09056, 0.02758, 0.00978, 0.02361, 0.00150,
				 0.01974, 0.00074] 	   #letter distribution of english

	for i in range(26):		#the 26 values to be summed
		expected=length*probability[i]
		sumX+=math.pow((occur[i]-expected), 2)/expected
	return sumX

def main():
	file="cipher.txt"
	string=("vptnvffuntshtarptymjwzirappljmhhqvsubwlzzygvtyitarptyiougxiuydtgzhhvvmum"
			"shwkzgstfmekvmpkswdgbilvjljmglmjfqwioiivknulvvfemioiemojtywdsajtwmtcgluy"
			"sdsumfbieugmvalvxkjduetukatymvkqzhvqvgvptytjwwldyeevquhlulwpkt")
	#string=read(file)
	#string="dlgcmqkzcbcqsqnvirowrgmrrssdwnkgccylpspdylkxcvc"
	string=string.upper()
	print(string)
	print("================================================================")
	k=key(string)
	cipher=caesar(string, k)
	#cipher[2]=ord('P')-65
	plntxt=decode(string, cipher, k)
	txtkey=translate(cipher, k)
	print(txtkey)
	print(plntxt)

main()