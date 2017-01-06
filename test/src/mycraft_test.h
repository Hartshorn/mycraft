#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "../../include/util.h"
#include "../../include/callbacks.h"
#include "../../include/map.h"
#include "../../include/db.h"
#include "../../include/world.h"
#include "../../include/worker.h"

typedef enum {
	T_INITIAL,
	T_SECONDARY,
	T_TERTIARY,
	T_FINAL
} Test;

#define TEST_COUNT	4

const char* resolve_test_name(Test t)
{
	switch (t) {
		case 0:
			return "T_INITIAL";
		case 1:
			return "T_SECONDARY";
		case 2:
			return "T_TERTIARY";
		case 3:
			return "T_FINAL";
		default:
			return "NOT FOUND!";
	}
}

typedef enum {
	T_PASSED,
	T_FAILED
} Test_Result;


typedef struct {
	Test test_to_perform;
	Test_Result result;
} Test_Case;

const char* resolve_test_name(Test);

Test_Case* create_test(Test);
Test_Result perform_test(Test_Case *);
void cleanup_test(Test_Case *);

Test_Result run_initial_tests();
Test_Result run_secondary_tests();
Test_Result run_tertiary_tests();
Test_Result run_final_tests();
