void test_countzeroes()
{
    int result[256];
    int length = 0;

    // Number = 0
    assert(count_zeroes(bin(0, result, &length), &length) == 1);
    printf("Test 1 passed\n");

    // Number = 1
    assert(count_zeroes(bin(1, result, &length), &length) == 0);
    printf("Test 2 passed\n");

    // Number = 1101
    assert(count_zeroes(bin(1101, result, &length), &length) == 3);
    printf("Test 3 passed\n");

    printf("All tests passed successfully!\n");

}