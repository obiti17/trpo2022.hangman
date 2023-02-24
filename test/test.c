#include <libhangman.h>
#include <ctest.h>

CTEST(libhangman, check_func_searchLetter1) 
{
    char letter = 'a', word[] = "abc", exp_tmp_word[] = "***", real_tmp_word[] = "a**";

    int real_data = 0;

    int exp_data = searchLetter(word, exp_tmp_word, letter);

    ASSERT_STR(exp_tmp_word, real_tmp_word);

    ASSERT_EQUAL(real_data, exp_data);
    
}

CTEST(libhangman, check_func_searchLetter2) 
{
    char letter = 'c', word[] = "abc", exp_tmp_word[] = "***", real_tmp_word[] = "**c";

    int real_data = 2;

    int exp_data = searchLetter(word, exp_tmp_word, letter);

    ASSERT_STR(exp_tmp_word, real_tmp_word);

    ASSERT_EQUAL(real_data, exp_data);
}

CTEST(libhangman, check_func_searchLetter3) 
{
    char letter1 = 'a', letter2 = 'b', letter3 = 'c', word[] = "abc", exp_tmp_word[] = "***", real_tmp_word[] = "abc";

    int real_data = 2;

    int exp_data = searchLetter(word, exp_tmp_word, letter1);
    exp_data = searchLetter(word, exp_tmp_word, letter2);
    exp_data = searchLetter(word, exp_tmp_word, letter3);

    ASSERT_STR(exp_tmp_word, real_tmp_word);

    ASSERT_EQUAL(real_data, exp_data);
}
