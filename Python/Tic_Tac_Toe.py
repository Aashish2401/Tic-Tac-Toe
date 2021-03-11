import numpy as np
from random import randint

grid = [[' ',' ',' '],          #Empty Tic Tac Toe grid declaration
        [' ',' ',' '],
        [' ',' ',' ']]

def update(player,pos):         #Method to update the grid according to the current input
    global grid
    
    if grid[int((pos - 1) / 3)][(pos - 1) % 3] == ' ': #Contition to check if spot is available
        grid[int((pos - 1) / 3)][(pos - 1) % 3] = player
        
    else: #Condition when spot is occupied
        print()
        pos = int(input("Oops, Position Taken, Try Again:"))
        update(player,pos)

def check_end():                #Method used to check if the current state of the grid is a terminal state and return it
    global grid
    draw = 1
    
    for i in range(3):
        if grid[i][0] == grid[i][1] == grid[i][2] and grid[i][0] != ' ':
            return grid[i][0],"Win"
        if grid[0][i] == grid[1][i] == grid[2][i] and grid[0][i] != ' ':
            return grid[0][i],"Win"

    if grid[0][0] == grid[1][1] == grid[2][2] and grid[0][0] != ' ':
        return grid[0][0],"Win"
    if grid[0][2] == grid[1][1] == grid[2][0] and grid[1][1] != ' ':
        return grid[2][0],"Win"

    for i in range(3):
        for j in range(3):
            if grid[i][j] == ' ':
                draw = 0

    if draw == 1:
        return None,"Draw"
    else:
        return None,"Continue"

def minimax(player,depth,y,x):  #Method used to perform the minimax algorithm on the current state of the grid and predict the best move available at the moment
    global grid
    
    winner,status = check_end() #To check if the game has ended already
    
    if status == "Win":
        if winner == 'X':
            return -12+depth,y,x
        
        if winner == 'O':
            return 12-depth,y,x
        
    if status == "Draw":
        return 0,y,x
    
    if status == "Continue":
        y = 0
        x = 0
        
        if player == 'X': #For minimizing player
            bestScore = 100000
            for i in range(3):
                for j in range(3):
                    if grid[i][j] == ' ':
                        grid[i][j] = 'X'
                        score,y_ind,x_ind = minimax('O',depth+1,i,j) #Recursive call
                        if score < bestScore:
                            bestScore = score
                            y = i
                            x = j
                        grid[i][j] = ' '
            return bestScore,y,x

        else: #For maximizing player
            bestScore = -100000
            for i in range(3):
                for j in range(3):
                    if grid[i][j] == ' ':
                        grid[i][j] = 'O'
                        score,y_ind,x_ind = minimax('X',depth+1,i,j) #Recursive call
                        if score > bestScore:
                            bestScore = score
                            y = i
                            x = j
                        grid[i][j] = ' '
            return bestScore,y,x

def print_board():
    global grid

    print("-------")
    print("|"+grid[0][0]+"|"+grid[0][1]+"|"+grid[0][2]+"|")
    print("|-----|")
    print("|"+grid[1][0]+"|"+grid[1][1]+"|"+grid[1][2]+"|")
    print("|-----|")
    print("|"+grid[2][0]+"|"+grid[2][1]+"|"+grid[2][2]+"|")
    print("-------")

players = input("Enter if you are player X or O:")                          #The user chooses X or O
print()

if players == 'x' or players == 'X':                                        #If the user chooses X, he is player 1
    for x in range(9):
        player,result = check_end()
        
        if result == "Win":
            print()
            print()
            print(player+" Wins!")
            break
        
        if result == "Draw":
            print()
            print()
            print("It's a draw.")
            break
        
        ind = int(input("Enter your position(1-9):"))
        update('X',ind)
        print()
        print_board()
        print()
        
        player,result = check_end()
        
        if result == "Win":
            print()
            print()
            print(player+" Wins!")
            break
        
        if result == "Draw":
            print()
            print()
            print("It's a draw.")
            break
        
        score,i,j = minimax('O',0,0,0)
        grid[i][j] = 'O'
        print("AI position: {0}".format(i * 3 + j + 1))
        print()
        print_board()
        print()

if players == 'o' or players == 'O':                        #If the user chooses O, he is player 2
    for i in range(9):
        if i == 0:                                          #This 'if' block is to make the AI players first move random, to make the game more fun I guess.... XD
            y = randint(1,9)
            print("AI position: {0}".format(y))
            grid[(y-1)//3][(y-1)%3] = 'X'
            print()
            print_board()
            print()
            
            ind = int(input("Enter your position(1-9):"))
            update('O',ind)
            print()
            print_board()
            print()
            
        player,result = check_end()
        
        if result == "Win":
            print()
            print()
            print(player+" Wins!")
            break
        
        if result == "Draw":
            print()
            print()
            print("It's a draw.")
            break
        
        score,i,j = minimax('X',0,0,0)
        grid[i][j] = 'X'
        print("AI position: {0}".format(i * 3 + j + 1))
        print()
        print_board()
        print()
        
        player,result = check_end()
        
        if result == "Win":
            print()
            print()
            print(player+" Wins!")
            break
        
        if result == "Draw":
            print()
            print()
            print("It's a draw.")
            break
        
        ind = int(input("Enter your position(1-9):"))
        update('O',ind)
        print()
        print_board()
        print()
input()
