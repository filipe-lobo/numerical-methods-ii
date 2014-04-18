all: richardson_forward richardson_backward richardson_central

richardson_forward: richardson_forward.c richardson_forward.h
	gcc richardson_forward.c richardson_forward.h utils.h -o richardson_forward

richardson_backward: richardson_backward.c richardson_backward.h
	gcc richardson_backward.c richardson_backward.h utils.h -o richardson_backward

richardson_central: richardson_central.c richardson_central.h
	gcc richardson_central.c richardson_central.h utils.h -o richardson_central
