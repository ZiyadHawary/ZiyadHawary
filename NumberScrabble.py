def sum_checker(x):
    if len(x) < 3:
        return False

    numbers_set = set(x)

    for i in range(len(x) - 2):
        for j in range(i + 1, len(x) - 1):
            target = 15 - (x[i] + x[j])
            if target in numbers_set:
                return True

    return False

def game():
    choices = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    print("**Welcome to Number Scrabble**")
    print("<The player to first choose three numbers that their sum is 15 wins>")

    player1=input("Enter player 1 name: ")
    player2=input("Enter player 2 name: ")

    print(choices)

    player1_list = list()
    player2_list = list()

    while choices:
        input1 = int(input(player1+": Choose a number from the following choices:"))
        while input1 not in choices:
            input1 = int(input("Please select a valid choice >>> "))

        player1_list.append(input1)
        choices.remove(input1)

        print(player1 + "'s score is now: ", player1_list)
        print(choices)

        if sum_checker(player1_list):
            print(player1 + " is the winner!")
            break

        input2 = int(input(player2+": Choose a number from the following choices:"))
        while input2 not in choices:
            input2 = int(input("Please select a valid choice >>> "))

        player2_list.append(input2)
        choices.remove(input2)

        print(player2 + "'s score is now: ", player2_list)
        print(choices)

        if sum_checker(player2_list):
            print(player2+" is the winner!")
            break

game ()
