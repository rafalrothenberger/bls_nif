#include "erl_nif.h"
#include <mcl/bn_c384_256.h>
#include <printf.h>
#include <string.h>

static
int load(ErlNifEnv *env, void **priv, ERL_NIF_TERM info)
{
    return mclBn_init(MCL_BLS12_381, MCLBN_COMPILED_TIME_VAR);
}

static
int upgrade(ErlNifEnv *caller_env, void **priv_data, void **old_priv_data, ERL_NIF_TERM load_info)
{
    return mclBn_init(MCL_BLS12_381, MCLBN_COMPILED_TIME_VAR);
}

static void unload(ErlNifEnv *caller_env, void *priv_data) {}

static ERL_NIF_TERM
g1neg(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG1 a, c;
    char aStr[250];
    enif_get_string(env, argv[0], aStr, 250, ERL_NIF_LATIN1);
    mclBnG1_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG1_neg(&c, &a);
    mclBnG1_getStr(aStr, 250, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g2neg(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG2 a, c;
    char aStr[500];
    enif_get_string(env, argv[0], aStr, 500, ERL_NIF_LATIN1);
    mclBnG2_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG2_neg(&c, &a);
    mclBnG2_getStr(aStr, 500, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g1dbl(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG1 a, c;
    char aStr[250];
    enif_get_string(env, argv[0], aStr, 250, ERL_NIF_LATIN1);
    mclBnG1_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG1_dbl(&c, &a);
    mclBnG1_getStr(aStr, 250, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g2dbl(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG2 a, c;
    char aStr[500];
    enif_get_string(env, argv[0], aStr, 500, ERL_NIF_LATIN1);
    mclBnG2_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG2_dbl(&c, &a);
    mclBnG2_getStr(aStr, 500, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g1add(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG1 a,b, c;
    char aStr[250], bStr[250];
    enif_get_string(env, argv[0], aStr, 250, ERL_NIF_LATIN1);
    enif_get_string(env, argv[1], bStr, 250, ERL_NIF_LATIN1);
    mclBnG1_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG1_setStr(&b, bStr, strlen(bStr), 10);
    mclBnG1_add(&c, &a, &b);
    mclBnG1_getStr(aStr, 250, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g2add(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG2 a, b, c;
    char aStr[500], bStr[500];
    enif_get_string(env, argv[0], aStr, 500, ERL_NIF_LATIN1);
    enif_get_string(env, argv[1], bStr, 500, ERL_NIF_LATIN1);
    mclBnG2_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG2_setStr(&b, bStr, strlen(bStr), 10);
    mclBnG2_add(&c, &a, &b);
    mclBnG2_getStr(aStr, 500, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g1sub(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG1 a, b, c;
    char aStr[250], bStr[250];
    enif_get_string(env, argv[0], aStr, 250, ERL_NIF_LATIN1);
    enif_get_string(env, argv[1], bStr, 250, ERL_NIF_LATIN1);
    mclBnG1_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG1_setStr(&b, bStr, strlen(bStr), 10);
    mclBnG1_sub(&c, &a, &b);
    mclBnG1_getStr(aStr, 250, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g2sub(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG2 a, b, c;
    char aStr[500], bStr[500];
    enif_get_string(env, argv[0], aStr, 500, ERL_NIF_LATIN1);
    enif_get_string(env, argv[1], bStr, 500, ERL_NIF_LATIN1);
    mclBnG2_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG2_setStr(&b, bStr, strlen(bStr), 10);
    mclBnG2_sub(&c, &a, &b);
    mclBnG2_getStr(aStr, 500, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g1mul(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG1 a, c;
    mclBnFr b;
    char aStr[250], bStr[100];
    enif_get_string(env, argv[0], aStr, 250, ERL_NIF_LATIN1);
    enif_get_string(env, argv[1], bStr, 100, ERL_NIF_LATIN1);
    mclBnG1_setStr(&a, aStr, strlen(aStr), 10);
    mclBnFr_setStr(&b, bStr, strlen(bStr), 10);
    mclBnG1_mul(&c, &a, &b);
    mclBnG1_getStr(aStr, 250, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g2mul(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG2 a, c;
    mclBnFr b;
    char aStr[500], bStr[100];
    enif_get_string(env, argv[0], aStr, 500, ERL_NIF_LATIN1);
    enif_get_string(env, argv[1], bStr, 100, ERL_NIF_LATIN1);
    mclBnG2_setStr(&a, aStr, strlen(aStr), 10);
    mclBnFr_setStr(&b, bStr, strlen(bStr), 10);
    mclBnG2_mul(&c, &a, &b);
    mclBnG2_getStr(aStr, 500, &c, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
rhash(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnFr a;
    unsigned long len;
    enif_get_ulong(env, argv[1], &len);

    char input[len+1], aStr[100] = {0};
    enif_get_string(env, argv[0], input, len + 1, ERL_NIF_LATIN1);

    mclBnFr_setHashOf(&a, input, len);
    mclBnFr_getStr(aStr, 100, &a, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g1hash(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG1 a;
    unsigned long len;
    enif_get_ulong(env, argv[1], &len);

    char input[len + 1], aStr[250] = {0};
    enif_get_string(env, argv[0], input, len + 1, ERL_NIF_LATIN1);

    mclBnG1_hashAndMapTo(&a, input, len);
    mclBnG1_getStr(aStr, 250, &a, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
g2hash(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG2 a;
    unsigned long len;
    enif_get_ulong(env, argv[1], &len);

    char input[len + 1], aStr[500];
    enif_get_string(env, argv[0], input, len + 1, ERL_NIF_LATIN1);

    mclBnG2_hashAndMapTo(&a, input, len);
    mclBnG2_getStr(aStr, 500, &a, 10);

    return enif_make_string(env, aStr, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
pairing(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    mclBnG1 a;
    mclBnG2 b;
    mclBnGT c;
    char aStr[250] = {0}, bStr[500] = {0}, cStr[1500] = {0};

    enif_get_string(env, argv[0], aStr, 250, ERL_NIF_LATIN1);
    enif_get_string(env, argv[1], bStr, 500, ERL_NIF_LATIN1);

    mclBnG1_setStr(&a, aStr, strlen(aStr), 10);
    mclBnG2_setStr(&b, bStr, strlen(bStr), 10);

    mclBn_pairing(&c, &a, &b);
    mclBnGT_getStr(cStr, 1500, &c, 10);

    return enif_make_string(env, cStr, ERL_NIF_LATIN1);
}

static ErlNifFunc nif_funcs[] = {
    // {ex_function_name, function_arity, c_function}
    {"nif_g1dbl", 1, g1dbl},
    {"nif_g2dbl", 1, g2dbl},
    {"nif_g1neg", 1, g1neg},
    {"nif_g2neg", 1, g2neg},
    {"nif_g1add", 2, g1add},
    {"nif_g2add", 2, g2add},
    {"nif_g1sub", 2, g1sub},
    {"nif_g2sub", 2, g2sub},
    {"nif_g1mul", 2, g1mul},
    {"nif_g2mul", 2, g2mul},
    {"nif_rhash", 2, rhash},
    {"nif_g1hash", 2, g1hash},
    {"nif_g2hash", 2, g2hash},
    {"nif_pairing", 2, pairing},
};

ERL_NIF_INIT(Elixir.BlsNif.Nif, nif_funcs, &load, NULL, &upgrade, &unload)
