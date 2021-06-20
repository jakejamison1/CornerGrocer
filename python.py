import re
import string

    #function to split string into list
def splitFoodString(foodString):    
    foodList = foodString.split()    
    return foodList

#function to search for item and frenquency
def searchCount(foodString):

    #declaring variables
    count = 0
    counter = 0
    countz=0
    test = False
    outList = []
    newList = []
    freqList = []
    foodList = splitFoodString(foodString)

    #logic loop to add values to new loop
    for item in foodList:
        for new in newList:
            if item == new:
                test = True
        if test == False:
            newList.append(item)
        test = False

        #logic loop to add frequency behind item 
    for item in newList:
        for new in foodList:
            if item == new:
                counter = counter + 1

        freqList.append(str(item) + "\n")
        freqList.append(str(counter) + "\n")
        counter = 0

        #open, write, and close file
    file1 = open('frequency.dat', 'w')
    file1.writelines(freqList)
    file1.close()

    #user input
    inp = input('Enter item to search for: ')
    file1 = open('frequency.dat', 'r')
    Lines = file1.readlines()

    #loop through list for input, print item and frequency
    for line in Lines:
        if count == 1:
            count = 0
            print(line.strip("\n"))

        if line.strip("\n") == inp:
            print(line.strip("\n") + " ", end = "")
            count = 1

            #close file
    file1.close()  
    return 100

    #function for histogram
def histogram(foodString):

    #declaring variables
    counter = 0
    countz=0
    test = False
    outList = []
    newList = []
    freqList = []
    foodList = splitFoodString(foodString)

    #logic loop to create foodlist
    for item in foodList:
        for new in newList:
            if item == new:
                test = True
        if test == False:
            newList.append(item)
        test = False

        #logic loop to add items and frequency
    for item in newList:
        for new in foodList:
            if item == new:
                counter = counter + 1

        freqList.append(str(item) + "\n")
        freqList.append(str(counter) + "\n")
        counter = 0

        #open, write, and close frequency.dat
    file1 = open('frequency.dat', 'w')
    file1.writelines(freqList)
    file1.close()
    file1 = open('frequency.dat', 'r')
    Lines = file1.readlines()

    #loops to print histogram with "*"
    for line in Lines:

        if countz % 2 == 0:
           print(line.strip("\n"), end = " ")

        else:
            holder = line.strip("\n")
            intholder = int(holder)
            for item in range(intholder):
                print(" * ",end = "")        
            print("")
        
        countz = countz + 1

    file1.close() 
    return 100

    #function for individual count
def individualCount(foodString):

    #declaring variables
    counter = 0
    test = False
    newList = []

    #string from c++ to python to make into a list
    foodList = splitFoodString(foodString)

    #loop to append items to new list
    for item in foodList:
        for new in newList:
            if item == new:
                test = True
        if test == False:
            newList.append(item)
        test = False

        #loop to print items and their frequency
    for item in newList:
        for new in foodList:
            if item == new:
                counter = counter + 1
        print(str(item) + " " + str(counter))
        counter = 0

    return 100