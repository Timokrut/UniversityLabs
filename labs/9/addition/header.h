#pragma once

void* bin(int number, int result[], int* length);
int count_zeroes(int digits[], int* length);
void tests();
int count_ones(int digits[], int* length);
void generateBinary(int ones, int zeros, char* prefix, int prefix_length);
void print_binary(int number[], int* len);
void generate_binary(int num_zeros, int num_ones);
void print_test();