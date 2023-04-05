# Write a program to implement DFA over{0, 1 },
# that contain substring 0001.

accept_states = ["q4"]
transition = {
    "q0": {"0": "q1", "1": "q0"},
    "q1": {"0": "q2", "1": "q0"},
    "q2": {"0": "q3", "1": "q0"},
    "q3": {"0": "q2", "1": "q4"},
    "q4": {"0": "q4", "1": "q4"},
}


word = input("Enter the string: ")
list_word = list(word)
index = len(word)

# Function for analize the string
def func():
    if index > 3:
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
