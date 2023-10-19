import matplotlib.pyplot as plt
import sys

if (len(sys.argv) != 2):
    print("no input file! Usage: python instrDump.py <input_file>")
    exit()

instrs = dict()

with open(sys.argv[1], 'r') as f:
    while line := f.readline().split():
        instrs[line[0]] = int(line[1])

instrs = dict(sorted(instrs.items(), key=lambda x:x[1], reverse=True)[:10])
fig, ax = plt.subplots(figsize=(10, 5))

names = list(instrs.keys())
counts = [instrs[key] for key in instrs.keys()]

ax.barh(names, counts, align='center')
ax.set_yticks(names, labels=names)
ax.invert_yaxis()
ax.set_yticklabels(names, rotation=45, ha='right')
ax.set_xlabel('count of using the instruction')
ax.set_title('How many instructions?')

plt.show()