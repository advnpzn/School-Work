#Python program to reverse the given Integer.
num = int(input("Enter the Number you want to reverse : ")) 
print("Number : ",num)                                     
rev = 0                                                     
while num > 0:                                              
    rem = num % 10                                          
    rev = (rev * 10) + rem                                
    num = num // 10                                                
else:
    print("Reversed Number : ",rev)
    pass
