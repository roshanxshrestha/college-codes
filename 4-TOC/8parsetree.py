# Take a Grammar of your choice and
# implement parse tree for the string produced by the grammar.


di = {"S": "sAB", "A": "a", "B": "b"}

fi = []
li = []
for i in di.keys():
    li.append(i)


str = "sab"


def parse_string(s, initial_string):
    global new
    new = ""
    st = ""
    p = di[s]
    i_string = initial_string
    print(s, " -> ", p)
    for i in p:
        if i not in li:
            fi.append(i)
            st = st + i
            i_str = i_string.replace(s, st, 1)
            print("updated string ", i_str)
            new = new + i_str

        else:
            st = st + i
            parse_string(i, new)
    return fi


start = "S"
initial_string = "sAB"
x = parse_string(start, initial_string)
final_string = ""

for i in x:
    final_string = final_string + i
print(final_string)
