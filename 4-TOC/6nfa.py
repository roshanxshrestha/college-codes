# Implement NFA over{0, 1 }, that accept the string starting with 01

accept_state = ["q2"]
transition = {
    "q0": {"0": ["q1"], "1": ["don't care"]},
    "q1": {"0": ["don't care"], "1": ["q2"]},
    "q2": {"0": ["q2"], "1": ["q2"]},
}

# User input
word = input("Enter the string: ")
word_list = list(word)
word_length = len(word)
current_state = ["q0"]

# Returns the final states of the nfa
def get_final_states(current_state):
    if word_length > 1:
        fi = []
        # For each charater of the given word
        for i in range(0, word_length):
            li = []
            ch = word_list[i]
            print("for ", word_list[i])  # Each character

            # For every state in the current_state find their next_state
            for c in current_state:
                if c == "don't care":
                    pass
                else:
                    new_state = transition[c][ch]
                    if new_state not in fi:
                        fi.append(new_state)
                    print(str(c) + " -> " + str(new_state))
            # print('states:', new_state)
            current_state = new_state
            print("-----------")
        return fi

    else:
        print("String size is less")
        quit()


x = get_final_states(current_state)
print("Final state ", x)

# If the accept_state if present in the final_states
if accept_state in x:
    print("String is valid!")
else:
    print("String is invalid!")
