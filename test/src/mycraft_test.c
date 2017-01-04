#include "mycraft_test.h"


Test_Case* create_test(Test test)
{
	Test_Case *test_case = malloc(sizeof(Test_Case));
	test_case->test_to_perform = test;
	test_case->result = T_FAILED;
	
	 return test_case;
}

void perform_test(Test_Case *test_case)
{
	Test t = test_case->test_to_perform;

	switch (t) {
		case T_FUNCTION:
			fprintf(stdout, "T_FUNCTION test.\n");
			break;
		case T_CALLBACK:
			fprintf(stdout, "T_CALLBACK test.\n");
			break;
		case T_OTHER:
			fprintf(stdout, "T_OTHER test.\n");
			break;
		default:
			fprintf(stdout, "DEFAULT test.\n");
			break;
	}
}

void cleanup_test(Test_Case *test_case)
{
	free(test_case);
}


int main(int argc, char **argv)
{
	Test_Case *tc1 = create_test(T_FUNCTION);
	Test_Case *tc2 = create_test(T_CALLBACK);
	Test_Case *tc3 = create_test(T_OTHER);
	Test_Case *tc4 = create_test(T_OTHER);


	perform_test(tc1);
	perform_test(tc2);
	perform_test(tc3);
	perform_test(tc4);

	cleanup_test(tc1);
	cleanup_test(tc2);
	cleanup_test(tc3);
	cleanup_test(tc4);

	return 0;

}
