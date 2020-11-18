//
//  open_ssl_wrapper.c
//  test_sic
//
//  Created by SergeyBrazhnik on 12.11.2020.
//

#include "open_ssl_wrapper.h"
#include "openssl_include.h"

int aes_cfb8_nopadding(
        const unsigned char aeskey[],
        const unsigned char iv[],
        const unsigned char body[],
        int body_length,
        unsigned char out[]) {
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return -1;

    if (1 != EVP_EncryptInit(ctx, EVP_aes_256_cfb8(), aeskey, iv)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    EVP_CIPHER_CTX_set_key_length(ctx, 32);

    int outlen = body_length;
    int pos = 0;

    if (1 != EVP_EncryptUpdate(ctx, out, &outlen, body, body_length)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    pos += outlen;
    if (pos < body_length) {
        outlen = body_length - pos;

        if (1 != EVP_EncryptFinal(ctx, out, &outlen)) {
            EVP_CIPHER_CTX_free(ctx);
            return -1;
        }
    }

    return 0;
}
