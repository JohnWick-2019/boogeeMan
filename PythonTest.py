import random

print("Let`s try guess my number...")
print()
print("You have three attempt`s")
print()

my_number = int(random.random() * 20)



counter = 0

while counter < 3:
    
    num = int(input("Enter a number from 0 to 20: "))

    
    if num == my_number:
        print("Congratulation!!! You guessed my number")
        break

    elif num > my_number:
        print("My number is less")
        counter +=1

    elif num < my_number:
        print("My number is biger")
        counter +=1
    
        
else:
    print("I guessed {}. ".format(my_number), "You dont guessed my number")
   
    




