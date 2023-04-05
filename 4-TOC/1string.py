# Program that takes input as a string and find its suffix, prefix and substring - lab1


# Function that returns the prefix of a string
def find_prefix(word):
    prefix_list = []
    for i in range(1, len(word) + 1):
        prefix_list.append(word[:i])
    return prefix_list


# Function that returns the suffix of a string
def find_suffix(word):
    suffix_list = []
    for i in range(0, len(word)):
        suffix_list.append(word[i:])
    return suffix_list


# Function that returns the substring of a string
def find_substring(word):
    substring_list = []
    for i in range(0, len(word)):
        for j in range(i + 1, len(word) + 1):
            substring_list.append(word[i:j])
    return substring_list


# Function that sorts the list according to length of list item
def sort_list(given_list):
    final_list = sorted(given_list, key=len)
    return final_list


# User Input
word = input("Enter the string: ")
print(
    "Prefix :",
    sort_list(find_prefix(word)),
    "\nSuffx :",
    sort_list(find_suffix(word)),
    "\nSubstring :",
    sort_list(find_substring(word)),
)
