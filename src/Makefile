.DEFAULT_GOAL := generate

generate:
	@mkdir -p priv/nifs
	@gcc -fPIC -dynamiclib -undefined dynamic_lookup -o priv/nifs/bls.so src/nifs/bls.c ${MCL_PATH}/lib/libmclbn384_256.a ${MCL_PATH}/lib/libmcl.a -L/usr/local/opt/openssl@1.1/lib -L/usr/local/opt/openssl/lib -L/usr/local/opt/gmp/lib -lgmp -lgmpxx -lcrypto -m64  -lstdc++

clean:
	@rm -rf priv/nifs
