#include "mycraft_test.h"


Test_Case* create_test(Test test, Model *game)
{
	Test_Case *test_case = malloc(sizeof(Test_Case));
	if (test_case) {
		test_case->test_to_perform = test;
		test_case->result = T_PASSED;
		test_case->game = game;
	}
	return test_case;
}


void build_tests(Test_Case **tests, Model *game)
{
	Test_Case *tc1 = create_test(T_INITIAL, game);
	Test_Case *tc2 = create_test(T_SECONDARY, game);
	Test_Case *tc3 = create_test(T_TERTIARY, game);
	Test_Case *tc4 = create_test(T_FINAL, game);

	tests[0] = tc1;
	tests[1] = tc2;
	tests[2] = tc3;
	tests[3] = tc4; 
}


Test_Result perform_test(Test_Case *test_case)
{
	Test t = test_case->test_to_perform;

	switch (t) {
		case T_INITIAL:
			return run_initial_tests(test_case);
		case T_SECONDARY:
			return run_secondary_tests(test_case);
		case T_TERTIARY:
			return run_tertiary_tests();
		case T_FINAL:
			return run_final_tests();
		default:
			fprintf(stdout, "DEFAULT test.\n");
			break;
	}
}


Test_Result run_tests(Test_Case **tests, int n)
{
	Test_Result result = T_PASSED;

	for (int i = 0; i < n; i++) {
		Test_Case *t = tests[i];
		t->result = perform_test(t);

		if (t->result != T_PASSED) {
			fprintf(stdout, "TEST FAILED: %s\n", \
					resolve_test_name(t->test_to_perform));
			result = T_FAILED;
		}
	}
	return result;
}


void cleanup_test(Test_Case *test_case)
{
	free(test_case);
}


void cleanup_all_tests(Test_Case **tests, int n)
{
	for (int i = 0; i < n; i++)
		cleanup_test(tests[i]);
	free(tests);
}


Test_Result run_initial_tests(Test_Case *tc)
{
	fprintf(stdout, "\nbegin initial test\n");
    
	key_callback(NULL, 1, 2, 3, 4);	

	set_db_path(tc->game);

	assert(strcmp(tc->game->db_path, "mycraft.db") == 0);
	
	fprintf(stdout, "\n\nend initial test\n");

	return T_PASSED;
}


Test_Result run_secondary_tests(Test_Case *tc)
{
	fprintf(stdout, "\nbegin secondary test\n");

    mouse_callback(NULL, 1, 2, 3); 

	glfwInit();
	create_window(tc->game);

	assert(tc->game->window != NULL);

	fprintf(stdout, "\n\nend secondary test\n");

	glfwTerminate();

	return T_PASSED;
}


Test_Result run_tertiary_tests()
{
	fprintf(stdout, "\nbegin tertiary test\n");

	scroll_callback(NULL, 123.45f, 33.44f); 

	fprintf(stdout, "\n\nend tertiary test\n");

	return T_PASSED;
}


Test_Result run_final_tests()
{
	fprintf(stdout, "\nbegin final test\n");

	char_callback(NULL, 12345);

	compute_chunk(NULL);

	fprintf(stdout, "\n\nend final test\n");

	return T_PASSED;
}

static Model model;
static Model *game = &model;

int main(int argc, char **argv)
{
	Test_Case **tests = malloc(sizeof(Test*) * TEST_COUNT);
	game = malloc(sizeof(Model));
	
	if (tests)
		build_tests(tests, game);
	
	if (run_tests(tests, TEST_COUNT) == T_FAILED)
		fprintf(stdout, "\nSOME TEST FAILED!\n\n");
	else
		fprintf(stdout, "\nALL TESTS PASSED!\n\n");
	
	cleanup_all_tests(tests, TEST_COUNT);
	
	return 0;
}
