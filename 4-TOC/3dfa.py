# Write a program to implement DFA over{0, 1 },
# that accept all the string that ends with 101.

accept_states = ["q3"]
transition = {
    "q0": {"0": "q0", "1": "q1"},
    "q1": {"0": "q2", "1": "q1"},
    "q2": {"0": "q0", "1": "q3"},
    "q3": {"0": "q2", "1": "q1"},
}


word = input("Enter the string: ")
list_word = list(word)
index = len(word)

# Function for analize the string
def func():
    if index > 2:
        current_state = "q0"
        for i in range(0, index):
            new_state = transition[current_state][list_word[i]]
            print(current_state + " (" + str(list_word[i]) + ") " + " -> " + new_state)
            current_state = new_state
        return current_state

    else:
        return "string size is less"


# Function calling
x = func()


if x in accept_states:
    print("String is valid!")
else:
    print("String is invalid!")
