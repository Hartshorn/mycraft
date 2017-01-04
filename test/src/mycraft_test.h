#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef enum {
	T_FUNCTION,
	T_CALLBACK,
	T_OTHER
} Test;

typedef enum {
	T_PASSED,
	T_FAILED
} Result;


typedef struct {
	Test test_to_perform;
	Result result;
} Test_Case;


Test_Case* create_test(Test);
void perform_test(Test_Case *);
void cleanup_test(Test_Case *);
	
