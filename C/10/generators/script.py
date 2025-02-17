def parse_input_file(input_file):
    function_header_dict = {}
    current_header = None

    with open(input_file, 'r') as file:
        for line in file:
            line = line.strip()
            if line.endswith('.h'):
                current_header = line
            elif line:
                function_header_dict[line] = current_header

    return function_header_dict

# Example usage
new_s = set()
input_file = 'func.txt'  # Provide the path to your input file
function_header_dict = parse_input_file(input_file)
with open("out.txt", "w") as f:
    i = 1
    for function_name, header_file in function_header_dict.items():
        f.write(f'if (strcmp(line, "{function_name}") == 0 && flag_{header_file.replace(".", "_", 1)} == 0) ? fputs("#include <{header_file}>\\n", out); flag_{header_file.replace(".", "_", 1)} = 1; printf("{function_name}");!\n')
        i += 1

        new_s.add("int flag_" + header_file.replace(".", "_", 1) + " = 0;")


for i in new_s:
    print(i)



