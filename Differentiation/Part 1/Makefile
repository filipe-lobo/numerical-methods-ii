all: forward_diff backward_diff central_diff

forward_diff: forward_diff.c forward_diff.h
	gcc forward_diff.c forward_diff.h utils.h -o forward_diff

backward_diff: backward_diff.c backward_diff.h
	gcc backward_diff.c backward_diff.h utils.h -o backward_diff

central_diff: central_diff.c central_diff.h
	gcc central_diff.c central_diff.h utils.h -o central_diff
