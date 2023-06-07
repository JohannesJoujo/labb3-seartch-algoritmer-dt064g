import matplotlib.pyplot as plt

# Open the text file and read the lines
with open('/Users/JohannesJoujo/CLionProjects/seartch/cmake-build-release/Find.txt', 'r') as file:
    lines = file.readlines()

# Initialize empty lists for the data
N_sekventiell_seartch = []
Lable_sekventiell_seartcht = []
T_sekventiell_seartch = []
Stdev_sekventiell_seartch = []

N_binary_seartch = []
T_binary_seartch = []
Stdev_binary_seartch = []

N_binary_seartch_tree = []
T_binary_seartch_tree = []
Stdev_binary_seartch_tree = []

N_hash_table = []
T_hash_table = []
Stdev_hash_table = []

# Loop through the lines and extract the data
for line in lines:
    if line.startswith('sekventiell_seartch'):
        parts = line.split('\t')
        Lable_sekventiell_seartcht.append(parts[0])
        continue
    if line.startswith('N'):
        continue
    if line.startswith('\n'):
        continue
    if line.startswith('a'):
        parts = line.split('\t')
        N_sekventiell_seartch.append(int(parts[1]))
        T_sekventiell_seartch.append(float(parts[2]))
        Stdev_sekventiell_seartch.append(float(parts[3]))

    if line.startswith('binary_seartch'):
        continue
    if line.startswith('N'):
        continue
    if line.startswith('\n'):
        continue
    if line.startswith('b'):
        parts = line.split('\t')
        N_binary_seartch.append(int(parts[1]))
        T_binary_seartch.append(float(parts[2]))
        Stdev_binary_seartch.append(float(parts[3]))

    if line.startswith('binary_seartch_tree'):
        continue
    if line.startswith('N'):
        continue
    if line.startswith('\n'):
        continue
    if line.startswith('c'):
        parts = line.split('\t')
        N_binary_seartch_tree.append(int(parts[1]))
        T_binary_seartch_tree.append(float(parts[2]))
        Stdev_binary_seartch_tree.append(float(parts[3]))

    if line.startswith('hash_table'):
        continue
    if line.startswith('N'):
        continue
    if line.startswith('\n'):
        continue
    if line.startswith('d'):
        parts = line.split('\t')
        N_hash_table.append(int(parts[1]))
        T_hash_table.append(float(parts[2]))
        Stdev_hash_table.append(float(parts[3]))

# Plot the data for sekventiell_seartch
plt.errorbar(N_sekventiell_seartch, T_sekventiell_seartch, yerr=Stdev_sekventiell_seartch, fmt='o-', ecolor='red')
plt.xlabel('N')
plt.ylabel('Time [ms]')
plt.title('sekventiell search')
plt.ylim(-0.5)
# plt.ylim(bottom=0)

# Plot the data for binary_seartch
plt.figure()  # Create a new figure
plt.errorbar(N_binary_seartch, T_binary_seartch, yerr=Stdev_binary_seartch, fmt='o-', ecolor='red')
plt.xlabel('N')
plt.ylabel('Time [ms]')
plt.title('binary search')
plt.ylim(-0.5)


# Plot the data for binary_seartch_tree
plt.figure()  # Create a new figure
plt.errorbar(N_binary_seartch_tree, T_binary_seartch_tree, yerr=Stdev_binary_seartch_tree, fmt='o-', ecolor='red')
plt.xlabel('N')
plt.ylabel('Time [ms]')
plt.title('binary search tree')
plt.ylim(-0.5)

# Plot the data for hash_table
plt.figure()  # Create a new figure
plt.errorbar(N_hash_table, T_hash_table, yerr=Stdev_hash_table, fmt='o-', ecolor='red')
plt.xlabel('N')
plt.ylabel('Time [ms]')
plt.title('hash table')
plt.ylim(-0.5)

# Display all the graphs together
plt.show()
