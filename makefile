export GTEST_DIR=/u/g/e1400476/linked_list/googletest/googletest
export COV_OUTPUT=./cov_output
my_test: libgtest.a test_case.c linkedlist.c Gtest_main.c
	
	g++ -isystem ${GTEST_DIR}/include -pthread test_case.c linkedlist.c Gtest_main.c libgtest.a -o my_test -g
	

libgtest.a:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc 
	ar -rv libgtest.a gtest-all.o
report:
	
	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o ${COV_OUTPUT} .coverage.total
	rm -f .coverage.base .coverage.run .coverage.tota
clean:
	rm -rf *.o my_test
	
