import random

def game():
    number_to_guess = random.randint(1, 10)
    guess = None
    attempts = 0

    while guess != number_to_guess:
        guess = input("Guess a number between 1 and 10: ")
        if guess.isdigit():
            guess = int(guess)
            attempts += 1
            if guess < number_to_guess:
                print("Too low!")
            elif guess > number_to_guess:
                print("Too high!")
        else:
            print("Invalid input. Please enter a number.")

    print(f"Congratulations! You've guessed the number in {attempts} attempts.")

    play_again = input("Play again? (yes/no): ").lower()
    if play_again == "yes":
        game()
    else:
        print("Thanks for playing!")

game()
