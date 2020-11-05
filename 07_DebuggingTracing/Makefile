unlink-wrap.so: bin unlink-wrap.c
	cc -shared -fPIC unlink-wrap.c -ldl -o bin/unlink-wrap.so

test_unlink_with_wrapper: bin test_file test_FIX_file unlink-wrap.so
	-LD_PRELOAD=bin/unlink-wrap.so rm bin/test_file
	-LD_PRELOAD=bin/unlink-wrap.so rm bin/test_FIX_file

test_unlink_without_wrapper: bin test_file test_FIX_file
	rm bin/test_file
	rm bin/test_FIX_file

test_file: bin
	touch bin/test_file

test_FIX_file: bin
	touch bin/test_FIX_file

bin:
	mkdir bin

clean:
	rm bin/*



