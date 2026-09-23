# This is program for a Calculator: 

def sum(a,b):
    return a + b

def sub(a,b):
    return a - b

def mul(a,b):
    return a * b

def div(a,b):
    if a > b:
        return a / b
    else:
        print("Error")

x = int(input("Enter a no: "))
y = int(input("Enter a no: "))

ch = input("Enter the operation: A : ADD \n B : SUB \n C : MUL \n D : DIV \n")

if ch == 'A':
    print(sum(x,y))

elif ch == 'B':
    print(sub(x,y))

elif ch == 'C':
    print(mul(x,y))

elif ch == 'D':
    print(div(x,y))

else:
    print("Invalid Choice")  