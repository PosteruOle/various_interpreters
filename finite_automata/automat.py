import sys

# regex: (ab|c)*b
prelazi = {("ADE","a") : "B", ("ADE","b") : "C", ("ADE", "c") : "ADE", 
            ("B", "b") : "ADE"
        }
    
pocetno = "ADE"
zavrsna = ["C"]

print("-----------------------------------------")

stanje=pocetno

while True:
	try:
		c=input("Unesite slovo a, b ili c: ")
		if c!='a' and c!='b' and c!='c':
			raise ValueError
		
		if prelazi.get((stanje, c)) is None:
			sys.exit("Nepostojece stanje!")
		
		stanje=prelazi[(stanje, c)]		
	
	except EOFError:
		#sys.exit("Greska!")
		break
	except ValueError:
		sys.exit("Greska pri unosu!")

if stanje in zavrsna:
	print("Automat prihvata unetu rec!")
else:
	print("Automat ne prihvata unetu rec!")
	print(stanje)			
