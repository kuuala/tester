#include "utility.h"

void print_help() {
    cout << "-h - help about tool" << endl;
    cout << "-r [length] - generate random sequence" << endl;
    cout << "-e [filename] - use existing sequence" << endl;
    cout << "-rl [min][max] - min and max reads length" << endl;
    cout << "-t [exe name] - name of tested program" << endl;
}

void parse_input(int argc, char *argv[], data &input) {
    int current = 1;
    while (current < argc) {
        if (string(argv[current]) == "-r") {
            input.is_rand = true;
            input.source_dna = "source.txt";
            ++current;
            input.sequence_length = atoi(argv[current]);
        } else if (string(argv[current]) == "-e") {
            input.is_rand = false;
            ++current;
            input.source_dna = string(argv[current]);
        } else if (string(argv[current]) == "-rl") {
            ++current;
            input.min_reads_length = atoi(argv[current]);
            ++current;
            input.max_reads_length = atoi(argv[current]);
            if (input.max_reads_length < input.min_reads_length ||
                input.min_reads_length < 1 ||
                input.max_reads_length < 1) {
                cout << "-rl bad values" << endl;
                exit(0);
            }
        } else if (string(argv[current]) == "-t") {
            ++current;
            input.tested_program = string(argv[current]);
        }
        ++current;
    }
    input.reads_filename = "reads.txt";
}