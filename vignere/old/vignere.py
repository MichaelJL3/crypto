def read(file):
	cipher=""
	with open(file, "r") as f:
		for line in f:
			if line!="":
				line.upper()
				cipher+=line
	return cipher

def caesar(string, shift):
	length=len(string)
	shift+=65
	line=""
	for i in range(0, length):
		line+=(chr((ord(string[i])-shift)%26+65))
	return line

def freq(string):
	ccount=[[0 for x in range(2)] for x in range(26)]
	for i in range(26):
		ccount[i][1]=i;
	index=0
	for letter in string:
		index=ord(letter)-65
		if(index>=0 and index<26):
			ccount[index][0]+=1
	sort(ccount, 0, 25)
	return ccount

def sorthelp(array, lp, rp):
	l=lp+1
	r=rp
	pivval=array[lp][0]
	done=False
	while not done:
		while l<=r and array[l][0]<=pivval:
			l+=1
		while array[r][0]>=pivval and r>=l:
			r-=1
		if(r<l):
			done=True
		else:
			temp=array[l]
			array[l]=array[r]
			array[r]=temp
	temp=array[lp]
	array[lp]=array[r]
	array[r]=temp
	return r;
	
def sort(array, lp ,rp):
	if(lp<rp):
		r=sorthelp(array, lp, rp)
		sort(array,lp,r-1)
		sort(array,r+1,rp)

def part(cipher, key):
	count=len(cipher)
	array=[]
	partitions=[]
	for i in range(0, key):
		string=""
		for index in range(i, count, key):
			string+=cipher[index]
		partitions.append(string)
		array.append(freq(string))
	analysis(array, partitions)
	return partitions

def analysis(array, partitions):
	length=len(array)
	letter=' '
	high=['Q','X','J','K','V','B','P','Y','G','F','W','M','U','C','L','D','R','H','S','N','I','O','A','T','E','Z']
	shift=0
	for x in range(length):
		list2=partitions[x];
		list1=array[x];
		for i in range(25, 0, -1):
			shift=(ord(high[i])-65-list1[25][1])%26
			partitions[x]=caesar(list2, shift)
			if(partitions[0][0]=='T'):
				print(recombine(partitions,3))

def recombine(partitions, key):
	count=len(partitions[0])
	plaintxt=""
	for index in range(0, count):
		for i in range(0, key):
			plaintxt+=partitions[i][index]
	return plaintxt

def main():
	file="cipher.txt"
	cipher=read(file)
	#key=findkey()
	key=3
	partitions=part(cipher, key)
	plaintxt=recombine(partitions, key)
	print(plaintxt)

main()