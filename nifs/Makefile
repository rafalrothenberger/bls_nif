.DEFAULT_GOAL := generate

generate:
	@mkdir -p priv/nifs
	@gcc -fPIC -dynamiclib -undefined dynamic_lookup -o priv/nifs/bls.so nifs/src/bls.c

clean:
	@rm -rf priv/nifs
