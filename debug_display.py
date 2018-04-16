import sys

indent = 0
next_indent = None
offset = 4
filename = sys.argv[1]

with open(filename, "rt") as t_file:
    while True:
        line = t_file.readline()
        if line == "":
            break

        start = line[0]
        if start == 'B':
            next_indent = indent + offset
        elif start in 'EF':
            indent = indent - offset
            if indent < 0:
                indent = 0

        tabbing = " " * indent
        if next_indent is not None:
            indent = next_indent
            next_indent = None
        sys.stdout.write(tabbing + line)

