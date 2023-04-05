# Write a program to implement DFA over{0, 1 },
# that accept all the string that start with 01.

accept_states = ["q2"]
transition = {
    "q0": {"0": "q1", "1": "q3"},
    "q1": {"0": "q3", "1": "q2"},
    "q2": {"0": "q2", "1": "q2"},
    "q3": {"0": "q3", "1": "q3"},
}


word = input("Enter the string: ")
list_word = list(word)
index = len(word)

# Function for analize the string
def func():
    if index > 1:
        current_state = "q0"
        for i in range(0, index):
            new_state = transition[current_state][list_word[i]]
            print(current_state + " -> " + new_state)
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
