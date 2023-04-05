# Python program to identify the identifier

# import re module

# re module provides support
# for regular expressions
import re

# Make a regular expression
# for identify valid identifier
regex = "^[A-Za-z_][A-Za-z0-9_]*"

# Define a function for
# identifying valid identifier
def check(word):
    keywords = [
        "int",
        "double",
        "auto",
        "break",
        "case",
        "char",
        "const",
        "continue",
        "default",
        "do",
        "else",
        "enum",
        "extern",
        "float",
        "for",
        "goto",
        "if",
        "long",
        "register",
        "return",
        "short",
        "signed",
        "sizeof",
        "static",
        "struct",
        "switch",
        "typedef",
        "union",
        "unsigned",
        "void",
        "volatile",
        "while",
    ]
    # pass the regular expression
    # and the string in search() method
    if re.search(regex, word):
        if word in keywords:
            print("It is a c keyword")
        else:
            print("Valid Identifier")

    else:
        print("Invalid Identifier")


# Driver Code
if __name__ == "__main__":
    character = input("Enter a string: ")
    check(character)
